/*
 * unittest4.c
 *
 *  Created on: Apr 20, 2015
 *      Author: Elias
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

#define NUMBER_OF_KINDS_OF_CARDS 10
#define MIN_DECK_SIZE 10

int main(int argc, char** argv) {
	
	int player, i, card, numMatches, deckSize;
	struct gameState* state;
	struct gameState* savedState;
		
	player = 0;
	state = newGame();
	savedState = newGame();
	state->deckCount[player] = 0;
	assert(shuffle(player, state) == -1);
	
	for (deckSize = MIN_DECK_SIZE; deckSize < MAX_DECK; deckSize = deckSize + 10) {
		state->deckCount[player] = deckSize;
		
		srand(time(NULL));
		for (i = 0; i < deckSize; i++) {
			card = rand() % NUMBER_OF_KINDS_OF_CARDS;
			state->deck[player][i] = card;
			savedState->deck[player][i] = card;
		}
		
		assert(shuffle(player, state) == 0);
		numMatches = 0;
		for (i = 0; i < deckSize; i++) {
			if (state->deck[player][i] == savedState->deck[player][i])
				numMatches++;
		}
		
		assert(numMatches < deckSize / 2);
		//printf("Number of matches: %i\n", numMatches);
	}
	
	
	free(state);
	
	printf("shuffle() passed all tests\n");
	
	return 1;
}