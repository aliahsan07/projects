#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState G;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf ("Gardens.\n");

	initializeGame(2, k, 2, &G);

	assert(cardEffect(gardens, 0, 0, 0 , &G, 0, 0) == -1);

	return 0;
}