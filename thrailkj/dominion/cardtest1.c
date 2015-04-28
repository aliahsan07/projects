#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){
	//card test for gardens 
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, smithy, village, baron, great_hall, minion};

	initializeGame(2, k, 4, &G);

	assert(cardEffect(gardens, 0, 0, 0, &G, 0, 0) == -1);

	printf("Unit test for gardens passed\n");

	return 0;
}
