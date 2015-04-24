/*
 * cardtest4.c
 *
 * Tests for Cutpurse card
 *
 * Cost: $4; 	+$2
 * Each other player discards a Copper card 
 * (or reveals a hand with no Copper).
 *
 *
 *  Created on: Apr 20, 2015
 *      Author: Elias
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

int main(int argc, char** argv) {
	
	struct gameState* state = newGame();
	int card, choice1, choice2, choice3, handPos, ret_val, currentPlayer, verbose;
	int i, j, initialNumActions, initialHandCount, initialNumBuys, initialCoins;
	int initialDiscardCount, initialDeckCount, empty;
	int initialPlayedCardCount, money, player, curCard;
	int* bonus;
	enum CARD cutpurseCard;
	enum CARD copperCard;
	
	verbose = 0; /* Set verbose to 1 to see final and initial values */
	empty = -523; /* This number indicates that a spot in an array does not have a card */
	handPos = 2;
	currentPlayer = 0;
	initialCoins = 7;
	bonus = NULL;
	cutpurseCard = cutpurse;
	copperCard = copper;
	card = (int) cutpurseCard;
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
		for (initialHandCount = 1; initialHandCount < 20; initialHandCount += 2) {
			for (initialDiscardCount = 0; initialDiscardCount < 100; initialDiscardCount += 20) {
				
				/* "money" is a Boolean that indicates 
				whether or not players' hands are filled with copper */ 
				money = rand() % 2;
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
				for (j = 0; j < MAX_PLAYERS; j++) {
					for (i = 0; i < MAX_HAND; i++) {
						state->hand[j][i] = empty;
					}
					
					for (i = 0; i < state->handCount[j]; i++) {
						state->hand[j][i] = money * copperCard;
						if (verbose) printf("%d ", state->hand[j][i]);
					}
					if (verbose) printf("    ");
				}
				if (verbose) printf("\n");
				
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
					for (j = 0; j < MAX_PLAYERS; j++) {
						for (i = 0; i < state->handCount[j]; i++) {
							printf("%d ", state->hand[j][i]);
						}
						printf("    ");
					}
					printf("\n");
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
					printf("state->playedCardCount: %d\n\n", state->playedCardCount);
				}
				
				assert(0 == ret_val);
				assert(initialNumActions == state->numActions);
				assert(initialNumBuys == state->numBuys);
				
				
				// assert(initialPlayedCardCount + state->numPlayers == state->playedCardCount);
				// assert(initialCoins - state->numPlayers == state->coins);

				// for (i = 0; i < MAX_PLAYERS; i++) {
					// if (i == currentPlayer)
						// assert(initialHandCount == state->handCount[i]);
					
					// else
						// assert(initialHandCount == state->handCount[i]);
						
				// }
				
				/* Make sure opponents' purses have been cut!  */
				int copperCount;
				for (player = 0; player < MAX_PLAYERS; player++) {
					
					copperCount = 0;					
					for (curCard = 0; curCard < state->handCount[player]; curCard++) {
						if (state->hand[player][curCard] == copperCard)
							copperCount++;
					}
											
					if (!money) {
						if (copperCount != 0) {
							printf("Test failed: hand corrupted\n");
							goto EXIT;
						}
					}
					
					else if (money && (player != currentPlayer)) {
						/* Other players should have exactly one card that 
						 is not copper */
						if (copperCount != state->handCount[player] - 1) {
							printf("Test failed: Copper not removed from other players' hands\n");
							goto EXIT;
						}
					}
						
					else if (money && (player == currentPlayer)) {
						if (copperCount != state->handCount[player]) {
							printf("Test failed: current player's hand corrupted\n");
							goto EXIT;
						}
					}								
				}

				
				/* Make sure correct number of cards are in discard pile */
				for (i = 0; i < state->discardCount[currentPlayer]; i++) {
					assert(state->discard[currentPlayer][i] != empty);
				}
				
				/* Make sure correct number of cards are in deck */
				for (i = 0; i < state->deckCount[currentPlayer]; i++) {
					assert(state->deck[currentPlayer][i] == 0);
				}			
			}
		}
	}
	
	printf("Cutpurse card passed all tests\n");
	
	EXIT:
	
	return 1;
}

