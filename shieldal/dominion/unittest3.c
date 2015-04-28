#include "dominion.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char* argv[])
{
  struct gameState* s = newGame();
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    		sea_hag, tribute, smithy};
  
  initializeGame(2, k, 3, s);

  assert(isGameOver(s) == 0);

  s->supplyCount[0] = 0;
  assert(isGameOver(s) == 0);
  
  s->supplyCount[1] = 0;
  assert(isGameOver(s) == 0);
  
  s->supplyCount[10] = 0;
  assert(isGameOver(s) == 1);

  s = newGame();
  initializeGame(2, k, 3, s);
  
  assert(isGameOver(s) == 0);
  
  s->supplyCount[province] = 0;

  assert(isGameOver(s) == 1);

  printf("isGameOver Passed. \n");
}
