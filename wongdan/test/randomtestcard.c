#include "dominion.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_TESTS 20

int main() {
	
	int i, j, numPlayers, currPlayer, handCount, deckCount, discardCount, seed, numAction;
	int fails = 0;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	struct gameState state;
	
	printf("Starting Test for Village");

	for (i = 0; i < MAX_TESTS; i++) {
		printf("*** Test %d ***\n", (i + 1));
		numPlayers = 2 +(rand() % 3);

		currPlayer = rand() % numPlayers;
		seed = rand();

		j = initializeGame(numPlayers, k, seed, &state);
		assert(j == 0);
		state.whoseTurn = currPlayer;

		state.deckCount[currPlayer] = (rand() % MAX_DECK);
		state.discardCount[currPlayer] =(rand() % MAX_DECK);
		state.handCount[currPlayer] = (rand() % MAX_HAND);

		if (seed % 3 == 0) {
			state.deckCount[currPlayer] = 0;
		}

		discardCount = state.handCount[currPlayer];
		deckCount = state.deckCount[currPlayer];
		handCount = state.handCount[currPlayer];
		numAction = state.numActions;

		printf("Cards discarded: %d\n", discardCount);
		printf("Cards in deck: %d\n", deckCount);
		printf("Cards in hand: %d\n", handCount);
		printf("Actions left: %d\n", numAction);

		j = cardEffect(village, 0, 0, 0, &state, 0, 0);

		if (j != 0) {
			fails++;
			printf("cardEffect has return wrong value!\n");	
		}

		if (handCount != state.handCount[currPlayer]){
			fails++;
			printf("currPlayer did not discard and draw!\n");
		}

		if ((numAction + 2) != state.numActions) {
			fails++;
			printf("numActions did not increase by 1!\n");
		}

		else {
			printf("Pass!\n");
		}

	}
	printf("***** Test Complete! %d/%d tests fail! *****\n\n\n", fails,MAX_TESTS);

return 0;	
}
