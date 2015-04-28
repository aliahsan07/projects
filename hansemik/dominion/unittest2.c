#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	
	printf("Testing initializeGame.\n");

	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
		baron, steward, tribute, embargo, sea_hag};
	
	printf("Testing too few players:\n");
	int ret_val = initializeGame(1, k, 5, &G);
	assert (ret_val == -1);
	printf("Test failed as expected...continuing\n");

	printf("Testing too many players:\n");
	ret_val = initializeGame(10, k, 5, &G);
	assert (ret_val == -1);
	printf("Test failed as expected...continuing\n");

	printf("Testing duplicate kingdom card:\n");
	k[1] = adventurer;
	ret_val = initializeGame(2, k, 5, &G);
	assert (ret_val == -1);
	printf("Test failed as expected...continuing\n");

	printf("Testing normal game with 2 players:\n");
	k[1] = council_room;
	ret_val = initializeGame(2, k, 5, &G);
	assert (ret_val == 0);
	assert (G.numPlayers == 2);
	assert (G.supplyCount[feast] == 10);
	assert (G.supplyCount[copper] == 60 - (7 * G.numPlayers));
	assert (G.supplyCount[silver] == 40);
	assert (G.supplyCount[gold] == 30);
	assert (G.supplyCount[curse] == 10);
	assert (G.numActions == 1);
	assert (G.numBuys == 1);
	assert (G.handCount[0] == 5);


	printf("Testing normal game with 3 players:\n");
	ret_val = initializeGame(3, k, 5, &G);
	assert (ret_val == 0);
	assert (G.numPlayers == 3);
	assert (G.supplyCount[feast] == 10);
	assert (G.supplyCount[copper] == 60 - (7 * G.numPlayers));
	assert (G.supplyCount[silver] == 40);
	assert (G.supplyCount[gold] == 30);
	assert (G.supplyCount[curse] == 20);
	assert (G.numActions == 1);
	assert (G.numBuys == 1);
	assert (G.handCount[0] == 5);

	printf("Testing normal game with 4 players:\n");
	ret_val = initializeGame(4, k, 5, &G);
	assert (ret_val == 0);
	assert (G.numPlayers == 4);
	assert (G.supplyCount[feast] == 10);
	assert (G.supplyCount[copper] == 60 - (7 * G.numPlayers));
	assert (G.supplyCount[silver] == 40);
	assert (G.supplyCount[gold] == 30);
	assert (G.supplyCount[curse] == 30);
	assert (G.numActions == 1);
	assert (G.numBuys == 1);
	assert (G.handCount[0] == 5);

	printf("Testing complete. All tests passed.\n");
	return 0;
}