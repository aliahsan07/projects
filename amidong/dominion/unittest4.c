#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Testing whoseTurn();
 
int main (int argc, char** argv) {
	struct gameState *state = newGame();
	assert(state != NULL);
	state->whoseTurn = 1;
	assert(whoseTurn(state) == 1);
	return 0; 
}