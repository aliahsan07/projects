#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(){
        printf("--------------------TESTING handCard-----------------\n");

  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
               sea_hag, tribute, smithy};


  initializeGame(2, k, 30, &G);

  assert(handCard(1,&G)==G.hand[whoseTurn(&G)][1]);



        printf("--------------------TEST PASSED---------------\n");

        return 0;
}

