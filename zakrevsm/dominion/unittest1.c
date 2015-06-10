/***********************
*Matthew Zakrevsky
*unittest1.c: scoreFor
*cs362 SP 2015
****************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main(int argc, char* argv[]){
	struct gameState state;
	struct gameState *p = &state;
	int i = 0;
	int k[10] = {council_room, feast, gardens, mine, remodel, baron, sea_hag, smithy, minion,outpost};
	
	printf("initializing game, 2 players. Taking in seed from command line\n");
	initializeGame(2, k, atoi(argv[1]), p);
	
	printf (" filling decks with junk, one player with ten curses and one province, one with all other provinces and duchy\n");
	printf("expected score for player 1: -4 points, plyer 2:45\n");
	
	//Player 1
	for(i = 0; i < 10; i++){
		gainCard(curse, p, 2, 0);
	}
	gainCard(province, p, 2, 0);
	
	printf("Player 1: Cards in deck = %d\n", p->deckCount[0]);
	
	//player2
	for(i = 0; i< 7; i++){
		gainCard(province, p, 2, 1);
	}
	gainCard(duchy, p, 2, 1);
	
	printf("Player 2: Cards in deck = %d\n", p->deckCount[1]);
	
	printf("score for player 1: %d, expected -4\n", scoreFor(0, p));
	printf("score for player 2: %d, expected 45\n", scoreFor(1,p));

	//clear all cards from the hands

	memset(&p->deckCount[0], 0, p->deckCount[1]);
	memset(&p->deckCount[1], 0, p->deckCount[1]);
	
	printf("Player 1: Cards in deck = %d\n", p->deckCount[0]);	
	printf("Player 2: Cards in deck = %d\n", p->deckCount[1]);

	//fill with junk;
	printf (" filling decks with junk, one player with 4 gardens and 40 cards in deck, one with 10 estates, 1 garden, 20 cards in deck\n");
	printf("expected score for player 1: 16 points, plyer 2:12\n");
	
	for(i = 0; i< 4; i++){
		gainCard(gardens, p, 2, 0);
	}
	
	for(i = 0; i< 6; i++){
		gainCard(smithy, p, 2, 0);
	}
	
	for(i = 0; i< 10; i++){
		gainCard(gold, p, 2, 0);
	}
	
	for(i = 0; i< 10; i++){
		gainCard(silver, p, 2, 0);
	}
	for(i = 0; i< 10; i++){
		gainCard(copper, p, 2, 0);
	}
	
	//player2
	for(i = 0; i< 10; i++){
		gainCard(estate, p, 2, 1);
	}
	
	for(i = 0; i< 9; i++){
		gainCard(copper, p, 2, 1);
	}
	
	gainCard(gardens, p, 2, 1);
	
	
	printf("score for player 1: %d, expected 16\n", scoreFor(0, p));
	printf("score for player 2: %d, expected 12\n", scoreFor(1,p));


	
	initializeGame(2, k, atoi(argv[1]), p);
	
	for ( i =0; i<10; i++){
	gainCard(curse, p, 2, 1);
	}
	
	gainCard(gardens, p , 2 ,1);
 
	
	for ( i =0; i<10; i++){
	gainCard(province, p, 2, 0);
	}
	
	
	printf("score for player 1: %d, expected 60\n", scoreFor(0, p));
	printf("score for player 2: %d, expected -9\n", scoreFor(1,p));

return EXIT_SUCCESS;
}
