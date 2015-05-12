// Test Adventurer

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

    puts("Kingdom cards:\n  adventurer");
    for (int i = 1; i < 10; i++) {
        while (1) {
            int r = rand_int(adventurer, treasure_map);
            int j;
            for (j = 0; j < i; j++)
                if (r == ks[j])
                    break;
            if (j == i) {  // the for loop was exited normally
                ks[i] = r;
                printf("  %s\n", cardNames[r]);
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

    // Gain a random number of random cards.
    for (int toFlag = 0; toFlag < 3; toFlag++) {
        switch (toFlag) {
            case 0:
                puts("Discard:");
                break;
            case 1:
                puts("Deck:");
                break;
            case 2:
                puts("Hand:");
                break;
        }
        int count = rand_int(0, 30);
        for (int i = 0; i < count; i++) {
            int card;
            while (1) {
                int r = rand_int(-7, 9);
                if (r < 0)
                    card = r + 7;
                else
                    card = ks[r];
                if (card == adventurer &&
                        supplyCount(adventurer, g) <= 1)
                    continue;
                if (gainCard(card, g, 2, player) == 0)
                    break;
            }
            printf("  %s\n", cardNames[card]);
        }
        if (toFlag == 2) {
            assertIntEqual(0, gainCard(adventurer, g, 2, player));
            puts("  adventurer");
        }
        putchar('\n');
    }

    if (isGameOver(g)) // Oops.
        return 0;


    int discard_before = g->discardCount[player];
    assertIntEqual(0, playCard(numHandCards(g) - 1, -1, -1, -1, g));
    int discard_after = g->discardCount[player];

    for (int i = discard_before; i < discard_after; i++)
        if (g->discard[player][i] >= copper && g->discard[player][i] <= gold) {
            fprintf(stderr, "TEST FAILED on line %d: "
                "Adventurer discarded a treasure card\n", __LINE__);
            return 1;
        }

    free(g);

    return 0;
}
