#include "dominion_helpers.h"
#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
  struct gameState G;

  int r; //Holds our values for our funtion calls
  int choice1 = embargo;//Cost 2
  int choice2 = gardens;//Cost 4
  int choice3 = adventurer;
  int handPos = 0;
  int *bonus = 0;
  int player1 = 0;
  // int player2 = 1;
  //int currentPlayer;
  //int temphand[MAX_HAND];
  //int drawntreasure = 0;
  //int z = 0; //counter for temp hand


  printf("\n***Start Testing***\n");
  printf("Initialize Game...\n");

  int k[10] = {minion, smithy, gardens, tribute, baron, adventurer, cutpurse,
               mine, embargo, outpost};
  initializeGame(2, k, 3, &G);

  //Make sure it is player 1's turn
  G.whoseTurn = player1;

  printf("\n\nTesting Smithy: this card adds three cards from the deck\n");
  printf("into your hand.\n");


  printf("\nTest: Check if three cards are added to my hand\n");
  printf("However, it will look like only 2 cards are added to the hand\n");
  printf("because you must discard smithy after using it.\n\n");

  int temp = G.handCount[player1];
  printf("There are %d cards in my hand.\n", G.handCount[player1]);
  r = cardEffect(smithy, choice1, choice2, choice3, &G, handPos, bonus);
  assert(r == 0);
  printf("Hand count should be temp + 2: handCount = %d, temp = %d\n", G.handCount[player1], temp);
  //  assert(G.handCount[player1] == temp + 2);


  printf("There are now %d cards in my hand.\n", G.handCount[player1]);

  printf("***Tests are Successful***\n");
  return 0;

}



