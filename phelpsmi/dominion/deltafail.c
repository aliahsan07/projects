#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

//This randomly tests a full dominion game

static const char *CARD_NAMES[] = {"curse","estate","duchy","province","copper","silver","gold",
								   "adventurer","council_room","feast","gardens","mine","remodel","smithy",
								   "village","baron","great_hall","minion","steward","tribute","ambassador",
   								   "cutpurse","embargo","outpost","salvager","sea_hag","treasure_map"};

void makeKingdomCards(int k[10]){
	int i, x, selection, flag;

	for(i = 0; i < 10; i++){
		flag = 0;
		selection = rand() % 20 + 7;
		for(x = 0; x < i; x++){
			if(selection == k[x]){
				flag = 1;
			}
		}
		if(!flag)
			k[i] = selection;
		else
			i--;
	}
	printf("kingdom cards: %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", CARD_NAMES[k[0]], CARD_NAMES[k[1]], CARD_NAMES[k[2]], CARD_NAMES[k[3]], CARD_NAMES[k[4]], CARD_NAMES[k[5]], CARD_NAMES[k[6]], CARD_NAMES[k[7]], CARD_NAMES[k[8]], CARD_NAMES[k[9]]);
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

int main() {

	srand(50);
	int k[10];
	makeKingdomCards(k);

	int players, turn = 1, player;
	//struct gameState state;
	struct gameState* s = newGame();

	printf("Running Random Game Test\n");

	players = rand() % 3 + 2;

	initializeGame(2, k, players, s);

	printHand(0, s, "hand");
  	printHand(0, s, "deck");
  	printHand(0, s, "discard");
	printf("score: %d\n", scoreFor(0, s));
  
  	

	return 0;
}

