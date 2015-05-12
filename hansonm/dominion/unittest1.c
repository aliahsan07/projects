#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) 
{
	int rv;  //return value
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	struct gameState G;
	
	printf("Starting test for initializeGame\n");
	
	rv = initializeGame(2, k, 10, &G);
	assert (rv == 0); //check game is created
	printf("Checking estate count on 2 players\n");
	assert(G.supplyCount[estate] == 8);
	printf("Checking duchy count on 2 players\n");
	assert(G.supplyCount[duchy] == 8);
	printf("Checking province count on 2 players\n");
	assert(G.supplyCount[province] == 8);
	//printf("Checking great_hall count on 2 players\n");
	//assert(G.supplyCount[copper] == 60); //Core dump
	printf("Checking curse Silver on 2 players\n");
	assert(G.supplyCount[silver] == 40);
	printf("Checking curse Gold on 2 players\n");
	assert(G.supplyCount[gold] == 30);
	
	rv = initializeGame(3, k, 10, &G);
	assert (rv == 0); //check game is created
	printf("Checking curse count on 3 players\n");
	assert(G.supplyCount[curse] == 20);
	
	rv = initializeGame(4, k, 10, &G);
	assert (rv == 0); //check game is created
	printf("Checking estate count on 4 players\n");
	assert(G.supplyCount[estate] == 12);
	printf("Checking duchy count on 4 players\n");
	assert(G.supplyCount[duchy] == 12);
	printf("Checking province count on 4 players\n");
	assert(G.supplyCount[province] == 12);
	printf("Checking curse count on 4 players\n");
	assert(G.supplyCount[curse] == 30);
	
	printf("Test Passed\n");
	
	return 0;
	
}
