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

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};

	struct gameState* G = newGame();
	
	printf("***** Starting Random Test for Village *****\n\n");

	for (i = 0; i < MAX_TESTS; i++) {
		
		printf("*** Test %d ***\n", i + 1);
		numPlayers = 2 + (rand() % 3);

		currPlayer = rand() % numPlayers;
		seed = rand();

		j = initializeGame(numPlayers, k, seed, G);
		assert(j == 0);
		G->whoseTurn = currPlayer;

		G->deckCount[currPlayer] = 10 + (rand() % MAX_DECK);
		deckCount = G->deckCount[currPlayer];

		G->discardCount[currPlayer] = rand() % (deckCount);
		discardCount = G->discardCount[currPlayer];

		G->handCount[currPlayer] = rand() % MAX_HAND;
		handCount = G->handCount[currPlayer];
		numAction = G->numActions;

		j = cardEffect(village, 1, 1, 1, G, 0, 0);

		//Increase fails
		if (j != 0){
			fails++;
			printf("cardEffect has returned wrong value!\n");
		}

		if (handCount != G->handCount[currPlayer]){
			fails++;
			printf("Current player did not discard and draw.\n");
		}

		if (numAction + 2 != G->numActions) {
			fails++;
			printf("numActions did not increase by 1.\n");
		}

		else {
			printf("Pass\n");
		}

	}
	printf("***** Test Conplete: %d/%d fails! *****\n\n\n", fails,MAX_TESTS);

return 0;
}
