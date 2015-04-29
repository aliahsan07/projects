#include "dominion.h"
//#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

//MINION TEST
int main (int argc, char *argv[]){
	struct gameState testState;
	struct gameState *tester = &testState;		

	printf("Testing Minion...\n");
	memset(tester,0,sizeof(struct gameState));

	testState.hand[0][0] = minion;
	testState.hand[0][1] = minion;
	testState.hand[0][2] = gold;
	
	for(int i = 0; i < 4; i++)
		testState.deck[0][i] = silver;
	testState.deckCount[0] = 4;
	testState.handCount[0] = 3;
	testState.numActions = 1;
	
	printf("P1:\n");
	printf("handCount: %d\n", testState.handCount[0]);
	for(int i = 0; i < testState.handCount[0]; i++)
		printf("handPos %d: %d\n", i, testState.hand[0][i]);	
	printf("deckCount: %d\n", testState.deckCount[0]);	
	printf("numActions: %d\n", testState.numActions);
	printf("Coins: %d\n", testState.coins);
	printf("discardCount: %d\n", testState.discardCount[0]);	
	
	playCard(0, 1, 0, 0, tester);
	
	printf("P1 played Minion (choice1):\n");
	printf("handCount: %d\n", testState.handCount[0]);
	for(int i = 0; i < testState.handCount[0]; i++)
		printf("handPos %d: %d\n", i, testState.hand[0][i]);	
	printf("deckCount: %d\n", testState.deckCount[0]);	
	printf("numActions: %d\n", testState.numActions);
	printf("Coins: %d\n", testState.coins);
	printf("discardCount: %d\n", testState.discardCount[0]);	
	
	playCard(1, 0, 1, 0, tester);
	
	printf("P1 played Minion (choice2):\n");
	printf("handCount: %d\n", testState.handCount[0]);
	for(int i = 0; i < testState.handCount[0]; i++)
		printf("handPos %d: %d\n", i, testState.hand[0][i]);	
	printf("deckCount: %d\n", testState.deckCount[0]);	
	printf("numActions: %d\n", testState.numActions);
	printf("Coins: %d\n", testState.coins);
	printf("discardCount: %d\n", testState.discardCount[0]);

	if(testState.coins != 10)
		printf("(COINS) TEST FAILED!\n");
	if(testState.handCount[0] != 4)
		printf("(HANDCOUNT) TEST FAILED!\n");
	if(testState.numActions != 1)
		printf("(NUMACTIONS) TEST FAILED!\n");
	if(testState.deckCount[0] != 0)
		printf("(DECKCOUNT) TEST FAILED!\n");	
	if(testState.discardCount[0] != 2)
		printf("(DISCARDCOUNT) TEST FAILED!\n");
	
	printf("Minion Test Complete...\n");
	
	return EXIT_SUCCESS;
}