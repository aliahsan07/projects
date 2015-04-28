#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int main () {
	printf("***Testing council_room***\n");
	struct gameState G;
	int k[10] = {salvager, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo,
			council_room};

	initializeGame(2, k, 3, &G);
	G.handCount[0] = 3;
	G.hand[0][0] = council_room;
	int preNumCards = G.handCount[0];
	int preNumBuys = G.numBuys;
	int preNumCards_P2 = G.handCount[1];


	printf("Testing if council_rooom draws 3 and increments NumBuys for player, and draws 1 for remaining players...\n");
	playCard(0, 1, 0, 0, &G);
	assert(G.handCount[0] == preNumCards + 3);
	assert(G.numBuys == preNumBuys + 1);
	assert(G.handCount[1] == preNumCards_P2 + 1 );

	printf("Test passes\n");

	//playCard(0, 1, 0, 0, NULL);


}
