#include "dominion.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char* argv[])
{
  struct gameState* s = newGame();
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    		sea_hag, tribute, smithy};
  
  initializeGame(2, k, 3, s);

  s->hand[s->whoseTurn][5] = outpost;

  assert(s->outpostPlayed == 0);
  assert(playCard(5, 0, 0, 0, s) == 0);
  assert(s->outpostPlayed == 1);

  
  printf("outpostEffect Passed. \n");
}
