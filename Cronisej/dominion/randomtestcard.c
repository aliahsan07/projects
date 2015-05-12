#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 10
//max hand : 500
//max deck : 500

//This randomly tests Steward

int main(int argc, char** argv) {

	int k[10] = { steward, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	int i, j, seed, players, testPlayer;
	int handCount = 0, deckCount = 0, discardCount = 0, coinCount = 0, choice1 = 0;


	struct gameState *state = NULL;

	srand(time(NULL));

	printf("Running Random Adventurer Test\n\n");

	for (i = 0; i < MAX_TESTS; i++) {

		state = newGame();

		players = (rand() % 3) + 2; //2-4 players
		testPlayer = rand() % players;
		seed = rand();

		printf("Test Number: %d\n", i);
		printf("Player Count: %d\n", players);
		printf("Test Player: %d\n", testPlayer);
		printf("Seed: %d\n", seed);

		initializeGame(players, k, seed, state);	//initialize Gamestate 
		state->whoseTurn = testPlayer;

		handCount = (rand() % (MAX_HAND - 5)) + 6; //random hand size between 5-500
		state->handCount[testPlayer] = handCount;
		printf("Hand Count: %d\n", handCount);

		deckCount = (rand() % (MAX_DECK - 10)) + 11; //random deck size between 10-500
		state->deckCount[testPlayer] = deckCount;
		printf("Deck Count: %d\n", deckCount);

		coinCount = state->coins;
		printf("Initial Coin Count: %d\n", coinCount);

		choice1 = rand() % 3 ; //sets choice1 to be 0, 1, 2
		printf("Choice1: %d\n", choice1);

		state->hand[testPlayer][0] = steward; //set first card to steward

		for (j = 1; j < handCount; j++) //fill hand
		{
			state->hand[testPlayer][j] = rand() % 27;
		}
		// total implemented cards = 27
		for (j = 0; j < deckCount; j++) //fill deck
		{
			state->deck[testPlayer][j] = rand() % 27;
		}

		if (choice1 == 0) //trash 2 cards in hand
		{
			discardCount = state->discardCount[testPlayer];
			cardEffect(steward, choice1, 1, 2, state, 0, 0);

			if (handCount == (state->handCount[testPlayer] + 3))
			{
				printf("Trash 2 Test Passed\n");
			}
			else
				printf("trash 2 Test Failed\n");
		}

		else if (choice1 == 1) // draw two cards 
		{
			discardCount = state->discardCount[testPlayer];
			cardEffect(steward, choice1, 1, 2, state, 0, 0);

			if (handCount == (state->handCount[testPlayer] - 1))
			{
				printf("Gain 2 Cards Test Passed\n");
			}
			else
				printf("Gain 2 Cards Test Failed\n");
		}
		else // gain 2 coins
		{
			discardCount = state->discardCount[testPlayer];
			cardEffect(steward, choice1, 1, 2, state, 0, 0);

			if (coinCount == state->coins - 2)
			{
				printf("Gain 2 Coins Test Passed\n");
			}
			else
				printf("Gain 2 Coins Test Failed\n");
		}

		//confirm correctly discarded
		if (discardCount <= state->discardCount[testPlayer])
		{
			printf("Discard Test Passed\n\n");
		}
		else
			printf("Discard Test Failed\n\n");


		//end tests. no tests for abnormal card behavior such as changing action count. 

		free(state);

	}


	printf("Tests Complete\n");

	return 0;
}