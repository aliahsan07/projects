#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h> 

#define MAX_TESTS 42

//Randomly tests the village card

int main() {

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	int i; 
	int a;
	int player; 
	int players; 
	int card;
	int temp;
	int handCount; 
	int newHandCount;
	int deckCount; 
	int seed; 
	int actions;
	  
	struct gameState G;

	srand(time(NULL)); //give random seed

	printf("Running Random Village Test\n");

	for (i = 0; i < MAX_TESTS; i++) {

		seed = rand();	//random seed		

		players = rand() % 4; //set random # players 

		
	 	a = initializeGame(players, k, seed, &G); //initialize Gamestate 
		if (a != 0){
			printf("Initalizing game failed");
		}

		//Initiate state variables
		G.deckCount[player] = rand() % MAX_DECK; //Choose random deck size
		G.discardCount[player] = rand() % MAX_DECK;
		G.handCount[player] = rand() % MAX_HAND;

		//Copy state variables
		handCount = G.handCount[player];
		deckCount = G.deckCount[player];
		actions = G.numActions;

		//give a 1/4 chance of creating an empty deack
		if (seed % 4 == 0) {
			G.deckCount[player] = 0;
		}
		
		a = cardEffect(village, 0, 0, 0, &G, 0, NULL); //Runs village card
		if (a != 0){
			printf("Village card failed");
		}

		newHandCount = G.handCount[player];
		if (newHandCount - handCount != 1){
			printf("+1 card not properly added to hand\n");		
		}

		if (G.numActions != actions + 2){
			printf("Two actions were not properly added to total actions\n");
		}
				
	}
	
	printf("Random tests on Village complete\n");
	
	return 0;
}
