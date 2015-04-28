//unit test for Village
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main(){

	printf("Running card test 4 (Village)\n");

	int kingCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int testPlayer = 0;
	struct gameState G;
	struct gameState *p = &G;
	srand(time(NULL));
	int r = rand();

	initializeGame(2, kingCards, r, p);

	p->hand[testPlayer][0] = village;
	p->hand[testPlayer][1] = feast;
	p->hand[testPlayer][2] = gardens;
	p->hand[testPlayer][3] = copper;
	p->numActions = 1;

	printf("\nPlayer hand before playing Village");
	printf("\n%d", p->hand[testPlayer][0]);
	printf("\n%d", p->hand[testPlayer][1]);
	printf("\n%d", p->hand[testPlayer][2]);
	printf("\n%d", p->hand[testPlayer][3]);
	printf("\nhand count: %d\n", p->handCount[testPlayer]);

	cardEffect(village, -1, -1, -1, p, 0, -1);

	printf("\nPlayer hand after playing Village");
	printf("\n%d", p->hand[testPlayer][0]);
	printf("\n%d", p->hand[testPlayer][1]);
	printf("\n%d", p->hand[testPlayer][2]);
	printf("\n%d", p->hand[testPlayer][3]);
	printf("\n%d", p->hand[testPlayer][4]);
	printf("\nhand count: %d\n", p->handCount[testPlayer]);

	assert(p->handCount[testPlayer] == 5);
	assert(p->numActions == 3);

	printf("Card test 4 ran, all test passed\n");
	return 0;
}