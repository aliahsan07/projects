#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
   struct gameState G;

   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

   initializeGame(2, k, 2, &G);

   printf("Testing Minion\n");
   printf("Number actions before call to minion = %d\n", G.numActions);
   int a = numHandCards(&G);
   int b = cardEffect(minion, 0, 0, 0, &G, 0, 0);
   printf("Number of actions after call to minion = %d\n\n", G.numActions);
   assert(a == 5);
   assert(b == 0);

   return 0;
}
