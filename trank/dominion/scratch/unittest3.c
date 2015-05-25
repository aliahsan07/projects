/******************************************
 * Unit Test 3: fullDeckCount *************
 ******************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main (int argc, char** argv) {

    printf ("******************************************\n");
    printf ("* Unit Test 3: fullDeckCount START *******\n");
    printf ("******************************************\n\n");
    
    int players = 2;
    int randomSeed = 1;
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState Game;
    int currentPlayer = 0;
    
    int r = initializeGame(players, cards, randomSeed, &Game);
    printf ("Initializing game...\n");
    printf ("(Expecting 0)\n");
    printf ("initializeGame(2, cards, 1, &Game) = %d\n\n", r);
    assert(r == 0);

    r = fullDeckCount(currentPlayer, smithy, &Game);
    printf ("Re-counting smithy cards in currentPlayer's hand, deck, and discard pile...\n");
    printf ("(Expecting 0)\n");
    printf ("fullDeckCount(currentPlayer, smithy, &Game) = %d\n\n", r);
    assert(r == 0);

    printf ("******************************************\n");
    printf ("* Unit Test 3: fullDeckCount PASSED ******\n");
    printf ("******************************************\n\n");

    return 0;
}
