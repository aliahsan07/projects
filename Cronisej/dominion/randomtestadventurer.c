#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 1000
//max hand : 500
//max deck : 500

//This randomly tests Adventurer

int main(int argc, char** argv) {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, j, seed, players, testPlayer;
	  int handCount = 0, deckCount = 0, discardCount = 0, treasureCount = 0;
	  int temp;

	  struct gameState *state= NULL;

	  srand(time(NULL));

	  printf("Running Random Adventurer Test\n\n");

	  for (i = 0; i < MAX_TESTS; i++) {
		  
	   state = newGame();

	   players = (rand() % 3)+2; //2-4 players
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

	   state->hand[testPlayer][0] = adventurer; //set first card to adventurer

	   for (j = 1; j < handCount; j++) //fill hand
	   {
		   state->hand[testPlayer][j] = rand() % 27;
	   }
	   // total implemented cards = 27
	   for (j = 0; j < deckCount; j++) //fill deck
	   {
		   state->deck[testPlayer][j] = rand() % 27;
	   }

	   for (j = 0; j < deckCount; j++) //count treasure cards in deck
	   {
		   temp = state->deck[testPlayer][j];
		   if (temp == copper || temp == silver || temp == gold)
		   {
			   treasureCount++;
		   }
	   }

	   if (treasureCount > 1)
	   {
		   //test draw 2 treasures
		   discardCount = state->discardCount[testPlayer];
		   cardEffect(adventurer, 0, 0, 0, state, 0, 0);
		   if (handCount + 2 == state->handCount[testPlayer])
		   {
			   printf("Draw 2 Test Passed\n");
		   }
		   else
			   printf("Draw 2 Test Failed\n");
	   }

	   else if (treasureCount == 1)
	   {
		   //test draw 1 treasures
		   discardCount = state->discardCount[testPlayer];
		   cardEffect(adventurer, 0, 0, 0, state, 0, 0);
		   if (handCount + 2 == state->handCount[testPlayer])
		   {
			   printf("Draw 1 Test Passed\n");
		   }
		   else
			   printf("Draw 1 Test Failed\n");
	   }
	   
	   else
	   {
		   //test draw 0 treasures
		   cardEffect(adventurer, 0, 0, 0, state, 0, 0);
		   if (handCount + 2 == state->handCount[testPlayer])
		   {
			   printf("Draw 0 Test Passed\n");
		   }
		   else
			   printf("Draw 0 Test Failed\n");
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