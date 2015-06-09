/**********************
*Matthew Zakrevsky	
*cardtest4.c
***********************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int determineChoice(int choice){
	switch(choice){
		case 0: return -1;break;
		
		case 1: return 0;break;
		
		case 2: return 1;break;
		
		default: return 1; break;
	}
}

int main(int argc, char* argv[]){
	srand(atoi(argv[1]));
	struct gameState state;
	struct gameState *p = &state;
	int i = 0;
	int k[10] = {feast, gardens, mine, remodel,council_room,  baron, sea_hag, smithy, minion,outpost};
	int smithyPos= -1;
	int result = 0;
	int c1, c2, c3, r1,r2,r3;
	

	initializeGame(2 ,k, atoi(argv[1]),p); 
	p->whoseTurn = 0;	
		
	for( i =0 ; i < 10 ; i++){
	p->hand[0][3]=feast;
	 r1 = rand()%2;
	 r2 = rand()%2;
	 r3 = rand()%2;
	
	c1 = determineChoice(r1);	
	c2 = determineChoice(r2);
	c3 = determineChoice(r3);

	printf("playing Feast\n");
	playCard(3, c1,c2,c3,p);
	}

	
	
	printf("Test complete.\n");
	
	
	
	return 0;
}

