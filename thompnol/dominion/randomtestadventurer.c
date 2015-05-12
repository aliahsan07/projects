//Nolan Thompson

#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 25

//This randomly tests Adventurer

int main() {

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	    sea_hag, tribute, smithy};

	int i;
	int players;
	int player;
	int handCount;
	int deckCount;
	int seed;
	struct gameState state;

	printf("Running Random Adventurer Test\n");

	for (i = 0; i < MAX_TESTS; i++) {
		players = rand() % 4;
		seed = rand();		//pick random seed
		initializeGame(players, k, seed, &state);	//initialize Gamestate 

		//Initiate valid state variables
		state.deckCount[player] = rand() % MAX_DECK;
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_HAND;
		handCount = state.handCount[player];
		deckCount = state.deckCount[player];

		//Increase chance of a deck with 0 cards in it
		if (seed % 5 == 0) {
			state.deckCount[player] = 0;
		}
		cardEffect(adventurer, 1, 1, 1, &state, 0, 0);
  	}
	
	printf("Tests Complete\n");
	return 0;
}
