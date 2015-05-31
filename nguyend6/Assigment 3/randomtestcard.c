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

#define MAX_TESTS 100000  

int main (int argc, char** argv) {
	struct gameState *q = newGame();
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		sea_hag, tribute, council_room};
	int p;
	int card = council_room; ////////////////
	int i;
	int numPlayers;
	int r;
	int j;
	int player[4][4];

	int numBuyBe;//for the number of card
	int numBuyAf;

	printf("----------------------------Testing the Coucil_room card:--------------------------\n");
	while (j <MAX_TESTS)
	{	
		p = rand();
		numPlayers = rand()%3 + 2; //2 to 4 players
		
		initializeGame(numPlayers, k, p , q);
		q->hand[0][0] = card; //set the first card to be concil room card
		
		for (i = 0; i < numPlayers; ++i)
		{
			player[i][0] = q->handCount[i];
			player[i][1] = q->deckCount[i];
		}

		numBuyBe = q->numBuys;

		r = playCard(0, -1, -1, -1, q);

		for (i = 0; i < numPlayers; ++i)
		{
			player[i][2] = q->handCount[i];
			player[i][3] = q->deckCount[i];
		}

		numBuyAf = q->numBuys;

		if (r != 0)		printf("ERROR: the playcard for adventure doesn't work\n");
		
		if(player[0][2] != (player[0][0] + 3)) 	printf("ERROR: CASE 1(hand): On the person that play the card\n" );
		if(player[0][3] != (player[0][1] - 4)) 	printf("ERROR: CASE 1(deck): On the person that play the card\n" );
		
		for (i = 1; i < numPlayers; i++)
		{
			if(player[i][2] != (player[i][0] + 1)) printf("ERROR: CASE 2(hand): On player # %d with %d total\n",i,numPlayers );
			if(player[i][3] != (player[i][1] - 1)) printf("ERROR: CASE 2(deck): On player # %d with %d total\n",i,numPlayers );
		}
		
		if(numBuyAf != (numBuyBe +1)) printf("ERROR: CASE 3: on the number of buy");
		
		++j;
	}
	return 0;

}