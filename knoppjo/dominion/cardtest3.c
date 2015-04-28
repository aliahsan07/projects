#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define DIE_ON_ASSERT 0


int main () {
	printf("***Testing steward***\n");
	struct gameState G;
	int k[10] = {village, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo,
			outpost};

	initializeGame(2, k, 3, &G);

	//Test Choice 1
	G.handCount[0] = 3;
	G.hand[0][0] = steward;
	int preNumCards = G.handCount[0];

	printf("Testing when given choice 1, if steward adds 1 card to hand...\n");
	playCard(0, 1, 0, 0, &G);
	assert(G.handCount[0] == preNumCards + 1);
	printf("Test passes\n");


	/*
	//Test choice 2
	struct gameState G2;
	initializeGame(2, k, 3, &G2);
	G2.handCount[0] = 3;
	G2.hand[0][0] = steward;
	G2.coins = 2;
	preNumCards = G2.handCount[0];
	int preCoins = G2.coins;

	printf("Testing when Given choice 2, if steward adds 2 coins and subtracts 1 card to hand...\n");
	playCard(0, 2, 0, 0, &G2);
	printf("%d, %d\n", preCoins, G2.coins);
	assert(G2.handCount[0] == preNumCards - 1);
	assert(G2.coins == preCoins + 2);

	printf("Test passes\n");
	*/


	//Test choice 3
	struct gameState G3;
	initializeGame(2, k, 3, &G3);
	G3.handCount[0] = 3;
	G3.hand[0][0] = steward;
	preNumCards = G3.handCount[0];

	printf("Testing when given any other choice but 1 or 2, steward subtracts 2 cards from hand...\n");
	playCard(0, 3, 0, 0, &G3);
	assert(G3.handCount[0] == preNumCards - 3);

	printf("Test passes\n");

	//playCard(0, 1, 0, 0, NULL);


}
