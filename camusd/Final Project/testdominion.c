#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_TESTS 500
#define SEED 25

int* randomizeKingdomCards() {
	int* k = malloc(10 * sizeof(int));
	int size = 0;
	int card;
	int i;
	int dupe_flag;
	
	while(size < 10) {
		dupe_flag = 0;
		card = (rand() % 20) + 7;
		for(i = 0; i < size; i++) {
			if(k[i] == card) {
				dupe_flag = 1;
			}
		}
		if(dupe_flag == 0 && card != feast && card != embargo && card != tribute && card != adventurer) {
			k[size] = card;
			size++;
		}
	}
	return k;
}

int hasAction(int player, struct gameState *state) {
	int i;
	
	for(i = 0; i < state->handCount[player]; i++) {
		if(state->hand[player][i] > gold && state->hand[player][i] != gardens) {
			printf("Action in hand is: %d\n", state->hand[player][i]);
			return 1;
		}
	}
	return 0;
}

int canBuy(struct gameState *state) {
	if(state->coins < 2) {
		if((state->supplyCount[curse] == 0) && (state->supplyCount[copper] == 0)) {
			return 0;
		}
	}
	return 1;
}

int main() {
	
	int* k = malloc(10 * sizeof(int));
	int i, j, players, player;
    int choice1, choice2, choice3;
	int victory_flag;
    int play_action = 0;
    int buy_choice = 0;
    int action_choice = 0;
    int r = 0;
	struct gameState *state;
	
	srand(SEED);
	  
    for(i = 0; i < NUM_TESTS; i++) {
		victory_flag = 0;
		k = randomizeKingdomCards();
		players = 2 + (rand() % 3);
		state = newGame();
		initializeGame(players, k, SEED, state);
	
		while(victory_flag != 1) {
			player = state->whoseTurn;
		
			printf("------ Before Turn ------\n");
			printf("whoseTurn: %d\n", state->whoseTurn);
			printf("phase: %d\n", state->phase);
			printf("numActions: %d\n", state->numActions);
			printf("numBuys: %d\n", state->numBuys);
			printf("coins %d\n", state->coins);
			printf("handCount: %d\n", state->handCount[state->whoseTurn]);
			printf("deckCount: %d\n", state->deckCount[state->whoseTurn]);
			printf("discardCount: %d\n", state->discardCount[state->whoseTurn]);
			printf("playedCardCount: %d\n", state->playedCardCount);
			
			if(hasAction(player, state)) {
			for(j = 0; j < state->numActions; j++) {
				action_choice = rand() % state->handCount[player];
				choice1 = rand() % 27;
				choice2 = rand() % 27;
				choice3 = rand() % 27;
				play_action = playCard(action_choice, choice1, choice2, choice3, state);
				printf("numActions: %d\n", state->numActions);
				printf("Action Card Choice: %d\n", action_choice);
			}
			}
			
			for(j = 0; j < state->numBuys; j++) {
				buy_choice = rand() % 27;
				r = buyCard(buy_choice, state);
				printf("Buy Card Choice: %d\n", buy_choice);
			}
			
			printf("------ After Turn ------\n");
			printf("whoseTurn: %d\n", state->whoseTurn);
			printf("phase: %d\n", state->phase);
			printf("numActions: %d\n", state->numActions);
			printf("numBuys: %d\n", state->numBuys);
			printf("coins %d\n", state->coins);
			printf("handCount: %d\n", state->handCount[state->whoseTurn]);
			printf("deckCount: %d\n", state->deckCount[state->whoseTurn]);
			printf("discardCount: %d\n", state->discardCount[state->whoseTurn]);
			printf("playedCardCount: %d\n", state->playedCardCount);			

			endTurn(state);
			victory_flag = isGameOver(state);
        } 
    }
    return 0;
}