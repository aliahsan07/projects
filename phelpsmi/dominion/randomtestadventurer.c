#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_TESTS 1000

static const char *CARD_NAMES[] = {"curse","estate","duchy","province","copper","silver","gold",
								   "adventurer","council_room","feast","gardens","mine","remodel","smithy",
								   "village","baron","great_hall","minion","steward","tribute","ambassador",
   								   "cutpurse","embargo","outpost","salvager","sea_hag","treasure_map", "no", "no", "no", "no", "no", "no", "no", "no", "no", "no", "no", "no", "no", "no", "no", "no", "no", "no", "no", "no", "no", "no"};
static const int CARD_COSTS[] = {0, 2, 5, 8, 0, 3, 6,
								   6, 5, 4, 4, 5, 4, 4,
								   3, 4, 3, 5, 3, 5, 3,
								   4, 2, 5, 4, 4, 4};

//This randomly tests Adventurer

void assignCards(int k[10], int size, int* cardSet);
void printHand(int player, struct gameState *state, const char *name);

int main() {

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	    sea_hag, tribute, smithy};

	int i, players, player, handCount, deckCount, seed, totalCards;
	//struct gameState state;
	struct gameState* state = newGame();

	printf("Running Random Adventurer Test\n");

	srand(2);

	for (i = 0; i < MAX_TESTS; i++) {

	  	players = rand() % 4 + 2;
	  	player = rand() % players;

	   	seed = rand();		//pick random seed

	   	initializeGame(players, k, seed, state);	//initialize Gamestate 

	   //Initiate valid state variables
		state->deckCount[player] = rand() % 50; //Pick random deck size out of a reasonable maximum size
		state->discardCount[player] = rand() % 50;
		state->handCount[player] = rand() % 50;
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
		totalCards = state->handCount[player] + state->deckCount[player] + state->discardCount[player];
		printf("\n");
		printHand( player, state, "hand");
		printHand( player, state, "discard");
		printHand( player, state, "deck");
		cardEffect(adventurer, 1, 1, 1, state, rand() % handCount, NULL);		//Run adventurer card
		free(state);
		if(totalCards != state->handCount[player] + state->deckCount[player] + state->discardCount[player]){
			printf("*******************card count changed******************************\n");
			printHand( player, state, "hand");
			printHand( player, state, "discard");
			printHand( player, state, "deck");
			printf("\n");
		}

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

void printHand(int player, struct gameState *state, const char *name){
	int i, size;
	printf("Player %d %s:", player + 1, name);
	if(!strcmp(name, "hand"))
		size = state->handCount[player];
	else if(!strcmp(name, "deck"))
		size = state->deckCount[player];
	else if(!strcmp(name, "discard"))
		size = state->discardCount[player];

	for(i = 0; i < size; i++){
		if(!strcmp(name, "hand"))
			printf(" %s", CARD_NAMES[state->hand[player][i]]);
		else if(!strcmp(name, "deck"))
			printf(" %s", CARD_NAMES[state->deck[player][i]]);
		else if(!strcmp(name, "discard"))
			printf(" %s", CARD_NAMES[state->discard[player][i]]);
		else
			printf("fuck me man");
	}
	printf("\n");
}