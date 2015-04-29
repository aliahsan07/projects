/*  Basil Alzamil  
    CS 362 - Assignment #2
    April 21, 2015 
 */

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Testing village()
int main (int argc, char** argv) {
    int currentPlayer;
    struct gameState G; 
    int choice3 = 0;
    int handPos = 5;
    int r;
    int players = 2;
    int bonus = 0;
    int action_old;
    int action_new;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    r = initializeGame(players, k, 3, &G);
    currentPlayer = whoseTurn(&G);
    assert (r == 0);
   
//Test 1: returned value is zero
//Test 2: Is state->numActions have been incremented by 2?
    action_old = G.numActions;
    r = cardEffect(village, copper, province, choice3, &G, handPos, &bonus);
    assert(r == 0);
    printf("Passed Test#1 successfully!\n");
    action_new = G.numActions;
    assert(action_new = action_old+2);
    printf("Passed Test#2 successfully!\n");

return 0;
}
