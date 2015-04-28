#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	struct gameState G;
	int randomSeed = rand();
	int newHand;
	int oldHand;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	printf("*****************************************\n");
	printf("\t\t\tUNIT TEST 1\t\t\t\n");
	printf("*****************************************\n");
	printf("\nStarting test for Adventurer card...\n");

	initializeGame(2, k, randomSeed, &G);

	printf("\nStarting hand count Player:%d\n", G.handCount[0]);
	oldHand = G.handCount[0];

	cardEffect(adventurer, 0, 0, 0, &G, 0 ,0);
	printf("\nEnding hand count player: %d\n", G.handCount[0]);
	newHand = G.handCount[0];

	assert(newHand = oldHand+2);

	printf("\nEnding Test\n");

	printf("\nStarting test for smithy card..\n");

	initializeGame(2, k, randomSeed, &G);
	printf("\nStarting hand count player:%d\n", G.handCount[0]);
	oldHand = G.handCount[0];

	cardEffect(smithy, 0, 0 ,0, &G, 0 ,0);
	printf("\nEnding hand count player:%d\n", G.handCount[0]);
	newHand = G.handCount[0];

	assert(newHand = oldHand+2);	

	printf("\nEnding Test\n");

return 0;
}
