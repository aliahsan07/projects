#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(){
        printf("--------------------TESTING council_room-----------------\n");

  struct gameState G;

  int k[10] = {adventurer, gardens, council_room, village, minion, mine, cutpurse,
               sea_hag, tribute, outpost};


  initializeGame(2, k, 30, &G);

  int r = G.numBuys+1;

  cardEffect(council_room,1,1,1,&G,1,1);

  assert(G.numBuys==r);



        printf("--------------------TEST PASSED---------------\n");

        return 0;
}


