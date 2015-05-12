#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 100

//This randomly tests Village

int main() {

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		sea_hag, tribute, smithy};

	int i, players, currplayer, handCount, deckCount, randseed, numActions; 

	struct gameState state1;
	
	int card = village;

	srand(time(NULL));

	printf("Running Random Village Test\n");

	for (i = 0; i < MAX_TESTS; i++) {

	  
		printf("Test #%d \n", i+1);
	    players = (rand() % 4) + 1;
		currplayer = (rand() % players);

		randseed = rand();		//pick random randseed
		
		initializeGame(players, k, randseed, &state1);	//initialize Gamestate 
		
		if(initializeGame(players, k, randseed, &state1) == -1){
			printf("ERROR: Initialization \n");
		}

		//Initiate valid state variables
		state1.deckCount[currplayer] = (rand() % MAX_DECK); //Pick random deck size out of MAX DECK size
		state1.discardCount[currplayer] = rand() % MAX_DECK;
		state1.handCount[currplayer] = rand() % MAX_HAND;
		
		  //1 in 3 chance of making empty deck for coverage
		if (randseed % 3 == 0) {
			state1.deckCount[currplayer] = 0;
		}
		
		handCount = state1.handCount[currplayer];
		deckCount = state1.deckCount[currplayer];
		handCount = state1.handCount[currplayer];
		numActions = state1.numActions + 2;
		  
		cardEffect(card, 1, 1, 1, &state1, 0, 0);

		if(state1.handCount[currplayer] != handCount){
			printf("ERROR: Hand count doesn't match! \n");
		}
		else{
			printf("PASS: Card properly drawn. \n");
		}
		
		if(state1.numActions != numActions){
			printf("ERROR: Number of Actions doesn't match! \n");
		}
		else{
			printf("PASS: Actions properly added. \n");
		}
	  }

	  printf("Tests Complete\n");

	  return 0;
}