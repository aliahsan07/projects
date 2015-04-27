//Unit test for initializeGame()

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main(){

	printf("Running unit test 1 (initializeGame)\n");

	int testVal = 0;
	int kingCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int testCards[10] = {adventurer, gardens, embargo, village, village, mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState G;
	struct gameState *p = &G;
	srand(time(NULL));
	int r = rand();
	
	testVal = initializeGame(2, kingCards, r, p);
	assert(testVal == 0);

	
	testVal = initializeGame(1, kingCards, r, p);
	assert(testVal == -1);

	testVal = initializeGame(2, testCards, r, p);
	assert(testVal == -1);
	
	printf("Unit test 1 passed\n");
	return 0;
}