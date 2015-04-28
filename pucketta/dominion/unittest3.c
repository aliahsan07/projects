//unit test for isGameOver()

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main(){

	printf("Running unit test 3 (isGameOver)\n");

	int kingCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int testPlayer = 2;
	int testVal = 0;
	struct gameState G;
	struct gameState *p = &G;
	srand(time(NULL));
	int r = rand();

	initializeGame(2, kingCards, r, p);

	testVal = isGameOver(p);
	assert(testVal == 0);

	p->supplyCount[province] = 0;

	testVal = isGameOver(p);
	assert(testVal == 1);

	printf("Unit test 3 passed\n");
	return 0;
}