#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
  struct gameState G;
  int r;
  int player1 = 0;
  int player2 = 1;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, curse, tribute, smithy};
  
  printf("\n");
  printf("***Start Testing whoseTurn***\n\n");
  printf("Initilizing Game...\n");
  initializeGame(2, k, 4, &G);
  
  printf("Should be player 2's turn\n\n");
  G.whoseTurn = player2;
  r = whoseTurn(&G);
  assert(r == 1);
  
  printf("Should be player 1's turn now\n\n");
  G.whoseTurn = player1;
  r = whoseTurn(&G);
  assert(r == 0);


  printf("Tests Are Successful\n\n");
  return 0;
}
