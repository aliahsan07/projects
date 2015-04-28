#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main () {

	struct gameState* new_game = newGame();

	int card = gardens;
	int check;

	assert(new_game != NULL);

	int k[10] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast};

	initializeGame(2, k, 1 , new_game);

	printf("Testing Garden's effect through cardEffect ... \n");

	check = cardEffect(card, 0, 0, 0, new_game, 0, 0);

	if (check == -1)
		printf("Test passed: Gardens had the correct return value.\n");

	else
		printf("Test failed: Gardens returned an incorrect value.\n");

	printf("\nTesting Garden's effect through gardens_effect ... \n");

	check = gardens_effect();

	if (check == -1)
			printf("Test passed: Gardens had the correct return value.\n");

	else
			printf("Test failed: Gardens returned an incorrect value.\n");


  return 0;
}
