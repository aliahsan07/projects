//unit test for remodelEffect()
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main(){

	printf("Running card test 2 (Remodel)\n");

	int kingCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int testPlayer = 0;
	struct gameState G;
	struct gameState *p = &G;
	srand(time(NULL));
	int r = rand();

	initializeGame(2, kingCards, r, p);

	p->hand[testPlayer][0] = remodel;
	p->hand[testPlayer][1] = feast;
	p->hand[testPlayer][2] = gardens;
	p->hand[testPlayer][3] = copper;

	printf("\nPlayer hand before playing Remodel");
	printf("\n%d", p->hand[testPlayer][0]);
	printf("\n%d", p->hand[testPlayer][1]);
	printf("\n%d", p->hand[testPlayer][2]);
	printf("\n%d\n", p->hand[testPlayer][3]);

	assert(cardEffect(remodel, 2, gold, -1, p, 0, -1) != -1);
	
	printf("\nPlayer hand after playing Remodel");
	printf("\n%d", p->hand[testPlayer][0]);
	printf("\n%d", p->hand[testPlayer][1]);
	printf("\n%d", p->hand[testPlayer][2]);
	printf("\n%d\n", p->hand[testPlayer][3]);

	assert(p->discard[testPlayer][0] == gold);
	assert(p->hand[testPlayer][1] == feast);
	

	printf("Card test 2 ran, all test passed\n");
	return 0;
}