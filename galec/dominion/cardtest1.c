/*
 *Cooper Gale
 *Card Test 1: village_rf
 */

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState x;
	int i;	
	
	int y[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, feast, smithy};

	printf ("village_rf\n");

	initializeGame(2, y, 2, &x);

	i = cardEffect(village, 0, 0, 0, &x, 0, 0);

	assert(i == 0);

	//DEBUG	printf ("%d \n", x.numActions);
	assert(x.numActions == 3);
	
	assert(numHandCards(&x) == 5);

	assert(x.numBuys ==1);

	return (0);
}
