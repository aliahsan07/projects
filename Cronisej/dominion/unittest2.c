//Test for isgameover function
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

	assert(isGameOver(&G) == 0);

	G.supplyCount[province] = 0; //set province card stack to 0
	assert(isGameOver(&G) == 1);

	G.supplyCount[province] = 1;

	G.supplyCount[copper] = 0;
	G.supplyCount[silver] = 0;
	G.supplyCount[gold] = 0;
	assert(isGameOver(&G) == 1);

	printf("All isGameOver function tests passed\n");

	return 0;
}
