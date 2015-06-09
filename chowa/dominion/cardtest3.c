#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main (int argc, char** argv) {
  struct gameState G;
	int players, handCount, actions, p;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	srand (time(NULL));
  printf ("Testing mines\n");
  players = 2 + rand() % 3 ;//2-4 players always

  //int g = initializeGame(players, k, atoi(argv[1]), &G);
  int g = initializeGame(players, k, 20, &G);
  assert (g == 0);

  p = whoseTurn(&G);
  printf("\t\t ***Current player is: %d ****\n", p);
  actions = G.numActions;
  handCount = numHandCards(&G);
  playCard(mine,0,0,0, &G);
  
 if (G.numActions != actions-1){
	   printf("Incorrect action count\n");
	   printf("\tInitial actions count: %d \n \tResulting action count: %d \n", actions, G.numActions );
  }  
  
 if (G.handCount[p] != handCount){
	  printf("FAIL: extra cards were added to the hand\n");
	  printf("Initial hand count: %d\n", handCount);
	  printf("Resulting hand count: %d\n", G.handCount[0]);
  }
  
  return 0;
}
