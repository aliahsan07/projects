//Test for Whoseturn function
//Joseph Cronise CS362

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){

	struct gameState G;
	int k[10] = { embargo, cutpurse, duchy, adventurer, village, sea_hag, minion, steward, salvager, mine };

	initializeGame(2, k, 2, &G);

	assert(whoseTurn(&G) == 0);

	endTurn(&G);

	assert(whoseTurn(&G) == 1);

	endTurn(&G);

	assert(whoseTurn(&G) == 0);

	printf("All whoseTurn funtion tests passed\n");

	return 0;
}