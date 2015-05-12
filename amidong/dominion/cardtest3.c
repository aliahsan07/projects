#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"

//Testing Outpost


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
	
	int r = cardEffect(outpost, 0, 0, 0, s, 0, 0);
	
	printf("Checking Outpost through CardEffect function\n\n");
	printf("Checking if OutpostPlayed increased\n\n");
	assert(s->outpostPlayed == 1);
	printf("Checking if cards decreased appropriately\n\n");
	assert(s->handCount[s->whoseTurn] == (numCards-1));
	printf("Checking correct return value\n\n");
	assert(r == 0);
	printf("Everything was a Success!\n\n");
	
	return 0;
}