#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 3500

//This randomly tests Adventurer

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, j, n, players, player, handCount, deckCount, seed, handPos, totalTreasures, success = 0, failure = 0, card;
       
      int choice1 = 0, choice2 = 0, choice3 = 0;
      struct gameState state;

	  printf("Running Random Adventurer Test\n");

      srand(time(NULL));

	  for (i = 0; i < MAX_TESTS; i++) {

          totalTreasures = 0;
          players = 2 + rand() % 3; //Between 2 and 4 players
	      seed = rand();		//pick random seed
          player = rand() % players;
          choice1 = rand() % 2;
          choice2 = rand() % 2;
          choice3 = rand() % 2;
		
	      initializeGame(players, k, seed, &state);	//initialize Gamestate

		  //Initiate valid state variables
		  state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  state.discardCount[player] = rand() % MAX_DECK;
		  state.handCount[player] = rand() % MAX_HAND;
          handPos = rand() % 4;


		  //Copy state variables
		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			state.deckCount[player] = 0;
		  }
		  n = cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, 0);		//Run adventurer card

       assert(n == 0); //Asserts that adventurer returned correctly

       //Check that the top two cards are treasures
           for (j = 0; j < 2; j++)
           {
                card = state.hand[player][state.handCount[player] - i];
                if (card == copper || card == silver || card == gold)
                {
                    totalTreasures++;
                }
           }

           if (totalTreasures == 2)
                success += 1;
           else
                failure +=1;
       }
       
       printf("Successes: %d\n", success);
       printf("Failures: %d\n", failure);
	   printf("Tests Complete\n");

	  return 0;
}
