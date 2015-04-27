#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
   struct gameState G;

   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

   initializeGame(2, k, 2, &G);
   
   printf("Testing Smithy");
   
   int a = numHandCards(&G);
   printf("Cards in hand before call to smithy: %d\n", a);

   int b = cardEffect(smithy, 0, 0, 0, &G, 0, 0);
   assert(b == 0);
   a = numHandCards(&G);
   printf("Cards in hand after call to smithy: %d\n\n", a);
   
   return 0;
}   
