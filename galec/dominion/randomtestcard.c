#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//Cooper Random Village Test

int main() {

	struct gameState state;
	
	int y[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, feast, smithy};

	printf ("randomtestvillage\n");

	int i, players, player, handCount, deckCount, numBuys, numActions, seed;

	for (i = 0; i < 10; i++) {
	
		//get random setup and initialize
		players = rand() % 4;
		seed = rand();		
		initializeGame(players, y, seed, &state);

		//Initiate valid state variables
		state.deckCount[player] = rand() % MAX_DECK;
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_HAND;


		//Copy state variables
		handCount = state.handCount[player];
		deckCount = state.deckCount[player];
		numBuys = state.numBuys;
		numActions = state.numActions;
		
		//attempt to increase coverage
		if (seed % 5 == 0) {
			state.deckCount[player] = 0;
		}


		cardEffect(village, 0, 0, 0, &state, 0, 0);//Run village card
		
		//check for errors
		if (state.handCount[player]!= handCount) {
			printf ("village error: handsize\n");
			
		}
		if (state.numBuys != numBuys) {
			printf ("village error: number of buys\n");
			
		}
		if (state.numActions!= numActions + 2) {
			printf ("village error: number of actions\n");
			
		}
	
		
	  }
	  


	  printf("Tests Complete\n");

	  return 0;
}
