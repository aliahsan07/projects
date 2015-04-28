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
	
  printf("\n !! Card Test 2 !! \n");
  srand(time(NULL));
  printf(" Smithy Card Testing: Begin! \n");
  struct gameState state;
  int startSeed = rand();
  int hand = 1;
  int p = 3;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

  printf("Status: Starting game. \n");
  //set turnCount and try for different turn values
  int turnCount = (rand() % 4) + 1;
  for(turnCount = 1; turnCount < 4; turnCount++){
    printf("Turn for test: %d\n", turnCount);
    initializeGame(p, k, startSeed, &state);
    int preCount = state.handCount[turnCount];
    int returnVal = smithyRefactor(turnCount, &state, hand);
    assert(returnVal == 0);
    if(preCount + 2 != state.handCount[turnCount]){
      printf("FAIL PreCount + 2 failure \n FAIL FAIL FAIL \n CARD TEST 2 FAIL \n");
    }
    else{
      printf("Assertions passed for turn %d!\n", turnCount);
    }
  }  
  return 0;
}
