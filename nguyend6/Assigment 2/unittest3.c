/*
Name: unittest3.c
Author: Duy Nguyen
Date: 4/26/2015
Assigiment 2 - CS 362
Program: Testing the whoseTurn function
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

	printf("------------------------Testing the whoseTurn function:-------------------------- \n");

	printf("Test for 2 players:\n");
	initializeGame(2, k, p , q);
	r = whoseTurn(q) ;
	printf("Turn1: %d \n",r);
	assert(r == 0);
	endTurn(q);
	r = whoseTurn(q) ;
	printf("Turn2: %d \n",r);
	assert(r == 1);
	endTurn(q);
	r = whoseTurn(q) ;
	printf("Turn1: %d \n\n",r);
	assert(r == 0);

	printf("Test for 4 players:\n");
	initializeGame(4, k, p , q);
	r = whoseTurn(q) ;
	printf("Turn1: %d \n",r);
	assert(r == 0);
	endTurn(q);
	r = whoseTurn(q) ;
	printf("Turn2: %d \n",r);
	assert(r == 1);
	endTurn(q);
	r = whoseTurn(q) ;
	printf("Turn3: %d \n",r);
	assert(r == 2);
	endTurn(q);
	r = whoseTurn(q) ;
	printf("Turn4: %d \n",r);
	assert(r == 3);
	endTurn(q);
	r = whoseTurn(q);
	assert(r == 0);
	printf("Turn1: %d \n",r);

	return 0;
}
