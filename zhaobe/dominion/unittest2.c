//
//  unittest2.c
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main(int argc, char* argv[]){

    int k[10] = {adventurer, embargo, great_hall, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    struct gameState g;
    
    printf("Test for number of cards in hand--------\n");
    printf("Unit Test 2 Running...\n");
    
    initializeGame(2, k, 5, &g);
    assert(numHandCards(&g) == 5);
    
    printf("Unit Test 2 Finished \n");
    printf("Unit Test 2 Passed \n");
    
    return 0;
}