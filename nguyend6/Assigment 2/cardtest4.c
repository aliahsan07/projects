/*
Name: cardtest4.c
Author: Duy Nguyen
Date: 4/26/2015
Assigiment 2 - CS 362
Program: Testing the Great Hall card
*/

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
int main (int argc, char** argv) {
	struct gameState *q = newGame();
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		sea_hag, great_hall, council_room};
	int p = rand();
	int card = great_hall; 
	int i;
	
	int handBe;//for the player
	int handAf;
	int deckBe;
	int deckAf;
	
	int numActBe;
	int numActAf;

	printf("--------------------------Testing the Great Hall card:--------------------------\n");

	initializeGame(2, k, p , q);
	q->hand[0][0] = card; //set the first card to be adventure card
	
	printf("Before play card:\n");

	handBe = q->handCount[0];
	deckBe = q->deckCount[0];
	numActBe = q->numActions;

	printf("Card on the playing player : %d \n",handBe);
	for (i = 0 ; i < handBe; i++)
	{
		if (q->hand[0][i] == card)		printf ("great_hall\n");
		if (q->hand[0][i] == copper) 	printf ("copper\n");
		if (q->hand[0][i] == estate)	printf ("estate\n");	
	}
	printf("Card on deck : %d \n",deckBe);
	printf("Number of action: %d\n", numActBe);

	playCard(0, -1, -1, -1, q);

	printf("After play card:\n");

	handAf = q->handCount[0];
	deckAf = q->deckCount[0];
	numActAf = q->numActions;

	printf("Card on the playing player : %d \n",handAf);
	for (i = 0 ; i < handAf; i++)
	{
		if (q->hand[0][i] == card)		printf ("great_hall\n");
		if (q->hand[0][i] == copper) 	printf ("copper\n");
		if (q->hand[0][i] == estate)	printf ("estate\n");	
	}
	printf("Card on deck : %d \n",deckAf);
	printf("Number of action: %d\n\n", numActAf);	
	
	assert(handAf == handBe);  		// discard the great hall
	assert(deckAf == deckBe - 1);	 
	assert(numActAf == numActBe);	//the first action is using the great hall, now the player still have one action after using great hall  
	
	return 0;

}