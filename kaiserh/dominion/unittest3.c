#include "dominion.h"
//#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//playCard TEST
int main (int argc, char *argv[]){
	struct gameState testState;
	struct gameState *tester = &testState;		

	printf("Testing playCard...\n");
	memset(tester,0,sizeof(struct gameState));

	testState.hand[0][0] = smithy;
	testState.hand[0][1] = village;
	testState.hand[0][2] = copper;
	for(int i = 0; i < 6; i++)
		testState.deck[0][i] = silver;
	testState.deckCount[0] = 6;
	testState.handCount[0] = 3;
	for(int i = 0; i < testState.handCount[0]; i++)
		printf("handPos %d: %d\n", i, testState.hand[0][i]);
	
	testState.phase = 1;
	if (playCard(0,0,0,0,tester) == 0)
		printf("playCard Test 1 Failed...");
	testState.phase = 0;
	
	if (playCard(0,0,0,0,tester) == 0)
		printf("playCard Test 2 Failed...");
	testState.numActions = 2;
		
	if (playCard(2,0,0,0,tester) == 0)
		printf("playCard Test 3 Failed...");
	
	if (playCard(7,1,1,7,tester) == 0)
		printf("playCard Illegal Card Test Failed...");		
	
	playCard(0, 0, 0, 0, tester); // PLAY SMITHY
	
	printf("P1:\n");
	printf("handCount: %d\n", testState.handCount[0]);
	for(int i = 0; i < testState.handCount[0]; i++)
		printf("handPos %d: %d\n", i, testState.hand[0][i]);	
	printf("deckCount: %d\n", testState.deckCount[0]);
	printf("numActions: %d\n", testState.numActions);
	printf("discardCount: %d\n", testState.discardCount[0]);
	printf("Coins: %d\n", testState.coins);
	
	playCard(1, 0, 0, 0, tester); //PLAY VILLAGE	

	printf("P1:\n");
	printf("handCount: %d\n", testState.handCount[0]);
	for(int i = 0; i < testState.handCount[0]; i++)
		printf("handPos %d: %d\n", i, testState.hand[0][i]);	
	printf("deckCount: %d\n", testState.deckCount[0]);
	printf("numActions: %d\n", testState.numActions);
	printf("discardCount: %d\n", testState.discardCount[0]);
	printf("Coins: %d\n", testState.coins);	
	
	if(testState.coins != 9)
		printf("(COINS) TEST FAILED!\n");
	if(testState.handCount[0] != 5)
		printf("(HANDCOUNT) TEST FAILED!\n");
	if(testState.numActions != 2)
		printf("(NUMACTIONS) TEST FAILED!\n");
	if(testState.deckCount[0] != 2)
		printf("(DECKCOUNT) TEST FAILED!\n");	
	if(testState.discardCount[0] != 0)
		printf("(DISCARDCOUNT) TEST FAILED!\n");	
	if(testState.playedCardCount != 2)
		printf("(PLAYEDCOUNT) TEST FAILED!\n");
		
	printf("playCard Tests Complete...\n");	
	
	return EXIT_SUCCESS;
}