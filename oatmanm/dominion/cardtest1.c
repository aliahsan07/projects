#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(){

	printf("Testing adventurer card...\n");

	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2, k, 2, &G);
	G.hand[0][0] = adventurer;

	/*for (int i = 0; i < G.handCount[0]; i++)
		printf("hand = %d\n", G.hand[0][i]);
	for (int i = 0; i < G.deckCount[0]; i++)
		printf("deck = %d\n", G.deck[0][i]);
	for (int i = 0; i < G.discardCount[0]; i++)
		printf("discard = %d\n", G.discard[0][i]);*/

	int currentPlayer = 0;
	int count = 0;

	for (int i = 0; i < G.handCount[currentPlayer]; i++){
		if (G.hand[currentPlayer][i] == copper)
			count++;
	}
	printf("Copper in hand = %d\n", count);
	assert(count == 3);
	count = 0;

	count = G.handCount[0];
	printf("Total number of cards in hand = %d\n", count);
	assert(count == 5);
	count = 0;

	cardEffect(adventurer, 0, 0, 0, &G, 0, 0);
	printf("After adventurer played...\n");

	for (int i = 0; i < G.handCount[currentPlayer]; i++){
		if (G.hand[currentPlayer][i] == copper)
			count++;
	}
	printf("Copper in hand = %d\n", count);
	count = 0;

	count = G.handCount[0];
	printf("Total number of cards in hand = %d\n", count);
	count = 0;

	printf("\nNew hand: 3 copper, 1 adventurer, and 1 estate. First five cards in deck: copper, smithy, hot garbage, copper, estate.\n");
	for (int i = 0; i < 3; i++)
		G.hand[0][i] = copper;

	G.hand[0][3] = adventurer;
	G.hand[0][4] = estate;
	G.handCount[0] = 5;
	G.deckCount[0] = 5;
	G.discardCount[0] = 0;
	G.deck[0][0] = copper;
	G.deck[0][1] = smithy;
	G.deck[0][2] = "hot garbage";
	G.deck[0][3] = copper;
	G.deck[0][4] = copper;

	printf("\nExpected results: 5 copper, 1 estate in hand. 1 estate in deck. Smithy and hot garbage in the discard pile.\n");
	
	cardEffect(adventurer, 0, 0, 0, &G, 3, 0);

	for (int i = 0; i < G.handCount[currentPlayer]; i++){
		if (G.hand[currentPlayer][i] == copper)
			count++;
	}
	printf("\nCopper in hand = %d\n", count);
	count = 0;

	count = G.handCount[0];
	printf("Total number of cards in hand = %d\n", count);
	count = 0;

	count = G.deckCount[0];
	printf("deck count = %d\n", count);
	count = 0;

	count = G.discardCount[0];
	printf("discard count = %d\n", count);
	count = 0;

	printf("Testing done for adventurer.\n");

	return 0;
}