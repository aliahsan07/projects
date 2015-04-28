#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Test endTurn, which seems reasonably simple.
int main(int argc, char *argv[]){
	struct gameState *game;
	int* cards;
	int r;
	game = newGame();
	cards = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy);
	initializeGame(MAX_PLAYERS, cards, 42, game);
	int currentPlayer = whoseTurn(game);
	r = endTurn(game);
	assert(r == 0);
	assert(currentPlayer != whoseTurn(game));
	printf("endTurn tested.\n");
	return 0;
}