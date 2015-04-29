#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

/*********************************
 ** This cardtest tests Smithy	**
 *********************************/

int main (int argc, char** argv) {
  struct gameState G;
  struct gameState copy;
  int choice1 = 1;
  int choice2 = 1;
  int choice3 = 1;
  int handPos = 1;
  int bonus = 0;

  printf ("\n*********************\n");
  printf ("cardtest3.\n");
  
  	if(argv[1] == NULL)
	{
		printf ("Enter a positive integer argument for the random number generator seed.\n");
		return 0;
	}

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
  
  initializeGame(2, k, atoi(argv[1]), &G);
  
  G.hand[1][handPos] = smithy;
  copy = G;
  
  cardEffect(smithy, choice1, choice2, choice3, &G, handPos, &bonus);
  //assert(G.deckCount[1] == (copy.deckCount[1])-2); 	//Fails
  //assert(G.handCount[1] == (copy.handCount[1])+2); 	//Fails
  assert(G.numActions == (copy.numActions));
  assert(G.playedCardCount == (copy.playedCardCount+1));
  

  printf ("Test fails.\n");
  printf ("*********************\n");
  
	return 0;
}
