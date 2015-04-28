#include "dominion.h"
//#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

//getWinners TEST
int main (int argc, char *argv[]){
	
		int k[10] = {adventurer, smithy, embargo, village, minion, mine, cutpurse, 
	    sea_hag, tribute, baron};
	struct gameState testState;
	struct gameState *tester = &testState;		
	int players[MAX_PLAYERS], random;
	
	srand(time(NULL));
	random = rand();
	printf("Testing getWinners...\n");
	memset(tester,0,sizeof(struct gameState));
	initializeGame(3, k, random, tester);
	testState.hand[2][0] = province;
	testState.hand[1][0] = province;
	testState.discard[0][0] = duchy;
	testState.handCount[1] = 1;
	testState.handCount[2] = 1;
	testState.discardCount[0] = 1;
	testState.whoseTurn = 1;
	
	getWinners(players, tester);
	
	printf("%d %d %d %d\n", players[0], players[1], players[2], players[3]);
	assert(players[0] == 0);
	assert(players[1] == 0);
	assert(players[2] == 1);
	assert(players[3] == 0);
	
	getWinners(players, tester);
	
	printf("%d %d %d %d\n", players[0], players[1], players[2], players[3]);	
	assert(players[0] == 0);
	assert(players[1] == 0);
	assert(players[2] == 1);
	assert(players[3] == 0);
	
	printf("getWinners Tests Complete...\n");		
	return EXIT_SUCCESS;
}