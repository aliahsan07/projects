#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main () {
	struct gameState *G = newGame();

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");
  
  int r = initializeGame(2, k, 3, G);
	
	G->deck[1][0] = estate;
	G->deck[1][1] = estate;
	G->deck[1][2] = estate;
	G->deck[1][3] = copper;
	G->deck[1][4] = copper;
	G->deck[1][5] = copper;
	G->deck[1][6] = copper;
	G->deck[1][7] = copper;
	G->deck[1][8] = copper;
	G->deck[1][9] = copper;
	G->deckCount[1] = 10;
	G->handCount[1] = 1;
	
	G->discardCount[1] = 0;
	G->hand[1][0] = village;
	doVillage(0,1,G);
	
	printf("Checking discard pile number...\n"); 
	if(G->discardCount[1]!= 1){
		printf("Discard pile doesn't match up (Discard = %d)\n", G->discardCount[1]);
	}
	else printf("Discard pile match up\n");
	
	printf("Checking hand number...\n"); 
	if(G->handCount[1]!= 1){
		printf("Hand doesn't match up\n");
	}
	else printf("Hand matches up\n");
	if(G->hand[1][0] != estate&& G->hand[1][0]!= copper){
		printf("Card is not drawn\n");
		if(G->hand[1][0] == village){
			printf("Card is village\n");
		}
	}
	else printf("Card is drawn\n");
	
	printf("Checking action number...\n"); 
	if(G->numActions!= 2){
		printf("Action doesn't match up\n");
	}
	else printf("Action matches up\n");
}
