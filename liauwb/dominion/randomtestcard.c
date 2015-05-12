#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define NUMTEST 1000

int main () {
	struct gameState *G = newGame();
	srand(time(NULL));
	int seed = rand() %9 +1;
	int players = rand() %4; 
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");
  
  int r = initializeGame(players, k, seed, G);
	
for(int i = 0; i<NUMTEST; i++){
	int totalDeck = (rand()%490) +10;
	printf("Doing Iteration number %d with %d total deck cards..\n",i, totalDeck); 
	G->discardCount[1] = rand()%(totalDeck- 1);
	int discardCount = G->discardCount[1];
	printf("Discard count is %d\n",discardCount);
	G->handCount[1] = rand()% (totalDeck - G->discardCount[1]);
	int handCount = G->handCount[1];
	printf("Hand count is %d\n",handCount);
	G->deckCount[1] = totalDeck-G->discardCount[1]-G->handCount[1];
	G->numActions = rand()% 10;
	int actions = G->numActions;
	for(int x = 0; x<G->handCount[1]; x++){
		G->hand[1][x] = copper;
	}
	for(int x = 0; x<G->deckCount[1]; x++){
		G->deck[1][x] = estate;
	}
	G->hand[1][0] = village;
	doVillage(0,1,G);
	
	printf("Checking discard pile number...\n"); 
	
	printf("Checking hand number...\n"); 
	if(G->handCount[1]!= handCount){
		printf("Hand doesn't match up\n");
		exit(0);
	}
	else printf("Hand matches up\n");

	printf("Checking action number...\n"); 
	if(G->numActions!= actions +2){
		printf("Action doesn't match up\n");
		exit(0);
	}
	else printf("Action matches up\n");

	}
}