#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(){
    struct gameState G;
    int k[11] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy,feast};
    initializeGame(2, k, 1 , &G);
    int r,i,dcbefore,handpos;
    int *p=0;
    dcbefore=G.discardCount[whoseTurn(&G)];
    printf("testing feast\n");
    G.hand[whoseTurn(&G)][0]=feast;
    r=playCard(0,3,2,3,&G);
    assert(G.discardCount[whoseTurn(&G)]=dcbefore+1);
    assert(r==0);
    printf("ALL TESTS PASSED\n");
    return 0;
}
