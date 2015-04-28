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
	
	assert(testState->handCount[0] == 5);
	assert(testState->deckCount[0] == 5);
	assert(testState->numActions == 1);
	assert(testState->numBuys == 1);
	assert(testState->coins > 1);
	assert(testState->coins < 6);
	assert(testState->discardCount[0] == 0);
	assert(testState->playedCardCount == 0);
	assert(supplyCount(14, testState) == 10);
	
	buyCard(14, testState);
	
	assert(testState->coins == 0);
	assert(testState->numBuys == 0);
	assert(testState->discardCount[0] == 1);
	assert(supplyCount(14, testState) == 9);
	
	endTurn(testState);
	
	assert(testState->handCount[1] == 5);
	assert(testState->deckCount[1] == 5);
	assert(testState->numActions == 1);
	assert(testState->numBuys == 1);
	assert(testState->coins > 1);
	assert(testState->coins < 6);
	assert(testState->discardCount[1] == 0);
	assert(testState->playedCardCount == 0);
	assert(supplyCount(7, testState) == 10);
	
	buyCard(7, testState);
	
	assert(testState->coins > 1);
	assert(testState->coins < 6);
	assert(testState->numBuys == 1);
	assert(testState->discardCount[1] == 0);
	assert(supplyCount(7, testState) == 10);
	
	return 0;
}