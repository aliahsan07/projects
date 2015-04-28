#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//next function in dominion.c, shuffle.
int main(int argc, char *argv[]) {
	struct gameState *game;
	int* cards;
	int r;
	game = newGame();
	cards = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy);
	initializeGame(MAX_PLAYERS, cards, 42, game);
	r = shuffle(whoseTurn(game), game);
	assert(r == 0);
	printf("Shuffle worked.\n");
	return 0;
}