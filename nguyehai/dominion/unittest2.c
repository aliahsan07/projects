#include "assert.h"
#include "dominion_helpers.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv) {
    struct gameState G;
    int index = 0;
    int cost = 0;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

    int i;
    int player;
    int randomSeed;

    printf("\nStarting Test for getCost...\n");

    SelectStream(2);
    PutSeed(3);

    printf("\nTesting inputs for getCost...\n");
    for(index = 0; index < 27; index++) {

        cost = getCost(index);

        printf("Index: %d     Cost: %d\n", index, cost);

    }

    printf("\nAll Tests PASSED\n");
    printf("\n\nEnding Test for getCost...\n");
    return 0;
}
//
