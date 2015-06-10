#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int main (int argc, char** argv) {
	struct gameState G;
	int seed = 1;
	int result;
  int * bonus;

	printf("testing minion\n");
  
  int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, minion};

  initializeGame(2, k, seed, &G);

  G.hand[0][0] = minion;

  assert(G.handCount[0] == 5);
  assert(G.numActions == 1);
  int coins = G.coins;

  assert(cardEffect(minion, 1, 0, 0, &G, 0, bonus) == 0);

  assert(G.coins == coins + 2);
  assert(G.numActions == 2);

  initializeGame(2, k, seed, &G);
  G.handCount[1] = 5;
  G.hand[0][0] = minion;
  G.hand[1][0] = curse;
  int i;
  for(i = 1; i < 5; i++){
    G.hand[0][i] = curse;
    G.hand[1][i] = curse;
  }
  assert(cardEffect(minion, 0, 1, 0, &G, 0, bonus) == 0);

  assert(G.handCount[0] == 4);
  assert(G.handCount[1] == 4);
  for(i = 0; i < 4; i++){
    assert(G.hand[0][i] != curse);
    assert(G.hand[1][i] != curse);
  }


  

  printf("minion: PASSED\n");

}