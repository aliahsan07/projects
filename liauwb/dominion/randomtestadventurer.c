#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define NUMTEST 1000

int main () {
	struct gameState *G = newGame();
	srand(time(NULL));
	int seed = rand()%9+1;
	int players = rand() %4;
	int test;
	int temp;
	int discarded;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");
  
  int r = initializeGame(players, k, seed, G);
	
for(int i = 0; i<NUMTEST; i++){
	temp = 0;
	int totalDeck = (rand()%490) +10;
	printf("Doing Iteration number %d with %d total deck cards..\n",i, totalDeck); 
	G->discardCount[1] = rand()%(totalDeck- 1);
	int discardCount = G->discardCount[1];
	printf("Discard count is %d\n",discardCount);
	G->handCount[1] = rand()% (totalDeck - G->discardCount[1]);
	int handCount = G->handCount[1];
	printf("Hand count is %d\n",handCount);
	G->deckCount[1] = totalDeck-G->discardCount[1]-G->handCount[1];
	
	for(int x = 0; x<G->handCount[1]; x++){
		G->deck[1][x] = estate;
	}
	for(int x = 0; x<G->deckCount[1]; x++){
		
		test = rand()%2;
		if(test==1){
			G->deck[1][x] = copper;
			temp++;
		}
		else{
			G->deck[1][x] = estate;
			if(temp<2){
				discardCount++;
			}
		}
	}
	G->hand[1][0] = village;
	printf("playing adventure\n");
	doAdventurer(1,G);
	
	printf("Checking discarded..\n");
	if(G->discardCount[1]!=discardCount){
		printf("discard doesn't match up (%d as compared to %d) \n", G->discardCount[1], discardCount);
	}
	else printf("Discard matches up\n");
	printf("Checking hand number...\n"); 
	if(G->handCount[1]!= handCount+1){
		printf("Hand doesn't match up (%d as compared to %d) \n", G->handCount[1], (handCount+1));
	}
	else printf("Hand matches up\n");

	printf("Checking card...\n"); 
	if(G->hand[1][handCount]!= copper||G->hand[1][handCount+1]!=copper){
		printf("Card in hand doesnt match up\n");
	}
	else printf("Card matches up\n");

	}
}