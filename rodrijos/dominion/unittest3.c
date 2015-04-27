#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(){
        printf("--------------------TESTING numHandCards-----------------\n");

  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
               sea_hag, tribute, smithy};


  initializeGame(2, k, 30, &G);

  assert(numHandCards(&G)==G.handCount[whoseTurn(&G)]);



        printf("--------------------TEST PASSED---------------\n");

        return 0;
}


