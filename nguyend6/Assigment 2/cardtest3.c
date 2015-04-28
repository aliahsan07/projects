/*
Name: cardtest3.c
Author: Duy Nguyen
Date: 4/26/2015
Assigiment 2 - CS 362
Program: Testing the Adventurer card
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
	int card = adventurer; 
	int i;
	
	int handBe;//for the player
	int handAf;
	int deckBe;
	int deckAf;
	
	printf("------------------------Testing the Adventurer card:------------------------\n");

	initializeGame(2, k, p , q);
	q->hand[0][0] = card; //set the first card to be adventure card
	
	q->deck[0][0] = estate; //just to make sure it go through the whole deck
	q->deck[0][1] = gold;	//the random function at initial is not actually random
	q->deck[0][2] = estate;
	q->deck[0][3] = silver;
	q->deck[0][4] = estate;

	printf("Before play card:\n");

	handBe = q->handCount[0];
	deckBe = q->deckCount[0];

	printf("Card on the playing player : %d \n",handBe);
	for (i = 0 ; i < handBe; i++)
	{
		if (q->hand[0][i] == card)		printf ("adventurer\n");
		if (q->deck[0][i] == silver) 	printf ("silver\n");
		if (q->deck[0][i] == gold) 		printf ("gold\n");
		if (q->hand[0][i] == copper) 	printf ("copper\n");
		if (q->hand[0][i] == estate)	printf ("estate\n");	
	}
	printf("Card on deck : %d \n",deckBe);
	for (i = 0 ; i < deckBe; i++)
	{
		if (q->deck[0][i] == card)		printf ("adventurer\n");
		if (q->deck[0][i] == silver) 	printf ("silver\n");
		if (q->deck[0][i] == gold) 		printf ("gold\n");
		if (q->deck[0][i] == copper) 	printf ("copper\n");
		if (q->deck[0][i] == estate)	printf ("estate\n");	
	}
	
	playCard(0, -1, -1, -1, q);

	printf("After play card:\n");

	handAf = q->handCount[0];
	deckAf = q->deckCount[0];

	printf("Card on the playing player : %d \n",handAf);
	for (i = 0 ; i < handAf; i++)
	{
		if (q->hand[0][i] == card)		printf ("adventurer\n");
		if (q->deck[0][i] == silver) 	printf ("silver\n");
		if (q->deck[0][i] == gold) 		printf ("gold\n");
		if (q->hand[0][i] == copper) 	printf ("copper\n");
		if (q->hand[0][i] == estate)	printf ("estate\n");	
	}
	printf("Card on deck : %d \n",deckAf);
	for (i = 0 ; i < deckAf; i++)
	{
		if (q->deck[0][i] == card)		printf ("adventurer\n");
		if (q->deck[0][i] == silver) 	printf ("silver\n");
		if (q->deck[0][i] == gold) 		printf ("gold\n");
		if (q->deck[0][i] == copper) 	printf ("copper\n");
		if (q->deck[0][i] == estate)	printf ("estate\n");	
	}
	
	assert(handAf == (handBe + 2));  
	assert(deckAf == 1);			// it needs to go to the 4th card in oreder to get 2 treaasures cards, 
	assert(q->deck[0][0] == estate);  
	
	return 0;

}