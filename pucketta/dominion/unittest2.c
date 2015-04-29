//Unit test for shuffle()

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main(){

	printf("Running unit test 2 (shuffle)\n");

	int kingCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int testPlayer = 2;
	int testVal = 0;
	struct gameState G;
	struct gameState *p = &G;
	srand(time(NULL));
	int r = rand();

	initializeGame(2, kingCards, r, p);
	
	testVal = shuffle(testPlayer, p);
	assert(testVal == -1);
	
	p->deckCount[testPlayer] = 5;

	testVal = shuffle(testPlayer, p);
	assert(testVal == 0);

	printf("Unit test 4 passed\n");
	return 0;
}
