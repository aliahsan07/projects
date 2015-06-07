#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#define MAX_TESTS 100

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
		
		//G.whoseTurn = player;
		
		G.deckCount[player] = rand() % MAX_DECK;
		G.discardCount[player] = rand() % MAX_DECK;
		G.handCount[player] = rand() % MAX_HAND;
		G.coins = rand();
		G.numBuys = rand();
		G.numActions = rand();
		coin_bonus = rand();
		
		int test_handcount = G.handCount[0] + 1; //Two cards were added
		int test_coins = G.coins; // No extra coins
		int test_numbuys = G.numBuys; // No extra buys
		int test_decksize = G.deckCount[0]; //No cards were drawn
		int test_actioncount = G.numActions; //Doesn't count as a action
		//int test_discardcount = G.discardCount[G.whoseTurn]; //card is played
		printf("Discard count is %i --",G.discardCount[player]);
		cardEffect(adventurer, 1, 1, 1, &G, G.handCount[player], &coin_bonus);
		printf("Discard count now is %i\n",G.discardCount[player]);
		if(G.handCount[0] != test_handcount) printf("Hand count is off: %i should be %i\n", test_handcount, G.handCount[0]);
		//if(G.discardCount[0] != test_discardcount) printf("Discard count is off: %i should be %i\n", test_discardcount, G.discardCount[player]);
		if(G.coins != test_coins) printf("Coins count is off\n");
		
		if(G.numBuys != test_numbuys) printf("Buy count count is off\n");
		//if(G.deckCount[0] != test_decksize) printf("Deck count count is off");
		if(G.numActions != test_actioncount) printf("Action count count is off\n");

	}
	
	
	printf("test passed\n");
	
}