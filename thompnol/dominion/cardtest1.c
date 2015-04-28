#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState G;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf ("Village.\n");

	initializeGame(2, k, 2, &G);

	int val = cardEffect(village, 0, 0, 0, &G, 0, 0);

	int d = numHandCards(&G);
	//int a = G.numActions

	assert(val == 0);
	assert(d == 5);
	assert(G.numActions == 3);

	//Bug where village give the player to 3 turns instead of 2 turns.

	return 0;
}
