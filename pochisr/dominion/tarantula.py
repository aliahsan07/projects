#!/usr/bin/env python2

from __future__ import unicode_literals

import sys
from collections import namedtuple
from sys import stderr, stdout


USAGE_TEXT = """\
Usage: {} SOURCES GCDAS
  SOURCES: a comma-separated list of source files to analyze
  GCDAS:   a comma-separated list of gcda files that correspond to the source
           files
"""


Line = namedtuple('Line', ('s', 'f'))


def main(sources, gcdas):
    lines = {}
    for source in sources:
        line_count = 0
        with open(source) as f:
            while True:
                chunk = f.read(4096)
                if chunk == '':
                    break
                line_count += chunk.count('\n')
        lines[source] = [Line(s=0, f=0) for i in xrange(line_count)]



if __name__ == '__main__':
    if len(sys.argv) != 3:
        stdout.write(USAGE_TEXT.format(sys.argv[0]))
        exit(2)

    main(sys.argv[1].split(','), sys.argv[2].split(','))
