#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 100

//This randomly tests Adventurer

int main() {

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		sea_hag, tribute, smithy};

	int i, players, currplayer, handCount, deckCount, randseed; 

	struct gameState state1;

	srand(time(NULL));

	printf("Running Random Adventurer Test\n");

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
		
		int j;
		int treasure1 = 0, treasure2 = 0;
			
		for(j = 0; j < state1.handCount[currplayer]; j++){
			if(state1.hand[currplayer][j] == copper){
				treasure1++;
			}
			else if(state1.hand[currplayer][j] == silver){
				treasure1++;
			}
			else if(state1.hand[currplayer][j] == gold){
				treasure1++;
			}
		}
		  
		cardEffect(adventurer, 0, 0, 0, &state1, 0, 0);		//Run adventurer card

		
		for(j = 0; j < state1.handCount[currplayer]; j++){
			if(state1.hand[currplayer][j] == copper){
				treasure2++;
			}
			else if(state1.hand[currplayer][j] == silver){
				treasure2++;
			}
			else if(state1.hand[currplayer][j] == gold){
				treasure2++;
			}
		}
		
		
		printf("Initial treasure in hand: %d \n", treasure1);
		printf("Expected treasure in hand after card activation: %d \n", treasure2);
		
		if(treasure1 != (treasure2 - 2)){
			printf("ERROR: Did not add two treasure to hand \n");
		}
		else{
			printf("Two treasures were properly added to hand. \n");
		}
	  }

	  printf("Tests Complete\n");

	  return 0;
}