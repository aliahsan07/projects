#!/usr/bin/env python2

from __future__ import division, unicode_literals

import errno
import itertools
import os
import shlex
import sys
from itertools import izip
from subprocess import Popen
from sys import stderr, stdout


SUSP_WIDTH = 8

USAGE_TEXT = """\
Usage: {} SOURCES GCDAS MINSEED MAXSEED
  SOURCES:  a colon-separated list of source files to analyze
    GCDAS:  a colon-separated list of gcda files that correspond to the
                source files
  MINSEED:  the minumum seed to use
  MAXSEED:  the maximum seed to use
"""


class TLine(object):
    __slots__ = ('p', 'f')

    def __init__(self, p=0, f=0):
        self.p = p
        self.f = f

    def get_susp(self, pass_count, fail_count):
        px = self.p / pass_count if pass_count > 0 else 0
        fx = self.f / fail_count if fail_count > 0 else 0
        return fx / (px + fx) if px + fx > 0.0 else 0.0


def main(sources, gcdas, minseed, maxseed):
    pass_count = 0
    fail_count = 0
    susp = {}  # suspiciousness

    for source in sources:
        line_count = 0
        with open(source) as f:
            while True:
                chunk = f.read(4096)
                if chunk == '':
                    break
                line_count += chunk.count('\n')
        susp[source] = [TLine(p=0, f=0) for i in xrange(line_count)]

    devnull = open(os.devnull, 'wb')

    for seed in xrange(minseed, maxseed + 1):
        for gcda in gcdas:
            try:
                os.remove(gcda)
            except OSError as e:
                if e.errno != errno.ENOENT:
                    raise

        pass_ = int(
            0 == Popen(('./testdominion', unicode(seed), '80000'),
                stdout=devnull).wait())
        pass_count += pass_
        fail_count += 1 - pass_

        if (Popen(['gcov'] + sources, stdout=devnull, stderr=devnull).wait()
                != 0):
            stderr.write('gcov failed\n')
            exit(1)

        for source in sources:
            try:
                with open(source + '.gcov') as f:
                    lines = iter(f)
                    for line in lines:
                        line = line.lstrip(' -:')
                        if line[0] != '0':
                            break

                    for i in itertools.count():  # First line is index 0.
                        count = line[:line.find(':')]
                        if count not in ('-', '#####'):
                            susp[source][i].p += pass_
                            susp[source][i].f += 1 - pass_
                        line = next(f, None)
                        if line is None:
                            break
                        line = line.lstrip()
            except IOError as e:
                if e.errno != errno.ENOENT:
                    raise
                # Oh well.

    for source in sources:
        with open(source + '.tla', 'w') as t, open(source) as s:
            i = 0  # First line is number 1.
            for line, sline in izip(susp[source], s):
                i += 1
                line_susp = int(line.get_susp(pass_count, fail_count) *
                    SUSP_WIDTH)

                t.write(
                    ' ' * (SUSP_WIDTH - line_susp)
                    + '#' * line_susp
                    + '  {}:  '.format(i)
                    + sline)


if __name__ == '__main__':
    if len(sys.argv) != 5:
        stdout.write(USAGE_TEXT.format(sys.argv[0]))
        exit(2)

    main(
        sys.argv[1].split(':'), sys.argv[2].split(':'), int(sys.argv[3]),
        int(sys.argv[4]))
