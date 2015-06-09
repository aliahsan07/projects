// Card Test for Council Room

#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"

#include <stdio.h>
#include <assert.h>
#include <math.h>

int main () {
    struct gameState G;
    int randomSeed = rand();
    int player = 0;
    int choice1, choice2, choice3;
    int handPos;
    int *bonus;

    int i;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                sea_hag, tribute, smithy};

    printf("\nStarting Test for Council Room...\n\n");

    initializeGame(3, k, randomSeed, &G);

    printf("Starting Cards in Deck for Player 1: %d\n", G.deckCount[0]);
    printf("Starting Cards in Deck: %d\n", G.deckCount[1]);
    printf("Starting Buys: %d\n\n", G.numBuys);

    //cardEffect(council_room, choice1, choice2, choice3, &G, 0, 0);
    cardEffect(council_room, 0, 0, 0, 0, 0, 0);

    printf("Ending Cards in Deck for Player 1: %d\n", G.deckCount[0]);
    assert(G.deckCount[0] == 1);
    printf("Ending Cards in Deck for Player 2: %d\n", G.deckCount[1]);
    assert(G.deckCount[1] == 9);
    printf("Ending Buys: %d", G.numBuys);

    printf("\n\nTests PASSED");
    printf("\n\n\n\nEnd Test\n\n");
}
