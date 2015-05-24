#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define fatal(rtn, str) fatal_(rtn, __LINE__, str)
#define fatal_e(rtn, str) fatal_e_(rtn, __LINE__, str)
#define print(x) fputs((x), stdout)


const char* progname;


void fatal_(int rtn, int line, const char* str)
{
    fprintf(stderr, "\n%s:%d: %s\n", progname, line, str);
    exit(rtn);
}


void fatal_e_(int rtn, int line, const char* str)
{
    fprintf(stderr, "\n%s:%d: %s (%s)\n", progname, line, str,
        strerror(errno));
    exit(rtn);
}


int main(int argc, const char* const* argv)
{
    progname = argv[0];

    if (argc < 4) {
        print(
            "Usage: fdiff FILE1 FILE2 LIMIT\n"
            "\n"
            "  FILE1: the first file to compare\n"
            "  FILE2: the second file to compare\n"
            "  LIMIT: the maximum number of differing lines to print\n"
        );
        return 2;
    }

    FILE* f1 = fopen(argv[1], "r");
    if (f1 == NULL)
        fatal_e(1, "Can't open first file");

    FILE* f2 = fopen(argv[2], "r");
    if (f2 == NULL)
        fatal_e(1, "Can't open second file");

    errno = 0;
    int limit = strtol(argv[3], NULL, 10);
    if (errno != 0)
        fatal_e(2, "Invalid line limit");
    else if (limit <= 0)
        fatal(2, "Line limit must be positive");

    char buf1[4096], buf2[4096];
    size_t count1, count2, line, pos = 0;
    bool differ = false;
    while (!differ) {
        count1 = fread(&buf1[pos], 1, sizeof(buf1) - pos, f1) + pos;
        if (count1 == pos) {
            if (feof(f1))
                break;
            else
                fatal(1, "Can't read from first file");
        }

        count2 = fread(&buf2[pos], 1, sizeof(buf2) - pos, f2) + pos;
        if (count2 == pos) {
            if (feof(f2))
                break;
            else
                fatal(1, "Can't read from second file");
        }

        line = 0;
        for (/* */; pos < count1 && pos < count2; pos++) {
            if (buf1[pos] != buf2[pos]) {
                differ = true;
                break;
            }

            if (buf1[pos] == '\n') {
                putchar(' ');
                if (fwrite(&buf1[line], pos - line + 1, 1, stdout) == 0)
                    fatal(1, "Can't write line");
                line = pos + 1;
            }
        }

        if (!differ && pos > line) {
            pos = pos - line;
            memmove(buf1, &buf1[line], pos);
            memmove(buf2, &buf2[line], pos);
            line = 0;
        }
    }

    if (differ)
        print("They differ.\n");

    return 0;
}
