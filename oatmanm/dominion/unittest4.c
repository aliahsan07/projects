#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(){

	printf("Testing isGameOver...\n");

	struct gameState G;
	int k[10] = {adventurer, village, feast, gardens, remodel, mine, steward, outpost, council_room, smithy};
	initializeGame(2,k,2,&G);

	printf("Testing if game ends when provinces run out...\n");

	G.supplyCount[province] = 0;
	int t = isGameOver(&G);
	assert(t == 1);

	printf("Testing if game ends when 3 supply piles run out...\n");

	G.supplyCount[province] = 8;
	G.supplyCount[smithy] = 0;
	G.supplyCount[village] = 0;
	G.supplyCount[adventurer] = 0;
	t = isGameOver(&G);
	assert(t == 1);

	printf("Testing other cases...\n");

	G.supplyCount[adventurer] = 1;
	t = isGameOver(&G);
	assert(t == 0);

	G.supplyCount[feast] = 0;
	G.supplyCount[gardens] = 0;
	t = isGameOver(&G);

	printf("isGameOver works!\n");

	return 0;
}