#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 12

//This randomly tests Adventurer

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	  int i; 
      int j; 
      int n; 
      int players; 
      int player; 
      int handCount; 
      int deckCount; 
      int seed; 
      int address;
      int choice1;
      int choice2;
      int choice3;
	  struct gameState state;
	  struct gameState stat;
	  struct gameState sta;
        
      srand(time(NULL));
	  printf("Running Random Adventurer Test\n");

	  for (i = 0; i < MAX_TESTS; i++) {
       choice1 = rand() % 2;
       choice2 = rand() % 2;
       choice3 = rand() % 2;
	   players = rand() % 4;
        
	   seed = rand();		//pick random seed
		
	   initializeGame(players, k, rand(), &state);	//initialize Gamestate 
        player = rand() % players;
	   //Initiate valid state variables
        state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
        state.discardCount[player] = rand() % MAX_DECK;
		  state.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 2 == 0) {
			state.deckCount[player] = 0;
		  }
          for(j=0; j<10; j++){
           gainCard(copper, &state, 2, player);
          }
		  cardEffect(adventurer, choice1, choice2, choice3, &state);		//Run adventurer card
	  }
	  
	   for (i = 0; i < MAX_TESTS; i++) {
          choice1 = rand() % 2;
          choice2 = rand() % 2;
          choice3 = rand() % 2;
  		  players = 2 + rand() % 3;
          player = rand() % players;
          
		  seed = rand();		//pick random seed
		
		  initializeGame(players, k, rand(), &stat);	//initialize Gamestate
          player = rand()%players;
		  //Initiate valid state variables
		  stat.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  stat.discardCount[player] = rand() % MAX_DECK;
		  stat.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = stat.handCount[player];
		  deckCount = stat.deckCount[player];
            
          for(j=0; j<10; j++){
            gainCard(silver, &stat, 2, player);
          }
		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 2 == 0) {

			stat.deckCount[player] = 0;
		  }

		  cardEffect(adventurer, choice1, choice2, choice3, &stat);		//Run adventurer card
	  }

	   for (i = 0; i < MAX_TESTS; i++) {
          choice1 = rand() % 2;
          choice2 = rand() % 2;
          choice3 = rand() % 2;
  		  players = 2 + rand() % 4;
          player = rand() % players;
          
		  seed = rand();		//pick random seed
		
		  initializeGame(players, k, rand(), &sta);	//initialize Gamestate

		  //Initiate valid state variables
		  sta.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  sta.discardCount[player] = rand() % MAX_DECK;
		  sta.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = sta.handCount[player];
		  deckCount = sta.deckCount[player];

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 2 == 0) {

			sta.deckCount[player] = 0;
		  }
          for(j=0; j<10; j++){
            gainCard(gold, &sta, 2, player);
          }
		  cardEffect(adventurer, choice1, choice2, choice3, &sta);		//Run adventurer card

	   }

	  printf("Tests Complete\n");

	  return 0;
}
