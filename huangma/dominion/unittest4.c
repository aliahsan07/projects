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
    int p[2];
    printf("getting winner\n");
    r=getWinners(p,&G);
    assert(r==0);
    printf("ALL TESTS PASSED\n");
    return 0;
}
