#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 1000

int main(int argc, char* argv[]) {

  srand(time(NULL));
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  int i, players; 
  int handPos, choice, currPlayer, deckCount, randSeed, returnVal;
  int totalFailures = 0;
  struct gameState state;
  printf("Testing Card: Salvager \n");
  
  for (i = 0; i < MAX_TESTS; i++) {
    randSeed = rand();		
    printf("Test number: %d \n", i+1);
    players = (rand() % 4) + 1;
    currPlayer = (rand() % players) + 1;
    printf("Players: %d\tCurrent: %d\n", players, currPlayer);
    
    
    initializeGame(players, k, randSeed, &state);
    
    state.deckCount[currPlayer] = (rand() % MAX_DECK) + 1;
    state.handCount[currPlayer] = 5;
    state.discardCount[currPlayer] = 0;
    handPos = (rand() % 5) + 1;
    choice = (rand() % 5) +1;
    
    deckCount = state.deckCount[currPlayer];
    
    if (randSeed % 3 == 0) {
      
      printf("Testing with deck count of 0\n");
      state.deckCount[currPlayer] = 0;
    }
    
    returnVal = salvagerRefactor(currPlayer, &state, handPos, choice);
    
    
    printf("Card returned: '%d'\n", returnVal);
    if (state.discardCount[currPlayer] == 0){
      printf("FAILURE DETECTED \n Current Player did not Discard \n");
      totalFailures++;
    }
    if (state.handCount[currPlayer] >= 5){
      printf("FAILURE DETECTED \n Hand Count wrong \n Current Player: %d\n", state.handCount[currPlayer]);
      totalFailures++;
    }
  }
  
  
  printf("Failure Count Total: %d\n", totalFailures);
  
  printf("Testing Finished.\n");
  
  return 0;
}
