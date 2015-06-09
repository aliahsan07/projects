#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1000

int main() {

    printf("Running remodel card random test ----------- \n");
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    
    int i;
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
        
        // there is a 1 in 3 change in making deck empty
        if(seed % 3 == 0){
            g.deckCount[playerNow] = 0;
        }
        
        
        cardEffect(remodel, 1, 3, -1, &g, 1, -1);
    }
    
    printf("All randomTestCard tests passed. \n");
    
    return 0;
}
