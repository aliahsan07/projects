/************************************
*Matthew Zakrevsky
*card1Test.c
* **********************************/


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
	int smithyPos= -1;
	p->whoseTurn = 0;
	
	p->hand[0][1] = smithy;

	for( i = 0; i < 5; i++){
	drawCard(i, p);
	}	
	printf("Player 1 card in hand: %d\n", p->handCount[0]);
	playCard(1, 0, 0, 0, p);
	printf("played smithy. Cards in hand: %d\n", p->handCount[0]);
	
	printf("cardTest1 complete\n");
	
	return 0;
	}
