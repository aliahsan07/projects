#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

	printf("Running Unit Test 1: newGame\n");

	for(int i = 0; i < 50; i++){
		struct gameState *g = newGame();
		if(g == NULL){
			printf("ERROR: w/ allocating newGame \n");
		}
		free(g);
	}

	printf("Unittest1 (newGame) Complete. \n");

	return 0;
}
