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

    printf("\nStarting test for Village...\n\n");

    initializeGame(2, k, randomSeed, &G);

    printTestResult(G.handCount[0] == 5, "Expected Value 5", "Starting Hand Count");
    printTestResult(G.numActions == 1, "Expected Value 1", "Starting Number of Actions");

    cardEffect(village, 0, 0, 0, &G, 0, 0);

    printTestResult(G.handCount[0] == 6, "Expected Value 6", "Ending Hand Count");
    printTestResult(G.numActions == 3, "Expected Value 3", "Ending Number of Actions");

    printf("\n\n\nEnd Test\n");
}

//function used to print result of a test function
void printTestResult(int predicate, char *message, char *function) {
    if (predicate)
	printf("%s: PASS (%s)\n", message, function);
    else
	printf("%s: FAIL (%s)\n", message, function);
}
