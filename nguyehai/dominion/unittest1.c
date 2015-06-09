#include "assert.h"
#include "dominion_helpers.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int checkUpdateCoins(int index, struct gameState *state) {
    if (state == NULL)
        return -1;

    updateCoins(index, state, 0);
    return 1;
}

int main (int argc, char** argv) {
    struct gameState G;
    int index = 0;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

    int i;
    int player;
    int randomSeed;

    printf("\nStarting Test for updateCoins...\n");

    SelectStream(2);
    PutSeed(3);

    printf("\nTesting inputs for updateCoins...\n");
    for(i = 0; i < 10000; i++) {
        player = floor(Random() * 2);
        randomSeed = floor(Random() * 30);
        initializeGame(player, k, randomSeed, &G);
        G.numActions = 1;
        G.numBuys = 0;
        index = floor(Random() * 26);
        checkUpdateCoins(index, &G);
    }

    printf("\nAll Tests PASSED\n");
    printf("\n\nEnding Test for updateCoins...\n");
    return 0;
}
//
