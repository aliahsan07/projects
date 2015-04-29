//
//  unittest3.c
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
    
    int i;
    int startGame;
    int k[10] = {adventurer, embargo, great_hall, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    struct gameState g;
    
    printf("Test for which player's turn--------\n");
    printf("Unit Test 3 Running...\n");
    
    for(i = 2; i<= 4; ++i){
        //assert game has begun
        startGame = initializeGame(i, k, 2, &g);
        assert(startGame == 0);
        
        startGame = whoseTurn(&g);
        assert(startGame == g.whoseTurn);
        
        printf("Turn of player: %d \n", i);
    }
    
    printf("Unit Test 3 Finished \n");
    printf("Unit test 3 passed. \n");
    
    return 0;
}