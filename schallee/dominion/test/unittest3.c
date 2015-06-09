/*** Unit test for isGameOver in dominion.c ***/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dominion.h"

#define NUM_TESTS 1

void makeCards(struct gameState* G){
    int c1, c2, c3;
    
    c1 = rand()%treasure_map+1;    
    c2 = rand()%treasure_map+1;
    c3 = rand()%treasure_map+1;
    
    while(c1 == c2){
        c2 = rand()%treasure_map+1;
    }
    while((c1 == c3) || (c2 == c3)){
        c3 = rand()%treasure_map+1;
    }
    
    G->supplyCount[c1] = 0;
    G->supplyCount[c2] = 0;
    G->supplyCount[c3] = 0;
}


int main(){
    struct gameState G;
    int r, i, j;
    int numPassed = 0, numFailed = 0;
    srand(time(NULL));

    for(j = 0; j < NUM_TESTS; j++){
	for(i = 0; i <= treasure_map; i++){    
	    G.supplyCount[i] = 1;
	} 
	
	makeCards(&G);

//	printf("\nBeginning isGameOver() test ... \n");
	r = isGameOver(&G);

	if(r != 1){
	    printf("TEST %i FAILED\nExpected 1, found %i\n", j, r);
	    numFailed++;
	    return 0;
	}else{
	    printf("TEST %i SUCCESSFULLY COMPLETED.\n", j);
	    numPassed++;
	    return 1;
	}
    }

//    printf("Tests Passed: %i\nTests Failed: %i\n", numPassed, numFailed);
}
