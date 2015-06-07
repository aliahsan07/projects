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
  printf ("Testing village\n");
  players = 2 + rand() % 3 ;//2-4 players always

 // int g = initializeGame(players, k, atoi(argv[1]), &G);
  int g = initializeGame(players, k, 20, &G);
  assert (g == 0);
  p = whoseTurn(&G);
  printf("\t\t ***Current player is: %d ****\n", p);
  actions = G.numActions;
  handCount = G.handCount[p];
  deckCount = total_card(p, &G);
  playCard(village,0,0,0, &G);
  if (G.numActions != actions+1){ //lose one and gain 2
	   printf("Incorrect actions added\n");
		printf("\tInitial actions count: %d \n \tResulting action count: %d \n", actions, G.numActions );
  }
	  
  if ((deckCount - G.handCount[p]) == 0)
	  printf("No more cards available to draw\n");
  else if (G.handCount[p] != handCount){ //discard village and replace with draw card
	  printf("FAIL: cards were added to the hand\n");
	  printf("Initial hand count: %d\n", handCount);
	  printf("Resulting hand count: %d\n", G.handCount[0]);
  }
  
  return 0;
}
