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
	
	int card = baron;
	int choice1 = village;
	int choice2 = minion;
	int choice3 = mine;
	int pos = 4;
	int bonus = 10;

	printf("Starting to test baron card......\n");
	
	int result = cardEffect(card, choice1, choice2, choice3, game, pos, &bonus);
	assert(result == 0);
	
	return EXIT_SUCCESS;
}
