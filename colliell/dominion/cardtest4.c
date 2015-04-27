#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main (int argc, char* argv[]) 
{
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  int r;
  struct gameState G;
  
  initializeGame(2, k, 7, &G);

  printf("Testing salvager.\n");

  //store values
  int numBuys = G.numBuys + 1;
  int handCount = G.handCount[0] - 1;
  int coins = G.coins;

  printf("Testing with copper.\n");

  r = cardEffect(salvager, 0, 0, 0, &G, 0, 0);

  assert(r == 0);
  assert(G.numBuys == numBuys);
  assert(G.handCount[0] == handCount);
  assert(G.coins = coins);

  initializeGame(2, k, 7, &G);

  //store values
  numBuys = G.numBuys + 1;
  handCount = G.handCount[0] - 2;
  coins = G.coins + 3;

  printf("Testing with silver.\n");

  r = cardEffect(salvager, 3, 0, 0, &G, 0, 0);

  assert(r == 0);
  assert(G.numBuys == numBuys);
  assert(G.handCount[0] == handCount);
  assert(G.coins = coins);

  initializeGame(2, k, 7, &G);

  numBuys = G.numBuys + 1;
  handCount = G.handCount[0] - 2;
  coins = G.coins + 6;

  printf("Testing with gold.\n");

  r = cardEffect(salvager, 6, 0, 0, &G, 0, 0);

  assert(r == 0);
  assert(G.numBuys == numBuys);
  assert(G.handCount[0] == handCount);
  assert(G.coins = coins);

  printf("Test complete.\n");

  return 0;
}
