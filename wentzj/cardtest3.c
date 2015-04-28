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
	int testCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, embargo, great_hall};
	int random;
	int v;
	srand(time(NULL));
	random = rand();
	initializeGame(2, testCards, random, &state);

	printf("Testing Card: ");

	v = state.coins+2;
	cardEffect(embargo, 0, 0, 0, &state, 0, 0);
	assert(state.coins==v);



	return 0;
}
