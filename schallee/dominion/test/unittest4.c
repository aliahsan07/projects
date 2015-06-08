/*** Unit test for whoseTurn() in dominion.c ***/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dominion.h"

int main(){


    struct gameState* G = newGame();
    int numPlayers = 4;
    int r, i, flag;
   
    printf("\nBeginning whoseTurn() test ... ");
    
    flag = 0;

    for(i = 0; i < numPlayers; i++){
        G->whoseTurn = i;
	r = whoseTurn(G); 
        if(r != i){
	    flag = 1;
	    printf("TEST FAILED\n");
	    break;
	}
    }
    if(!flag){
        printf("TEST SUCCESSFULLY COMPLETED.\n");
    }
    return 0;
}
