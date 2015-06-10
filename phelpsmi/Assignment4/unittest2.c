#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState G;
	int seed = 1;
	int result;
	int shuffle1, shuffle2;
	int failCount = 0;

	printf("testing shuffle()\n");

  	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

  	initializeGame(2, k, seed, &G);

  	int i;
  	for(i = 0; i <= 16; i++){
  		G.deck[0][i] = i;
  	}
  	G.deckCount[0] = 17;

  	for(i = 0; i < 1000; i++){
  		shuffle(0, &G);
  		shuffle1 = G.deck[0][0];
  		shuffle(0, &G);
  		shuffle2 = G.deck[0][0];
  		if(shuffle1 == shuffle2) failCount++;
  	}

  	assert(failCount < 100);

  	printf("shuffle(): PASSED\n");
  	
  	return 0;

}