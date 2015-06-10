#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	struct gameState G;
	int players;
	int i;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	printf("***********************************\n");
	printf("\t\t\tUNIT TEST 4\t\t\t\n");
	printf("***********************************\n");
	printf("\nTesting players turn\n");
	for (players = 2; players <=4; ++players){
		i = initializeGame(players, k, 2, &G);
		assert(i == 0);
		i = whoseTurn(&G);
		assert(i == G.whoseTurn);
		printf("Player %d's turn\n", players);
	}

	printf("All tests passed.\n\n");

return 0;	
}
