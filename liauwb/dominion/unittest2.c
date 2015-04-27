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
	G->numPlayers = 2;
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
	G->deck[2][0] = estate;
	G->deck[2][1] = estate;
	G->deck[2][2] = estate;
	G->deck[2][3] = copper;
	G->deck[2][4] = copper;
	G->deck[2][5] = copper;
	G->deck[2][6] = copper;
	G->deck[2][7] = copper;
	G->deck[2][8] = copper;
	G->deck[2][9] = copper;
	G->handCount[1] = 0;
	G->handCount[2] = 0;
	G->discardCount[1] = 0;
	G->discardCount[2] = 0;
	G->deckCount[1] = decknum;
	G->deckCount[2] = decknum;
	
	G->supplyCount[smithy] = 3;

	
	printf("Trying to gain card to top of deck...\n");
	gainCard(smithy, G, 1, 1);
	if(G->deckCount[1]!= decknum+1){
		printf("Deck count is wrong\n");
	}
	else printf("Deck count is correct\n");
	if(G->deck[1][decknum]!= smithy){
		printf("Smithy is not placed\n");
	}
	else printf("Smithy is placed\n");
	
	printf("Trying to gain card to hand...\n");
	gainCard(smithy, G, 2, 1);
	if(G->handCount[1]!= handnum+1){
		printf("Hand count is wrong\n");
	}
	else printf("Hand count is correct\n");
	if(G->hand[1][handnum]!= smithy){
		printf("Smithy is not placed\n");
	}
	else printf("Smithy is placed\n");
	
	printf("Trying to gain card to discard pile...\n");
	gainCard(smithy, G, 0, 1);
	if(G->discardCount[1]!= discardnum+1){
		printf("Discard count is wrong\n");
	}
	else printf("Discard count is correct\n");
	if(G->discard[1][discardnum]!= smithy){
		printf("Smithy is not placed\n");
	}
	else printf("Smithy is placed\n");
	
	printf("Trying to gain card that is not supposed to be gained...\n");
	if(gainCard(smithy, G, 0, 1)!= -1){
		printf("Card is incorrectly gained\n");
	}
	else printf("Card is not gained\n");
  return 0;
}
