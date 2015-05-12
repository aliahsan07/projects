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
	
	printf ("Testing for card Smithy\n");
	printf("Smithy: +3 Card \n");
	
	rv = initializeGame(2, k, 10, &G);
	assert (rv == 0); //check game is created
	
	int test_handcount = G.handCount[0] + 2; //Don't add a card because the Smithy is used
	int test_actioncount = G.numActions; //Doesn't count as a action
	int test_decksize = G.deckCount[0] - 3; //how many cards that were drawn
	
	printf("Deck count before card: ");
	printf("%i\n", G.deckCount[0]);
	
	
	printf("Hand count before card: ");
	printf("%i\n", G.handCount[0]);
	printf("Action count before card: ");
	printf("%i\n", G.numActions);
	rv = cardEffect(smithy, 0, 0, 0, &G, 0, 0);
	assert (rv ==0); //check card was played
	
	
	printf("Hand count after card: ");
	printf("%i\n", G.handCount[0]);
	assert(test_handcount == G.handCount[0]); //check to see if player 0 got a card
	
	printf("Action count after card: ");
	printf("%i\n", G.numActions);
	assert(test_actioncount == G.numActions); //check to see if player 0 got a action
	
	printf("Deck count after card: ");
	printf("%i\n", G.deckCount[0]);
	assert(test_decksize == G.deckCount[0]);
	
	printf("test passed\n");
	
	return 0;
	
	
}