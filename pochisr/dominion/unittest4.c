// Test that a player can't play a non-action card.

#include "dominion_helpers.h"

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


int main()
{
    struct gameState* g = newGame();
    int* ks = kingdomCards(
        adventurer, gardens, mine, baron, tribute, ambassador, embargo,
        outpost, sea_hag, treasure_map);
    assertIntEqual(0, initializeGame(2, ks, 2849, g));

    assertIntEqual(-1, playCard(0, -1, -1, -1, g));

    free(g);
    free(ks);

    puts("TEST PASSED");
    return 0;
}
