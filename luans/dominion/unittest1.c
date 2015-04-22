#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#include "cbmc_dominion.h"
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"
//#include "interface.h"

int main(int argc, char *argv[])
{
	struct gameState *game = newGame();
	int card = council_room;
	
	printf("Starting to test supplying count......\n");
	
	int result = supplyCount(card, game);
	assert(result == 0);
		
	return EXIT_SUCCESS;
}