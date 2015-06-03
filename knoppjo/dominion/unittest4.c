#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {

	printf("***Testing updateCoins***\n");
	struct gameState G;

	int k[10] = {minion, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo,
			outpost};

	initializeGame(2, k, 3, &G);

	printf("Testing player has 7 coins (+1 bonus)***\n");
	G.handCount[0] = 3;
	G.hand[0][0] = copper;
	G.hand[0][1] = silver;
	G.hand[0][2] = gold;

	int r = updateCoins(0, &G, 1);
	int Coins = G.coins;
	assert(Coins == 7);
	printf("Test passes, player 1 has %d coins\n", Coins);

	printf("Testing player has -94 coins (-100 bonus)***\n");
	G.handCount[0] = 3;
	G.hand[0][0] = copper;
	G.hand[0][1] = silver;
	G.hand[0][2] = gold;

	r = updateCoins(0, &G, -100);
	Coins = G.coins;
	assert(Coins == -94);
	printf("Test fails for negative bonus, player 1 has %d coins\n", Coins);

	//r = updateCoins(NULL);

}




