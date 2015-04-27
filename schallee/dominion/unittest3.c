/*** Unit test for isGameOver in dominion.c ***/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dominion.h"

int main(){


    struct gameState G;
    int r, i;

    for(i = 0; i <= treasure_map; i++){    
	G.supplyCount[i] = 1;
    } 

    G.supplyCount[curse] = 0;
    G.supplyCount[village] = 0;
    G.supplyCount[treasure_map] = 0;

    printf("\nBeginning isGameOver() test ... \n");
    r = isGameOver(&G);

    if(r != 1){
        printf("TEST FAILED\nExpected 1, found %i\n", r);
    }else{
        printf("TEST SUCCESSFULLY COMPLETED.\n");
	}
    return 0;
}
