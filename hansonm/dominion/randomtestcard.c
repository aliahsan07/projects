#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#define MAX_TESTS 10

int main (int argc, char* argv[]) 
{
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	struct gameState G;
	int i, players, player, seed, coin_bonus;
	
	for(i = 0; i < MAX_TESTS; i++ ){
		players = rand() % MAX_PLAYERS;
		seed = rand();
		
		initializeGame(players, k, seed, &G);
		
		//G.deckCount[player] = rand() % MAX_DECK;
		//G.discardCount[player] = rand() % MAX_DECK;
		//G.handCount[player] = rand() % MAX_HAND;
		//G.coins = rand();
		//G.numBuys = rand();
		//G.numActions = rand();
		coin_bonus = rand();
		
		//int test_handcount = G.handCount[0] - 1; //No cards were added
		//int test_coins = G.coins; // No extra coins
		//int test_numbuys = G.numBuys; // No extra buys
		//int test_decksize = G.deckCount[0]; //No cards were drawn
		//int test_actioncount = G.numActions; //Doesn't count as a action
		
		cardEffect(adventurer, 1, 1, 1, &G, G.handCount[player], &coin_bonus);
		
		//if(G.handCount[0] != test_handcount) printf("Hand count is off");
		//if(G.coins != test_coins) printf("Coins count is off");
		//if(G.numBuys != test_numbuys) printf("Buy count count is off");
		//if(G.deckCount[0] != test_decksize) printf("Deck count count is off");
		//if(G.numActions != test_actioncount) printf("Action count count is off");

	}
	
	
	printf("test passed\n");
	
}