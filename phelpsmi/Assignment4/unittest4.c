#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int main (int argc, char** argv) {
	struct gameState G;
	int seed = 1;
	int result;

	printf("testing isGameOver()\n");

  	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

  	initializeGame(2, k, seed, &G);

    assert(isGameOver(&G) == 0);

    G.supplyCount[province] = 0;
    assert(isGameOver(&G) == 1);

    G.supplyCount[province] = 1;
    G.supplyCount[adventurer] = 0;
    G.supplyCount[gardens] = 0;
    G.supplyCount[village] = 0;

    assert(isGameOver(&G) == 1);

  

  	printf("isGameOver(): PASSED\n");

}