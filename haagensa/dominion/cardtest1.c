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

int main(){

  printf("\n !! Card Test 1 !! \n");
  struct gameState state;
  srand(time(NULL));
  int i = 0;
  int p = 0;
  int hand = 2;
  int startSeed = rand();
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  
  printf(" Adventurer Card Testing: Begin! \n");
  initializeGame(3, k, startSeed, &state);

  
  int ret_val = adventurerRefactor(p, &state, hand);
  assert(ret_val == 0);
  
  for (i = 0; i < 3; i++) {
    printf("Value of handCount is %d\n", state.handCount[i]);
  }
  if(state.handCount[0] > 0){
    printf("Assertions: All Passed \n");
  }
  else {
    printf("!!! Failure Encountered !!!\n");
  }
  
  return 0;
}
