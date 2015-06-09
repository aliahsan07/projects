/*
 * part3_adventurer.c
 *
 * Test of adventure.
 *
 * Overflow at the end of discard[MAX_PLAYERS][MAX_DECK] overwrites values
 * in discardCount[MAX_PLAYERS];
 *
 *  Created on: Jun 8, 2015
 *      Author: martich2
 */

#include <stdio.h>
#include <assert.h>
#include "dominion_helpers.h"
#include "dominion.h"

int main(int argc, char** argv)
{
    /* make a new game */
    int kCards[10] = {smithy, mine, gardens, feast, adventurer, village, baron,
            remodel, tribute, ambassador};
    struct gameState *aGame = newGame();
    initializeGame(2, kCards, 42, aGame);

    //set up game state
    aGame->discardCount[0] = 42; // THESE VALUE WILL BE OVERWRITEN BY CARDEFFECT
    aGame->discardCount[1] = 42;
    aGame->discardCount[2] = 42;
    // change this value to see where overflow occurred
    aGame->discardCount[3] = MAX_DECK;

    aGame->deckCount[3] = 5;
    aGame->deck[3][4] = smithy;
    aGame->deck[3][3] = mine;
    aGame->deck[3][2] = gold;
    aGame->deck[3][1] = gold;
    aGame->deck[3][0] = village;

    aGame->whoseTurn = 3;

    cardEffect(adventurer,-1,-1,-1, aGame, 0, 0);
    printf("discardCount[0] is %d, but should be 42!\n", aGame->discardCount[0]);
    printf("discardCount[0] is %d, but should be 42!\n", aGame->discardCount[1]);
    printf("discardCount[0] is %d, but should be 42!\n", aGame->discardCount[2]);

	return 0;
}
