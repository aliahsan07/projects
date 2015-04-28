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
		testState->hand[0][i] = (i + 5);
	}
	
	int card = testState->deck[0][testState->deckCount[0] - 1];
	
	assert(testState->handCount[0] == 5);
	assert(testState->deckCount[0] == 5);
	
	drawCard(0, testState);
	
	assert(testState->handCount[0] == 6);
	assert(testState->deckCount[0] == 4);
	assert(testState->hand[0][5] == card);
	
	testState = newGame();
	initializeGame(2, myKingdomCards, 3, testState);
	
	
	for(i = 0; i < 5; i++) {
		testState->discard[0][i] = i;
		testState->hand[0][i] = i + 5;
		testState->deck[0][i] = i + 10;
	}
	
	testState->discardCount[0] = 5;
	
	for(i = 0; i < 5; i++) {
		drawCard(0, testState);
	}
	
	assert(testState->deckCount[0] == 0);
	assert(testState->handCount[0] == 10);
	
	drawCard(0, testState);
	
	assert(testState->deckCount[0] == 4);
	assert(testState->discardCount[0] == 0);
	assert(testState->handCount[0] == 11);
	
	for(i = 0; i < 4; i++) {
		assert(testState->deck[0][i] < 5);
	}
	
	assert(testState->hand[0][testState->handCount[0] - 1] < 5);
	
	return 0;
}