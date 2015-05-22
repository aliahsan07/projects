// DONE

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main (){


  struct gameState state;
  srand(time(NULL));
  printf("\n !! Card Test 3 !! \n");
  printf("Council Card Testing: Begin! \n");
  int startSeed = rand();
  
  int k[10]={adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  initializeGame(3,k,startSeed,&state);
  int preCount = state.numBuys;

  int curPlayer = 1;
  int curHand = 1;  
  int i = 0;

  //try running it in the function

  cardEffect(council_room,0,0,0,&state,curHand,1);

  assert(state.numBuys > preCount);
  printf("Assertions: Passed\n");

  return 0;

}
    
