#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 50

//This randomly tests Adventurer

int main() {
   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
   int i, j, l;
   int players;
   int handCount;
   int deckCount;
   int seed;
   int treasureseed;
   int numtreasures;
   int treasurespot;
   int treasures;
   int failedtest = 0;
   int cardcheck;
   int notreasuresindeck;
   struct gameState state;

   printf("Random Adventurer Test:\n\n");
   for (i = 0; i < MAX_TESTS; i++) {
      players = rand() % 4;
      seed = rand();   // Random seed
      treasureseed = rand(); // Seed treasures
      // Initialize Gamestate:
         initializeGame(players, k, seed, &state);

      // Initialize valid state variables:
         state.deckCount[players] = rand() %MAX_DECK;
         state.discardCount[players] = rand() %MAX_DECK;
         state.handCount[players] = rand() % MAX_DECK;

      // State variables before call to cardEffect:
         handCount = state.handCount[players];
         deckCount = state.deckCount[players];
	 numtreasures = treasureseed % 3;
         if (seed % 5 == 0) { // 1/5 chance of empty deck
	    state.deckCount[players] = 0;
	 
	 }
	 if (state.deckCount[players] > 1) {
	    // fill first two spots in hand with treasure cards
	    notreasuresindeck = seed % 2; // 1/2 chance for treasures in deck
	    if (notreasuresindeck < 0) {   // Put treasure card into deck
	       for (j = 0; j  < 2; j++) { 
	          treasureseed = rand();
	          numtreasures = treasureseed % 3;
	          if(numtreasures == 0 || numtreasures == 1){
	             state.deck[players][j] = copper;
	          }
	          else if (numtreasures == 2) {
	             state.deck[players][j] = silver;
	          }
	          else if (numtreasures == 3) {
	             state.deck[players][j] = gold; 
	          }
               }
	    }
	 }
	 if (seed % 5 == 0) { // 1/5 chance of empty deck
	    state.deckCount[players] = 0;
	 }
	 
	 cardcheck = cardEffect(adventurer, 1, 1, 1, &state, 0, 0);
         assert (cardcheck == 0);   // cardEffect returns correctly
         
	 if (notreasuresindeck != 0) {
	   for (l = 0; l < state.handCount[players]; l++) {
	       if (state.hand[players][l] == copper || state.hand[players][l] == silver || state.hand[players][l] == gold) {
	          treasures++;
	       }
	       
            }
	    if (treasures < 2) {
  	       if (notreasuresindeck != 0) {  // indicates treasures in deck
 		  failedtest++;
	       }
	    }
	    
	    /* Alternative way to count failed tests that I was testing
	    if (treasures < 2) {  // adventurer didn't bring them into hand correctly
	         
	       if (handCount != (state.handCount[players] + 2)){    
	          failedtest++;
	       }
	    
            }
	    */
  
       } 
   }
   printf("Tests Complete\n");	
   printf("Total tests: %d\n", MAX_TESTS);
   printf("Number of failed tests: %d\n", failedtest);
   return 0;
}
