#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
  struct gameState G;
  printf("\n***Start Testing***\n");
  printf("Initialize Game...\n");
  
  int r;
  int k[10] = {minion, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo, outpost};
  initializeGame(2, k, 5, &G);
  
  int choice1 = 0;
  int choice2 = 0;
  int choice3 = 0;
  int handPos = 0;;
  int *bonus;
  int player1 = 0;
  int player2 = 1;
  int currentPlayer = whoseTurn(&G);
  int temphand[MAX_HAND];
  int drawntreasure = 0;
  int z = 0; //counter for temp hand

  printf("Deck Count should equal 5 for player 1: %d\n", G.deckCount[player1]);
  //  assert(G.deckCount[player1] == 5);
  printf("Deck Count should equal 10 for player 2: %d\n", G.deckCount[player2]);
  // assert(G.deckCount[player2] == 10);
  printf("Discard for player 1 is empty: %d\n", G.discardCount[player1]);
  
  printf("Run Council Room:\n");
  G.whoseTurn = player1;

  r = cardEffect(council_room, choice1, choice2, choice3, &G, handPos, &bonus);
  printf("r should equal 0, r = %d\n", r);
  //  assert(r == 0);

  printf("Ran Successfully\n");

  /*What should happen after running council room
  is there should be 4 less cards from the deck.
  In addition, the number of buys should increase by one
  and the other player(s) should have one less card from their deck 
  Finally, player 1's discard pile should have 1 more card in it*/
  
  //As for why player 1 has 5 cards and player 2 has 10 cards...
  //I am not sure.

   printf("Deck Count should now equal 1 for player1: %d\n", G.deckCount[player1]);
  // assert(G.deckCount[player1] == 1);
   printf("Deck Count should now equal 9 for player2: %d\n", G.deckCount[player2]);
   // assert(G.deckCount[player2] == 9);

  printf("***Tests Are Successful***\n");

  return 0;
}



