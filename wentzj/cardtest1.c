//CardTest1
//Card: gardens
//Parameters: 

#include "dominion.h"
#include "dominion_helpers.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"
#include <time.h>
#include <math.h>

int main(){
	struct gameState state;
	int testCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int random;
	int v;
	srand(time(NULL));
	random = rand();
	initializeGame(2, testCards, random, &state);
	printf("---------------------\nTesting Card: Gardens\n---------------------\n\n");

	v = cardEffect(gardens,0,0,0,&state,0,0);
	assert(v==-1);

	return 0;
}
