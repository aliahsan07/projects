/*** Test for village in dominion.c  ***/

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
    int card = village;
    int numActionsBefore;
    int handCountBefore;
    int flag = 0;

    initializeGame(numPlayers, k, rSeed, &G);
    
    G.hand[player][0] = card;
    numActionsBefore = G.numActions;
    handCountBefore = G.handCount[player];

    printf("\nBeginning village card test ... ");
  
    r = cardEffect(card, 0, 0, 0, &G, 0, 0);
    
    if(r != 0){
	flag = 1;
        printf("TEST FAILED: return value\nExpected value 0, found %i\n", r);
    }
    else if(G.numActions != numActionsBefore+2){
    	flag = 1;
        printf("TEST FAILED: numActions\nExpected value %i, found %i\n", numActionsBefore+2, G.numActions);
    }
    else if(G.handCount[player] != handCountBefore){
    	flag = 1;
        printf("TEST FAILED: handCount\nExpected value %i, found %i\n", handCountBefore, G.handCount[player]);
    }
    if(!flag){
        printf("Test passed successfully\n");
    }
    
    return 0;
}
