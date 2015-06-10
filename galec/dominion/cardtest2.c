/*
 *Cooper Gale
 *Card Test 2: smithy_rf
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

	printf ("smithy_rf\n");

	initializeGame(2, y, 2, &x);

	i = cardEffect(smithy, 0, 0, 0, &x, 0, 0);

	assert(i == 0);

	//DEBUG printf("%d \n", x.numActions);
	assert(x.numActions == 1);
	
	assert(numHandCards(&x) == 7);

	assert(x.numBuys ==1);

	return (0);
}
