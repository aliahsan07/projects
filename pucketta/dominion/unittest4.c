//unit test for updateCoins()

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main(){

	printf("Running unit test 4 (updateCoins)\n");

	int kingCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int testPlayer = 0;
	int testVal = 0;
	struct gameState G;
	struct gameState *p = &G;
	srand(time(NULL));
	int r = rand();
	int i;

	initializeGame(2, kingCards, r, p);

	for (i = 0; i < 5; i++){
		p->hand[testPlayer][i] = copper;
	}

	testVal = updateCoins(testPlayer, p, 0);
	assert(testVal == 0);

	//printf("%d\n", p->coins);
	testVal = p->coins;
	assert(testVal == 5);

	printf("Unit test 4 passed\n");
	return 0;
}