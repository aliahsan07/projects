#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(){
	printf("Testing councilRoomCard...\n");
	struct gameState G;
	int count = 0;
	int countBefore = 0;
	int countBuysBefore;
	int countBuys;
	int k[10] = {adventurer, village, feast, gardens, remodel, mine, steward, outpost, council_room, smithy};
	initializeGame(2, k, 2, &G);
	G.hand[0][2] = council_room;
	countBefore = G.handCount[1];
	countBuysBefore = G.numBuys;

	cardEffect(council_room, 0, 0, 0, &G, 2, 0);
	printf("Current Situation: 3 copper, 1 estate, 1 council room in hand. 2 estate and 3 copper in deck.\n");
	printf("Expected Result: 6 copper, 2 estates in hand. 1 copper in deck. 1 council room in discard.\n");

	int currentPlayer = 0;

	for (int i = 0; i < G.handCount[currentPlayer]; i++){
		if (G.hand[currentPlayer][i] == copper)
			count++;
	}
	printf("Copper in hand = %d\n", count);
	count = 0;

	count = G.handCount[currentPlayer];
	printf("Total number of cards in hand = %d\n", count);
	count = 0;

	count = G.deckCount[currentPlayer];
	printf("deck count = %d\n", count);
	count = 0;

	count = G.discardCount[currentPlayer];
	printf("discard count = %d\n", count);
	count = 0;

	countBuys = G.numBuys;
	printf("Number of buys before card was drawn: %d\n", countBuysBefore);
	printf("Number of buys after card was drawn: %d\n", countBuys);

	count = G.handCount[1];
	printf("Number of cards in hand of other player:\n");
	printf("Before council room was drawn: %d\n", countBefore);
	printf("After council room was drawn: %d\n", count);

	printf("Testing for council room done.\n");

	return 0;
}