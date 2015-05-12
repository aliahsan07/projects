#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

	printf("Running Unit Test 3: buyCard\n");
	int player, card;
	
	struct gameState *state = malloc(sizeof(struct gameState));
	
	player = state->whoseTurn;
	card = 1;
	
	state->handCount[player] = 5;
	state->whoseTurn = 1;
	state->phase = 0;
	state->numBuys = 0;
	
	if (buyCard(card, state) == -1 ){
		printf("PASS:Cannot purchase when numBuys <0\n");
	} else {

		printf("ERROR: Purchase allowed when numBuys <0\n");
	}

	state->numBuys = 1;

	state->supplyCount[card] = 0;
	if( buyCard(card, state) == -1){
		printf("PASS:Player cannot draw from empty supply pile\n");
	} else {
		printf("ERROR: Cannot buy when SupplyCount is empty\n");
	}
	
	state->supplyCount[card] = 1;
	state->coins = 1;
	if( buyCard(card, state) == -1){
		printf("PASS:Cannot buy w/o enough coins\n");
	} else {
		printf("ERROR: Purchased card w/o enough coins\n");
	}
	
	printf("Unittest3 (buyCards) Complete. \n");
	return 0;
}




