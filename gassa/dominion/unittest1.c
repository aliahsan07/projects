#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Test initializeGame first, because it's needed to start the game
int main(int argc, char *argv[]){
	int i;
	int r;
	struct gameState *game;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	printf("Player number tests:\n");
	printf("Calling game init for valid players\n");
	for(i=2; i <= MAX_PLAYERS; i++){
		game = newGame();
		r = initializeGame(i,k,42,game);
		assert (r == 0);
	}
	printf("Calling game init for fewer and more players\nthan is valid\n");
	for(i=0; i < 2; i++){
		game = newGame();
		r = initializeGame(i,k,42,game);
		assert (r == -1);
	}
	for(i=MAX_PLAYERS+1; i <= MAX_PLAYERS+4; i++){
		game = newGame();
		r = initializeGame(i,k,42,game);
		assert (r == -1);
	}
	printf("Player number tests concluded.\n");
	printf("Invalid card set test: ");
	k[1] = adventurer;
	r = initializeGame(2,k,42,game);
	assert(r == -1);
	printf("Passed.\n");
	return 0;
}