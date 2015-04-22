#include "dominion.h"
#include "assert.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv)
{

  struct gameState G;
  printf("\n***Start Testing***\n");
  printf("Initialize Game...\n");

  int r; //Holds our values for our funtion calls
  int choice1 = smithy;
  int choice2 = 0;
  int choice3 = 0;
  int handPos;
  int *bonus;
  int player1 = 0;
  int player2 = 1;
  int currentPlayer;
  int temphand[MAX_HAND];
  int drawntreasure = 0;
  int z = 0; //counter for temp hand

  int k[10] = {minion, smithy, gardens, tribute, baron, adventurer, cutpurse,
               mine, embargo, outpost};
  initializeGame(2, k, 3, &G);

  printf("Deck Count should equal 5 for player 1: %d\n", G.deckCount[player1]\
	 );
  assert(G.deckCount[player1] == 5);
  //printf("Deck Count should equal 10 for player 2: %d\n", G.deckCount[player2]);
// assert(G.deckCount[player2] == 10);
  printf("Supply of card choice 1 is: %d\n", G.supplyCount[choice1]);


  printf("Run Feast\n");
  r = feastCard(&G, 0, choice1, temphand);//First player, first card choice
  assert(r == 0);

  return 0;
}


