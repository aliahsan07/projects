#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){
	//card test for embargo	
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, smithy, village, baron, great_hall, embargo};
	int c;
	int c2;
	int e;
	int e2;

	initializeGame(2, k, 4, &G);

	c = G.coins;
	e = G.embargoTokens[0];

	cardEffect(embargo, 0, 0, 0, &G, 0, 0);

	c2 = G.coins;
	e3 = G.embargoTokens[0];

	assert(c2 == c1 + 2);
	assert(e2 == e + 1);

	printf("Unit test for embargo passed\n");

	return 0;
}
