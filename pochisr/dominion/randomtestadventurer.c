#include "dominion_helpers.h"
#include "rngs.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>


#define assertIntEqual(x, y) assertIntEqual_(x, y, __LINE__)


void assertIntEqual_(int x, int y, int line)
{
    if (x != y) {
        fprintf(
            stderr, "TEST FAILED on line %d: expected %d but got %d\n",
            line, x, y);
        exit(1);
    }
}


int get_seed(int argc, char** argv)
{
    if (argc < 2) {
        puts("Usage: randomtestadventurer SEED");
        exit(1);
    }

    errno = 0;
    long seed = strtol(argv[1], NULL, 10);
    if (errno || seed <= 0) {
        fputs("Invalid seed\n", stderr);
        exit(1);
    }

    return seed;
}


/* Note: The probability of returning max + 1 is very small but nonzero.
 *       If double were infinitely precise, it would be zero, but it's not. */
int rand_int(int min, int max)
{
    return min + (int)((max - min + 1) * Random());
}


int main(int argc, char** argv)
{

    int seed = get_seed(argc, argv);
    PlantSeeds(seed);
    for (int i = 0; i < 189; i++)
        (void)Random();

    struct gameState* g = newGame();
    int ks[10];
    ks[0] = adventurer;

    fputs("Kingdom cards:\n  adventurer  ", stdout);
    for (int i = 1; i < 10; i++) {
        while (1) {
            int r = rand_int(adventurer, treasure_map);
            int j;
            for (j = 0; j < i; j++)
                if (r == ks[j])
                    break;
            if (j == i) {  // the for loop was exited normally
                ks[i] = r;
                printf("%s  ", cardNames[r]);
                break;
            }
        }
    }
    putchar('\n');

    initializeGame(2, ks, seed, g);
    for (int i = 0; i < 189; i++)
        (void)Random();

    if (rand_int(0, 1))
        endTurn(g);

    int player = whoseTurn(g);

    // Trash all our cards.
    for (int i = 0; i < 5; i++)
        assertIntEqual(0, drawCard(player, g));
    for (int i = 0; i < 10; i++)
        assertIntEqual(0, discardCard(0, player, g, 1));
    assertIntEqual(0, numHandCards(g));

    fputs("Hand:\n  adventurer  ", stdout);
    assertIntEqual(0, gainCard(adventurer, g, 2, player));
    // Gain a random number of random cards.
    {
        int count = rand_int(0, 30);
        for (int i = 0; i < count; i++) {
            int card;
            do {
                int r = rand_int(-3, 9);
                if (r < 0)
                    card = copper + r + 3;
                else
                    card = ks[r];
            } while (gainCard(card, g, 2, player) != 0);
            printf("%s  ", cardNames[card]);
        }
        putchar('\n');
    }

    gainCard(adventurer, g, 2, player);
    assertIntEqual(0, playCard(numHandCards(g) - 1, -1, -1, -1, g));

    /*for (int i = 0; i < g->discardCount[0]; i++)*/

    free(g);

    return 0;
}
