#include "dominion.h"
#include "rngs.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	struct gameState G;
	int i;

	int k[10] = {adventurer, cutpurse, embargo, gardens, mine, minion, sea_hag, smithy, tribute, village};

	printf("******************************\n");
	printf("\t\t\tCARD TEST 3\t\t\t\n");
	printf("******************************\n");
	printf("Testing gardens card...\n");

	initializeGame(2, k, 2, &G);

	i = cardEffect(gardens, 0, 0, 0, &G, 0, 0);

	assert(i == -1);
	assert(G.numActions == 1);
	assert(numHandCards(&G) == 5);
	assert(G.numBuys == 1);

	printf("Tests passed.\n");
return 0;	
}
