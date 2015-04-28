#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main (int argc, char* argv[]) 
{
  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  int r, i;

  printf("Testing council_room.\n");

  for(i = 0; i <= 6; i++)
  {
    initializeGame(i, k, 7, &G);

    //store values
    if(i == 2) 
    {
      int handCount1 = G.handCount[0] + 3;
      int handCount2 = G.handCount[1] + 1;
      int numBuys = G.numBuys + 1;

      r = cardEffect(council_room, 0, 0, 0, &G, i, 0);

      assert(G.handCount[0] == handCount1);
      assert(G.handCount[1] == handCount2);
      assert(G.numBuys == numBuys);
      assert(r == 0);
    }

    else if(i == 3)
    {
      int handCount1 = G.handCount[0] + 3;
      int handCount2 = G.handCount[1] + 1;
      int handCount3 = G.handCount[2] + 1;
      int numBuys = G.numBuys + 1;

      r = cardEffect(council_room, 0, 0, 0, &G, i, 0);
    
      assert(G.handCount[0] == handCount1);
      assert(G.handCount[1] == handCount2);
      assert(G.handCount[2] == handCount3);
      assert(G.numBuys == numBuys);
      assert(r == 0);
    }

    else if(i == 4)
    {
      int handCount1 = G.handCount[0] + 3;
      int handCount2 = G.handCount[1] + 1;
      int handCount3 = G.handCount[2] + 1;
      int handCount4 = G.handCount[3] + 1;
      int numBuys = G.numBuys + 1;

      r = cardEffect(council_room, 0, 0, 0, &G, i, 0);
    
      assert(G.handCount[0] == handCount1);
      assert(G.handCount[1] == handCount2);
      assert(G.handCount[2] == handCount3);
      assert(G.handCount[3] == handCount4);
      assert(G.numBuys == numBuys);
      assert(r == 0);
    }
}

  printf("Test complete.\n");

  return 0;
}
