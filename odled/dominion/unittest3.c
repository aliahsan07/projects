#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
   struct gameState G;

   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

   int r = initializeGame(2, k, 2, &G);
   assert (r == 0);
   
   printf("Testing isGameOver:\n");
   
   printf("Testing without game being over\n");
   int a = isGameOver(&G);
   assert(a == 0);
   printf("Test Passed\n\n");
   

   return 0;		
}
