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

  
  printf("\n\n***FEAST adds cards to the discard pile,so we will check the discard pile to make sure we are receiving our cards***\n");
  
  printf("\nBefore running Feast, there should be 0 cards in my discard pile.\n",
	 G.discardCount[player1]);
  assert(G.discardCount[player1] == 0);

  printf("How many coins do I have before running feast:%d\n", G.coins);

  printf("\nRun Feast\n");
  G.whoseTurn = player1;
  // r = feastCard(&G, player1, choice1, temphand);
  //assert(r == 0);

  r = cardEffect(feast, choice1, choice2, choice3, &G, handPos, &bonus);
  assert(r == 0);
  printf("First Run Successful\n\n");
   
  printf("%d card(s) are in the discard pile now\n", G.discardCount[player1]);
  assert(G.discardCount[player1] == 1);

  printf("Coins should equal 5 now, in order to buy a card: %d\n", G.coins);
  assert(G.coins == 5);
  
  choice2 = mine;
  printf("Adding a mine to my disard pile now\n");

  printf("\nRun Feast\n");
  //r = feastCard(&G, 0, choice2, temphand);
  //assert(r == 0);
 
  r = cardEffect(feast, choice1, choice2, choice3, &G, handPos, &bonus);
  assert(r == 0);
  
  printf("Second Run Successful\n");
  
  printf("%d card(s) are in the discard pile now\n", G.discardCount[player1]);
  assert(G.discardCount[player1] == 2);

  printf("***Tests Are Successful***\n");

  return 0;
}
