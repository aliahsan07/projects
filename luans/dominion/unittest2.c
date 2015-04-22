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
	int pos = 3;
	
	printf("Starting to buy a card......\n");
	
	int result = buyCard(pos, game);
	assert(result == 0);
	
	return EXIT_SUCCESS;
}