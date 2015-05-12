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
	int baseCoins = G.coins;
	int baseHandCountP1 = G.handCount[currentPlayer];

	cardEffect(steward, 0, 0, 0, &G, 0, 0);
	assert(G.handCount[currentPlayer] == baseHandCountP1 - 3);

	baseHandCountP1 = G.handCount[currentPlayer];
	cardEffect(steward, 1, 0, 0, &G, 0, 0);
	assert(G.handCount[currentPlayer] == baseHandCountP1 + 1);

	cardEffect(steward, 2, 0, 0, &G, 0, 0);
	assert(G.coins == baseCoins + 2);

	printf("All card tests passed\n");

	return 0;
}

