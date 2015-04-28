#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
   struct gameState G;

   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

   initializeGame(2, k, 2, &G);

   printf("Testing Village\n");

   int a = numHandCards(&G);
   printf("Cards before call to village: %d\n", a);
   int b = G.numActions;
   printf("Actions before call to village: %d\n", b);

   int c = cardEffect(village, 0, 0, 0, &G, 0, 0);
   
   a = numHandCards(&G);
   b = G.numActions;
   printf("Cards after call to village: %d\n", a);
   printf("Actions after call to village: %d\n\n", b);	

   return 0;
}
