#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){

	printf("Running Unit Test 4: isGameOver\n");
	int i;

	struct gameState *state = malloc(sizeof(struct gameState));

	//if stack of Province cards is empty, the game ends
	state->supplyCount[province] = 0 ; 

	if( isGameOver(state) == 1 ){
		printf("PASS: game ends when all provinces are gone\n");
	} else if ( isGameOver(state) == 0 ){
		printf("ERROR: isGameOver: game still running with no provinces available\n");
	}

	
	//if three supply piles are at 0, the game ends
	for ( i = 0; i < 3 ; i++){
		state->supplyCount[i] = 0;
	} 
	if( isGameOver(state) == 0 ){
		printf("ERROR: isGameOver: returned false with win condition\n");
	} else if (isGameOver(state) == 1){
		printf("PASS: 3 supply pile Win Condition properly returned as true \n");
	}


	printf("Unittest4 (isGameOver) Complete. \n");
	return 0;

}