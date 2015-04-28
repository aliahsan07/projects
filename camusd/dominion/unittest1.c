#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	int i;
	int j;
	int dif;
	struct gameState* testState = newGame();
	struct gameState* controlState = newGame();
	int* myKingdomCards = kingdomCards(7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	initializeGame(2, myKingdomCards, 3, testState);
	
	for(i = 0; i < 10; i++) {
		controlState->deck[0][i] = i;
		testState->deck[0][i] = i;
	}
	
	dif = 0;
	
	for(i = 0; i < 10; i++) {
		if(controlState->deck[0][i] != testState->deck[0][i]) {
			dif = dif + 1;
		}
	}
	
	assert(dif == 0);
	
	for(j = 0; j < 50; j++) {
		
		dif = 0;
	
		shuffle(0, testState);
	
		for(i = 0; i < 10; i++) {
			if(controlState->deck[0][i] != testState->deck[0][i]) {
				dif++;
			}
		}
	
		assert(dif > 0);
		assert(sizeof(controlState->deck) == sizeof(testState->deck));
	}
	
	return 0;
}

