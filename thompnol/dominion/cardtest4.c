#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState G;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf ("Embargo.\n");

	initializeGame(2, k, 2, &G);

	G.coins = 0;
	int val = embargo_ref(0, &G, 0, 0);

	assert(val == 0);
	assert(G.coins == 2);

	return 0;
}