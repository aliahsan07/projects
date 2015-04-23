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
	int player = 0;
	int pos = 4;
	
	printf("Starting to test council_room card......\n");
	
	int result = func_council_room(player, pos, game);
	
	assert(result == 0);
	printf("CARD COUNCIL_ROOM: %d\n", result);
	
	return EXIT_SUCCESS;
}