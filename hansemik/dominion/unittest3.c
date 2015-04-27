#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	
	printf("Testing isGameOver.\n");

	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
		baron, steward, tribute, embargo, sea_hag};

	initializeGame(2, k, 5, &G);

	printf("Check with 1 province left.\n");
	G.supplyCount[province] = 1;
	int ret_val = isGameOver(&G);
	assert(ret_val == 0);
	printf("Game is not over as expected...continuing\n");

	printf("Check with 2 kingdom card pile exhausted.\n");
	G.supplyCount[adventurer] = 0;
	G.supplyCount[embargo] = 0;
	ret_val = isGameOver(&G);
	assert(ret_val == 0);
	printf("Game is not over as expected...continuing\n");

	printf("Check with 0 provinces left\n");
	G.supplyCount[province] = 0;
	ret_val = isGameOver(&G);
	assert(ret_val == 1);
	printf("Game is over as expected...continuing\n");

	printf("Check with 3 or more kingdom card piles exhausted.\n");
	G.supplyCount[province] = 1;
	G.supplyCount[feast] = 0;
	ret_val = isGameOver(&G);
	assert(ret_val == 1);
	printf("Game is over as expected\n");

	printf("Testing complete. All tests passed.\n");
	return 0;
}
