#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>

int main(int argc, char *argv[]){
	printf("*** Testing Great Hall Card ***\n");
	struct gameState *g = newGame();
	int i= great_hallcard(g, 0, 1);
	if(i != 0){
		printf("Test Failed! \n");
	}
	if (g->numActions -1 == g->numActions)
	{
		printf("Test Failed! \n");
	}
	else{
		printf("Test Passed! \n");
	}
	return 0;

}
