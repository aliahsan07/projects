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
    int player=1;
    printf("shuffling player 1 deck\n");
    int r;
    r=shuffle(player,&G);
    assert(r==0);
    printf("shuffled player 1 deck\n");
    printf("testing shuffling for deckcount<0\n");
    G.deckCount[1]=0;
    r=shuffle(player,&G);
    assert(r==-1);
    printf("ALL TESTS PASSED\n");
    return 0;
}
