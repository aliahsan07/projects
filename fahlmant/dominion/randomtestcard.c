#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 1300

//This randomly tests great hall

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, great_hall};

	  int i, j, n, players, player, handCount, deckCount, seed, address;
      int choice1, choice2, choice3;
      int preActions = 0;
      int afterActions = 0;
      int success = 0;
      int failure = 0;
      int handPos = 0;
	  struct gameState state;

	  printf("Running Random Card Test for Great Hall\n");

      srand(time(NULL));
	  for (i = 0; i < MAX_TESTS; i++) {

		  
		 players = 2 + rand() % 3; //between 2 and 4 players
		 seed = rand();		//pick random seed
         player = rand() % players;
		 choice1 = rand() % 2;
         choice2 = rand() % 2;
         choice3 = rand() % 2;
         handPos = rand() % 4;

		 initializeGame(players, k, seed, &state);	//initialize Gamestate

		  //Initiate valid state variables
		  state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  state.discardCount[player] = rand() % MAX_DECK;
		  state.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];

          if(seed % 3 == 0)
          {
              state.deckCount[player] = 0;
          }
            
          preActions = state.numActions;          

		  cardEffect(great_hall, choice1, choice2, choice3, &state, handPos, 0);		//Run adventurer card

          afterActions = state.numActions;

          if (afterActions == preActions + 1)
          {
              success++;
          }
          else
          {
              failure++;
          }


	  }

      printf("Successes: %d\n", success);
      printf("Failure: %d\n", failure);
	  printf("Tests Complete\n");

	  return 0;
}
