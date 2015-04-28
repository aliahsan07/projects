/*
Name: unittest4.c
Author: Duy Nguyen
Date: 4/26/2015
Assigiment 2 - CS 362
Program: Testing the numHandCards function
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
	int r;

	printf("---------------------Testing the numHandCards function--------------------\n");

	initializeGame(2, k, p , q);
	r = numHandCards(q) ;
	printf("HandCard: %d \n",r);
	assert(r == 5);

	return 0;
}
