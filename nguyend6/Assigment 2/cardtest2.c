/*
Name: cardtest2.c
Author: Duy Nguyen
Date: 4/26/2015
Assigiment 2 - CS 362
Program: Testing the Coucil_room card
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
		sea_hag, tribute, council_room};
	int p = rand();
	int card = council_room; ////////////////
	int i;
	
	int handBe1;//for the first player
	int handAf1;
	int deckBe1;
	int deckAf1;

	int numBuyBe;//for the number of card
	int numBuyAf;

	int handBe2;//for the second player
	int handAf2;
	int deckBe2;
	int deckAf2;

	printf("----------------------------Testing the Coucil_room card:--------------------------\n");

	initializeGame(2, k, p , q);
	q->hand[0][0] = card; //set the first card to be concil room card
	
	handBe1 = q->handCount[0];
	deckBe1 = q->deckCount[0];

	printf("Before play card:\n");

	printf("Card on the playing player (0): %d \n",handBe1);
	for (i = 0 ; i < handBe1; i++)
	{
		if (q->hand[0][i] == card)		printf ("council_room\n");
		if (q->hand[0][i] == copper) 	printf ("copper\n");
		if (q->hand[0][i] == estate)	printf ("estate\n");	
	}
	printf("Card on deck (0): %d \n",deckBe1);
	

	numBuyBe = q->numBuys;
	printf("How many buys player 0 can buy: %d \n\n",numBuyBe);

	handBe2 = q->handCount[1];
	deckBe2 = q->deckCount[1];

	printf("Card on the others player (1): %d \n",handBe2);
	for (i = 0 ; i < handBe2; i++)
	{
		if (q->hand[1][i] == card)		printf ("council_room\n");
		if (q->hand[1][i] == copper) 	printf ("copper\n");
		if (q->hand[1][i] == estate)	printf ("estate\n");	
	}

	printf("Card on deck (1): %d \n\n",deckBe2);
	
	printf ("After play card:\n");

	playCard(0, -1, -1, -1, q);

	handAf1 = q->handCount[0];
	deckAf1 = q->deckCount[0];

	printf("Card on the playing player (0): %d \n",handAf1);
	for (i = 0 ; i < handAf1; i++)
	{
		if (q->hand[0][i] == card)		printf ("council_room\n");
		if (q->hand[0][i] == copper) 	printf ("copper\n");
		if (q->hand[0][i] == estate)	printf ("estate\n");	
	}
	printf("Card on deck (0): %d \n",deckAf1);
	
	numBuyAf = q->numBuys;
	printf("How many buys player 0 can buy: %d \n\n",numBuyAf);

	handAf2 = q->handCount[1];
	deckAf2 = q->deckCount[1];

	printf("Card on the others player (1): %d \n",handAf2);
	for (i = 0 ; i < handAf2; i++)
	{
		if (q->hand[1][i] == card)		printf ("council_room\n");
		if (q->hand[1][i] == copper) 	printf ("copper\n");
		if (q->hand[1][i] == estate)	printf ("estate\n");	
	}

	printf("Card on deck (1): %d \n\n",deckAf2);
	
	assert(handAf1 == (handBe1 + 3));  // the "consil room" card was put into the discard section and not in the hand anymore => no count
	assert(deckAf1 == (deckBe1 - 4)); 

	assert(handAf2 == (handBe2 + 1));  
	assert(deckAf2 == (deckBe2 - 1)); 

	assert (numBuyAf == (numBuyBe +1));
	return 0;

}