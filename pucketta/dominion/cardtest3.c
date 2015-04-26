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
	struct gameState G;
	struct gameState *p = &G;
	srand(time(NULL));
	int r = rand();

	initializeGame(2, kingCards, r, p);

	p->hand[testPlayer][0] = smithy;
	p->hand[testPlayer][1] = feast;
	p->hand[testPlayer][2] = gardens;
	p->hand[testPlayer][3] = copper;

	printf("\nPlayer hand before playing Smithy");
	printf("\n%d", p->hand[testPlayer][0]);
	printf("\n%d", p->hand[testPlayer][1]);
	printf("\n%d", p->hand[testPlayer][2]);
	printf("\n%d", p->hand[testPlayer][3]);
	printf("\nhand count: %d\n", p->handCount[testPlayer]);

	cardEffect(smithy, -1, -1, -1, p, 0, -1);

	printf("\nPlayer hand after playing Smithy");
	printf("\n%d", p->hand[testPlayer][0]);
	printf("\n%d", p->hand[testPlayer][1]);
	printf("\n%d", p->hand[testPlayer][2]);
	printf("\n%d", p->hand[testPlayer][3]);
	printf("\n%d", p->hand[testPlayer][4]);
	printf("\n%d", p->hand[testPlayer][5]);
	printf("\n%d", p->hand[testPlayer][6]);
	printf("\nhand count: %d\n", p->handCount[testPlayer]);

	assert(p->handCount[testPlayer] == 7);

	printf("Card test 3 ran, all test passed\n");
	return 0;
}