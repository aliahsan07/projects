/**********************
*Matthew Zakrevsky	
*cardtest4.c
***********************/
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
	int result = 0;
	
	p->whoseTurn = 0;

	p->hand[0][1] = outpost;
	printf("testing outpost\n");
	printf("outpost played: %d\n", p->outpostPlayed);
	
	result = playCard(1, 0, 0, 0, p);
	
	printf("played the outpost. Outpost played: %d\n", p->outpostPlayed);
	printf("result of play card: %d\n", result);
	
	printf("outpost played: %d\n", p->outpostPlayed);
	
	result = playCard(1, 0, 0, 0, p );
	
	printf("played the outpost. Outpost played: %d\n", p->outpostPlayed);
	printf("result of play card: %d\n", result);
	
	printf("Test complete.\n");
	
	
	
	return 0;
}

