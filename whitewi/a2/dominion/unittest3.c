#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

/*************************************************
 ** This unittest checks to see if supplyCount()**
 ** works by changing the amount of cards 		**
 ** available and then rechecking				**
 **												**
 ** This test assumes that initializeGame() is  **
 ** working and will initialize supply. 		**
 *************************************************/

int main (int argc, char** argv) {
  struct gameState G;
  int i;
  
	if(argv[1] == NULL)
	{
		printf ("Enter a positive integer argument for the random number generator seed.\n");
		return 0;
	}

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("\n*********************\n");
  printf ("Testing supplyCount().\n");
  
  int r = initializeGame(2, k, atoi(argv[1]), &G);

  assert (r == 0);
  
  for (i = 0; i < 27; i++)
  {
	  assert(G.supplyCount[i] == supplyCount(i, &G));
  }
  
  printf ("Test passed.\n");
  printf ("*********************\n");

  return 0;
}
