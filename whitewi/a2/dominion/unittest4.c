#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

/*************************************************
 ** This unittest checks to see if isGameOver()	**
 ** works by changing manually triggering end	**
 ** conditions and seeing if they are detected.	**
 **												**
 ** This test assumes that initializeGame() is  **
 ** working and will initialize the game. 		**
 *************************************************/

int main (int argc, char** argv) {
  struct gameState G;
  int temp;
  
  	if(argv[1] == NULL)
	{
		printf ("Enter a positive integer argument for the random number generator seed.\n");
		return 0;
	}

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("\n*********************\n");
  printf ("Testing isGameOver().\n");

  
  int r = initializeGame(2, k, atoi(argv[1]), &G);

  assert (r == 0);
  
  assert(isGameOver(&G) == 0);
  temp = G.supplyCount[province];
  G.supplyCount[province] = 0;
  assert(isGameOver(&G) == 1);
  G.supplyCount[province] = temp;
  G.supplyCount[1] = 0;
  G.supplyCount[2] = 0;
  G.supplyCount[3] = 0;
  assert(isGameOver(&G) == 1);
  printf ("Test passed.\n");
  printf ("*********************\n");

  return 0;
}
