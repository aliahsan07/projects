#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag);

int main(int argc, char** argv) {
	
	struct gameState *state;
	int handPos, currentPlayer, trashFlag, initialHandCount, initialDiscardCount;
	int initialDeckCount;
	
	currentPlayer = 0;
	trashFlag = 0;
	handPos = 0;
	initialHandCount = 5;
	initialDiscardCount = 20;
	initialDeckCount = 10;
	state = newGame();
	state->discardCount[currentPlayer] = initialDiscardCount;
	state->handCount[currentPlayer] = initialHandCount;
	state->deckCount[currentPlayer] = initialDeckCount;
	assert(0 == discardCard(handPos, currentPlayer, state, trashFlag));
	assert(state->handCount[currentPlayer] == initialHandCount - 1);
	assert(state->deckCount[currentPlayer] == initialDeckCount);
	
	if (state->discardCount[currentPlayer] == initialDiscardCount + 1)
		printf("discardCard() passed all tests\n");
	
	else
		printf("discardCard() failed to add card to discard pile\n");
	
	return 1;
}

