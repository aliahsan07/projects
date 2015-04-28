#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

//gardens
int main(int argc, char *argv[]){
	int r;
	int bonus = 0;
	struct gameState *game;
	game = newGame();
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	initializeGame(3,k,42,game);
	r = cardEffect(gardens,copper,copper,copper,game,3,&bonus);
	assert(r != 0);
	printf("Gardens returned a no discard result.\n");
	return 0;
}