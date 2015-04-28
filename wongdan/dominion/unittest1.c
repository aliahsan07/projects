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
	int i, x;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	printf("*****************************************\n");
	printf("\t\t\tUNIT TEST 1\t\t\t\n");
	printf("*****************************************\n");

	printf("\nStarting test for supplyCount...\n");

	x = initializeGame(2, k, randomSeed, &G);
	
	assert(x == 0);

	for (i = 0; i < 27; i++) {
		assert(G.supplyCount[i] == supplyCount(i, &G));	
	}


	printf("\nTests passed.\n");

return 0;
}
