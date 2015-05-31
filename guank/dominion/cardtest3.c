#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int r, handCount;

	struct gameState state;
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	printf("Running Unit Test: Smithy \n");
	

	initializeGame(4, k, 10, &state);
		
	handCount = state.handCount[0] + 2;
	printf("Current Hand: %d \n", state.handCount[0]);
		
	r = cardEffect(smithy, 0, 0, 0, &state, 0, 0);
	
	printf("\nSmithy activates. \n\n");
		
	if(state.handCount[0] != handCount){
		printf("ERROR: Hands don't match. test: %d. returned: %d \n", handCount, state.handCount[0]);
	}
	else{
		printf("Updated Hand Count: %d \nPASS: Card properly drawn.\n", state.handCount[0]);
	}
		

	printf("Unit Test: Smithy complete. \n");
	
	return 0;

}