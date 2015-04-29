/*
Name: unittest2.c
Author: Duy Nguyen
Date: 4/26/2015
Assigiment 2 - CS 362
Program: Testing the supplyCount function
*/


#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "math.h"

int main (int argc, char** argv) {
	struct gameState G;
	struct gameState *q = &G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		sea_hag, tribute, smithy};
	int p = rand();
	int i;
	int r;  

	printf("-----------------------Testing the supplyCount function:------------------------- \n");

	initializeGame(2, k, p , q);

	i = supplyCount(adventurer,q);
	printf("Adventurer: %d\n",i);

	r = supplyCount(copper,q);
	printf("Copper: %d\n", r);

	buyCard(copper,q);
	i = supplyCount(copper,q);
	printf("After one copper is Bought: %d\n",i);

	assert((r-1) == i);

}
