#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1000

//This randomly tests Adventurer

int main() {

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy};

	int i, r, players, player, handCount, deckCount, discardCount, seed, numAction;
	int failedTests = 0;
	struct gameState* G = newGame();

	printf("***Running Random Village Test***\n");

	for (i = 0; i < MAX_TESTS; i++) {

		printf("*Test %d*\n", i);
		players = 2 + (rand() % 3); //Set players between 2 and 4
		printf("players is %d\n", players);

		player = rand() % players;

		seed = rand();		//pick random seed

		int r = initializeGame(players, k, seed, G);	//initialize Gamestate
		assert(r == 0);
		G->whoseTurn = player;

		//Initiate valid state variables
		G->deckCount[player] = 10 + (rand() % 490); //Pick random deck size out of MAX DECK size
		deckCount = G->deckCount[player];
		printf("deckCount is %d\n", deckCount);

		G->discardCount[player] = rand() % (deckCount);
		discardCount = G->discardCount[player];
		printf("discardCount is %d\n", discardCount);

		G->handCount[player] = rand() % MAX_HAND;
		handCount = G->handCount[player];
		printf("handCount is %d\n", handCount);
		numAction = G->numActions;


		r = cardEffect(village, 0, 0, 0, G, 0, 0);		//Run village card

		if(r != 0){
			failedTests++;
			printf("FAILED: cardEffect returned improper value");
		}

		if( handCount != G->handCount[player]){
			failedTests++;
			printf("FAILED: player did not draw a card and then discard one\n");
		}

		if( numAction + 2 != G->numActions ){
			failedTests++;
			printf("FAILED: numActions was not incremented by 1 after playCard\n");
		}

		else{
			printf("PASSED\n");
		}

	}


	printf("***Tests Complete: %d total failures***\n", failedTests);

	return 0;
}
