/*
 *Cooper Gale
 *Card Test 4: gardens
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

	printf ("gardens\n");

	initializeGame(2, y, 2, &x);

	i = cardEffect(gardens, 0, 0, 0, &x, 0, 0);

	assert(i == -1);

	assert(x.numActions == 1);
	
	assert(numHandCards(&x) == 5);

	assert(x.numBuys ==1); //nothing should change

	return (0);
}
