#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 20

//This program randomly tests adventurer 20 times

int main(int argc, char* argv[]) {

  srand(time(NULL));
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  
  int i, totalPlayers; 
  int currPlayer, deckCount;
  int randSeed; 
  int totalFailures = 0;
  struct gameState state;

  printf("Random Adventurer Test: Begin!\n");

  for (i = 0; i < MAX_TESTS; i++) {

    printf("\n Test #%d \n", i+1);
    totalPlayers = (rand() % 4) + 1;
    currPlayer = (rand() % totalPlayers) + 1;
    printf("Total TotalPlayers %d \n", totalPlayers); 
    printf("Current Player: %d\n", currPlayer);
    
    randSeed = rand();		
		
    initializeGame(totalPlayers, k, randSeed, &state);
    //set our current players correct hand
    state.deckCount[currPlayer] = (rand() % MAX_DECK) + 1;
    state.handCount[currPlayer] = 5;
    state.discardCount[currPlayer] = 0;
    
    deckCount = state.deckCount[currPlayer];
    
    if (randSeed % 3 == 0) {
      state.deckCount[currPlayer] = 0;
      printf("Deck count is 0\n");
    }
    
    adventurerRefactor(currPlayer, &state);
    
    if(state.handCount[currPlayer] != 7){
      printf("FAILURE: Did not acquire right cards\n");
      totalFailures++;
    }
  }
  printf("Total totalFailures: %d\n", totalFailures);
  
  printf("Tests Complete\n");
  
  return 0;
}
