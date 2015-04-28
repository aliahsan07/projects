#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]){
	int r;
	int buys;
	int i;
	int bonus = 0;
	struct gameState *game;
	int players = 3;
	int cardCount[players];
	game = newGame();
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	initializeGame(players,k,42,game);
	for(i=0;i<players;i++){
		cardCount[i] = game->handCount[i] + 1;
	}
	cardCount[whoseTurn(game)] = cardCount[whoseTurn(game)] + 2;
	buys = game->numBuys;
	r = cardEffect(council_room,copper,copper,copper,game,3,&bonus);
	assert(r == 0);
	for(i=0;i<players;i++){
		assert(cardCount[i] == game->handCount[i]);
	}
	printf("The proper number of cards have been added to players.\n");
	assert(game->numBuys == buys + 1);
	printf("The player has one more buy.\n");
	return 0;
}