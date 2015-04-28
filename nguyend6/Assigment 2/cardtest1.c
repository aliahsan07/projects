/*
Name: cardtest1.c
Author: Duy Nguyen
Date: 4/26/2015
Assigiment 2 - CS 362
Program: Testing the Smithy card
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
		sea_hag, tribute, smithy};
	int p = rand();
	int card = smithy; ////////////////
	int i;
	int handBe;
	int handAf;
	int deckBe;
	int deckAf;

	initializeGame(2, k, p , q);
	q->hand[0][0] = card; //set the first card to be smithy card

	printf("--------------------Testing the Smithy card:-------------------------\n");
	
	handBe = q->handCount[0];
	deckBe = q->deckCount[0];

	printf("Card on hand (Before): %d \n",handBe);
	for (i = 0 ; i < handBe; i++)
	{
		if (q->hand[0][i] == card)		printf ("smithy\n");
		if (q->hand[0][i] == copper) 	printf ("copper\n");
		if (q->hand[0][i] == estate)	printf ("estate\n");	
	}
	
	playCard(0, -1, -1, -1, q);

	handAf = q->handCount[0];
	deckAf = q->deckCount[0];

	printf("Card on hand (After): %d \n",handAf);
	for (i = 0 ; i < handAf; i++)
	{
		if (q->hand[0][i] == card)		printf ("smithy\n");
		if (q->hand[0][i] == copper) 	printf ("copper\n");
		if (q->hand[0][i] == estate)	printf ("estate\n");	
	}
		
	assert(handAf == (handBe + 2));  // the "smithy" card was put into the discard section and not in the hand anymore => no count
	assert(deckAf == (deckBe - 3)); 

	return 0;
}