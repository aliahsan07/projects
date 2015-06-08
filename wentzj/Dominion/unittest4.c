//Unit Test 4
//Function: numHandCards
//Parameters: gameState

#include "dominion.h"
#include "assert.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include "math.h"
#include <time.h>

int main() {
	struct gameState state;
	int random;	
	int testCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	srand(time(NULL));
	random = rand();

	initializeGame(2, testCards, random, &state);
	
	printf("--------------------\nTesting numHandCards\n--------------------\n");
	assert(numHandCards(&state)==state.handCount[whoseTurn(&state)]);


   return 0;
}
