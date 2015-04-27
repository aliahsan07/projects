// DONE

#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (){

  printf(" !! Begin Unit Test 2 !!\n");

  struct gameState state;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  
  printf(" ! Test numHandCard Begin !\n");
  printf("Beginning Game Now \n");
  int i;    
  for (i = 0; i < 4; i++){
    state.whoseTurn = i;    
    state.handCount[i] = 5;
    assert(numHandCards(&state) == 5);
  }
    
  printf("Passed All Assertions\n");         
  return 0;         
}
