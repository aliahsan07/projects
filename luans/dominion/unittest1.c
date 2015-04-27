#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"

int main(int argc, char *argv[])
{
	struct gameState *game = newGame();
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	printf("Starting to test kingdom cards......\n");
	
	int *result_array = kingdomCards(k[0], k[1], k[2], k[3], k[4], k[5], k[6], k[7], k[8], k[9]);
	
	int i;
	
	printf("+++++++++++++++++++++++++++++++++++++++++++++++\n");
	
	for(i = 0; i < 10; i ++)
	{
		assert(result_array[i] == k[i]);
		printf("CARD-[%d]: %d\n", i + 1, result_array[i]);		
	}
	
	return EXIT_SUCCESS;
}