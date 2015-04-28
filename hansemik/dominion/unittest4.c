#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {

	
	printf("Testing updateCoins.\n");


	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
		baron, steward, tribute, embargo, sea_hag};
	
	initializeGame(2, k, 5, &G);

	int player = 0;
	int bonus = 0;

	//Clear hand
	for (int i = 0; i < G.handCount[player]; i++)
	{
		G.hand[player][i] = -1;
	}
	G.handCount[player] = 0;


	printf("Check with no coins.\n");
	int r = updateCoins(player, &G, bonus);
	assert(G.coins == 0);
	printf("Counted 0 coins in hand correctly...continuing\n");


	printf("Check with all coins.\n");
	printf("1 copper. 1 silver. 1 gold.\n");
	G.hand[player][0] = copper;
	G.hand[player][1] = silver;
	G.hand[player][2] = gold;
	G.handCount[player] = 3;
	r = updateCoins(player, &G, bonus);
	assert(G.coins == 6);
	printf("Counted 6 coins in hand correctly...continuing\n");


	printf("Check with all coins and 2 bonus.\n");
	printf("1 copper. 1 silver. 1 gold. 2 bonus.\n");
	G.hand[player][0] = copper;
	G.hand[player][1] = silver;
	G.hand[player][2] = gold;
	bonus = 2;
	G.handCount[player] = 3;
	r = updateCoins(player, &G, bonus);
	assert(G.coins == 8);
	printf("Counted 8 coins in hand correctly...continuing\n");


	printf("Check with coins and kindgom cards.\n");
	printf("1 copper. 1 silver. 1 gold. 1 adventurer. 1 feast. 1 curse, 1 duchy\n");
	G.hand[player][0] = copper;
	G.hand[player][1] = silver;
	G.hand[player][2] = gold;
	G.hand[player][3] = adventurer;
	G.hand[player][4] = feast;
	G.hand[player][5] = curse;
	G.hand[player][6] = duchy;
	bonus = 0;
	G.handCount[player] = 7;
	r = updateCoins(player, &G, bonus);
	assert(G.coins == 6);
	printf("Counted 6 coins in hand correctly...continuing\n");


	printf("Check with all kingdom cards.\n");
	printf("1 adventurer. 1 feast. 1 curse, 1 duchy\n");
	G.hand[player][0] = adventurer;
	G.hand[player][1] = feast;
	G.hand[player][2] = curse;
	G.hand[player][3] = duchy;
	G.handCount[player] = 4;
	r = updateCoins(player, &G, bonus);
	assert(G.coins == 0);
	printf("Counted 0 coins in hand correctly...continuing\n");

	printf("Testing complete. All tests passed.\n");
	return 0;
}