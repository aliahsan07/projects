/*** Test for adventurerCard in dominion.c  ***/

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
    int card = adventurer;

    initializeGame(numPlayers, k, rSeed, &G);
    
    G.hand[player][0] = card;
    printf("\nBeginning adventurerCard test ... ");
  
    r = cardEffect(card, 0, 0, 0, &G, 0, 0);
    
    if(r != 0){
        printf("TEST FAILED\nExpected value 0, found %i\n", r);
    }else{
        printf("Test passed successfully\n");
    }

    return 0;
}
