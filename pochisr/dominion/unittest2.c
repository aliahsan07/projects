#include "dominion.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define assertBoolEqual(x, y) assertBoolEqual_(x, y, __LINE__)
#define assertIntEqual(x, y) assertIntEqual_(x, y, __LINE__)


void assertBoolEqual_(int x, int y, int line)
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


void assertIntEqual_(int x, int y, int line)
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
    struct gameState* g = newGame();
    int* ks = kingdomCards(
        adventurer, gardens, mine, baron, tribute, ambassador, embargo,
        outpost, sea_hag, treasure_map);
    assertIntEqual(0, initializeGame(2, ks, 2849, g));

    for (int i = 0; i < 60 - 2 * 7; i++) { // 60 - 2 * 7 coppers in supply
        assertIntEqual(0, buyCard(copper, g));
        assertIntEqual(7 + i/2 + 1, fullDeckCount(whoseTurn(g), copper, g));
        assertIntEqual(0, endTurn(g));
    }

    free(g);
    free(ks);

    puts("TEST PASSED");
    return 0;
}
