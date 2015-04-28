#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState G;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy};

	initializeGame(2, k, atoi(argv[1]), &G);
	G.handCount[1] = 3;
	G.hand[1][0] = copper;
	G.hand[1][1] = silver;
	G.hand[1][2] = gold;

	int r = updateCoins(1, G, 100);

	assert(r == 0);

	printf("All tests pass");

	return 0;

}




