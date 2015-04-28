//
//  unittest4.c
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
    
    int gameRunning;
    int k[10] = {adventurer, embargo, great_hall, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    printf("Test that game hasn't finished--------\n");
    printf("Unit Test 4 Running...\n");
    
    struct gameState *g = newGame();
    
    initializeGame(3, k, 3, g);
    
    gameRunning = isGameOver(g);
    printf("If 0 game is still running: %d \n", gameRunning);
    assert(gameRunning == 0);
    
    printf("Unit Test 4 Finished \n");
    printf("Unit Test 4 passed. \n");
    
    return 0;
}