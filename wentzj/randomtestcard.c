#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 40000000

//This randomly tests village
int main() {
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy}; 
    int players; 
    int handCount; 
    int deckCount;  
    int numActions;
    int passedHandCount = 0;
    int passedNumActions = 0;
    struct gameState state;
    srand(time(NULL));
    
    printf("Testing Random Village:\n");
    for (int i = 0; i < MAX_TESTS; i++) {
        players = rand() % 4;
        initializeGame(players, k, rand(), &state);
        state.deckCount[players] = rand() % MAX_DECK;
        state.discardCount[players] = rand() % MAX_DECK;
        state.handCount[players] = rand() % MAX_HAND;
        handCount = state.handCount[players];
        deckCount = state.deckCount[players];
        numActions = state.numActions;
        printf("------------------------------\n");
        printf("STARTING  state.handCount: %d\n", numHandCards(&state));
        printf("STARTING state.numActions: %d\n", state.numActions);
        cardEffect(village, 1, 1, 1, &state, 0, 0);
        printf("FINISHED  state.handCount: %d\n", numHandCards(&state));
        printf("FINISHED state.numActions: %d\n", state.numActions);
        printf("------------------------------\n");
        if(i<(MAX_TESTS - 1)){
            printf("Next Test\n");
        }
        else{
            printf("\n");
        }
        if(handCount == state.handCount[players]){
            passedHandCount++;
        }
        if(numActions == (state.numActions - 2)){
            passedNumActions++;
        }
    }

    printf("++++++++++++++++++++++++++++++\n");
    printf("Total Tests: %d\n", MAX_TESTS);
    printf("Total Passed +1 Cards: %d\n", passedHandCount);
    printf("Total Passed +2 Actions: %d\n", passedNumActions);
    printf("++++++++++++++++++++++++++++++\n\n");

    return 0;
}
