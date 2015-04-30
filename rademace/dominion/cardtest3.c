/*
 * cardtest3.c
 *
 * Tests for Council Room Card
 *
 * $5; 	+4 Cards; +1 Buy
 * Each other player draws a card.
 *
 *
 *
 *  Created on: Apr 20, 2015
 *      Author: Elias
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

int main(int argc, char** argv) {
	
	struct gameState* state = newGame();
	int card, choice1, choice2, choice3, handPos, ret_val, currentPlayer, verbose;
	int i, initialNumActions, initialHandCount, initialNumBuys, initialCoins;
	int initialDiscardCount, initialDeckCount, empty;
	int initialPlayedCardCount;
	int* bonus;
	enum CARD councilRoomCard;
	char result[50];
	
	verbose = 0; /* Set verbose to 1 to see final and initial values */
	empty = -523; /* This number indicates that a spot in an array does not have a card */
	handPos = 2;
	strcpy(result, "Council Room card passed all tests");
	currentPlayer = 0;
	initialCoins = 7;
	bonus = NULL;
	councilRoomCard = council_room;
	card = (int) councilRoomCard;
	choice1 = 0;
	choice2 = 0;
	choice3 = 0;
	state->numPlayers = MAX_PLAYERS; /* Ideally this value would be varied */
	state->coins = initialCoins;
	srand(time(NULL));
	
	/* Don't test the case where both your deck and discard pile are empty.
	That's an improbable scenario, and there are no safety features built into
	the game to check for this. */
	for (initialDeckCount = 10; initialDeckCount < 100; initialDeckCount += 10) {	
		for (initialHandCount = 2; initialHandCount < 20; initialHandCount += 2) {
			for (initialDiscardCount = 10; initialDiscardCount < 100; initialDiscardCount += 10) {
		
				initialNumActions = (rand() % 10) + 1;
				state->numActions = initialNumActions;
				initialNumBuys = rand() % 5;
				state->numBuys = initialNumBuys;
				initialPlayedCardCount = rand() % 5;
				state->playedCardCount = initialPlayedCardCount;
				state->deckCount[currentPlayer] = initialDeckCount;		
				state->discardCount[currentPlayer] = initialDiscardCount;
				
				for (i = 0; i < MAX_PLAYERS; i++) {
					state->handCount[i] = initialHandCount;
				}
				
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
					printf("state->discardCount[currentPlayer]: %d\n", state->discardCount[currentPlayer]);
					printf("initialPlayedCardCount: %d\n", initialPlayedCardCount);
					printf("state->playedCardCount: %d\n\n", state->playedCardCount);
				}
				
				assert(0 == ret_val);
				assert(initialNumActions == state->numActions);
				assert(initialNumBuys + 1 == state->numBuys);
				assert(initialCoins == state->coins);
				assert(initialPlayedCardCount + 1 == state->playedCardCount);
				
				/* Make sure current player has an extra 4 cards and 
				all other players have 1 extra card in their hand. */
				for (i = 0; i < MAX_PLAYERS; i++) {
					if (i != currentPlayer) {
						if (initialHandCount + 1 != state->handCount[i]) {
							strcpy(result, "Failure: Other players hands not increased by 1");
							goto EXIT;
						}
					}
							
					
					else {
						if(initialHandCount + 4 != state->handCount[i]) {
							strcpy(result, "Failure: Current player's hand not increased by 4");
							goto EXIT;
						}
					}
				}
				
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
	
	EXIT: printf("%s\n", result);
	
	return 1;
}

