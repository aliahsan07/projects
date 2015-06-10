#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
   struct gameState G;

   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
  	       sea_hag, tribute, smithy};

   int r = initializeGame(2, k, 2, &G);
   assert (r == 0);
   
   printf("Testing Draw Card Function\n");
   printf("Drawing card and testing that hand has 6 cards\n");
   int a = drawCard(0, &G);
   int b = numHandCards(&G);
   assert(a == 0);
   assert(b == 6);
   printf("Test Passed\n");

   printf("Now Testing with empty hand\n");
   G.handCount[0] = 0;
   a = drawCard(0, &G);
   b = numHandCards(&G);
   assert(a == 0);  
   assert(b == 1); 
   printf("Test Passed\n");   

   printf("Now Testing with empty draw deck. Should return -1\n");
   G.deckCount[0] = 0;
   a = drawCard(0, &G);
   b = numHandCards(&G);
   assert(a == -1);
   assert(b == 1);
   printf("Test Passed\n\n");


   return 0;
}
