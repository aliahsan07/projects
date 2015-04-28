#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState G;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf ("Whose Turn.\n");

	initializeGame(2, k, 2, &G);

	int j = whoseTurn(&G);
	assert(j == 0);

	endTurn(&G);
	int i = whoseTurn(&G);
	assert (i == 1);

	return 0;
}