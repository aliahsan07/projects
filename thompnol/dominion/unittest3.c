#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState G;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf ("Drawing Card.\n");

	initializeGame(2, k, 2, &G);

	drawCard(0, &G);
	int d = numHandCards(&G);
	G.deckCount[0] = 0;

	int c = drawCard(0, &G);

	assert(d == 6);
	assert(c == -1);

	return 0;
}