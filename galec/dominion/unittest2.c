/*
 *Cooper Gale
 *Unit Test 2: drawCard
 *Check card drawing
 */

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState x;

	int y[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, feast, smithy};

	printf ("drawCard.\n");

	initializeGame(2, y, 2, &x);
	
	drawCard(0, &x);

	assert (numHandCards(&x) == 6);
	
	drawCard(1, &x);
	
	assert (numHandCards(&x) == 6);


	return (0);
}

	
