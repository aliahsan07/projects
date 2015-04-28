//Unit Test 2
//Function: isGameOver
//Parameters: gameState *state

#include "dominion.h"
#include "assert.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"
#include <math.h>

int main(){
	int v;
	struct gameState state;
	printf("----------------------------\nTesting Function: isGameOver\n----------------------------\n");

	printf("----------------------\nProvince cards is empty\n");
	state.supplyCount[province] = 0;
	v = isGameOver(&state);
	assert(v==1);
	printf("----------------------\n");

	state.supplyCount[province] = 2;
	
	printf("-----------------------------------\nThree or more supply piles are at 0\n-----------------------------------\n");
	state.supplyCount[1] = 0;
	state.supplyCount[2] = 0;
	state.supplyCount[3] = 0;
	v = isGameOver(&state);
	assert(v==1);

	return 0;
}