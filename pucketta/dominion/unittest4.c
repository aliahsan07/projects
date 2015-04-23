//unit test for updateCoins()

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main(){
	int kingCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int testPlayer = 1;
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

	testVal = p->coins;
	assert(testVal == 5);
}