/*
 *Cooper Gale
 *Unit Test 3: scoreFor
 *Check score of player
 */

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState x;

	int y[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, feast, smithy};

	printf ("getCost.\n");

	initializeGame(2, y, 2, &x);

	assert(scoreFor(0, &x) == 1);
	
	//DEBUG	printf("%d \n", scoreFor(1, &x));
	assert(scoreFor(1, &x) == 0);
	
	return (0);
}
