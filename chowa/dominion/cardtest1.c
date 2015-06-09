#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main (int argc, char** argv) {
  struct gameState G;
	int players, handCount, deckCount, actions, p;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	srand (time(NULL));
  printf ("Testing smithy\n");
  players = 2 + rand() % 3 ;//2-4 players always	
  //int g = initializeGame(players, k, atoi(argv[1]), &G);
  int g = initializeGame(players, k, 20, &G);
  assert (g == 0);
  
  p = whoseTurn(&G);
  printf("\t\t ***Current player is: %d ****\n", p);
  handCount = G.handCount[p];
  deckCount = total_card(p, &G);
  actions = G.numActions;
  playCard(smithy,0,0,0, &G);
  if (G.numActions != actions-1){
	   printf("Incorrect action count\n");
	   printf("\tInitial actions count: %d \n \tResulting action count: %d \n", actions, G.numActions );
  }  
  if ((deckCount - G.handCount[p]) < 4)
	  printf("Less then 3 cards available to draw");
  else if (G.handCount[p] != handCount+3){
	  printf("FAIL: 3 cards were not added to the hand\n");
	  printf("Initial hand count: %d\n", handCount);
	  printf("Resulting hand count: %d\n", G.handCount[p]);
  }
  
  return 0;
}
