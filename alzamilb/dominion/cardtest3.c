/*  Basil Alzamil  
    CS 362 - Assignment #2
    April 21, 2015 
 */

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Testing embargo()
int main (int argc, char** argv) {
    int currentPlayer;
    struct gameState G; 
    int choice3 = 0;
    int handPos = 5;
    int r;
    int players = 2;
    int bonus = 0;
    int coins_before;
    int coins_after;
    int embargoTokens_before;
    int embargoTokens_after;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    r = initializeGame(players, k, 3, &G);
    currentPlayer = whoseTurn(&G);
    assert (r == 0);
   
//Test 1: returned value is zero
//Test 2: embargo suppose to add +2 coins: Checking G coins before and after
//Test 3: Checking emabargoTokens
    coins_before = G.coins;
    embargoTokens_before = G.embargoTokens[4]; //4 is choice1 
    r = cardEffect(embargo, copper, province, choice3, &G, handPos, &bonus);
    assert(r == 0);
    printf("Passed Test#1 successfully!\n");
    coins_after = G.coins;
    embargoTokens_after = G.embargoTokens[4];
    assert(coins_after == coins_before+2);
    printf("Passed Test#2 successfully!\n");
    assert(embargoTokens_after == embargoTokens_before+1);
    printf("Passed Test#3 successfully!\n");
    

return 0;
}
