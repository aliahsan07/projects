#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

#define NUMBER_OF_KINDS_OF_CARDS 12

int drawCard(int player, struct gameState *state);

int main(int argc, char** argv) {
	
	int player, initialDiscardCount, initialDeckCount, i, initialHandSize, verbose;
	verbose = 0;
	struct gameState* state = newGame();
	player = 0;
	srand(time(NULL));
	
	for (initialDiscardCount = 9; initialDiscardCount < MAX_DECK; initialDiscardCount += 50) {
		for (initialDeckCount = 0; initialDeckCount < MAX_DECK; initialDeckCount += 50) {
			for (initialHandSize = 1; initialHandSize < MAX_HAND; initialHandSize += 50) {
				
				state->deckCount[player] = initialDeckCount;
				state->discardCount[player] = initialDiscardCount;
				state->handCount[player] = initialHandSize;
				
				/* Put some random cards in discard pile */
				for (i = 0; i < state->discardCount[player]; i++){
				  state->discard[player][i] = rand() % NUMBER_OF_KINDS_OF_CARDS;
				}
				
				/* Put some random cards in deck */
				for (i = 0; i < state->deckCount[player]; i++){
				  state->deck[player][i] = rand() % NUMBER_OF_KINDS_OF_CARDS;
				}
				
				/* Put some random cards in hand */
				for (i = 0; i < state->handCount[player]; i++){
				  state->hand[player][i] = rand() % NUMBER_OF_KINDS_OF_CARDS;
				}
									
				if (verbose) {
					printf("Number of cards in deck: %i\n", state->deckCount[player]);
					printf("Number of cards in hand: %i\n", state->handCount[player]);
					printf("Number of cards in discard pile: %i\n", state->discardCount[player]);
					printf("Drawing a card...\n");
				}
				
				drawCard(player, state);
				
				if (verbose) {
					printf("Number of cards in deck: %i\n", state->deckCount[player]);
					printf("Number of cards in hand: %i\n", state->handCount[player]);
					printf("Number of cards in discard pile: %i\n\n", state->discardCount[player]);
				}				
				
				if (0 == initialDeckCount) {
					assert(initialDiscardCount - 1 == (state->deckCount[player]));
					assert(0 == state->discardCount[player]);
				}
				
				else {
					assert(initialDeckCount - 1 == state->deckCount[player]);
					assert(initialDiscardCount == state->discardCount[player]);
				}
					
				assert(initialHandSize + 1 == state->handCount[player]);
				
				/* make sure discard pile still contains valid cards */
				for (i = 0; i < state->discardCount[player]; i++){
				  assert(state->discard[player][i] >= 0);
				  assert(state->discard[player][i] < NUMBER_OF_KINDS_OF_CARDS);
				}
				
				/* make sure deck still contains valid cards */
				for (i = 0; i < state->deckCount[player]; i++){
				  assert(state->deck[player][i] >= 0);
				  assert(state->deck[player][i] < NUMBER_OF_KINDS_OF_CARDS);
				}
				
				
				
				/* make sure hand still contains valid cards */
				for (i = 0; i < state->handCount[player]; i++){
				  assert(state->hand[player][i] >= 0);
				  assert(state->hand[player][i] < NUMBER_OF_KINDS_OF_CARDS);
				}
			}
		}
	}
	
	printf("drawCard() passed all tests\n");
	
	return 1;
}

