/*
 * cardtest1.c
 *
 * Tests for Village card
 * Cost: $3
 * +1 Card; +2 Actions
 *
 *
 *
 *  Created on: Apr 20, 2015
 *      Author: Elias
 */
 
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include "assert.h"
#include "dominion.h"
#include "dominion.c"
#include "rngs.h"
#include "rngs.c"


int main(int argc, char argv[]) {
		
	int card, choice1, choice2, choice3, handPos, ret_val, currentPlayer, verbose;
	int i, k, j, initialNumActions, initialHandCount, initialNumBuys, initialCoins;
	int initialDiscardCount, initialDeckCount, fd, empty;
	FILE *fp;
	int* bonus;
	struct gameState* state = newGame();
	enum CARD villageCard;
	char buffer[500];
	
	verbose = 0; /* Set verbose to 1 to see final and initial values */
	empty = -523; /* This number indicates that a spot in an array does not have a card */
	handPos = 2;
	initialNumBuys = 0;
	initialCoins = 7;
	villageCard = village;
	card = (int) villageCard;
	choice1 = 0;
	choice2 = 0;
	choice3 = 0;
	state->numPlayers = 4; /* Ideally this value would be varied */
	state->coins = initialCoins;
	state->numBuys = initialNumBuys;
	state->playedCardCount = 0;
	srand(time(NULL));
	
	/* Don't test the case where both your deck and discard pile are empty.
	That's an improbable scenario, and there are no safety features built into
	the game to check for this. */
	for (initialDeckCount = 0; initialDeckCount < 100; initialDeckCount += 10) {	
		for (initialHandCount = 0; initialHandCount < 20; initialHandCount += 2) {
			for (initialDiscardCount = 1; initialDiscardCount < 100; initialDiscardCount += 10) {
		
				initialNumActions = rand() % 10;
				state->numActions = initialNumActions;
				
				state->deckCount[currentPlayer] = initialDeckCount;
				state->handCount[currentPlayer] = initialHandCount;
				state->discardCount[currentPlayer] = initialDiscardCount;
							
				/* Put some cards in hand */
				for (i = 0; i < MAX_HAND; i++) {
					state->hand[currentPlayer][i] = empty;
				}
				
				for (i = 0; i < state->handCount[currentPlayer]; i++) {
					state->hand[currentPlayer][i] = 0;
				}
				
				/* Put some cards in discard pile */
				for (i = 0; i < MAX_DECK; i++) {
					state->discard[currentPlayer][i] = empty;
				}
				
				for (i = 0; i < state->discardCount[currentPlayer]; i++) {
					state->discard[currentPlayer][i] = 0;
				}
				
				/* Put some cards in deck */
				for (i = 0; i < MAX_DECK; i++) {
					state->deck[currentPlayer][i] = empty;
				}
				
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
					printf("state->handCount[currentPlayer]: %d\n", state->handCount[currentPlayer]);
					printf("initialDiscardCount: %d\n", initialDiscardCount);
					printf("state->discardCount[currentPlayer]: %d\n\n", state->discardCount[currentPlayer]);
				}
				
				assert(0 == ret_val);
				assert(initialNumActions + 2 == state->numActions);
				assert(initialHandCount == state->handCount[currentPlayer]);
				assert(initialNumBuys == state->numBuys);
				assert(initialCoins == state->coins);
				//assert(initialDiscardCount + 1 == state->discardCount[currentPlayer]);
				
				/* Make sure correct number of cards are in hand */
				for (i = 0; i < state->handCount[currentPlayer]; i++) {
					assert(state->hand[currentPlayer][i] == 0);
				}
				
				/* Make sure correct number of cards are in discard pile */
				for (i = 0; i < state->discardCount[currentPlayer]; i++) {
					assert(state->discard[currentPlayer][i] == 0);
				}
				
				/* Make sure correct number of cards are in deck */
				for (i = 0; i < state->deckCount[currentPlayer]; i++) {
					assert(state->deck[currentPlayer][i] == 0);
				}			
			}
		}
	}
	
	printf("Village card passed all tests\n");
	
	return 1;
}

