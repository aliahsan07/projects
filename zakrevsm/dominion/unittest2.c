/*************************
*MAtthew Zakrevsky 
*unittest2.c: Shuffle unit test
**************************/
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

int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
		   
	printf("initializing game with 2 players and random seed from command line\n");
	
	initializeGame(2, k, atoi(argv[1]), p);
	
	//adding to the first player's deck.
	printf("player 5 gained silver, shuffling deck\n");
	for(i = 0; i < 5; i++){
			gainCard(silver, p, 1, 0);
	}	
	
	for( i = 0; i < p->deckCount[0]; i++ ){
		printf("card: %d\n", p->deck[0][i]);	
	}
	
	printf("shuffling the decks\n");
	
	shuffle( 0,p);
	
	printf("results:");
	for( i = 0; i < p->deckCount[0]; i++ ){
		printf("card: %d \n", p->deck[0][i]);	
	}
	
	printf("shuffling the decks, results:\n");
	
	shuffle(0,p);
	
	for( i = 0; i < p->deckCount[0]; i++ ){
		printf("card: %d \n", p->deck[0][i]);	
	}
	

return 0;
}