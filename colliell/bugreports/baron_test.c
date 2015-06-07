/*********************************************************************
** baron_test.c
** Reilly Collins [colliell]
** CS 362, Spring 2015
** Unit tester for baron card
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

	for(i = 0; i < 100; i++)
	{
		num_players = rand()%5; //gives max of 4 players per game instructions
		while(num_players == 0 || num_players == 1) num_players = rand()%5; //makes sure 2-4 players
		assert(num_players > 1 && num_players < 5); 

		//initialize game and assert it worked
		init = initializeGame(num_players, k, seed, G);
		assert(init == 0);

		int coins_before = G->coins;
		int buys_before = G->numBuys;
		G->hand[0][0] = estate;
		int r = cardEffect(baron, 1, 0, 0, G, 0, 0);
		int coins_after = G->coins;
		int buys_after = G->numBuys;
		assert(r == 0);
		if(coins_before != coins_after-4) printf("error: coins before: %d\tcoins after = %d\n", coins_before, coins_after);
		else printf("Baron passed coins test.\n");
		if(buys_before != buys_after-1) printf("error: buys before: %d\tbuys after = %d\n", buys_before, buys_after);
		else printf("Baron passed buys test.\n");
	}
	return 0;

}
