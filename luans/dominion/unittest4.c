#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dominion.h"
#include "rngs.h"

int main(int argc, char *argv[])
{
	struct gameState *game = newGame();
	int pos = 4;
	int choice1 = gardens;
	int choice2 = village;
	int choice3 = cutpurse;
	
	printf("Starting to play cards......");
	
	int result = playCard(pos, choice1, choice2, choice3, game);
	assert(result == 0);
	
	return EXIT_SUCCESS;
}