#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(){
	printf("Testing steward...\n");
	struct gameState G;
	int k[10] = {adventurer, village, feast, gardens, remodel, mine, steward, outpost, council_room, smithy};
	initializeGame(2, k, 2, &G);
	int count = 0;
	int countBefore = 0;
	int coins = 0;
	int coinsBefore = 0;

	G.hand[0][0] = steward;
	countBefore = G.handCount[0];
	coinsBefore = G.coins;

	printf("Playing steward to draw 2 cards.\n");
	cardEffect(steward, 1, 2, 3, &G, 0, 0);
	count = G.handCount[0];
	printf("Number of cards in hand before playing card: %d\n", countBefore);
	printf("Number of cards in hand after card was played (expecting 6): %d\n", count);

	printf("Playing steward to get 2 coins.\n");
	G.hand[0][0] = 0;
	cardEffect(steward, 2, 2, 3, &G, 0, 0);
	coins = G.coins;
	printf("Number of coins before card played: %d\n", coinsBefore);
	printf("Number of coins after card played: %d\n", coins);

	printf("Playing steward to trash 2 cards.\n");
	G.hand[0][0];
	countBefore = G.handCount[0];
	cardEffect(steward, 3, 2, 3, &G, 0, 0);
	count = G.handCount[0];
	printf("Number of cards in hand before card played: %d\n", countBefore);
	printf("Number of cards in hand after card played (expecting 2): %d\n", count);
	printf("Testing for steward done.\n");

	return 0;
}