#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"


int main () {

	struct gameState* new_game = newGame();

	int card = smithy;
	int check;
	int old_hand_count;
	int player = 0;

	assert(new_game != NULL);

	int k[10] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast};

	initializeGame(2, k, 5, new_game);

	old_hand_count = new_game -> handCount[player];

	printf("Testing Smithy's effect throuch cardEffect ... \n");

	check = cardEffect(card, 0, 0, 0, new_game, 0, 0);

	printf("old count is %d\n", old_hand_count);
	printf("new hand count is %d\n", new_game -> handCount[player]);

	if (check == 0 && (new_game -> handCount[player] == old_hand_count + 2))
		printf("Test passed: Function had the correct return value and drew 2 cards.\n");
	else
		printf("Test failed!\n");

	printf("\nTesting Smithy's effect throuch smithy_effect ... \n");

	new_game = newGame();

	initializeGame(2, k, 1 , new_game);

	check = smithy_effect(0, player, new_game, 0);


	printf("old count is %d\n", old_hand_count);
	printf("new hand count is %d\n", new_game -> handCount[player]);

	if (check == 0 && (new_game -> handCount[player] == old_hand_count + 2))
		printf("Test passed: Function had the correct return value and drew 2 cards.\n");
	else
		printf("Test failed!\n");


  return 0;
}
