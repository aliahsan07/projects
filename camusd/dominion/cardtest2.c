#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	struct gameState* testState = newGame();
	int* myKingdomCards = kingdomCards(7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	initializeGame(2, myKingdomCards, 3, testState);
	
	testState->hand[0][0] = village;
	playCard(0, 0, 0, 0, testState);
	
	assert(testState->numActions == 2);
	assert(testState->playedCardCount == 1);
	assert(testState->playedCards[0] == village);
	assert(testState->handCount[0] == 5);
	assert(testState->deckCount[0] == 4);
	assert(testState->discardCount[0] == 0);
	
	endTurn(testState);
	
	assert(testState->discardCount[0] == 6);
	assert(testState->discard[0][0] == village);
	
	return 0;
}