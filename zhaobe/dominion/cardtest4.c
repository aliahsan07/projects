//
//  cardtest4.c
//  Village test


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


int main(){

    int oldAction;
    int newAction;
    int k[10] = {adventurer, embargo, great_hall, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    struct gameState *g = newGame();
    
    printf("Testing Village...\n");
    
    initializeGame(2, k, 5, g);
    
    oldAction = g->numActions;
    cardEffect(village, 0, 0, 0, g, 0, 0);
    newAction = g->numActions;
    
    printf("Number of old actions = %d \n", oldAction);
    printf("Number of new actions = %d \n", newAction);
    
    printf("Village Test Passed\n");    
    
    return 0;
}
