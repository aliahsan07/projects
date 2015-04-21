#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dominion.h"
#include "rngs.h"

int main(int argc, char *argv[])
{
	struct gameState *game = newGame();
	int player = 3;
	
	int result = shuffle(player, game);
	assert(result == 0);
	
	return EXIT_SUCCESS;
}