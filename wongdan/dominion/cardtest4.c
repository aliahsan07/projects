#include "dominion.h"
#include "rngs.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(){
	struct gameState G;

	int cost;
	int k[10] = {adventurer, cutpurse, embargo, gardens, mine, minion, sea_hag, smithy, tribute, village};

	printf("******************************\n");
	printf("\t\t\tCARD TEST 4\t\t\t\n");
	printf("******************************\n");

	printf("Testing salvager...\n");

	initializeGame(2, k, 7, &G);

	int numBuys = G.numBuys + 1;
	int handCount = G.handCount[0] - 1;
	int coins = G.coins;

	cost = cardEffect(salvager, 0, 0, 0, &G, 0, 0);
	
	assert(cost == 0);
	assert(G.numBuys == numBuys);
	assert(G.handCount[0] == handCount);
	assert(G.coins = coins);

	numBuys = G.numBuys + 1;
	handCount = G.handCount[0] - 2;
	coins = G.coins + 3;

	printf("Test has passed.\n");

return 0;	
}
