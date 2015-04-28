/******************************
*Matthew Zakrevsky
*unittest3.c: buycard
******************************/

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main( int argc, char* argv[]){

//initialize game w/ the random seed.
struct gameState game;
struct gameState* p = &game;
int i;
int pos = -1;
int money = 0;



int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
		   
	initializeGame(2, k, atoi(argv[1]), p);
	
	money = 20;
	printf("beginning buyCard test\n");	

	printf("purchasing gold\n");
	buyCard(gold, p);
	
	printf("showing cards in discard pile\n");
	
	for(i = 0; i < p->discardCount[0]; i++){
		printf("card %d: %d\n", i, p->discard[0][i]);
	}
	
	printf("purchasing silver\n");
	
	buyCard(silver, p);
	
	printf("showing cards in discard pile\n");
	
	for(i = 0; i < p->discardCount[0]; i++){
		printf("card %d: %d\n", i, p->discard[0][i]);
	}
	
	printf("purchasing sea_hag\n");
	
	buyCard(sea_hag, p);
	
	for(i = 0; i < p->discardCount[0]; i++){
		printf("card %d: %d\n", i, p->discard[0][i]);
	}
	
   printf("test complete\n");
   
   return 0;
}	
