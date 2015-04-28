#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"

//Testing Great Hall


int main (int argc, char** argv) {


	printf("Creating new gameState: \n\n");
	struct gameState *s = newGame();
	assert(s != NULL);
	int numCards;
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
	
	int r = cardEffect(great_hall, 0, 0, 0, s, 0, 0);
	
	printf("Checking Great Hall through CardEffect function\n\n");
	printf("Checking to see if NumActions Increased\n\n");
	assert(s->numActions == 2);
	printf("Checking if cards decreased appropriately\n\n");
	assert(s->handCount[s->whoseTurn] == numCards);
	printf("Returning Correct Value...\n\n");
	assert(r == 1);
	printf("Everything was a Success!\n\n");
	
	
	printf("Checking Great Hall through GreatHallEffect function\n\n");
	r = greatHallEffect(0,s,0);
	printf("Checking to see if NumActions Increased\n\n");
	assert(s->numActions == 3);
	printf("Should still have same number of cards...\n\n");
	assert(s->handCount[s->whoseTurn] == numCards);
	printf("Returning Correct Value...\n\n");
	assert(r == 1);
	printf("Everything was a Success!\n\n");
	
	return 0;
}



