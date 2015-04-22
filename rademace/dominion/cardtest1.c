/*
 * cardtest1.c
 *
 *  Created on: Apr 20, 2015
 *      Author: Elias
 */
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "dominion.c"
#include "rngs.h"
#include "rngs.c"

int main(int argc, char argv[]) {
	
	int card, choice1, choice2, choice3, handPos, ret_val, currentPlayer, verbose;
	int i, k, j, initialNumActions, initialHandCount, initialNumBuys, initialCoins;
	int initialDiscardCount;
	int* bonus;
	struct gameState* state = newGame();
	enum CARD villageCard;
	handPos = 2;

	verbose = 0; /* Set verbose to 1 to see final and initial values */
	initialNumActions = 1;
	initialHandCount = 5;
	initialNumBuys = 0;
	initialDiscardCount = 10;
	initialCoins = 7;
	villageCard = village;
	card = (int) villageCard;
	choice1 = 0;
	choice2 = 0;
	choice3 = 0;
	currentPlayer = 0;
	state->numPlayers = 2;
	state->supplyCount[treasure_map+1] = 0;
	state->embargoTokens[treasure_map+1] = 0;
	state->outpostPlayed = 0;
	state->outpostTurn = 0;
	state->whoseTurn = 0;
	state->coins = initialCoins;
	state->numBuys = initialNumBuys;
	state->playedCardCount = 0;
	state->deckCount[currentPlayer] = 10;
	state->discardCount[currentPlayer] = initialDiscardCount;
	
	
	for (initialNumActions = 0; initialNumActions < 50; initialNumActions += 5) {
		for (initialHandCount = 0; initialHandCount < MAX_HAND; initialHandCount += 50) {
	
			state->handCount[currentPlayer] = initialHandCount;
			state->numActions = initialNumActions;
			
			/* Put some cards in hand */
			for (i = 0; i < MAX_HAND; i++) {
				state->hand[currentPlayer][i] = -523;
			}
			
			for (i = 0; i < state->handCount[currentPlayer]; i++) {
				state->hand[currentPlayer][i] = 0;
			}
			
			/* Put some cards in discard pile */
			for (i = 0; i < MAX_DECK; i++) {
				state->discard[currentPlayer][i] = -523;
			}
			
			for (i = 0; i < state->discardCount[currentPlayer]; i++) {
				state->discard[currentPlayer][i] = 0;
			}
			
			/* Put some cards in deck */
			for (i = 0; i < state->deckCount[currentPlayer]; i++) {
				state->deck[currentPlayer][i] = 0;
			}
			
			if (verbose)
				printf("calling cardEffect()...\n");
			ret_val = cardEffect(card, 
						choice1, 
						choice2, 
						choice3,
						state,
						handPos, 
						bonus);
			
			if (verbose) {
				printf("initialNumBuys: %d\n", initialNumBuys);
				printf("state->numBuys: %d\n", state->numBuys);
				printf("initialCoins: %d\n", initialCoins);
				printf("state->coins: %d\n", state->coins);
				printf("initialNumActions: %d\n", initialNumActions);
				printf("state->numActions: %d\n", state->numActions);
				printf("initialHandCount: %d\n", initialHandCount);
				printf("state->handCount[currentPlayer]: %d\n\n", state->handCount[currentPlayer]);
				printf("initialDiscardCount: %d\n", initialDiscardCount);
				printf("state->discardCount[currentPlayer]: %d\n\n", state->discardCount[currentPlayer]);
			}
			
			assert(0 == ret_val);
			assert(initialNumActions + 2 == state->numActions);
			assert(initialHandCount == state->handCount[currentPlayer]);
			assert(initialNumBuys == state->numBuys);
			assert(initialCoins == state->coins);
			//assert(initialDiscardCount + 1 == state->discardCount[currentPlayer]);
		}
	}
	
	
	printf("Village card passed all tests\n");
	
	return 1;
}

