/*
 * cardtest3.c
 *
 * Test of steward
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
    int kCards[10] = {steward, mine, gardens, feast, adventurer, village, baron,
            remodel, tribute, ambassador};
    struct gameState *aGame = newGame();
    initializeGame(2, kCards, 42, aGame);
    aGame->deckCount[0] = 5;    // force player0 to have a deck of 5 cards.
    aGame->hand[0][0] = steward;// give player0 a village card in handPos 0
    aGame->coins = 2;           // override the default of 0.

    // Test 1, choice1 = 1, +2 cards, coins same
    int num_cards = aGame->handCount[0] - 1; // -1 b/c steward  is discarded
    int coins = aGame->coins;
    cardEffect(steward, 1, 0, 0, aGame, 0, 0);

    printf("Test 1A: player0 has two more cards...");
    assert((num_cards + 2) == aGame->handCount[0]);
    printf("passes\n");

    printf("Test 1B: player0 coins unchanged...");
    assert(coins == aGame->coins);
    printf("passes\n");

    // Test 2, choice1 = 2, +2 coins, cards same.
    aGame->deckCount[0] = 5;    // force player0 to have a deck of 5 cards.
    aGame->hand[0][0] = steward;// give player0 a village card in handPos 0
    num_cards = aGame->handCount[0] - 1; // -1 b/c steward  is discarded
    coins = aGame->coins;
    cardEffect(steward, 2, 0, 0, aGame, 0, 0);

    printf("Test 2A: player0 has same number of cards...");
    assert(num_cards == aGame->handCount[0]);
    printf("passes\n");

    printf("Test 2B: player0 two more coins...");
    assert((coins + 2) == aGame->coins);
    printf("passes\n");

    // Test 3 choice1 = third option
    aGame->deckCount[0] = 5;    // force player0 to have a deck of 5 cards.
    aGame->hand[0][0] = steward;// give player0 a village card in handPos 0
    num_cards = aGame->handCount[0] - 1; // -1 b/c steward  is discarded
    coins = aGame->coins;
    cardEffect(steward, 5, 1, 2, aGame, 0, 0);

    printf("Test 3A: player0 has two less cards...");
    assert((num_cards - 2) == aGame->handCount[0]);
    printf("passes\n");

    printf("Test 3B: player0 coins unchanged...");
    assert(coins == aGame->coins);
    printf("passes\n");

    // Test 4 commented out so scripts will run
//    aGame = NULL;
//    printf("Test 4: null game state, invalid state, will seg fault\n");
//    cardEffect(steward, 0, 0, 0, aGame, 0, 0);

	return 0;
}
