#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){

	printf("Running Unit Test 2: updateCoins \n");

	struct gameState *state = malloc(sizeof(struct gameState));
	
	int i, player, bonus, coincheck;
	i = 0;
	player = 1;
	bonus = 2;
	state->handCount[player]  = 4;
	state->hand[player][0] =  1;	
	state->hand[player][1] =  copper;		
	state->hand[player][2] =  silver; 
	state->hand[player][3] =  gold;
	state->coins  = 5;

	if(updateCoins(player, state, bonus) != 0){
		assert(i != 0);
	}
	else{
		coincheck = 8;
		if( coincheck == state->coins ){
			printf("PASS: Add Every Card Test\nTest Val: %d\n Returned Val: %d \n", coincheck, state->coins);
		} 
		else{
			printf("ERROR: Add Every Card Test\nTest Val: %d\nFunction Val: %d \n", coincheck, state->coins);
		}
	}

	bonus = 0;
	state->coins = 5;
	state->handCount[player]  = 4;
	state->hand[player][0] =  1;
	state->hand[player][1] =  1;		
	state->hand[player][2] =  1; 
	state->hand[player][3] =  1;
	
	if(updateCoins(player, state, bonus) != 0){
		assert(i != 0);
	}
	else{
		coincheck = 0;
		if( coincheck == state->coins ){
			printf("PASS: No Coins Test\nTest Val: %d\nReturned Val: %d \n", coincheck, state->coins);
		} 
		else{
			printf("ERROR: No Coins Test\nTest Val: %d\nReturned Val: %d \n", coincheck, state->coins);
		}
	}
	
	bonus = 0;
	state->coins  = 5;
	state->handCount[player]  = 4;
	state->hand[player][0] =  copper;
	state->hand[player][1] =  copper;		
	state->hand[player][2] =  copper; 
	state->hand[player][3] =  copper;

	if(updateCoins(player, state, bonus) != 0){
		assert(i != 0);
	}
	else{
		coincheck = 4;
		if( coincheck == state->coins ){
			printf("PASS: Identical Coin Test\nTest Val: %d\nFunction Val: %d \n", coincheck, state->coins);
		} 
		else{
			printf("ERROR: Identical Coin Test\nTest Val: %d\nFunction Val: %d \n", coincheck, state->coins);
		}
	}

	printf("Unittest2 (updateCoin) Complete. \n");

	return 0;
}