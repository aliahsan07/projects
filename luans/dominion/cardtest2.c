#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dominion.h"
#include "rngs.h"

int main(int argc, char *argv[])
{
	struct gameState *game = newGame();
	int tmp = 0;
	int player = 3;
	int choice1 = 1;
	
	printf("Starting to test feast card......\n");
	
	int result = func_feast(player, &tmp, choice1, game);
	assert(result == 0);
	
	return EXIT_SUCCESS;
}
