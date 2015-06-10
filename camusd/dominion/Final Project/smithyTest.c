#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	struct gameState* testState = newGame();
	int* myKingdomCards = kingdomCards(7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	initializeGame(2, myKingdomCards, 3, testState);
	
	testState->hand[0][0] = smithy;
	playCard(0, 0, 0, 0, testState);
	printf("Begin assert statements\n");
	
	assert(testState->numActions == 0);
	assert(testState->playedCardCount == 1);
	assert(testState->playedCards[0] == smithy);
	assert(testState->handCount[0] == 7);
	assert(testState->deckCount[0] == 2);
	assert(testState->discardCount[0] == 0);
	
	endTurn(testState);
	
	assert(testState->discardCount[0] == 6);
	assert(testState->discard[0][0] == smithy);
	
	printf("Test complete\n");
	
	return 0;
}