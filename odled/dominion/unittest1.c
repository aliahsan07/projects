#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>





int main (int argc, char** argv) {
   struct gameState G;
   
   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
   
   int r = initializeGame(2, k, 2, &G);
   assert(r == 0);

   printf("Testing numHandCards function: \n");

   printf("Testing that player1 starts with 5 cards in hand\n");
   int a = numHandCards(&G);
   assert(a == 5);
   printf("Test Passed\n");


   printf("Putting 10 cards in player1's hand and testing that there are 10 cards in hand\n");
   G.handCount[0] = 10;
   a = numHandCards(&G);
   assert(a == 10);
   printf("Test Passed\n");
   
   printf("Testing with 0 cards in hand\n");
   G.handCount[0] = 0;
   a = numHandCards(&G);  
   assert(a == 0);
   printf("Test Passed\n");

   printf("Putting -1 cards into the player's hand and testing\n");
   G.handCount[0] = -1;
   a = numHandCards(&G);
   assert(a == -1);
   printf("Test Passed\n\n");

   return 0;
}
