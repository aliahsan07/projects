#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 4000

//This randomly tests Adventurer

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       smithy, tribute, remodel};

	  int i, n, players, player, handCount, fullDeckCnt, testDeckTotal, seed;
	  
	  struct gameState state;
	  
	  printf("Running Random Adventurer Test\n");

	srand (time(NULL));
	for (i = 0; i < MAX_TESTS; i++) {

	players = 2 + rand() % 3 ;//2-4 players always
	player = rand() % players;
	seed = rand();		//pick random seed num
	
	initializeGame(players, k, seed, &state);	//initialize Gamestate 

	//Initiate valid state variables
			state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
			if(seed%7777 == 6){
				state.deckCount[player] = 0;
			}
			state.discardCount[player] = rand() % MAX_DECK;
			if(seed%3333 == 12){
				state.discardCount[player] = 0;
			}
			state.handCount[player] = rand() % MAX_HAND;
	//Copy state variables for later comparison
		handCount = state.handCount[player];
		fullDeckCnt = total_card(player, &state);
		

	n = cardEffect(adventurer, 1, 1, 1, &state);		//Run adventurer card, card choices are not used
	//changed dominion code to account for case of endless loops if zero/one treasure is present in entire deck
	//returns number of drawntreasure
	if(n > 10 || n < 0){ //n should be only be 0 to max treasure amount
		printf("\nAdventurer FAIL, invalid value %d returned from cardEffect\n", n);
		assert(NULL);
	} 
	if (handCount > state.handCount[player]){
		printf("\nHand count mismatch \n starting hand = %d \n ending hand = %d \n treasures added = %d\n", handCount, state.handCount[player], n);
		printf("\n\t Test no. %d", i);
		assert(NULL);
	}
	testDeckTotal = total_card(player, &state);
	if (fullDeckCnt != testDeckTotal){
		printf("\nNumber of total cards in deck mismatch \n starting total of cards = %d \n ending total of cards = %d\n", fullDeckCnt, testDeckTotal);
		printf("\n\t Test no. %d", i);
		assert(NULL);
	}
	}
	  

	  printf("\nTest for Adventurer Complete\n");

	  return 0;
}