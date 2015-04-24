#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "cbmc_dominion.h"
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"
#include "interface.h"

int main(int argc, char *argv[])
{
	struct gameState *game = newGame();
	int player = 3;
	
	printf("Starting to shuffle cards......\n");
	
	int result = shuffle(player, game);
	
	assert(result == 0);
	printf("SHUFFLE: %d\n", result);
	
	return EXIT_SUCCESS;
}