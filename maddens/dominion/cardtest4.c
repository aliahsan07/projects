#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main () {

	struct gameState* new_game = newGame();
  assert(new_game != NULL);


	int card = outpost;
	int player = 0;
	int check;
	int old_hand_count;

	int k[10] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, outpost};

	initializeGame(2, k, 5, new_game);

	printf("Testing outpost's effect through cardEffect ... \n");

	old_hand_count = new_game -> handCount[player];

	check = cardEffect(card, 0, 0, 0, new_game, 0, 0);

  printf("Outpost played is now %d\n", new_game -> outpostPlayed);
  printf("Old car count  is %d\n", old_hand_count);
  printf("New card count is %d\n", new_game -> handCount[player]);

	if (check == 0 && new_game -> handCount[player] == old_hand_count - 1 && new_game -> outpostPlayed == 1)
		printf("Test passed: Outpost had the correct return value, incremented outpostPlayed and discarded a card.\n");

	else
		printf("Test failed: Outpost returned an incorrect value.\n");



  return 0;
}
