#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(){
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    initializeGame(2, k, 1 , &G);
    int r;
    printf("checking if game is over when its not\n");
    r=isGameOver(&G);
    assert(r==0);
    printf("checking if game is over when provinces=0\n");
    G.supplyCount[province]=0;
    r=isGameOver(&G);
    assert(r==1);
    printf("checking if game is over when j>=3\n");
    G.supplyCount[province]=2;
    G.supplyCount[0]=0;
    G.supplyCount[1]=0;
    G.supplyCount[2]=0;
    r=isGameOver(&G);
    assert(r==1);
    printf("ALL TESTS PASSED\n");
    return 0;
}
