#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){
	//unit test for isGameOver()
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, smithy, village, baron, great_hall, minion};
	int r;

	initializeGame(2, k, 2, &G);

	G.supplyCount[province] = 1;
	r = isGameOver(&G);
	assert(r == 0);
	printf("Game not over\n");

	G.supplyCount[province] = 0;
	r = isGameOver(&G);
	assert(r == 1);
	printf("Game over\n");

	printf("Unit test for isGameOver() passed\n");

	return 0;
}
