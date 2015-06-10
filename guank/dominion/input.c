#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int activateCard(int card, int c1, int c2, int c3, struct gameState *state) {
	int i, r;
	int whoTurn = state->whoseTurn;

	for(i=0; i < state->handCount[whoTurn]; i++) {
		if (state->hand[whoTurn][i] == card) {
			r = playCard(i, c1, c2, c3, state);
			
			return 0;
		}
	}
	return -1;
}

int main () {
	
	int i, j;	
	int r;		
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, sea_hag, great_hall};
	
	struct gameState G;

	r = initializeGame(4, k, 1, &G);		
	for (i = adventurer; i <= treasure_map; i++) {
		G.supplyCount[i] = 10;
	}
	G.hand[G.whoseTurn][0] = adventurer;
	G.hand[G.whoseTurn][1] = village;
	G.hand[G.whoseTurn][2] = feast;
	G.hand[G.whoseTurn][3] = copper;
	G.hand[G.whoseTurn][4] = gold;
	G.handCount[G.whoseTurn] = 5;
	G.numActions = 5;
	
	activateCard(adventurer, 0, 0, 0, &G);
	activateCard(village, 3, gold, 0, &G);
	activateCard(feast, 0, 1, 0, &G);
	buyCard(gold, &G);
	endTurn(&G);

	G.supplyCount[5] = 0;
	G.supplyCount[8] = 0;
	G.supplyCount[15] = 0;

	r = isGameOver(&G);

}
