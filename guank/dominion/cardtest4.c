#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int r, handCount, numBuys, discardCount;

	struct gameState state;
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	printf("Running Unit Test: Salvager \n");

	initializeGame(2, k, 10, &state);
		
	handCount = state.handCount[0] - 1;
	numBuys = state.numBuys + 1;
	discardCount = state.discardCount[0] + 1;
	
	printf("Current Hand: %d \n", state.handCount[0]);
	printf("Current Buys: %d \n", state.numBuys);
	printf("Current Discard Pile: %d \n", state.discardCount[0]);
		
	r = cardEffect(salvager, 0, 0, 0, &state, 0, 0);
	
	printf("\n Salvager activates. \n\n");
		
	if(state.handCount[0] != handCount){
		printf("ERROR: Hands don't match. test: %d. returned: %d \n", handCount, state.handCount[0]);
	}
	else{
		printf("Updated Hand Count: %d \nPASS: Card properly discarded.\n", state.handCount[0]);
	}
	
	if(state.numBuys != numBuys){
		printf("ERROR: Buy Counts don't match. test: %d. returned: %d \n", numBuys, state.numBuys);
	}
	else{
		printf("Updated Buy Count: %d \nPASS: Buy properly added.\n", state.numBuys);
	}
	
	if(state.discardCount[0] != discardCount){
		printf("ERROR: Discard Piles don't match. test: %d. returned: %d \n", discardCount, state.discardCount[0]);
	}
	else{
		printf("Updated Discard Pile: %d \nPASS: Card properly discarded to discard pile.\n", state.discardCount[0]);
	}

	printf("Unit Test: Salvager complete. \n");
	
	return 0;

}