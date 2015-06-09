#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h> 

#define MAX_TESTS 42

//Randomly tests the adventurer card

int main() {

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	int i; 
	int a;
	int player; 
	int players; 
	int card;
	int temp;
	int numTreasure;
	int handCount; 
	int newHandCount;
	int deckCount; 
	int seed; 
	  
	struct gameState G;

	srand(time(NULL)); //give random seed

	printf("Running Random Adventurer Test\n");

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

		//give a 1/4 chance of creating an empty deack
		if (seed % 4 == 0) {
			G.deckCount[player] = 0;
		}
		
		a = cardEffect(adventurer, 0, 0, 0, &G, 0, NULL); //Runs adventurer card
		if (a != 0){
			printf("Adventurer card failed");
		}
		
		newHandCount = G.handCount[player];
		if (newHandCount - handCount != 2){
			printf("Two cards were not added to handCount\n");
			printf("Old hand count: %d \n", handCount);
			printf("New hand count: %d \n", newHandCount);
		}
		
		// Checks for 2 treasure cards in deck
		for (card = 0; card < deckCount; card++){
            		temp = G.deck[player][card];
            		if (temp == copper || temp == silver ||temp == gold){
               			numTreasure++;
			}
            		if (numTreasure >= 2) break;
		
        	}
		if (numTreasure == 1){
			printf("There are only 1 treasure cards in the deck\n");		
		}
		else if (numTreasure == 0){
			printf("There are no treasure cards in the deck\n");
		}

	  }

	  

	printf("Random tests on adventurer complete\n");

	return 0;
}
