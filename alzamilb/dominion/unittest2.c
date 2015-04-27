/*  Basil Alzamil  
    CS 362 - Assignment #2
    April 21, 2015 
 */

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Testing whoseTurn()
int main(int argc, char** argv) {
    struct gameState G; 
    int G_turn;
    int r;
    int players;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    for (players = 2 ; players <= 4 ; ++players) {
        r = initializeGame(players, k, 2, &G);
        assert (r == 0);
        r = whoseTurn(&G);
        assert (r == G.whoseTurn);
    }

    printf("Passed Tests Successfully!\n");

return 0;
}
