#include "dominion.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char* argv[])
{
  struct gameState* s = newGame();
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    		sea_hag, tribute, smithy};
  
  initializeGame(2, k, 3, s);

  endTurn(s);

  assert(s->whoseTurn == 1);
  assert(s->handCount[0] == 0);
  assert(s->handCount[1] == 5);

  endTurn(s);

  assert(s->whoseTurn == 0);
  assert(s->handCount[0] == 5);
  assert(s->handCount[1] == 0);

  printf("endTurn Passed. \n");
}
