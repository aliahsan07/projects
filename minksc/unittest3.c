#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>

int main(int argc, char *argv[]){
	struct gameState *g = malloc(sizeof(struct gameState));
	printf("**Testing SupplyCount **\n");
	int p = duchy;
	int r = supplyCount(p, g);
	if(r == 0){
		printf("Test Passes");
	}
	else{
		printf("Test Failed");
	}
	return 0;
}