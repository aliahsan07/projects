#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main (int argc, char* argv[]) 
{
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  int r, i;
  struct gameState G;
  
  initializeGame(2, k, 7, &G);

  printf("Testing great_hall.\n");

  for(i = 0; i <= 6; i++) {
	  //store values
	  int handCount = G.handCount[i];
	  int numActions = G.numActions +1;

	  r = cardEffect(great_hall, 0, 0, 0, &G, 0, 0);

	  assert(r == 0);
	  assert(G.handCount[i] == handCount);
	  assert(G.numActions == numActions);
}

  printf("Test complete.\n");

  return 0;
}


