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
	
	testState->hand[0][0] = remodel;
	
	assert(testState->coins == 3);
	assert(testState->handCount[0] == 5);
	
	playCard(0, copper, estate, 0, testState);
	
	assert(testState->coins == 2);
	assert(testState->handCount[0] == 3);
	assert(testState->discardCount[0] == 1);
	assert(testState->discard[0][0] == estate);
	assert(testState->playedCardCount == 1);
	assert(testState->playedCards[0] == remodel);
	
	endTurn(testState);
	
	assert(testState->discardCount[0] == 5);
	assert(testState->discard[0][0] == remodel);
	
	return 0;
}