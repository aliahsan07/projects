#include "dominion.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char* argv[])
{
  struct gameState* s = newGame();
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    		sea_hag, tribute, smithy};
  
  initializeGame(2, k, 3, s);

  s->hand[s->whoseTurn][5] = mine;
  s->hand[s->whoseTurn][0] = copper;

  assert(playCard(5, treasure_map, curse, 0, s) == -1);

  assert(playCard(5, 0, 1000, 0, s) == -1);

  assert(playCard(5, 0, gold, 0, s) == -1);

  assert(playCard(5, 0, silver, 0, s) == 0);
  
  printf("mineEffect Passed. \n");
}
