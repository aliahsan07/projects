#include "dominion.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char* argv[])
{
  struct gameState* s = newGame();
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    		sea_hag, tribute, smithy};
  
  initializeGame(2, k, 3, s);

  s->coins = 0;
  assert(buyCard(mine, s) == -1);

  s->coins = 10;
  s->supplyCount[gardens] = 0;
  assert(buyCard(gardens, s) == -1);

  assert(buyCard(mine, s) == 0);
  assert(s->discard[s->whoseTurn][s->discardCount[s->whoseTurn] - 1] == mine);

  assert(buyCard(mine, s) == -1);

  printf("buyCard Passed. \n");
}
