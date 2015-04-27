/*
 * cardtest4.c
 *
 * Test of outpost
 *
 *  Created on: Apr 27, 2015
 *      Author: martich2
 */

#include <stdio.h>
#include <assert.h>
#include "dominion_helpers.h"
#include "dominion.h"

int main(int argc, char** argv)
{
    /* make a new game */
    int kCards[10] = {outpost, mine, gardens, feast, adventurer, village, baron,
            remodel, tribute, ambassador};
    struct gameState *aGame = newGame();
    initializeGame(2, kCards, 42, aGame);
    aGame->deckCount[0] = 5;    // force player0 to have a deck of 5 cards.
    aGame->hand[0][0] = outpost;// give player0 a village card in handPos 0
    aGame->outpostPlayed = 1;           // override the default of 0.

    // Test 1, +1 outpost, -1 card
    int outpost_played = aGame->outpostPlayed;
    int num_cards = aGame->handCount[0];    // checking for discard, don't -1
    cardEffect(outpost, 0, 0, 0, aGame, 0, 0);

    printf("Test 1A: one outpost played...");
    assert((outpost_played + 1) == aGame->outpostPlayed);
    printf("passes.\n");

    printf("Test 1B: one card discarded...");
    assert((num_cards - 1) == aGame->handCount[0]);
    printf("passes.\n");

    // Test 2
    aGame = NULL;
    printf("Test 2: null game state, invalid state, will seg fault\n");
    cardEffect(outpost, 0, 0, 0, aGame, 0, 0);

	return 0;
}
