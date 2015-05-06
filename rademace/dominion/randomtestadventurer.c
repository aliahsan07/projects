/* Assignment  3:

1.	Write a random test generator for two Dominion cards, including the adventurer card.  
	Check these testers in as randomtestcard.c and randomtestadventurer.c.
	
2.	Add rules to the Makefile to produce randomtestcard.out and randomtestadventurer.out.

3.	Write up the development of your random testers, including improvements in coverage 
	and efforts to check the correctness of your specification by breaking the code, 
	as randomhistory.txt. */


/*
 * cardtest4.c
 *
 * Tests for Adventurer card
 *
 * Cost: $6
 * Reveal cards from your deck until you reveal 2 Treasure cards. 
 * Put those Treasure cards in your hand and discard the other revealed cards.
 *
 *
 *  Created on: May 6, 2015
 *      Author: Elias Rademacher
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

#define NUM_TESTS 10000
#define MAX_HAND_COUNT 15
#define MAX_DISCARD_COUNT 50
#define MAX_DECK_COUNT 50

int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

int main(int argc, char** argv) {
	
	struct gameState* state = newGame();
	int card, ret_val, currentPlayer, verbose;
	int initialNumActions, initialHandCount, initialNumBuys, initialCoins, test;
	int initialDiscardCount, initialDeckCount, empty, initialPlayedCardCount, initialtreasureCardsDeck, treasureCardsDeck, curCard;
	
	verbose = 0; /* Set verbose to 1 to see final and initial values */
	empty = -523; /* This number indicates that a spot in an array does not have a card */
	currentPlayer = 0;
	srand(time(NULL));
	
	/* Don't test the case where both your deck and discard pile are empty.
	That's an improbable scenario, and there are no safety features built into
	the game to check for this. */
	for (test = 0; test < NUM_TESTS; test++) {	
		
		initialDeckCount = 10 + rand() % (MAX_DECK_COUNT - 9);
		initialHandCount = 1 + rand() % MAX_HAND_COUNT;
		initialDiscardCount = rand() % MAX_DISCARD_COUNT;
		initialNumActions = rand() % 10;
		initialNumBuys = rand() % 5;
		initialPlayedCardCount = rand() % 5;
		initialCoins = rand() % 8;
		
		state->numPlayers = MAX_PLAYERS - (rand() % 2);
		state->deckCount[currentPlayer] = initialDeckCount;
		state->handCount[currentPlayer] = initialHandCount;
		state->discardCount[currentPlayer] = initialDiscardCount;
		state->numActions = initialNumActions;
		state->numBuys = initialNumBuys;
		state->playedCardCount = initialPlayedCardCount;
		state->coins = initialCoins;
		
		
		/* Put some cards in hand */
		for (card = 0; card < MAX_HAND; card++) {
			state->hand[currentPlayer][card] = empty;
		}
		
		if (verbose) printf("hand: ");
		for (card = 0; card < state->handCount[currentPlayer]; card++) {
			state->hand[currentPlayer][card] = 0;
			if (verbose) printf("%d ", state->hand[currentPlayer][card]);
		}
		if (verbose) printf("\n");
		
		/* initialize deck and discard pile to empty */
		for (card = 0; card < MAX_DECK; card++) {
			state->discard[currentPlayer][card] = empty;
			state->deck[currentPlayer][card] = empty;
		}
		
		/* Put some cards in discard pile */
		for (card = 0; card < state->discardCount[currentPlayer]; card++) {
			state->discard[currentPlayer][card] = 0;
		}
		
		
		/* Put some cards in deck. Make sure there are at least 2 treasure cards. */
		initialtreasureCardsDeck = 2;		
		state->deck[currentPlayer][0] = copper;
		state->deck[currentPlayer][1] = copper;
		
		for (card = 2; card < state->deckCount[currentPlayer]; card++) {
			curCard = rand() % 7;
			if (curCard < 7 && curCard > 3)
				initialtreasureCardsDeck++;
			state->deck[currentPlayer][card] = curCard;
		}
		
		
		if (verbose)
			printf("calling cardEffect()...\n");
		ret_val = cardEffect(adventurer, 0, 0, 0, state, 2, NULL);
		
		if (verbose) {
			printf("hand: ");
			for (card = 0; card < state->handCount[currentPlayer]; card++) {
				printf("%d ", state->hand[currentPlayer][card]);
			}
			printf("\n");
		}
		
		treasureCardsDeck = 0;
		for (card = 0; card < state->deckCount[currentPlayer]; card++) {
			curCard = state->deck[currentPlayer][card];
			if (curCard < 7 && curCard > 3)
				treasureCardsDeck++;		
		}
		
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
			printf("state->discardCount[currentPlayer]: %d\n", state->discardCount[currentPlayer]);
			printf("initialPlayedCardCount: %d\n", initialPlayedCardCount);
			printf("state->playedCardCount: %d\n", state->playedCardCount);
			printf("initialtreasureCardsDeck: %d\n", initialtreasureCardsDeck);
			printf("treasureCardsDeck: %d\n\n", treasureCardsDeck);
		}
	
		assert(0 == ret_val);
		assert(treasureCardsDeck == initialtreasureCardsDeck - 2);
		assert(initialNumActions == state->numActions);
		assert(initialNumBuys == state->numBuys);	
		assert(state->deckCount[currentPlayer] < initialDeckCount - 1);
		assert(state->handCount[currentPlayer] == initialHandCount + 2);
		assert(!(state->discardCount[currentPlayer] < initialDiscardCount));
		
		
	}
	
	printf("Adventurer card passed all tests\n");
	
	return 1;
}
