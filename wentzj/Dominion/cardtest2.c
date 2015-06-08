//CardTest2
//Card: 
//Parameters: 

#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>
#include <time.h>

int main(){
	struct gameState state;
	int random;
	int testCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, outpost};
	int v;
	srand(time(NULL));
	random = rand();

	printf("---------------------\nTesting Card: Outpost\n---------------------\n\n");
	initializeGame(2, testCards, random, &state);

	v = state.outpostPlayed+1;

	cardEffect(outpost,0,0,0,&state,0,0);

	assert(state.outpostPlayed==v);

	return 0;
}
