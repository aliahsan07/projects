//Test for Card Embargo
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

	int currentPlayer = whoseTurn(&G);
	int baseCoins = G.coins;
	int baseEmbargoTokens = G.embargoTokens[copper];
	int baseHandCount = G.handCount[currentPlayer];
	
	cardEffect(embargo, copper, 0, 0, &G, 0, 0);
	
	int newCoins = G.coins;
	int newEmbargoTokens = G.embargoTokens[copper];
	int newHandCount = G.handCount[currentPlayer];


	assert(newCoins == baseCoins + 2);
	assert(newEmbargoTokens == baseEmbargoTokens + 1);
	assert(newHandCount == baseHandCount - 1);

	printf("All card tests passed\n");

	return 0;
}
