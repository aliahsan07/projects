#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
   struct gameState G;

   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

   printf ("Whose Turn.\n");
	
   int r = initializeGame(2, k, 2, &G);
   assert(r == 0);
   printf("Testing Whose Turn\n");
   
   printf("Testing for Player 0's turn:\n");	
   int a = whoseTurn(&G);
   assert(a == 0);
   printf("Test Passed\n");

   int b = endTurn(&G);

   printf("Testing for Player 1's turn: \n");
   a = whoseTurn(&G);	   
   assert(a == 1);
   printf("Test Passed\n\n");


   return 0;
}
