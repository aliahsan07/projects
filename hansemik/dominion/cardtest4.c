#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {

	
	printf("Testing mine.\n");


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
	G.hand[player][1] = mine;
	G.hand[player][2] = curse;
	G.hand[player][3] = curse;
	G.hand[player][4] = mine;
	G.hand[player][5] = tribute;
	G.hand[player][6] = duchy;
	G.handCount[player] = 7;

	printf("Testing if it returns -1 when choice 1 is a non-treasure card: ");
	int ret_val = cardEffect(mine, 3, silver, 0, &G, 2, 0);
	assert(ret_val == -1);
	printf("PASSED\n");

	printf("Testing if it returns -1 when choice 2 is a non-treasure card: ");
	ret_val = cardEffect(mine, 0, -5, 0, &G, 2, 0);
	assert(ret_val == -1);
	printf("PASSED\n");

	printf("Testing if it returns -1 when choice 2 is too expensive: ");
	ret_val = cardEffect(mine, 0, gold, 0, &G, 2, 0);
	assert(ret_val == -1);
	printf("PASSED\n");

	printf("Testing if it successfully gains silver after giving copper: ");
	ret_val = cardEffect(mine, 0, silver, 0, &G, 2, 0);
	assert(ret_val == 0);

	int passed_test = 0;
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

	printf("Testing complete. All tests passed.\n");
	return 0;
}