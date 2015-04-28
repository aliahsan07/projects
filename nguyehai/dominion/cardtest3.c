#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"

#include <stdio.h>
#include <assert.h>
#include <math.h>

int main() {
    struct gameState G;
    int randomSeed = rand();
    int player = 0;
    int choice1, choice2, choice3;
    int handPos = 0;
    int *bonus;

    int i;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy};

    printf("\nStarting Test for Smithy...\n\n");

    initializeGame(2, k, randomSeed, &G);

    printf("Starting Cards in Hand for Player 1: %d\n\n", G.handCount[0]);
    assert(G.handCount[0] == 5);

    cardEffect(smithy, choice1, choice2, choice3, &G, 0, 0);

    printf("Ending Cards in Hand for Player1: %d\n\n", G.handCount[0]);
    printTestResult(G.handCount[0] == 8, "Expected Value 8", "Ending Cards in Hand");
    //Expected value of 8, according to Wiki
    //assert(G.handCount[0] == 8);

    printf("\n\n\nEnd Test\n\n");
}

//function used to print result of a test function
void printTestResult(int predicate, char *message, char *function) {
    if (predicate)
	printf("%s: PASS (%s)\n", message, function);
    else
	printf("%s: FAIL (%s)\n", message, function);
}
