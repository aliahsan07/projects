/*  Basil Alzamil  
    CS 362 - Assignment #2
    April 21, 2015 
 */

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Testing smithy()
int main (int argc, char** argv) {
    int currentPlayer;
    struct gameState G; 
    int choice3 = 0;
    int handPos = 5;
    int r;
    int players = 2;
    int bonus = 0;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    r = initializeGame(players, k, 3, &G);
    currentPlayer = whoseTurn(&G);
    assert (r == 0);

       
//Test 1: smithy: smithy should give the player +3 cards
    r = cardEffect(smithy, copper, province, choice3, &G, handPos, &bonus);
    if (r != 3)
    printf("r = %d, smithy Test Fails!\n", r);

  return 0;
}

