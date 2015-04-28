/*** Test for smithy in dominion.c  ***/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

int main(){

    struct gameState G;
     int k[10] = {minion, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo,
                   outpost};
    int r;
    int numPlayers = 3;
    int rSeed = 3; 
    int player = 0;
    int handCountBefore;
    int card = smithy;
    int flag = 0;

    initializeGame(numPlayers, k, rSeed, &G);
    
    handCountBefore = G.handCount[player];
    G.hand[player][0] = card;
    
    printf("\nBeginning smithy card test ... ");
  
    r = cardEffect(card, 0, 0, 0, &G, 0, 0);
    
    if(r != 0){
        flag = 1;
	printf("TEST FAILED: return value\nExpected value 0, found %i\n", r);
    }
    else if(G.handCount[player] != handCountBefore+2){
        flag = 1;
	printf("TEST FAILED: handCount\n Expected value %i, found %i\n", handCountBefore+2, G.handCount[player]);
    }
    if(!flag){
        printf("Test passed successfully\n");
    }

    return 0;
}
