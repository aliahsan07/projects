//
//  cardtest2.c
//  Embargo test


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


int main(){

    int coinAmtA;
    int coinAmtB;
    int eCreditA;
    int eCreditB;
    int k[10] = {adventurer, embargo, great_hall, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    struct gameState g;
    
    printf("Testing Embargo...\n");
    
    initializeGame(2, k, 5, &g);
    
    coinAmtA = g.coins;
    eCreditA = g.embargoTokens[0];
    
    cardEffect(embargo, 0, 0, 0, &g, 0, 0);
    
    coinAmtB = g.coins;
    eCreditB = g.embargoTokens[0];
    assert(coinAmtB == coinAmtA + 2);
    assert(eCreditB == eCreditA + 1);
    
    printf("Test Ending...\n");
    printf("Embargo Test Passed.\n");
    
    return 0;
}
