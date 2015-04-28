#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){
	//card test for council_room	
	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, smithy, village, baron, great_hall, minion};

	int player1 = 0;
	int player2 = 1;
	int oldDeck1; 
	int oldDeck2; 
	int newDeck1; 
	int newDeck2; 

	initializeGame(2, k, 4, &G);
	oldDeck1 = G.deckCount[player1];
	oldDeck2 = G.deckCount[player2];

	cardEffect(council_room, 0, 0, 0, &G, 0, 0);

	newDeck1 = G.deckCount[player1];
	newDeck2 = G.deckCount[player2];

	assert(newDeck1 == oldDeck1 - 4);
	assert(newDeck2 == oldDeck2 - 1);
	
	printf("Unit test for council_room passed\n");
	
	return 0;
}
