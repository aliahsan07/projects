#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	int i;
	struct gameState* testState = newGame();
	int* myKingdomCards = kingdomCards(7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	initializeGame(2, myKingdomCards, 3, testState);
	
	for(i = 0; i < 5; i++) {
		testState->hand[0][i] = i;
	}	
	
	int card = testState->hand[0][0];
	
	assert(testState->handCount[0] == 5);
	assert(testState->playedCardCount == 0);
	assert(testState->hand[0][0] == card);
	assert(testState->hand[0][1] != card);
	assert(testState->hand[0][2] != card);
	assert(testState->hand[0][3] != card);
	assert(testState->hand[0][4] != card);
	
	discardCard(0, 0, testState, 0);
	
	assert(testState->handCount[0] == 4);
	assert(testState->playedCardCount == 1);
	assert(testState->playedCards[0] == card);
	assert(testState->hand[0][0] != card);
	assert(testState->hand[0][1] != card);
	assert(testState->hand[0][2] != card);
	assert(testState->hand[0][3] != card);

	return 0;
}