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
  
	
	int decknum = 10;
	int handnum = 0;
	int discardnum = 0;

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

	G->handCount[1] = 0;

	G->discardCount[1] = 0;

	G->deckCount[1] = decknum;
	
	G->coins = 5;
	G->supplyCount[smithy] = 3;
	G->whoseTurn = 1;
	G->numBuys = 3;
	
	buyCard(smithy, G);
	printf("Trying to buy a card normally...\n");
	if(G->discardCount[1]!= discardnum+1){
		printf("Discard count is wrong\n");
	}
	else printf("Discard count is correct\n");
	if(G->discard[1][discardnum]!= smithy){
		printf("Smithy is not placed\n");
	}
	else printf("Smithy is placed\n");
	
	discardnum++;
	G->coins = 4;
	
	printf("Trying to buy a card with just enough coins...\n");
	buyCard(smithy, G);
	if(G->discardCount[1]!= discardnum+1){
		printf("Discard count is wrong\n");
		//printf("%d\n",G->discardCount[1]);
	}
	else printf("Discard count is correct\n");
	if(G->discard[1][discardnum]!= smithy){
		printf("Smithy is not placed\n");
	}
	else printf("Smithy is placed\n");
	
	discardnum++;
	G->coins = 3;
	
	printf("Trying to buy a card with not enough coins...\n");
	buyCard(smithy, G);
	if(G->discardCount[1]!= discardnum){
		printf("Discard count is wrong\n");
		printf("%d\n",G->discardCount[1]);
	}
	else printf("Discard count is correct\n");
	if(G->discard[1][discardnum+1]!= smithy){
		printf("Smithy is not placed\n");
	}
	else printf("Smithy is placed\n");
	
	printf("Trying to buy a card with not enough buys...\n");
	buyCard(smithy, G);
	if(G->discardCount[1]!= discardnum){
		printf("Discard count is wrong\n");
		printf("%d\n",G->discardCount[1]);
	}
	else printf("Discard count is correct\n");
	if(G->discard[1][discardnum+1]!= smithy){
		printf("Smithy is not placed\n");
	}
	else printf("Smithy is placed\n");
  return 0;
}
