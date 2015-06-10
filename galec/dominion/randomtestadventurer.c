#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//Cooper Random Adventure Test

int main() {

	struct gameState state;
	
	int y[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, feast, smithy};

	printf ("randomtestadventurer\n");

	int i, players, player,handCount, deckCount, discardCount, seed;

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
		discardCount = state.discardCount[player];

		//attempt to increase coverage
		if (seed % 5 == 0) {
			state.deckCount[player] = 0;
		}



		cardEffect(adventurer, 1, 1, 1, &state);//Run adventurer card
		
		//check for errors
		if (state.handCount[player]!= handCount + 1) {
			printf ("adventurer error: handsize\n");
			
		}
		if ((state.deckCount[player] > deckCount) && discardCount > (state.discardCount[player])){
			printf ("adventurer error: deck/discard counting");
		}
		

		
	  }
	  


	  printf("Tests Complete\n");

	  return 0;
}
