#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[])
{
  int i;
  struct gameState* s = newGame();
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    		sea_hag, tribute, smithy};
  
  initializeGame(2, k, 3, s);
  
  assert(s->handCount[s->whoseTurn] == 5);

  for(i = 0; i < 5; i++) {
    assert(drawCard(s->whoseTurn, s) == 0);
  }

  endTurn(s);

  assert(s->handCount[s->whoseTurn] == 5);

  endTurn(s);

  assert(s->handCount[s->whoseTurn] == 5);
 
  for(i = 0; i < 5; i++) {
    assert(drawCard(s->whoseTurn, s) == 0);
  }

  assert(drawCard(s->whoseTurn, s) == -1);


  printf("drawCard Passed. \n");
}
