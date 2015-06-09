// DONE

#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>

int main() {

  printf(" !! Begin Unit Test 3 !!\n");

  int returnVal;
  int numPlayers = 4;
  int i = 0;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  struct gameState game;
  srand(time(NULL));
  printf(" ! Test initializeGame Begin !\n");
  //test different seeds for crashes
  for(i = 0; i < 500; i++){
    int randSeed = rand();
    //  printf("Random Seed Chosen is %d, trying new game\n", randSeed);
    returnVal = initializeGame(numPlayers, k, randSeed, &game);
    assert(numPlayers == game.numPlayers);
    assert(game.coins);
    assert(returnVal == 0);
    assert(game.numActions);
    assert(game.numBuys);
  }
  printf("Passed all asserts!\n");
  return 0;
}
