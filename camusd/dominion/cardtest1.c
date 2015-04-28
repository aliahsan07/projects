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
	
	testState->hand[0][0] = adventurer;
	testState->deck[0][testState->deckCount[0] - 1] = estate;
	playCard(0, 0, 0, 0, testState);
	
	assert(testState->playedCardCount == 1);
	assert(testState->playedCards[0] == adventurer);
	assert(testState->hand[0][testState->handCount[0] - 2] == copper);
	assert(testState->hand[0][testState->handCount[0] - 1] == copper);
	assert(testState->discard[0][0] == estate);
	assert(testState->discardCount[0] == 1);
	assert(testState->handCount[0] == 6);
	
	endTurn(testState);
	
	assert(testState->discardCount[0] == 8);
	assert(testState->discard[0][1] == adventurer);
	
	testState = newGame();
	initializeGame(2, myKingdomCards, 3, testState);
	
	testState->hand[0][0] = adventurer;
	
	for(i = 0; i < 5; i++) {
		testState->discard[0][i] = silver;
	}
	
	testState->discardCount[0] = 5;
	
	for(i = 0; i < 5; i++) {
		drawCard(0, testState);
	}
	
	playCard(0, 0, 0, 0, testState);
	
	assert(testState->hand[0][testState->handCount[0] - 2] == silver);
	assert(testState->hand[0][testState->handCount[0] - 1] == silver);
	assert(testState->handCount[0] == 11);
	assert(testState->discardCount[0] == 0);
	
	endTurn(testState);
	
	assert(testState->discardCount[0] == 12);
	assert(testState->discard[0][0] == adventurer);

	return 0;
}