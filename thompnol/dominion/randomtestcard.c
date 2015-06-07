//Nolan Thompson
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "rngs.h"

#define MAX_TESTS 500

//This randomly tests gardens

int main() {

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	int i;
	int players;
	int player;
	int handCount;
	int deckCount;
	int seed;

	//struct gameState state;
	struct gameState state;


	printf("Running Random Card Test for Gardens\n");

	for (i = 0; i < MAX_TESTS; i++) {
		players = rand() % 4;
		seed = rand();		
		initializeGame(players, k, seed, &state);	

		//Initiate valid state variables
		state.deckCount[player] = rand() % MAX_DECK; 
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_HAND;

		//Copy state variables
		handCount = state.handCount[player];
		deckCount = state.deckCount[player];

		//Before
		printf("%d A\n", i);
		assert(cardEffect(gardens, 0, 0, 0, &state, 0, 0) == -1);		
		//After Effect
		printf("%d B\n", i);
	}

	printf("Tests Complete\n");
	return 0;
}
