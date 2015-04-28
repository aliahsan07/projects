/*  Basil Alzamil  
    CS 362 - Assignment #2
    April 21, 2015 
 */

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Testing numHandCards()
int main(int argc, char** argv) {
    struct gameState G; 
    int G_turn;
    int r;
    int players = 2;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    r = initializeGame(players, k, 3, &G);
    assert (r == 0);
   
    r = numHandCards(&G);
    assert(r == G.handCount[whoseTurn(&G)]);
 
    printf("Passed Tests Successfully!\n");

return 0;
}

