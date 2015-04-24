#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>

int int main(int argc, char *argv[]){
	struct gameState *g = newGame();
	printf("**Testing SupplyCount **\n");
	int p = dutchy
	int r = supplyCount(p, game);
	if(r == 0){
		printf("Test Passes");
	}
	else{
		printf("Test Failed");
	}
	return 0;
}