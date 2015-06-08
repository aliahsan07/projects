#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "rngs.h"
#include "assert.h"

int main(){
	struct gameState state;
	int testCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int random;
	srand(time(NULL));
	random = rand();
	initializeGame(2, testCards, random, &state);
	int firstPlayer = 0;
	int secondPlayer = 1;
	int oldD1, oldD2, newD1, newD2;

	printf("--------------------------\nTesting Card: Council Room\n--------------------------\n ");
	
	oldD1 = state.deckCount[firstPlayer];
	oldD2 = state.deckCount[secondPlayer];

	cardEffect(council_room,0,0,0,&state,0,0);

	newD1 = state.deckCount[firstPlayer];
	newD2 = state.deckCount[secondPlayer];

	assert(newD1 == oldD1 - 4);
	assert(newD2 == oldD2 - 1);

	return 0;
}
