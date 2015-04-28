//Test for Card
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
	int baseHandCount = G.handCount[currentPlayer];
	cardEffect(smithy, copper, silver, gold, &G, 1, 0);
	//r_smithy(currentPlayer, 1, &G);

	assert(G.handCount[currentPlayer] = baseHandCount + 2);

	printf("All card tests passed\n");
	return 0;
}
