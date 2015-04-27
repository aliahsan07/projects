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

  printf("Testing sea_hag.\n");

  

  for(i = 0; i <= 6; i++)
  {

    initializeGame(i, k, 7, &G);
    //store values
    if(i == 2) 
    {

      int deckCount1 = G.deckCount[i-1] - 1;
      int discardCount1 = G.discardCount[i-1] + 1;

      r = cardEffect(sea_hag, 0, 0, 0, &G, i, 0);

      if(G.deckCount[i-1] != deckCount1) printf("error: deckCount != old deckCount - 1\n");
      if(G.discardCount[i-1] != discardCount1) printf("error: discardCount != old discardCount + 1\n");;
      if(G.deck[i-1][G.deckCount[i-1]] != curse) printf("error: top of deck != curse\n");
      assert(r == 0);
    }

    if(i == 3) 
    {

      int deckCount1 = G.deckCount[i-1] - 1;
      int discardCount1 = G.discardCount[i-1] + 1;
      int deckCount2 = G.deckCount[i-2] - 1;
      int discardCount2 = G.discardCount[i-2] + 1;

      r = cardEffect(sea_hag, 0, 0, 0, &G, i, 0);

      if(G.deckCount[i-1] != deckCount1) printf("error: deckCount1 != old deckCount - 1\n");
      if(G.discardCount[i-1] != discardCount1) printf("error: discardCount1 != old discardCount + 1\n");;
      if(G.deck[i-1][G.deckCount[i-1]] != curse) printf("error: top of deck 1 != curse\n");
      if(G.deckCount[i-2] != deckCount2) printf("error: deckCount2 != old deckCount - 1\n");
      if(G.discardCount[i-2] != discardCount2) printf("error: discardCount2 != old discardCount + 1\n");;
      if(G.deck[i-2][G.deckCount[i-2]] != curse) printf("error: top of deck 2 != curse\n");
      assert(r == 0);
    }

    if(i == 4) 
    {

      int deckCount1 = G.deckCount[i-1] - 1;
      int discardCount1 = G.discardCount[i-1] + 1;
      int deckCount2 = G.deckCount[i-2] - 1;
      int discardCount2 = G.discardCount[i-2] + 1;
      int deckCount3 = G.deckCount[i-3] - 1;
      int discardCount3 = G.discardCount[i-3] + 1;

      r = cardEffect(sea_hag, 0, 0, 0, &G, i, 0);

      if(G.deckCount[i-1] != deckCount1) printf("error: deckCount1 != old deckCount - 1\n");
      if(G.discardCount[i-1] != discardCount1) printf("error: discardCount1 != old discardCount + 1\n");;
      if(G.deck[i-1][G.deckCount[i-1]] != curse) printf("error: top of deck 1 != curse\n");
      if(G.deckCount[i-2] != deckCount2) printf("error: deckCount2 != old deckCount - 1\n");
      if(G.discardCount[i-2] != discardCount2) printf("error: discardCount2 != old discardCount + 1\n");;
      if(G.deck[i-2][G.deckCount[i-2]] != curse) printf("error: top of deck 2 != curse\n");
      if(G.deckCount[i-3] != deckCount3) printf("error: deckCount3 != old deckCount - 1\n");
      if(G.discardCount[i-3] != discardCount3) printf("error: discardCount3 != old discardCount + 1\n");;
      if(G.deck[i-3][G.deckCount[i-3]] != curse) printf("error: top of deck 3 != curse\n");
      assert(r == 0);
    }

}

  printf("Test complete.\n");

  return 0;
}
