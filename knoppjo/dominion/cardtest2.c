#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define DIE_ON_ASSERT 0


int main () {
	printf("***Testing gardens***\n");
	printf("Testing whether gardens returns -1...\n");
	struct gameState G;
	int k[10] = {village, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo,
			outpost};

	initializeGame(2, k, 3, &G);

	G.handCount[0] = 3;
	G.hand[0][0] = gardens;

	int r = playCard(0, 1, 0, 0, &G);
	assert(r ==  -1);

	printf("Test passes\n");

	//playCard(0, 1, 0, 0, NULL);


}
