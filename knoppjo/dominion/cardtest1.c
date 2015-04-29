#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int main () {
	printf("***Testing outpost***\n");
	printf("Testing whether outpostplayed is incremented and handCount is decremented...\n");
	struct gameState G;
	int k[10] = {great_hall, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo,
			outpost};

	initializeGame(2, k, 3, &G);

	G.handCount[0] = 3;
	G.hand[0][0] = outpost;

	int preOutpostPlayed = G.outpostPlayed;
	int preNumCards = G.handCount[0];

	playCard(0, 1, 0, 0, &G);
	assert(G.outpostPlayed == preOutpostPlayed + 1);
	assert(G.handCount[0] == preNumCards - 1);

	printf("Test passes\n");

	//playCard(0, 1, 0, 0, &G);


}
