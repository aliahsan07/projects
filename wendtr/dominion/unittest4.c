#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
  int r;
  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, smithy, baron, tribute, curse};
  
  printf("\n");
  printf("***Start Testing supplyCount***\n");
  initializeGame(2, k, 10, &G);

  G.supplyCount[adventurer] = 30;

  
  printf("There are 30 adventurer cards in supply\n\n");
  r = supplyCount(adventurer, &G);
  assert(r == 30);
  
  printf("There are no adventurer cards in supply\n\n");
  r = G.supplyCount[adventurer] = 0;
  assert(r == 0);

  printf("Tests Are Successful\n");

  return 0;
}
