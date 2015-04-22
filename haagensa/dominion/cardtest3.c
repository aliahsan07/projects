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

  //Took switch-case function and pulled it out to create test
  //from council case
  //perform a quick player draw test
  for (i = 0; i < 5; i++) {
    drawCard(curPlayer, &state);
  }

  state.numBuys++;
			
  //Each other player draws a card for council room
  for (i = 0; i < state.numPlayers; i++){
    if ( i != curPlayer ){
      drawCard(i, &state);
    }
  }
  
  discardCard(curHand, curPlayer, &state, 0);  

  assert(state.numBuys > preCount);
  printf("Assertions: Passed\n");

  return 0;

}
    
