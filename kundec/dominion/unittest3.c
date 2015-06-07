#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

	printf("\nStarting Unit Test 3 (fullDeckCount)\n");

	int *tempKC = kingdomCards(council_room, feast, mine, great_hall, cutpurse,
		treasure_map, outpost, smithy, gardens, embargo);
	struct gameState *G = newGame();

	initializeGame(4, tempKC, 4, G);

	int a = fullDeckCount(G->whoseTurn, copper, G);
	int b = fullDeckCount(G->whoseTurn, estate, G);
	int c = fullDeckCount(G->whoseTurn, feast, G);
	int d = fullDeckCount(G->whoseTurn, baron, G);
	printf("Copper count:  %i, Estate Count:  %i, Feast Count:  %i, Baron Count:  %i", a, b, c, d);


	printf("\n*********************************************************\n");
	printf("Successfully finished Unit Test 3\n");
	printf("*********************************************************\n\n");
	return 0;
}