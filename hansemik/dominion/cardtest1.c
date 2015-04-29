#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {

	
	printf("Testing council_room.\n");


	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
		baron, steward, tribute, embargo, sea_hag};
	
	initializeGame(2, k, 5, &G);

	int player_one = 0;
	int player_two = 1;

//	for (int i = 0; i < G.handCount[player_one]; i++)
//	{
//		printf(G.hand[player_one][i]);
//	}

//	printf("%s\n", G.handCount[player_one]);
	int old_handCount_1 = G.handCount[player_one];
	int old_deckCount_1 = G.deckCount[player_one];

	int old_handCount_2 = G.handCount[player_two];
	int old_deckCount_2 = G.deckCount[player_two];

	int ret_val = cardEffect(council_room, 0, 0, 0, &G, 0, 0);
//	printf("%s\n", G.handCount[player_one]);
	int new_handCount_1 = G.handCount[player_one];
	int new_deckCount_1 = G.deckCount[player_one];

	int new_handCount_2 = G.handCount[player_two];
	int new_deckCount_2 = G.deckCount[player_two];

	printf("Check if 3 more cards are in the hand of player one(after discard: ");
	assert(old_handCount_1 == new_handCount_1 - 3);
	printf("PASSED\n");

	printf("Check if 4 cards were drawn from the deck of player one: ");
	assert(old_deckCount_1 == new_deckCount_1 + 4);
	printf("PASSED\n");

	printf("Check if 1 more cards are in the hand of player two: ");
	assert(old_handCount_2 == new_handCount_2 - 1);
	printf("PASSED\n");

	printf("Check if 1 card was drawn from the deck of player two: ");
	assert(old_deckCount_2 == new_deckCount_2 + 1);
	printf("PASSED\n");

	printf("Testing complete. All tests passed.\n");
	return 0;
}