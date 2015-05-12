#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main () {

	struct gameState* new_game = newGame();

	int card = great_hall;
	int player = 0;
	int check;
	int old_hand_count;
	int old_num_action;

	assert(new_game != NULL);

	int k[10] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, great_hall};

	initializeGame(2, k, 5, new_game);

	printf("Testing great_hall's effect through cardEffect ... \n");

	old_hand_count = new_game -> handCount[player];
	old_num_action = new_game -> numActions;

	check = cardEffect(card, 0, 0, 0, new_game, 0, 0);

	printf("old action count  is %d\n", old_num_action);
	printf("new action count is %d\n", new_game -> numActions);


	if (check == 0 && new_game -> handCount[player] == old_hand_count && new_game -> numActions == old_num_action + 1)
		printf("Test passed: Great Hall had the correct return value and increased number of actions by 1.\n");

	else
		printf("Test failed: Great hall returned an incorrect value.\n");



  return 0;
}
