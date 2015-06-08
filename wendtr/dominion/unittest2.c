#include "dominion_helpers.h"
#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int main(int argc, char** argv)
{
  struct gameState G;
  int r;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, baron, tribute, smithy};
  printf("\n");
  printf("***Start Testing isGameOver***\n");

  printf("Initialize Game...\n");
  initializeGame(2,k, 3, &G); 
  
  printf("We have 2 provinces left\n\n");
  G.supplyCount[province] = 2;
  r = isGameOver(&G);
  assert(r == 0);

  printf("No more provinces left, game should be over\n\n");
  G.supplyCount[province] = 0;
  r = isGameOver(&G);
  assert(r == 1);
  
  G.supplyCount[province] = 3;

  // printf("i am here %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
  printf("Less than 3 cards are gone, game continues:\n\n");
  G.supplyCount[mine] = 0;
  r = isGameOver(&G);
  assert(r == 0);

  printf("More than 3  cards are gone, game should be over\n\n");
  G.supplyCount[smithy] = 0;
  G.supplyCount[adventurer] = 0;
  G.supplyCount[baron] = 0;
  r = isGameOver(&G);
  assert(r == 1);

  printf("Tests Are Successful\n\n");
  return 0;
}
