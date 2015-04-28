//Test for Card Council_Room
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
	int baseBuys = G.numBuys;
	int baseHandCountP1 = G.handCount[currentPlayer];
	int baseHandCountP2 = G.handCount[currentPlayer+1];

	cardEffect( council_room,  copper,  silver,  gold, &G,  1,  0);

	assert(G.handCount[currentPlayer] == baseHandCountP1 + 3);
	assert(G.handCount[currentPlayer+1] == baseHandCountP2 + 1);
	assert(G.numBuys == baseBuys + 1);

	printf("All card tests passed\n");

	return 0;
}