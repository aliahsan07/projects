// Test Baron

#include "dominion_helpers.h"
#include "rngs.h"

#include <errno.h>
#include <stdbool.h>
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
    ks[0] = baron;

    puts("Kingdom cards:\n  baron");
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
    bool have_estate = false;
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
                if (card == baron &&
                        supplyCount(baron, g) <= 1)
                    continue;
                if (gainCard(card, g, toFlag, player) == 0)
                    break;
            }
            if (card == estate && toFlag == 2) // have Estate in hand
                have_estate = true;
            printf("  %s\n", cardNames[card]);
        }
        if (toFlag == 2) {
            assertIntEqual(0, gainCard(baron, g, 2, player));
            puts("  baron");
        }
        putchar('\n');
    }
    updateCoins(player, g, 0);

    if (isGameOver(g)) // Oops.
        return 0;

    if (rand_int(0, 1)) {
        // Discard an Estate for 4 coins.
        int coins_before = g->coins;
        int r = playCard(numHandCards(g) - 1, 1, -1, -1, g);
        if (have_estate) { // It should succeed.
            assertIntEqual(0, r);
            assertIntEqual(coins_before + 4, g->coins);
            assertIntEqual(0, buyCard(copper, g));
        } // Otherwise it at least shouldn't crash.
    } else {
        // Gain an Estate.
        int estates_before = fullDeckCount(player, estate, g);
        assertIntEqual(0, playCard(numHandCards(g) - 1, 0, -1, -1, g));
        assertIntEqual(estates_before + 1, fullDeckCount(player, estate, g));
        assertIntEqual(0, buyCard(copper, g));
    }

    free(g);

    return 0;
}
