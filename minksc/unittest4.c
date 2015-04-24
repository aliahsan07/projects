#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>

int int main(int argc, char *argv[]){
	printf("*** Testing HandCard ***\n");
	struct gameState *g = newGame();
	g->whoseTurn = 1;
	int who = g->whoseTurn;
	int p = 0;

	for (int i =1; i< = 7; i++){
		g->hand[who][i]= copper;
	}
	for (int i =1; i< = 7; i++){
		if (handCard(i,g)==copper){
			printf("Test %d Passed \n",i);
		}
		else{
			printf("Test %d Failed",i);
			P++;
		}
	}
	if (p == 0){
		printf("All Tests Passed\n");
	}
	else{
		printf("%d Tests Failed\n",p);
	}
	return 0;
}