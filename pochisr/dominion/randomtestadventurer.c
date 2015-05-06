#include "dominion.h"
#include "rngs.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv)
{
    if (argc < 2) {
        puts("Usage: randomtestadventurer SEED");
        exit(1);
    }

    {
        errno = 0;
        long seed = strtol(argv[1], NULL, 10);
        if (errno || seed <= 0) {
            fputs("Invalid seed\n", stderr);
            exit(1);
        }
        PlantSeeds(seed);
        SelectStream(0);
    }

    for (int i = 0; i < 20; i++)
        (void)Random();

    printf("%d\n", (unsigned int)(Random() * 100));

    return 0;
}
