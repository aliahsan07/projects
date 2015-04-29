#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState G;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf ("IsGameOver.\n");

	initializeGame(2, k, 2, &G);

	int x = isGameOver(&G);

	assert (x == 0);
	return 0;
}