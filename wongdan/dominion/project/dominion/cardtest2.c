#include "dominion.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	struct gameState G;
	int a, b;

	int k[10] = {adventurer, cutpurse, embargo, gardens, mine, minion, sea_hag, smithy, tribute, village};

	printf("******************************\n");
	printf("\t\t\tCARD TEST 2\t\t\t\n");
	printf("******************************\n");

	initializeGame(2, k, 2, &G);
	printf("Testing minion...\n");
	printf("Actions before: %d\n", G.numActions);
	a = numHandCards(&G);
	b = cardEffect(minion, 0, 0, 0, &G, 0, 0);

	printf("Actions after: %d\n", G.numActions);
	assert(a == 5);
	assert(b == 0);

return 0;	
}
