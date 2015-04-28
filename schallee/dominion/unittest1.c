/*** unit test for updateCoins() in dominion.c ***/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "rngs.h"

int main(){

    struct gameState* G = newGame();
    int i;
    int result;
    int bonus = 3;


    printf("\nBeginning unit test for updateCoins() ... ");
    for(i = 0; i < 30; i++){
	G->hand[0][i] = 0;
        G->handCount[0]++;
    }

    G->hand[0][0] = copper; //1
    G->hand[0][8] = silver; //2
    G->hand[0][15] = gold;  //3
    G->hand[0][23] = copper; //1
    G->hand[0][29] = copper; //1


    result = updateCoins(0, G, bonus);  
    
    if(result != 0){
       printf("TEST FAILED\nExpected 0, found %i\n", result);
    
    }
    else if(G->coins != 11){
        printf("TEST FAILED\nExpected 11, found %i\n", G->coins);
    }
    else{ printf("Unit test for updateCoins() passed.\n"); }
    
    return 0;
}
