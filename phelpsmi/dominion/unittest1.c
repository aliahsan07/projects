#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int main (int argc, char** argv) {
	printf("testing initializeGame()\n");

 	struct gameState G;
 	int seed = 1;
 	int result;

  	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int repeat_k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, feast, baron, great_hall}; //feast is repeated
 	int low_k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village}; //only 8 cards
 	int empty_k[10] = {};

	printf("starting tests...\n");

	result = initializeGame(1 , k, seed, &G);
 	assert( result == -1);

 	result = initializeGame(20, k, seed, &G);
 	assert( result == -1);

 	result = initializeGame(2, repeat_k, seed, &G);
 	assert(result == -1);
  
 	result = initializeGame(2, low_k, seed, &G);
 	assert(result == -1);

 	result = initializeGame(2, empty_k, seed, &G);
  	assert(result == -1);

 	result = initializeGame(2, k, seed, &G);
 	assert(result == 0);

 	assert(G.numPlayers == 2);
 	printf("%d\n", G.deckCount[0]);
 	printf("%d\n", G.handCount[0]);
 	printf("%d\n", G.deckCount[1]);
 	assert(G.deckCount[0] == 5);
 	assert(G.deckCount[1] == 5);

 	assert(G.handCount[0] == 5);
 	assert(G.handCount[1] == 5);

 	printf("initializeGame() PASSED\n");
  	return 0;

}
