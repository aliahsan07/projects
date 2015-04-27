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

  printf(" !! Begin Unit Test 3 !!\n");
  int returnVal;
  int i;
	
  struct gameState state;
  
  srand(time(NULL));
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  int numPlayers = 4;
  
  int myseed = rand();	
  printf("Initializing Game with Seed %d\n", myseed);
  
  returnVal = initializeGame(numPlayers, k, myseed, &state);
  assert(returnVal == 0);
  printf("Succesfully made game");
  returnVal = isGameOver(&state);
  printf("isGameOver after init: %d\n", returnVal);
  
  state.supplyCount[province] = 0;
  returnVal = isGameOver(&state);
  
  printf("isGameOver post modified supplyCount[province] returned: %d\n", returnVal);
  
  for (i = 0; i < 3; i++){
    state.supplyCount[i] = 0;
  }
  state.supplyCount[province] = 1;
  returnVal = isGameOver(&state);
  
  printf("isGameOver post modification of supplyCount[i]  returned: %d\n", returnVal);
  
  return 0;	
	
}
