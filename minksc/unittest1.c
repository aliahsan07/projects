#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>

int main(int argc, char *argv[]){
	struct gameState *g = malloc(sizeof(struct gameState));
	printf("*** Testing WhoseTurn ***\n");
	int r = whoseTurn(g);

	if (r > g->numPlayers){
		printf("Test Failed\n");
	}

	else if (g->numPlayers <= -1){
		printf("Test Failed\n");
	}

	else{
		printf("Test Passed\n");
	}

	return 0;
}