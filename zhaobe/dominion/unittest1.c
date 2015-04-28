//
//  unittest1.c
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
    
    printf("Test Multiple New Games--------\n");
    printf("Unit Test 1 Running...\n");

    for (i = 0; i < 30; i++) {
        struct gameState *g = newGame();
        //assert that game isn't bad
        assert(g != NULL);
        free(g);
    }
    
    printf("Unit Test 1 Finished \n");
    printf("Unit Test 1 Passed \n");
    
    return 0;
}