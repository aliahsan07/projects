#include "dominion.h"
//#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//buyCard TEST
int main (int argc, char *argv[]){
	struct gameState testState;
	struct gameState *tester = &testState;	
	
	printf("Testing buyCard...\n");
	memset(tester,0,sizeof(struct gameState));
	testState.supplyCount[estate] = 4;
	for(int i = 0; i < 5; i++){
		printf("Estates Remaining: %d\n", testState.supplyCount[estate]);
		if((testState.supplyCount[estate] < 1) && (buyCard(estate, tester) == 0))
			printf("buyCard Test 4 FAILED...\n");
			
		if(buyCard(estate, tester) == 0)
			printf("buyCard Test 1 FAILED...\n");
		testState.numBuys++;
		
		if(buyCard(estate, tester) == 0)
			printf("buyCard Test 2 FAILED...\n");
		testState.coins = 2;
	
		if((testState.supplyCount[estate] > 0) && (buyCard(estate, tester) == -1)){
			printf("estate cost = 2, coins = %d\n", testState.coins);
			printf("buyCard Test 3 FAILED...\n");
		}
	}
	printf("Final Estates Remaining: %d\n", testState.supplyCount[estate]);
	printf("buyCard Tests Complete...\n");
	
	return EXIT_SUCCESS;
}