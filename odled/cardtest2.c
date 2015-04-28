#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
   struct gameState G;

   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

   initializeGame(2, k, 2, &G);
   
   printf("Testing Great Hall \n");
   int a = numHandCards(&G);
   assert(a == 5); // Should be 5 starting cards in hand
   printf("Actions = %d\n", G.numActions);
   
   int b = cardEffect(great_hall, 0, 0, 0, &G, 0, 0);
   a = numHandCards(&G);
   assert (a == 5); // Drew 1 card and discarded 1 card
   assert (b == 0); // +1 Card
   printf("Actions = %d\n\n", G.numActions);
   
   return 0;
}
