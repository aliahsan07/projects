#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Testing supplyCount.
int main(int argc, char *argv[]) {
	struct gameState *game;
	int r;
	game = newGame();
	r = supplyCount(duchy, game);
	assert(r == 0);
	return 0;
}