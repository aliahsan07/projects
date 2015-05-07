/*
 * cardtest2.c
 *
 * Test of village
 *
 *  Created on: Apr 26, 2015
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
    aGame->deckCount[0] = 5; // force player0 to have a deck of 5 cards.
    aGame->hand[0][0] = village; // give player0 a village card in handPos 0

    // Test 1, +1 card, +2 action
    int num_cards = aGame->handCount[0] - 1; // -1 b/c village is discarded
    int num_actions = aGame->numActions; // Test 1B
    cardEffect(village, 0, 0, 0, aGame, 0, 0);

    printf("Test 1A: player0 has one more card now...");
    assert((num_cards + 1) == aGame->handCount[0]);
    printf("passes.\n");

    printf("Test 1B: player0 has two more actions now...");
    assert((num_actions +2) == aGame->numActions);
    printf("passes.\n");

    // Test 2
    aGame->deckCount[1] = 5; // force player1 to have a deck of 5 cards.
    aGame->hand[1][0] = village; // give player1 a village card in handPos 0
    aGame->whoseTurn = 1;       // set current player to player1

    num_cards = aGame->handCount[1] - 1; // -1 b/c village is discarded
    num_actions = aGame->numActions; // Test 2B
    cardEffect(village, 0, 0, 0, aGame, 0, 0);

    printf("Test 2A: player1 has one more card now...");
    assert((num_cards + 1) == aGame->handCount[1]);
    printf("passes.\n");

    printf("Test 2B: player1 has two more actions now...");
    assert((num_actions +2) == aGame->numActions);
    printf("passes.\n");

    // Test 3 commented out so scripts will run
//    aGame = NULL;
//    printf("Test 3: null game state, invalid state, will seg fault\n");
//    cardEffect(village, 0, 0, 0, aGame, 0, 0);

	return 0;
}
