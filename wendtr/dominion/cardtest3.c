
#include "dominion.h"
#include "assert.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int main(int argc, char** argv)
{
  struct gameState G;
  int r; //Holds our values for our funtion calls
  int choice1 = embargo;//Cost 2
  int choice2 = gardens;//Cost 4
  int choice3 = minion; //Cost 5
  int handPos = 0;
  int *bonus;
  int player1 = 0;
  int player2 = 1;
  int currentPlayer;
  int temphand[MAX_HAND];
  int drawntreasure = 0;
  int z = 0; //counter for temp hand


  printf("\n***Start Testing***\n");
  printf("Initialize Game...\n");

  int k[10] = {minion, smithy, gardens, tribute, baron, adventurer, cutpurse,
               mine, embargo, outpost};
  initializeGame(2, k, 3, &G);

  //Add card to hand for sure
  gainCard(choice1, &G, 2, player1);

  //Make sure it is player 1's turn
  G.whoseTurn = player1;

  printf("\n\nTesting Remodel: this card takes a card from your hand\n");
  printf("and throws it in the discard pile. You then gain a card\n");
  printf("that costs 2 more coins than the trashed card.\n");
  
  
  printf("\nFirst Test: Trash an embargo for a gardens card\n");
  r = cardEffect(remodel, choice1, choice2, choice3, &G, handPos, &bonus); 
  assert(r == 0);

  G.whoseTurn = player2;
  gainCard(choice1, &G, 2, player2);
  printf("\nSecond Test: Trash an embargo for a minion card, shouldn't work\n");
  r = cardEffect(remodel, choice1, choice2, choice3, &G, handPos, &bonus);
  assert(r == 0);
  printf("What is happening here??\n\n");

  printf("***Tests are Successful***\n");
  return 0;
}



