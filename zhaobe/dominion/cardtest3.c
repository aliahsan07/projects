//
//  cardtest3.c
//  Smithy test


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void passOrFail(int truth, char* msg, char *msg2){
    if (truth) {
        printf("TEST PASS: %s, %s--- \n", msg, msg2);
    }
    else {
        printf("TEST FAIL: %s, %s--- \n", msg, msg2);
    }
}

int main(){

    int k[10] = {adventurer, embargo, great_hall, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    struct gameState g;
    
    printf("Testing Smithy...\n");
    
    initializeGame(2, k, 5, &g);
    
    printf("Start Hand has: %d cards \n", g.handCount[0]);
    assert(g.handCount[0] == 5);
    
    cardEffect(smithy, 0, 0, 0, &g, 0, 0);
    
    printf("End Hand has: %d cards \n", g.handCount[0]);
    passOrFail(g.handCount[0] == 8, "Hand needs 8 cards", "Mismatch end amount in hand");

    return 0;
}
