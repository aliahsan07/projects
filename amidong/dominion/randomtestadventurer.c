#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 100

int main() {

	struct gameState state;
	
	int y[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, great_hall, feast, smithy};

	printf ("Test Adventurer\n");

	int i, players, player,handCount, deckCount, discardCount, seed;

	for (i = 0; i < MAX_TESTS; i++) {
		players = rand() % 4;
		seed = rand();		
		initializeGame(players, y, seed, &state);
		state.deckCount[player] = rand() % MAX_DECK;
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_HAND;
		//hold values to test before adventurer is called
		handCount = state.handCount[player];
		deckCount = state.deckCount[player];
		discardCount = state.discardCount[player];
		if (seed % 5 == 0) {
			state.deckCount[player] = 0;
		}
		cardEffect(adventurer, 1, 1, 1, &state);
		printf("State: %d\n", state.handCount[player]);
		printf("Hand Count: %d\n", handCount);
		if (state.handCount[player]!= handCount + 2) {
			printf("---------------------------------------------\n");
			printf ("Hand Size Does not match:\n State says: %d\n handCount says: %d\n", state.handCount[player], handCount);
			printf("---------------------------------------------\n");
			
		}
		if ((state.deckCount[player] > deckCount) && discardCount > (state.discardCount[player])){
			printf ("Discard does not match\n");
		}
	  }
	  return 0;
}