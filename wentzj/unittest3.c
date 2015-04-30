//Unit Test 3
//Function: initializeGame
//Parameters: numPlayers, kingdomCards, randomSeed, gameState *state

#include "dominion.h"
#include "assert.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"
#include <math.h>
#include <time.h>

int main() {
	struct gameState state;
	struct gameState *g = &state;
	int v = 0;
	int random;
	int testCards1[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int testCards2[10] = {adventurer, adventurer, council_room, council_room, feast, feast, gardens, gardens, mine, mine};
	int testCards3[10];
	srand(time(NULL));
	
	random = rand();
	printf("--------------------------------\nTesting Function: initializeGame\n--------------------------------\n");
	v = initializeGame(2, testCards1, random, g);
	assert(v==0);

	printf("\n-------------------------\nTesting number of players\n-------------------------\n");
	v = initializeGame(1, testCards1, random, g);
	assert(v==-1);

	printf("\n------------------------------------\nTesting selected cards are different\n------------------------------------\n");
	v = initializeGame(2, testCards2, random, g);
	assert(v==-1);

	printf("\n------------------------------\nTesting shuffle player decks\n------------------------------\n");
	v = initializeGame(2, testCards3, random, g);
	assert(v==-1);

   return 0;
}
