#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(){
        printf("--------------------TESTING gardens-----------------\n");

  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
               sea_hag, tribute, outpost};


  initializeGame(2, k, 30, &G);

  assert(cardEffect(gardens,1,1,1,&G,1,1)==-1);



        printf("--------------------TEST PASSED---------------\n");

        return 0;
}


