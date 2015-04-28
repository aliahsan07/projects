#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {

	
	printf("Testing remodel.\n");


	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
		baron, steward, tribute, remodel, sea_hag};
	
	initializeGame(2, k, 5, &G);

	int player = 0;
	int passed_test = 1;

	//Clear hand
	for (int i = 0; i < G.handCount[player]; i++)
	{
		G.hand[player][i] = -1;
	}
	G.handCount[player] = 0;

	G.hand[player][0] = copper;
	G.hand[player][1] = silver;
	G.hand[player][2] = gold;
	G.hand[player][3] = remodel;
	G.hand[player][4] = feast;
	G.hand[player][5] = curse;
	G.hand[player][6] = duchy;
	G.handCount[player] = 7;

	printf("Testing whether we can trade a card costing 2 more: ");
	int ret_val = cardEffect(remodel, 0, estate, 0, &G, 3, 0);
	assert(ret_val == 0);

	//Check if we discarded correct card
	for (int i = 0; i < G.handCount[player]; i++)
	{
		if (G.hand[player][i] == copper)
	    {
	    	passed_test = 0;
	    }
	}

	assert(passed_test == 1);

	//Check if we gained correct card
	for (int i = 0; i < G.handCount[player]; i++)
	{
		if (G.hand[player][i] == estate)
	    {
	    	passed_test = 1;
	    }
	}
	assert(passed_test == 1);
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
	G.hand[player][3] = remodel;
	G.hand[player][4] = feast;
	G.hand[player][5] = curse;
	G.hand[player][6] = duchy;
	G.handCount[player] = 7;

	printf("Testing whether we can trade a card costing 0 more: ");
	ret_val = cardEffect(remodel, 0, curse, 0, &G, 3, 0);
	assert(ret_val == 0);

	//Check if we discarded correct card
	for (int i = 0; i < G.handCount[player]; i++)
	{
		if (G.hand[player][i] == copper)
	    {
	    	passed_test = 0;
	    }
	}

	assert(passed_test == 1);

	//Check if we gained correct card
	for (int i = 0; i < G.handCount[player]; i++)
	{
		if (G.hand[player][i] == curse)
	    {
	    	passed_test = 1;
	    }
	}
	assert(passed_test == 1);
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
	G.hand[player][3] = remodel;
	G.hand[player][4] = feast;
	G.hand[player][5] = curse;
	G.hand[player][6] = duchy;
	G.handCount[player] = 7;

	printf("Testing whether we can trade a card costing less: ");
	ret_val = cardEffect(remodel, 2, silver, 0, &G, 3, 0);
	assert(ret_val == 0);

	//Check if we discarded correct card
	for (int i = 0; i < G.handCount[player]; i++)
	{
		if (G.hand[player][i] == gold)
	    {
	    	passed_test = 0;
	    }
	}

	assert(passed_test == 1);

	//Check if we gained correct card
	for (int i = 0; i < G.handCount[player]; i++)
	{
		if (G.hand[player][i] == silver)
	    {
	    	passed_test = 1;
	    }
	}
	assert(passed_test == 1);
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
	G.hand[player][3] = remodel;
	G.hand[player][4] = feast;
	G.hand[player][5] = curse;
	G.hand[player][6] = duchy;
	G.handCount[player] = 7;

	printf("Testing whether trading up for more than 2 fails: ");
	ret_val = cardEffect(remodel, 0, duchy, 0, &G, 3, 0);
	assert(ret_val == -1);
	printf("PASSED\n");


	printf("Testing complete. All tests passed.\n");
	return 0;
}


