#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){
	//unit test for numHandCards()
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, smithy, village, baron, great_hall, minion};

	initializeGame(2, k, 2, &G);
	
	assert(numHandCards(&G) == 5);

	printf("Unit test for numHandCards() passed\n");

	return 0;
}
