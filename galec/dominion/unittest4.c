/*
 *Cooper Gale
 *Unit Test 4: supplyCount
 *check proper supply pile counts
 */

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState x;

	int y[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, feast, smithy};

	printf ("supplyCount\n");

	initializeGame(2, y, 2, &x);

	assert(supplyCount(7, &x)== 10); //adventurer

	return (0);
} 
