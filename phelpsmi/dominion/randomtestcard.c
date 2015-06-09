#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 50000

//This randomly tests Adventurer

void assignCards(int k[10], int size, int* cardSet);

int main() {

	int k[10] = {council_room, gardens, embargo, village, minion, mine, cutpurse, 
	    sea_hag, tribute, smithy};

	int i, players, player, handCount, deckCount, seed, address;
	//struct gameState state;
	struct gameState* state = newGame();

	printf("Running Random Council Room Test\n");

	srand(2);

	for (i = 0; i < MAX_TESTS; i++) {

	  	players = rand() % 4 + 2;
	  	player = rand() % players;

	   	seed = rand();		//pick random seed

	   	initializeGame(players, k, seed, state);	//initialize Gamestate 

	   //Initiate valid state variables
		state->deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		state->discardCount[player] = rand() % MAX_DECK;
		state->handCount[player] = rand() % MAX_HAND;
		state->handCount[player]++;

		handCount = state->handCount[player];
		deckCount = state->deckCount[player];

		assignCards(k, state->deckCount[player], state->deck[player]);
		assignCards(k, state->discardCount[player], state->discard[player]);
		assignCards(k, state->handCount[player], state->hand[player]);

		state->handCount[player] = handCount;


		//ensures we have atleast
		state->discard[player][0] = copper;
		state->discard[player][1] = copper;
		if(state->discardCount[player] < 2)
			state->discardCount[player] = 2;

		  //Copy state variables
		


		  //1 in 3 chance of making empty deck for coverage
		if (seed % 3 == 0) {

			state->deckCount[player] = 0;
		}
		cardEffect(council_room, 1, 1, 1, state, rand() % handCount, NULL);		//Run adventurer card
		free(state);

		state = newGame();
	}

	printf("Tests Complete\n");

	return 0;
}

void assignCards(int k[10], int size, int* cardSet){
	int i, selection;
	for(i = 0; i < size; i++){
		selection = rand() % 17;
		if(selection <= 6){
			cardSet[i] = selection;
		} else {
			cardSet[i] = k[selection - 7];
		}
	}
}