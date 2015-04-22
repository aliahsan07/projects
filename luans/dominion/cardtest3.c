#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dominion.h"
#include "rngs.h"

int main(int argc, char *argv[])
{
	struct gameState *game = newGame();
	
	int card = remodel;
	int choice1 = adventurer;
	int choice2 = gardens;
	int choice3 = embargo;
	int pos = 4;
	int bonus = 10;

	printf("Starting to test remodel card......\n");
	
	int result = cardEffect(card, choice1, choice2, choice3, game, pos, &bonus);
	assert(result == 0);
	
	return EXIT_SUCCESS;
}
