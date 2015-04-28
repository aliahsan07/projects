//Card Test for Adventurer Card


#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"

#include <stdio.h>
#include <math.h>
#include <assert.h>

int main () {
    struct gameState G;
    int randomSeed = rand();
    int player = 0;
    int i = 0;
    int newHand;
    int oldHand;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                sea_hag, tribute, smithy};

    printf("\nStarting Test for Adventure Card...\n");

    initializeGame(2, k, randomSeed, &G);

        printf("\nStarting hand count Player: %d\n", G.handCount[0]);
        oldHand = G.handCount[0];

        cardEffect(adventurer, 0, 0, 0, &G, 0, 0);

        printf("\nEnding hand count Player: %d\n", G.handCount[0]);
        newHand = G.handCount[0];

        assert(newHand = oldHand+2);

    printf("\nEnding Test\n");

}
