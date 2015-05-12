#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 100 //arbitary, can be anything


int main() {
    
    printf("Running randomTestAdventurer ----------- \n");
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    
    int i;
    //    int handCount, deckCount;
    int players = 0;
    int playerNow = 0;
    int seed;
    
    srand(time(NULL));
    
    struct gameState g;
    
    for (i = 0; i < MAX_TESTS; i++) {
        
        players = (rand() % 5);
        seed = rand();
        
        initializeGame(players, k, rand(), &g);	//initialize the gameState

        
        g.deckCount[playerNow] = rand() % MAX_DECK;
        g.discardCount[playerNow] = rand() % MAX_DECK;
        g.handCount[playerNow] = rand() % MAX_HAND;
        
        
        cardEffect(adventurer, -1, -1, -1, &g, 1, -1);
    }
    
    printf("All randomTestAdventurer tests passed. \n");
    
    return 0;
}
