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
	G->handCount[1] = 2;
	G->whoseTurn = 1;
	G->discardCount[1] = 0;
	G->hand[1][0] = salvager;
	G->hand[1][1] = village;
	int *bonus = malloc(sizeof(int));
	cardEffect(salvager,1,0,0,G,0, bonus);
	
	printf("Checking discard pile number...\n"); 
	if(G->discardCount[1]!= 1){
		printf("Discard pile doesn't match up (Discard = %d)\n", G->discardCount[1]);
	}
	else printf("Discard pile match up\n");

	
	printf("Checking hand number...\n"); 
	if(G->handCount[1]!= 0){
		printf("Hand doesn't match up(%d)\n", G->handCount[1]);
	}
	else printf("Hand matches up\n");
	
	printf("Checking buy number...\n"); 
	if(G->numBuys!= 1){
		printf("Buy doesn't match up\n");
	}
	else printf("Buy matches up\n");
}