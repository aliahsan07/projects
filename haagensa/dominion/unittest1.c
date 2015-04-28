// DONE

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (){
    
  printf(" !! Begin Unit Test 1 !!\n");
    
  struct gameState state;
  int returnVal;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  
  printf("! Test fullDeckCount Begin !\n");
  
  int i = 4;
  int j = Random() * MAX_DECK;
  int p = Random() * 3;
  initializeGame(i, k, j, &state);
  printf("Starting game. \n");
  returnVal = fullDeckCount(p, i, &state);
  if(returnVal == 0){    
    printf("Passed All assertions\n");
  }
  else{
    printf("TEST FAIL TEST FAIL \n");
    printf(" !! UNIT TEST 1 FAILED !! \n");
  }
  return 0;    
}
