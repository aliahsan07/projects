/*********************************************************************
** minion_test.c
** Reilly Collins [colliell]
** CS 362, Spring 2015
** Unit tester for minion card
*********************************************************************/
#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>

int main (int argc, char* argv[]) 
{
	srand(time(NULL));
	int i, init = -1;
	int seed, num_players = 0;
  	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, baron, tribute, smithy};
	struct gameState * G = newGame();

	//use CLA or random value for seed
	if(argc > 1) seed = atoi(argv[1]);
	else seed = rand();

	for(i = 0; i < 10; i++)
	{
		printf("\n\n***TEST %d***\n", i+1);
		num_players = rand()%5; //gives max of 4 players per game instructions
		while(num_players == 0 || num_players == 1) num_players = rand()%5; //makes sure 2-4 players
		assert(num_players > 1 && num_players < 5); 


		//initialize game and assert it worked
		init = initializeGame(num_players, k, seed, G);
		assert(init == 0);

		//check for option 1
		int coins_before = G->coins;
		int r = cardEffect(minion, 1, 0, 0, G, 0, 0);
		int coins_after = G->coins;
		assert(r == 0);
		printf("Testing choice 1.\t\t");
		if(coins_before != coins_after-2) printf("\terror: coins before: %d  coins after = %d\n", coins_before, coins_after);
		else printf("\tPassed\n");

		num_players = rand()%5; //gives max of 4 players per game instructions
		while(num_players == 0 || num_players == 1) num_players = rand()%5; //makes sure 2-4 players
		assert(num_players > 1 && num_players < 5); 


		//initialize game and assert it worked
		init = initializeGame(num_players, k, seed, G);
		assert(init == 0);
		//check for option 2
		G->hand[0][G->handCount[0]-1] = minion;
		int deck_before = G->deckCount[0];
		r = cardEffect(minion, 0, 1, 0, G, 0, 0);
		int deck_after = G->deckCount[0];
		assert(r == 0);
		printf("Testing choice 2.\t\t");
		if(deck_before != deck_after+4) printf("\terror: deck count before: %d  deck count after: %d\n", deck_before, deck_after);
		else printf("\tPassed\n");

		//initialize game and assert it worked
		init = initializeGame(num_players, k, seed, G);
		assert(init == 0);

		//check for option 1
		coins_before = G->coins;
		r = cardEffect(minion, 0, 1, 0, G, 0, 0); //SWAPPED OPTION 1 AND 2
		coins_after = G->coins;
		assert(r == 0);
		printf("Testing choice 1, swapped.\t");
		if(coins_before != coins_after-2) printf("\terror: coins before: %d  coins after = %d\n", coins_before, coins_after);
		else printf("\tPassed\n");

		num_players = rand()%5; //gives max of 4 players per game instructions
		while(num_players == 0 || num_players == 1) num_players = rand()%5; //makes sure 2-4 players
		assert(num_players > 1 && num_players < 5); 


		//initialize game and assert it worked
		init = initializeGame(num_players, k, seed, G);
		assert(init == 0);
		//check for option 2
		G->hand[0][G->handCount[0]-1] = minion;
		deck_before = G->deckCount[0];
		r = cardEffect(minion, 1, 0, 0, G, 0, 0); //SWAPPED OPTION 2 AND 1
		deck_after = G->deckCount[0];
		assert(r == 0);
		printf("Testing choice 2, swapped.\t");
		if(deck_before != deck_after+4) printf("error: deck count before: %d\tdeck count after: %d\n", deck_before, deck_after);
		else printf("\tPassed\n");
	}

	return 0;

}
