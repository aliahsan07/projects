#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"


// Testing Gardens

int main (int argc, char** argv) {

	printf("Creating new gameState: \n\n");
	struct gameState *s = newGame();
	int numCards;
	assert(s != NULL);
	printf("Successfully created gameState\n\n");
	
	int c[10] = {outpost, smithy, embargo, baron, adventurer, village ,gardens , mine, great_hall,
                   feast};
				   
	printf("Initializing Game: \n\n");
	initializeGame(2,c,21,s);
	numCards = s->handCount[s->whoseTurn];
	assert(s->outpostPlayed == 0);
	assert(s->phase == 0);
	assert(s->numActions == 1);
	assert(s->numBuys == 1);
	assert(s->playedCardCount == 0);
	assert(s->whoseTurn ==0);
	assert(s->handCount[s->whoseTurn] == numCards);
	printf("Successfully initialized Game \n\n");
	
	int r = cardEffect(gardens, 0, 0, 0, s, 0, 0);
	
	printf("Checking Garden through CardEffect function\n\n");
	assert(r == -1);
	printf("Success!\n\n");
	
	printf("Checking Garden through GardenEffect function\n\n");
	r = gardenEffect();
	assert( r == -1); 
	printf("Success!\n");
	
	return 0;
}

