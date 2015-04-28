#include "dominion.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char* argv[])
{
  int coins;
  int who;
  struct gameState* s = newGame();
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    		sea_hag, tribute, smithy};
  
  initializeGame(2, k, 3, s);
  coins = s->coins;
  who = s->whoseTurn;
  s->hand[who][6] = steward;
  s->handCount[who]++;

  assert(playCard(6, 1, 0, 0, s) == 0);
  assert(s->handCount[who] == 7);
   
  s = newGame();
  initializeGame(2, k, 3, s);
  coins = s->coins;
  who = s->whoseTurn;
  s->hand[who][6] = steward;
  s->handCount[who]++;
  assert(playCard(6, 0, 0, 1, s) == 0);
  assert(s->handCount[who] == 3);
  
  printf("stewardEffect Passed. \n");
}
