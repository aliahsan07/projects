#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(){
	printf("Testing salvager...\n");
	struct gameState G;
	int buysBefore = 0;
	int buys = 0;
	int k[10] = {adventurer, salvager, feast, gardens, remodel, mine, steward, outpost, council_room, smithy};
	initializeGame(2, k, 2, &G);

	printf("Playing salvager to get rid of the estate in hand.\n");
	G.hand[0][0] = salvager;
	buysBefore = G.numBuys;
	cardEffect(salvager, 3, 0, 0, &G, 0, 0);
	buys = G.numBuys;
	printf("Printing the contents of the hand, should be all 4's.\n");
	for (int i = 0; i < G.handCount[0]; i++)
		printf("Card %d = %d\n", (i+1), G.hand[0][i]);
	printf("Number of buys before playing the card: %d\n", buysBefore);
	printf("Number of buys after playing the card (should be one more): %d\n", buys);
	printf("Testing for salvager done.\n");

	return 0;
}