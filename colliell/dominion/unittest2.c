#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char* argv[]) 
{
  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  
  int r, i;

  printf("Testing initializeGame.\n");

  for (i = 0; i < 6; i++) 
  {
    r = initializeGame(i, k, 2, &G);
    if ((i >= 2) && (i <= 4)) 
    {
      if (i == 2) 
      {
    		if(G.supplyCount[estate] != 8) printf("error: estate = %d\n", G.supplyCount[estate]);
    		if(G.supplyCount[duchy] != 8) printf("error: duchy = %d\n", G.supplyCount[duchy]);
    		if(G.supplyCount[province] != 8) printf("error: province = %d\n", G.supplyCount[province]);
    		if(G.supplyCount[gardens] != 8) printf("error: gardens = %d\n", G.supplyCount[gardens]);
    		if(G.supplyCount[great_hall] != 8) printf("error: great_hall = %d\n", G.supplyCount[great_hall]);
        if(G.supplyCount[curse] != 10) printf("error: curse = %d\n", G.supplyCount[curse]);
      } 


      else 
      {
    		if(G.supplyCount[estate] != 12) printf("error: estate = %d\n", G.supplyCount[estate]);
    		if(G.supplyCount[duchy] != 12) printf("error: duchy = %d\n", G.supplyCount[duchy]);
    		if(G.supplyCount[province] != 12) printf("error: province = %d\n", G.supplyCount[province]);
    		if(G.supplyCount[gardens] != 12) printf("error: gardens = %d\n", G.supplyCount[gardens]);
    		if(G.supplyCount[great_hall] != 12) printf("error: great_hall = %d\n", G.supplyCount[great_hall]);
        if(i == 3) 
        {
          if(G.supplyCount[curse] != 20) printf("error: curse = %d\n", G.supplyCount[curse]);
        }
        else if(i ==4)
        {
          if(G.supplyCount[curse] != 30) printf("error: curse = %d\n", G.supplyCount[curse]); 
        }
      }

      assert (r == 0);
      assert(G.deckCount[i-1] == 10);
      assert(G.embargoTokens[i-1] == 0);
      assert(G.outpostPlayed == 0);
      assert(G.phase == 0);
      assert(G.numActions == 1);
      assert(G.numBuys == 1);
      assert(G.whoseTurn == 0);
      assert(G.handCount[i-1] == 0);
      assert(G.discardCount[i-1] == 0);
    } 

    else 
    	assert (r != 0);
  }

  printf("Test complete.\n");

  return 0;
}
