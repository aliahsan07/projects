/*
 *Cooper Gale
 *Card Test 3: feast
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

	printf ("feast\n");

	initializeGame(2, y, 2, &x);

	i = cardEffect(feast, village, 0, 0, &x, 0, 0);

	assert(i == 0);

	assert(x.numActions == 1);
	
	assert(numHandCards(&x) == 5);

	assert(x.numBuys ==1);

	assert(fullDeckCount(0, village, &x) == 1);

	return (0);
}
