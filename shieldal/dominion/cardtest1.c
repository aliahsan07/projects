#include "dominion.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char* argv[])
{
  struct gameState* s = newGame();
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    		sea_hag, tribute, smithy};
  
  initializeGame(2, k, 3, s);

  s->hand[s->whoseTurn][6] = smithy;

  playCard(6, 0, 0, 0, s);

  assert(s->handCount[s->whoseTurn] == 7);

  printf("smithyEffect Passed. \n");
}
