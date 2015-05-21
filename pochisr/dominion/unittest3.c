// Test that the game is over when the Province supply is exhausted.

#include "dominion_helpers.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define assertBoolEqual(x, y) assertBoolEqual_(x, y, __LINE__)
#define assertIntEqual(x, y) assertIntEqual_(x, y, __LINE__)


static void assertBoolEqual_(int x, int y, int line)
{
    x = !!x;
    y = !!y;
    if (x != y) {
        fprintf(
            stderr, "TEST FAILED on line %d: expected %s but got %s\n",
            line, x ? "true" : "false", y ? "true" : "false");
        exit(1);
    }
}


static void assertIntEqual_(int x, int y, int line)
{
    if (x != y) {
        fprintf(
            stderr, "TEST FAILED on line %d: expected %d but got %d\n",
            line, x, y);
        exit(1);
    }
}


int main()
{
    for (int toFlag = 0; toFlag <= 2; toFlag++) {
        struct gameState* g = newGame();
        int* ks = kingdomCards(
            adventurer, gardens, mine, baron, tribute, ambassador, embargo,
            outpost, sea_hag, treasure_map);
        assertIntEqual(0, initializeGame(2, ks, 2849, g));

        for (int i = 1; i <= 8; i++) {
            assertIntEqual(0, gainCard(province, g, toFlag, 0));
            assertIntEqual(i, fullDeckCount(0, province, g));
        }
        assertIntEqual(-1, gainCard(province, g, toFlag, 0));
        assertBoolEqual(true, isGameOver(g));

        free(g);
        free(ks);
    }

    puts("TEST PASSED");
    return 0;
}
