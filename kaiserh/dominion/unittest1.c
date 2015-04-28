#include "dominion.h"
//#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

//COPIED OVER COMPARE FROM dominion.c FOR TESTING
#ifdef DEBUG
int compare2(const void* a, const void* b) {
  if (*(int*)a > *(int*)b)
    return 1;
  if (*(int*)a < *(int*)b)
    return -1;
  return 0;
}
#endif

//SHUFFLE TEST
int main (int argc, char *argv[]){
	int k[10] = {adventurer, smithy, embargo, village, minion, mine, cutpurse, 
	    sea_hag, tribute, baron};
	struct gameState testState;
	struct gameState *tester = &testState;
	struct gameState saveState;
	int check, random, lost_count = 0;
	int deck_a, deck_b;
	
	srand(time(NULL));
	random = rand();
	printf("Testing Shuffle...\n");
	initializeGame(4, k, random, tester);
	
	memcpy(&saveState, tester, sizeof(struct gameState));
	
	
	printf("P2:\n");
	printf("Deck Count: %d\n", testState.deckCount[1]);
	for(int i = 0; i < testState.deckCount[1]; i++){
		printf("Card[%d]: %d\n", i, testState.deck[1][i]);
	}
	
	deck_a = testState.deckCount[0];
	check = shuffle(0, tester);
	deck_b = testState.deckCount[0];
	if (check == -1 || (deck_a != deck_b)){
		printf("Player 1 Test 1 FAILED...\n");
	}
	
	deck_a = testState.deckCount[0];
	check = shuffle(0, tester);
	deck_b = testState.deckCount[0];
	if (check == -1 || (deck_a != deck_b)){
		printf("Player 1 Test 2 FAILED...\n");
	}
	
	deck_a = testState.deckCount[1];	
	check = shuffle(1, tester);
	deck_b = testState.deckCount[1];
	if (check == -1 || (deck_a != deck_b)){
		printf("Player 2 Test 1 FAILED...\n");
	}
	
	deck_a = testState.deckCount[2];
	check = shuffle(2, tester);
	deck_b = testState.deckCount[2];
	if (check == -1 || (deck_a != deck_b)){
		printf("Player 3 Test 1 FAILED...\n");
	}
	
	deck_a = testState.deckCount[3];
	check = shuffle(3, tester);
	deck_b = testState.deckCount[3];
	if (check == -1 || (deck_a != deck_b)){
		printf("Player 4 Test 1 FAILED...\n");
	}
	deck_a = testState.deckCount[1];
	check = shuffle(1, tester);
	deck_b = testState.deckCount[1];
	if (check == -1 || (deck_a != deck_b)){
		printf("Player 2 Test 2 FAILED...\n");
	}

	deck_a = testState.deckCount[2];
	check = shuffle(2, tester);
	deck_b = testState.deckCount[2];
	if (check == -1 || (deck_a != deck_b)){
		printf("Player 3 Test 2 FAILED...\n");
	}

	deck_a = testState.deckCount[3];
	check = shuffle(3, tester);
	deck_b = testState.deckCount[3];
	if (check == -1 || (deck_a != deck_b)){
		printf("Player 4 Test 2 FAILED...\n");
	}
	
	testState.deckCount[2] = 0;
	check = shuffle(2, tester);
	if (check == 0)
		printf("Empty Deck Test FAILED...\n");		
	
    qsort ((void*)(testState.deck[1]), testState.deckCount[1], sizeof(int), compare2);
    qsort ((void*)(saveState.deck[1]), saveState.deckCount[1], sizeof(int), compare2);
	for(int i = 0; i < testState.deckCount[1]; i++){
		if(testState.deck[1][i] != saveState.deck[1][i])
			lost_count++;
	}
	
	printf("Sort Test: %d Cards Lost\n", lost_count);
	printf("P2:\n");
	printf("Deck Count: %d\n", testState.deckCount[1]);
	for(int i = 0; i < testState.deckCount[1]; i++){
		printf("Card[%d]: %d\n", i, testState.deck[1][i]);
	}
	
	printf("Shuffle Tests Complete...\n");
	
	return EXIT_SUCCESS;
}