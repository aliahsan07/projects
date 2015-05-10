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

	int i, j, z, numDiscarded, r, drawntreasure, cardDrawn, players, player, handCount, deckCount, discardCount, seed;
	int failedTests = 0;
	struct gameState* G = newGame();

	printf("Running Random Adventurer Test\n");

	for (z = 0; z < MAX_TESTS; z++) {

		printf("***Test %d***\n", z);
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
		for(i = 0; i < deckCount; i++){
			G->deck[player][i] = rand() % (treasure_map - 1);
		}

		G->discardCount[player] = rand() % (deckCount);
		discardCount = G->discardCount[player];
		printf("discardCount is %d\n", discardCount);
		for(i = 0; i < discardCount; i++){
			G->discard[player][i] = rand() % (treasure_map - 1);
		}

		G->handCount[player] = rand() % MAX_HAND;
		handCount = G->handCount[player];
		printf("handCount is %d\n", handCount);
		for(i = 0; i < handCount; i++){
			G->hand[player][i] = rand() % (treasure_map - 1);
		}


		r = cardEffect(adventurer, 0, 0, 0, G, 0, 0);		//Run adventurer card

		int treasure1 = G->hand[player][handCount];
		int treasure2 = G->hand[player][handCount+1];

		if(r != 0){
			failedTests++;
			printf("FAILED: cardEffect returned improper value\n");
		}

		else if(G->handCount[player] != handCount + 2){
			failedTests++;
			printf("FAILED: treasures not added\n");
		}


		else{
			printf("PASSED\n");
		}
	}


	printf("***Tests Complete: %d total failures***\n", failedTests);

	return 0;
}
