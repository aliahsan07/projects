//unit test for Smithy
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main(){

	printf("Running card test 3 (Smithy)\n");

	int kingCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int testPlayer = 0;
	int handNum;
	struct gameState G;
	struct gameState *p = &G;
	srand(time(NULL));
	int r = rand();
	int i;

	initializeGame(2, kingCards, r, p);

	p->hand[testPlayer][0] = smithy;
	p->hand[testPlayer][1] = feast;
	p->hand[testPlayer][2] = gardens;
	p->hand[testPlayer][3] = copper;

	handNum = p->handCount[testPlayer];
	printf("\nPlayer hand before playing Smithy, %d cards", handNum);
	
	for(i = 0; i < handNum; i++){
		printf("\n%d", p->hand[testPlayer][i]);
	}
	
	assert(cardEffect(smithy, -1, -1, -1, p, 0, -1) != -1);

	handNum = p->handCount[testPlayer];
	printf("\nPlayer hand after playing Smithy, %d cards", handNum);
	
	for(i = 0; i < handNum; i++){
		printf("\n%d", p->hand[testPlayer][i]);
	}
	
	printf("\n%d", p->hand[testPlayer][i+1]);
	printf("\n%d", p->hand[testPlayer][i+2]);

	assert(p->handCount[testPlayer] == 7);

	printf("\nCard test 3 ran, all test passed\n");
	return 0;
}