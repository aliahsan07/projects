#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>

int main(int argc, char *argv[]){
	printf("*** Testing Gardens Card ***\n ");
	struct gameState *g = newGame();
	int i=0;
	i= cardEffect(gardens, 0, 0, 0, g, 0, 0);
	if(i== -1){
		printf("Test Passed! \n");
	}
	else{
		printf("Test Failed! \n");
	}
	return 0;
}
