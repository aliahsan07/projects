#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int main (int argc, char** argv) {
	struct gameState G;
	int seed = 1;
	int result;

	printf("testing buyCard()\n");

  	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

  	initializeGame(2, k, seed, &G);
  	G.numBuys = 0;
  	G.coins = 0;
    G.whoseTurn = 0;

  	assert(buyCard(0, &G) == -1);

  	G.numBuys = 1;
  	assert(buyCard(2, &G) == -1);

    assert(G.discardCount[0] == 0);

  	G.coins = 5;

  	assert(buyCard(2, &G) == 0);
    assert(G.discardCount[0] == 1);
    assert(G.discard[0][0] == 2);

  	printf("buyCard(): PASSED\n");

}