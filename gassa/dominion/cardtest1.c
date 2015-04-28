#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

//smithy
int main(int argc, char *argv[]){
	int r;
	int count;
	int bonus = 0;
	struct gameState *game;
	game = newGame();
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	initializeGame(3,k,42,game);
	count = game->handCount[whoseTurn(game)];
	r = cardEffect(smithy,0,0,0,game,3,&bonus);
	assert(r == 0);
	assert(game->handCount[whoseTurn(game)] == count + 2);
	printf("Two more cards are held now than before.\n");
	printf("This is a sign of smithy passing.\n");
	return 0;
}