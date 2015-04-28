#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int i, r, handCount, numActions;

	struct gameState state;
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	printf("Running Unit Test: Village \n");
	

	initializeGame(4, k, 10, &state);
		
	for(i = 0; i < 5; i++){
	
		handCount = state.handCount[i];
		numActions = state.numActions + 2;
		
		r = cardEffect(village, 0, 0, 0, &state, 0, 0);
		
		printf("Test %d: \n", i+1);
		
		if(state.handCount[i] != handCount){
			printf("ERROR: Hand doesn't match! \n");
		}
		else{
			printf("PASS: Card properly drawn. \n");
		}
		
		if(state.numActions != numActions){
			printf("ERROR: Number of Actions doesn't match! \n");
		}
		else{
			printf("PASS: Actions properly added. \n");
		}
	}	
	

	printf("Unit Test: Village complete. \n");
	
	return 0;

}