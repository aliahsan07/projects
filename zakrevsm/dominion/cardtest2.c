/**********************
* Matthew Zakrevsky
*cardTest2:gardens
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
	
	p->hand[0][1] = gardens;
	
	printf("playing gardens\n");
	result = playCard(1, 0, 0, 0,p);
	
	printf("result of test: %d\n", result);
	
	printf("test complete\n");
	
	return 0;
	}