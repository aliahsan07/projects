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
        outpost, remodel, village);
    assertIntEqual(0, initializeGame(2, ks, 2849, g));

    // Magically put three Villages in our hand.
    assertIntEqual(0, gainCard(village, g, 2, 0));
    assertIntEqual(0, gainCard(village, g, 2, 0));
    assertIntEqual(0, gainCard(village, g, 2, 0));

    // Check that we have the right number of cards.
    assertIntEqual(8, numHandCards(g));
    assertIntEqual(3, fullDeckCount(0, village, g));

    // Play all three Villages.
    assertIntEqual(0, playCard(5, -1, -1, -1, g));
    assertIntEqual(0, playCard(6, -1, -1, -1, g));
    assertIntEqual(0, playCard(7, -1, -1, -1, g));

    // Check that we have the right number of cards.
    assertIntEqual(8, numHandCards(g));
    assertIntEqual(0, fullDeckCount(0, village, g));

    free(g);
    free(ks);

    puts("TEST PASSED");
    return 0;
}
