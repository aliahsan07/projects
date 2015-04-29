//Test for numhandcards function
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

	assert(numHandCards(&G) == 5);

	printf("All numHandCards function tests passed\n");


	return 0;
}