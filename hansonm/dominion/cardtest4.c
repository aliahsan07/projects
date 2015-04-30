#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main (int argc, char* argv[]) 
{
	int rv;  //return value
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	struct gameState G;
	
	printf ("Testing for card Embargo\n");
	printf("Embargo: +2 coins, trash this card. Put an Embargo token on top of a Supply pile\n");
	printf("When a player buys a card, he gains a Curse card per embargo token on that pile");
	
	rv = initializeGame(2, k, 10, &G);
	assert (rv == 0); //check game is created
	
	int test_handcount = G.handCount[0] - 1; //No cards were added
	int test_actioncount = G.numActions; //Doesn't count as a action
	int test_decksize = G.deckCount[0]; //No cards were drawn
	int test_numbuys = G.numBuys; // No extra buys
	int test_coins = G.coins + 2; // two extra coins
	int test_embargoTokens = G.embargoTokens[0] + 1; //1 embargo Token
	
	printf("Deck count before card: ");
	printf("%i\n", G.deckCount[0]);
	
	
	printf("Hand count before card: ");
	printf("%i\n", G.handCount[0]);
	printf("Action count before card: ");
	printf("%i\n", G.numActions);
	printf("Buy count before card: ");
	printf("%i\n", G.numBuys);
	printf("Coins count before card: ");
	printf("%i\n", G.coins);
	printf("Embargo count before card: ");
	printf("%i\n", G.embargoTokens[0]);
	rv = cardEffect(embargo, 0, 0, 0, &G, 0, 0);
	assert (rv ==0); //check card was played
	
	
	printf("Hand count after card: ");
	printf("%i\n", G.handCount[0]);
	assert(test_handcount == G.handCount[0]); //check to see if player got 4 cards
	
	printf("Action count after card: ");
	printf("%i\n", G.numActions);
	assert(test_actioncount == G.numActions); //check to see if player on actions
	
	printf("Deck count after card: ");
	printf("%i\n", G.deckCount[0]);
	assert(test_decksize == G.deckCount[0]); //check deck size is correct
	
	printf("Buy count after card: ");
	printf("%i\n", G.numBuys);
	assert(test_numbuys == G.numBuys); //check number of buys is correct
	
	printf("Coin count after card: ");
	printf("%i\n", G.coins);
	assert(test_coins == G.coins); //check number of coins is correct
	
	printf("Embargo count after card: ");
	printf("%i\n", G.embargoTokens[0]);
	assert(test_embargoTokens == G.embargoTokens[0]); //check number of coins is correct
	
	printf("test passed\n");
	
}