#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState *G = newGame();

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");
  
  int r = initializeGame(2, k, 3, G);
	for(int i = 0; i < 46; i++){
		G->hand[1][i] = copper;
	}
	G->handCount[1] = 46;
	updateCoins(1, G, 0);
	if(G->coins!= 46){
		printf("%d\n", G->coins);
		printf("Value of coins doesnt match up\n");
	}
	else{
		printf("Value of coins is correct\n");
	}
	printf("Placing no coin cards to hand..\n");
	for(int i = 0; i< 5; i++){
		G->hand[2][i] = estate;
	}
	G->handCount[2] = 5;
	updateCoins(2, G, 0);
	if(G->coins!= 0){
		printf("%d\n", G->coins);
		printf("Value of coins doesnt match up\n");
	}
	else{
		printf("Value of coins is correct\n");
	}
	return 0;
}
