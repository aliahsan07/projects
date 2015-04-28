#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"


//Testing supplyCount(...);

int main (int argc, char** argv) {


	struct gameState *state = newGame();
	assert(state != NULL);
	state->supplyCount[0] = 100;
	
	int i = 0;
	int result = supplyCount(i,state);
	assert(result == 100);
	return 0; 
}