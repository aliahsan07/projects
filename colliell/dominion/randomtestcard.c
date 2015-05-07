#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define MAX_TESTS 50000

int main() {

	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	int i;
	int r = 0;
	int choice1 = 0, choice2 = 0, choice3 = 0;
	int numPlayers = 0, curPlayer = 0;
	int handPos = 0, handCount = 0, discardCount = 0, numActions = 0;
	int counter = 0;
	int seed;

	struct gameState G;

	srand(time(NULL));

	printf("**Testing great_hall.\n\n");

	for (i = 0; i < MAX_TESTS; i++) 
	{
		//Give random values to cardEffect arguments
		numPlayers = rand()%5; //gives max of 4 players per game instructions
		if(numPlayers == 0 || numPlayers == 1) numPlayers += 2; //need to have 2-4 players
		curPlayer = rand()%numPlayers; 
		seed = rand();
		choice1 = rand()%2;
		choice2 = rand()%2;
		choice3 = rand()%2;
		handPos = rand()%4;

		initializeGame(numPlayers, k, seed, &G);	//initialize Gamestate 

		//Give random values to state variables
		G.deckCount[curPlayer] = rand()%MAX_DECK; 
		G.discardCount[curPlayer] = rand()%MAX_DECK;
		G.handCount[curPlayer] = rand()%MAX_HAND;

		//1 in 2 chance of making empty deck, increase coverage as shown in class
		if (seed%2 == 0) G.deckCount[curPlayer] = 0;

	    //Save some values for comparing later
		handCount = G.handCount[curPlayer]; //should stay the same
		discardCount = G.discardCount[curPlayer]; //should increase by 1
		numActions = G.numActions; //should increase by 1

		r = cardEffect(great_hall, choice1, choice2, choice3, &G, handPos, 0);

		//Make sure cardEffect returned correctly
		assert(r == 0);	

		if(handCount != G.handCount[curPlayer])
		{
			printf("\tTest failed: hand count (i = %d)\n", i);
			printf("\t\tG.handCount = %d\t handCount = %d\n\n", G.handCount[curPlayer], handCount);
		}
		if(discardCount != G.discardCount[curPlayer]-1 && G.discardCount[curPlayer] != 0) counter++;
		if(numActions != G.numActions-1)
		{
			printf("\tTest failed: num actions (i = %d)\n", i);
			printf("\t\tG.numActions = %d\t numActions = %d\n\n", G.numActions, numActions);
		}
	}

	printf("\tTest failed: discard count\n\t\t %d times\n\n", counter);
	printf("**Test complete.\n");

	return 0;
}
