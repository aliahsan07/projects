#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define MAX_TESTS 100 //max num tests I want to do, can change to increase/decrease as needed

int main() {

	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	int i;
	int r = 0;
	int choice1 = 0, choice2 = 0, choice3 = 0;
	int numPlayers = 0, curPlayer = 0;
	int handPos = 0, handCount = 0, deckCount = 0;
	int seed;

	struct gameState G;

	srand(time(NULL));

	printf("**Testing adventurer.\n\n");

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

		//Save values to compare later
		deckCount = G.deckCount[curPlayer];

		//1 in 3 chance of making empty deck, increase coverage as shown in class
		if (seed%3 == 0) G.deckCount[curPlayer] = 0;

		//Need to make sure there's at least 2 treasure cards in deck
		int j;
	    for (j = 0; j < G.handCount[curPlayer]; j++) gainCard(copper, &G, 2, curPlayer);

		r = cardEffect(adventurer, choice1, choice2, choice3, &G, handPos, 0);

		int x, treasure = 0, zero = 0;
		for(x = 0; x < G.handCount[curPlayer]; x++)
		{
			if(G.hand[curPlayer][x] == copper || G.hand[curPlayer][x] == silver || G.hand[curPlayer][x] == gold) treasure++;
			else if(G.hand[curPlayer][x] == 0) zero++; //to account for new hand
		}

		//Make sure cardEffect returned correctly
		assert(r == 0);	

		//If treasure not increased by at least two, adventurer didn't do its job
		if(treasure < 2 && zero != G.handCount[curPlayer] && G.handCount[curPlayer] != 0) 
		{
			printf("\tTest failed: treasure count (i = %d)\n", i);
			printf("\t\tG.handCount = %d\ttreasure = %d\n", G.handCount[curPlayer], treasure);
			for(x = 0; x < G.handCount[curPlayer]; x++)
			{
				printf("\tG.hand[curPlayer][x] = %d\n", G.hand[curPlayer][x]);
			}
			printf("\n");

		}
		//If handCount is negative, something went wrong
		if(G.handCount[curPlayer] < 0) 
		{
			printf("\tTest failed: hand count (i = %d)\n", i);
			printf("\t\tG.handCount = %d\t handCount = %d\n\n", G.handCount[curPlayer], handCount);
		}

		if(deckCount < G.deckCount[curPlayer]+2 && deckCount != G.deckCount[curPlayer] && G.deckCount[curPlayer] != 0)
		{
			printf("\tTest failed: deck count (i = %d)\n", i);
			printf("\t\tG.deckCount = %d\t deckCount = %d\n\n", G.deckCount[curPlayer], deckCount);
		}

	}

	printf("**Test complete.\n");

	return 0;
}