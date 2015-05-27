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

    // Magically put a Remodel and a Silver in our hand.
    assertIntEqual(0, gainCard(remodel, g, 2, 0));
    assertIntEqual(0, gainCard(silver, g, 2, 0));

    // Check that we have the right number of cards.
    assertIntEqual(7, numHandCards(g));
    assertIntEqual(1, fullDeckCount(0, remodel, g));
    assertIntEqual(1, fullDeckCount(0, silver, g));

    // Play the Mine: trash a Silver and gain a Village.
    assertIntEqual(0, playCard(5, 6, village, -1, g));

    // Check that we have the right number of cards.
    assertIntEqual(6, numHandCards(g));
    assertIntEqual(1, fullDeckCount(0, remodel, g));
    assertIntEqual(0, fullDeckCount(0, silver, g));
    assertIntEqual(1, fullDeckCount(0, village, g));

    free(g);
    free(ks);

    puts("TEST PASSED");
    return 0;
}
