#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

//village
int main(int argc, char *argv[]){
	int r;
	int count;
	int actions;
	int bonus = 0;
	struct gameState *game;
	game = newGame();
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	initializeGame(3,k,42,game);
	count = game->handCount[whoseTurn(game)];
	actions = game->numActions;
	r = cardEffect(village,copper,copper,copper,game,3,&bonus);
	assert(r == 0);
	assert(game->handCount[whoseTurn(game)] == count);
	printf("The same number of cards is held as before.\n");
	printf("No net card change expected.\n");
	assert(game->numActions == actions + 2);
	printf("Two more actions are available.\n");
	return 0;
}