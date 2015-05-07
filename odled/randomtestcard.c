#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 200  

//This randomly tests village

int main() {
   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
   int i; 
   int players;
   int handCount;
   int deckCount;
   int seed;
   int numActions;
   int failedHandCount = 0;
   int failedNumActions = 0;
   struct gameState state;
   printf("Random Village Test:\n");
   
   for (i = 0; i < MAX_TESTS; i++) {
      players = rand() %4;
      seed = rand();   // Random seed
      
      // Initialize Gamestate:
         initializeGame(players, k, seed, &state);

      // Initialize valid state variables:
         state.deckCount[players] = rand() % MAX_DECK;
         state.discardCount[players] = rand() % MAX_DECK;
         state.handCount[players] = rand() % MAX_HAND;
                                  
      // State variables before call to cardEffect:
         handCount = state.handCount[players];
         deckCount = state.deckCount[players];
         numActions = state.numActions;
         
	 printf("\nbefore state.handCount: %d\n", numHandCards(&state));
	 printf("before state.numActions: %d\n", state.numActions);
	 
	 cardEffect(village, 1, 1, 1, &state, 0, 0);

      // State variables after call to cardEffect:
         printf("after state.handCount: %d\n", numHandCards(&state));
	 printf("after state.numActions: %d\n\n", state.numActions);
	 
	 if(handCount != state.handCount[players] + 1)
	 {
	    failedHandCount++;
	 }
	 
	 if (numActions != state.numActions + 2) 
	 {
	    failedNumActions++;
	 }
   
   }
   printf("Tests Complete:\n");
   printf("Total Tests: %d\n", MAX_TESTS);
   printf("Total Failed +1 Cards: %d\n", failedHandCount);
   printf("Total Failed +2 Actions: %d\n", failedNumActions);
   return 0;
   
}
