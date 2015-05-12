/**************************
*Matthew Zakrevsky
*unittest4.c:supply count	
*
*
*****************************/
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
	p->whoseTurn = 0;
	
	printf("initializing game, 2 players. Taking in seed from command line\n");
	initializeGame(2, k, atoi(argv[1]), p);
	
	printf("this test will cover the number of cards within the game\n");
	
	printf("province remaining: %d\n", supplyCount(province, p));
	buyCard(province , p);
	printf("purchase  province remaining: %d\n", supplyCount(province, p));
	
	printf("gold remaining: %d\n", supplyCount(gold, p));
	buyCard(gold, p);
	printf("Purchase complete. gold remaining: %d\n", supplyCount(gold, p));
	
	printf("silver remaining: %d\n", supplyCount(silver, p));
	buyCard(gold, p);
	printf("Purchase complete. silver remaining: %d\n", supplyCount(silver, p));
	
	return 0;
	}
	









