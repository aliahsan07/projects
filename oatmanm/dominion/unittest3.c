#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(){

	printf("Testing fullDeckCount...\n");

	struct gameState G;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, k, 2, &G);
	/*for (int i = 0; i < G.handCount[0]; i++)
		printf("hand = %d\n", G.hand[0][i]);
	for (int i = 0; i < G.deckCount[0]; i++)
		printf("deck = %d\n", G.deck[0][i]);
	for (int i = 0; i < G.discardCount[0]; i++)
		printf("discard = %d\n", G.discard[0][i]);*/
	printf("Testing fullDeckCount after game is initialized.\nEstate count should be 3 and Copper count should be 7.\n");
	int t = fullDeckCount(0, estate, &G);
	printf("Estate count = %d\n", t);
	t = fullDeckCount(0, copper, &G);
	printf("Copper count = %d\n", t);

	printf("Adding more copper to deck and discard pile. New copper count should be at 17.\n");
	for (int i = 0; i < 5; i++){
		G.discard[0][i] = copper;
		G.discardCount[0]++;
	}
	for (int i = 5; i < 10; i++){
		G.deck[0][i] = copper;
		G.deckCount[0]++;
	}
	t = fullDeckCount(0, copper, &G);
	printf("Copper count = %d\n", t);

	printf("Adding smithy to the discard pile. Shouldn't affect copper count.\n");
	for (int i = 5; i < 10; i++){
		G.discard[0][i] = smithy;
	}
	t = fullDeckCount(0, copper, &G);
	printf("Copper count = %d\n", t);

	printf("Adding garbage values throughout the entire hand. New copper count should be 15.\n");
	G.hand[0][2] = "hot_garbage";
	G.deck[0][4] = "cooper";
	G.discard[0][9] = -1;
	t = fullDeckCount(0, copper, &G);
	printf("Copper count = %d\n", t);

	printf("Test finished.\n");

	return 0;
}