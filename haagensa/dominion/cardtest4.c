// DONE

#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>

int main() {

  struct gameState state;
  srand(time(NULL));
  printf("\n !! Card Test 4 Great Hall !! \n");
  int totalPlayers = 4;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  int returnVal;
  int curPos = 3;
  int startSeed = rand();	
  
  initializeGame(totalPlayers, k, startSeed, &state);

  //implementation of great hall taken from dominion.c
  //its the one in the switch-case block that 
  //was not refactored at any point

  returnVal = cardEffect(great_hall,0,0,0,&state,curPos,1);

  assert(returnVal == 0); 
  assert(state.numActions > 0);
  printf("passed all assertions\n\n");
  
}
