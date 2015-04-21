/*
 * unittest4.c
 *
 *  Created on: Apr 20, 2015
 *      Author: Elias
 */

#include <stdlib.h>
#include <time.h>
#include "assert.h"
#include "dominion.h"
#include "dominion.c"
#include "rngs.h"
#include "rngs.c"


int main(int argc, char argv[]) {
	
	int player, i, card, numMatches, deckSize;
	struct gameState* state;
	struct gameState* savedState;
		
	player = 0;
	state = newGame();
	savedState = newGame();
	state->deckCount[player] = 0;
	assert(shuffle(player, state) == -1);
	
	for (deckSize = 10; deckSize < MAX_DECK; deckSize = deckSize + 10) {
		state->deckCount[player] = deckSize;
		
		srand(time(NULL));
		for (i = 0; i < deckSize; i++) {
			card = rand() % 10;
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