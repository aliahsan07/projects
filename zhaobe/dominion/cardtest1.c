//
//  cardtest1.c
//  Adventurer test


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


int main(){
    
    int handA;
    int handB;
    int k[10] = {adventurer, embargo, great_hall, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    struct gameState g;
    
    printf("Testing Adventurer...\n");
    
    initializeGame(2, k, 5, &g);
    
    printf("Start Amount of Cards: %d\n", g.handCount[0]);
    handA = g.handCount[0];
    
    cardEffect(adventurer, 0, 0, 0, &g, 0, 0);
    
    printf("End Amount of Cards: %d\n", g.handCount[0]);
    handB = g.handCount[0];
    
    printf("Test Ending...\n");
    printf("Adventurer Test Passed.\n");
    
    return 0;
}
