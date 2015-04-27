/*
 * cardtest1.c
 *
 * Test of smithy
 *
 *  Created on: Apr 25, 2015
 *      Author: martich2
 */

#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main(int argc, char** argv)
{
    /* Make a  new game */
    int kCards[10] = {smithy, mine, gardens, feast, adventurer, village, baron,
	        remodel, tribute, ambassador};
	struct gameState *aGame = newGame();
    initializeGame(2, kCards, 42,aGame);
    aGame->deckCount[0] = 5; // force player0 to have a deck of 5 cards.
    aGame->hand[0][0] = smithy; // give player0 a smithy in handPos 0

    // Test 1
    int num_cards = aGame->handCount[0] - 1; // -1 b/c smithy is discarded
    cardEffect(smithy, 0, 0, 0, aGame, 0, 0);

    printf("Test 1: player0 has three more cards now...");
    assert((num_cards + 3) == aGame->handCount[0]);
    printf("passes.\n");

    // Test 2 commented out so scripts will run
//    aGame = NULL;
//    printf("Test 2: null game state, invalid state, will seg fault\n");
//    cardEffect(smithy, 0, 0, 0, aGame, 0, 0);


	return 0;
}
