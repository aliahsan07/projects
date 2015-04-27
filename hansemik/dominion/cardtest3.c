#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {

	
	printf("Testing steward.\n");


	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
		baron, steward, tribute, remodel, sea_hag};
	
	initializeGame(2, k, 5, &G);

	int player = 0;

	//Clear hand
	for (int i = 0; i < G.handCount[player]; i++)
	{
		G.hand[player][i] = -1;
	}
	G.handCount[player] = 0;

	G.hand[player][0] = copper;
	G.hand[player][1] = silver;
	G.hand[player][2] = gold;
	G.hand[player][3] = steward;
	G.hand[player][4] = feast;
	G.hand[player][5] = curse;
	G.hand[player][6] = duchy;
	G.handCount[player] = 7;

	int old_deckCount = G.deckCount[player];

	int old_handCount = G.handCount[player];

	printf("Testing if we draw two cards with option 1: ");
	int ret_val = cardEffect(steward, 1, 0, 0, &G, 3, 0);

	int new_deckCount = G.deckCount[player];
	int new_handCount = G.handCount[player];

	assert(new_deckCount == old_deckCount - 2);
	assert(new_handCount == old_handCount + 1);
	printf("PASSED\n");



	//Clear hand
	for (int i = 0; i < G.handCount[player]; i++)
	{
		G.hand[player][i] = -1;
	}
	G.handCount[player] = 0;

	G.hand[player][0] = copper;
	G.hand[player][1] = silver;
	G.hand[player][2] = gold;
	G.hand[player][3] = steward;
	G.hand[player][4] = feast;
	G.hand[player][5] = curse;
	G.hand[player][6] = duchy;
	G.handCount[player] = 7;


	printf("Testing if we gain 2 coins with option 2: ");
	int old_coin = G.coins;
	ret_val = cardEffect(steward, 2, 0, 0, &G, 3, 0);
	int new_coin = G.coins;

	assert(old_coin == new_coin - 2);
	printf("PASSED\n");




	//Clear hand
	for (int i = 0; i < G.handCount[player]; i++)
	{
		G.hand[player][i] = -1;
	}
	G.handCount[player] = 0;

	G.hand[player][0] = copper;
	G.hand[player][1] = silver;
	G.hand[player][2] = gold;
	G.hand[player][3] = steward;
	G.hand[player][4] = feast;
	G.hand[player][5] = curse;
	G.hand[player][6] = duchy;
	G.handCount[player] = 7;

	printf("Testing if we trash 2 cards with option 3: \n");
	old_handCount = G.handCount[player];
	ret_val = cardEffect(steward, 3, 0, 1, &G, 3, 0);

	new_handCount = G.handCount[player];

	assert(old_handCount == new_handCount + 3);
	printf("PASSED\n");

	printf("Testing complete. All tests passed.\n");
	return 0;
}
