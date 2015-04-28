#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){
	//unit test for whoseTurn()	
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, smithy, village, baron, great_hall, minion};	
	int player1 = 0;
	int player2 = 1;	

	initializeGame(2, k, 2, &G);

	G.whoseTurn = player1;
	assert(whoseTurn(&G) == 0);


	G.whoseTurn = player2;
	assert(whoseTurn(&G) == 1);
	
	printf("Unit test for whoseTurn() passed");

	return 0;
}
