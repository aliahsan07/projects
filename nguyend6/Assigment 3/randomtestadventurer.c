/*
Name: randomtestadventure.c
Author: Duy Nguyen
Date: 5/6/2015
Assigiment 3 - CS 362
Program: Testing the Adventurer card
*/

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

#define MAX_TESTS 100000 

int main (int argc, char** argv) {
	struct gameState *q = newGame();
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		sea_hag, tribute, council_room};
	int p ;
	int card = adventurer; 
	int i;
	int j = 0;

	int pos1;	//the position for 5 treasure card
	int pos2;
	int pos3;
	int pos4;
	int pos5;
	
	int handBe;//for the player
	int handAf;
	int deckBe;
	int deckAf;
	int r;


	printf("------------------------Testing the Adventurer card:------------------------\n");

	while (j <= MAX_TESTS)
	{
		p = rand();
		initializeGame(2, k, p , q);
	
		handBe = q->handCount[0];
		deckBe = q->deckCount[0];

		q->hand[0][0] = card; //set the first card to be adventure card

		for (i = 0; i < deckBe; i++){//set all the card in deck to be estate
			q->deck[0][i] = estate;	
		}

		pos1 = rand() % 6;	//get the random position for the first treasure card
		pos2 = rand() % 6;	//we can have the case that there is no treasure card
		pos3 = rand() % 6;		
		pos4 = rand() % 6;
		pos5 = rand() % 6;

		if (pos1 < deckBe)	q->deck[0][pos1] = gold;
		if (pos2 < deckBe)	q->deck[0][pos2] = silver;
		if (pos3 < deckBe)	q->deck[0][pos3] = copper;
		if (pos4 < deckBe)	q->deck[0][pos4] = silver;
		if (pos5 < deckBe)	q->deck[0][pos5] = copper;
/*
/*
		printf("Before play card:\n");

		printf("Card on the playing player : %d \n",handBe);
		for (i = 0 ; i < handBe; i++)
		{
			if (q->hand[0][i] == card)		printf ("adventurer\n");
			if (q->hand[0][i] == silver) 	printf ("silver\n");
			if (q->hand[0][i] == gold) 		printf ("gold\n");
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
*/		
		r = playCard(0, -1, -1, -1, q);
		handAf = q->handCount[0];
		deckAf = q->deckCount[0];

/*
		printf("After play card:\n");
		printf("Card on the playing player : %d \n",handAf);
		for (i = 0 ; i < handAf; i++)
		{
			if (q->hand[0][i] == card)		printf ("adventurer\n");
			if (q->hand[0][i] == silver) 	printf ("silver\n");
			if (q->hand[0][i] == gold) 		printf ("gold\n");
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
		
		printf("\n");
*/
		
		if (r != 0)		printf("ERROR: the playcard for adventure doesn't work\n");

		//assert(r == 0);
		
		if (pos1 >= 5 && pos2 >= 5 && pos3 >= 5 && pos4 >= 5 && pos5 >=5) 
		{
			if(handAf != handBe)	printf("ERROR: CASE 1: No treasure cards in deck\n" );
		}	  
		
		if (pos1 < 5 || pos2 < 5 || pos3 < 5 || pos4 < 5 || pos5 < 5)
		{
			if(handAf <= handBe)	printf("ERROR: CASE 2: When there is at least one treasure card in deck\n" );
		}		
		
		j++;	
	
	}	

	return 0;

}