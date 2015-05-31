#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1000

//This randomly tests smithy

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, steward, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, j, n, players, player, deckcopper, handcopper, foundcopper, handCount, deckCount, coins, seed, address, choice, trashchoice1, trashchoice2;
	  //struct gameState state;
	  struct gameState state;

	  printf("Running Random Card Test for Adventurer\n");


	  for (i = 0; i < MAX_TESTS; i++) {
        printf("/n/n Test # %d\n", i);
		players = (rand() % MAX_PLAYERS - 1) + 1 ;
		 if (players == 0){
            player = rand() % 1;
         }
         else{
         player = rand() % players;
         }
         seed = rand();		//pick random seed

		
		 initializeGame(players, k, seed, &state);	//initialize Gamestate

		  //Initiate valid state variables
		  state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  if (state.deckCount[player] == 0){
            
          state.discardCount[player] = rand() % 1;
          }
          else{
          state.discardCount[player] = rand() % state.deckCount[player];
          }
          //This discard count cannot be large than the deck 
          if (state.deckCount[player] < MAX_HAND){
            state.handCount[player] = state.deckCount[player];
          } 
          else { 
		  state.handCount[player] = rand() % MAX_HAND;
          }
		  //Copy state variables
		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];
          coins = state.coins;
          printf("handCount for test %d is %d\n", i, state.handCount[player]);
          printf("deckCount for test %d is %d\n", i, state.deckCount[player]);
          state.hand[player][0] = adventurer;
          deckcopper = fullDeckCount(player, copper, &state);
          int j;
          handcopper = 0; 
          for (j = 0; j < handCount; j++){//figuring out how many copper are in hand
            if (handCard(j, &state) == copper){
                handcopper ++;
            }
          } 
           foundcopper = deckcopper - handcopper; 
           printf("deckcopper is %d, handcopper is %d, foundcopper is %d\n", deckcopper, handcopper, foundcopper);
            playCard(0, 1, -1, -1, &state);
          if (foundcopper >= 2){
            if (handCount != state.handCount[player] + 2){
                printf("Adventuer did not increase the number of cards by 2\n");
            }
         }
         if (foundcopper == 1) { //plus 2 money test for increase
                if (handCount != state.handCount[player] + 1){
                    printf("Adventurer did not increase the number of cards by 1\n");
                }

         }
         if (foundcopper == 0) { //plus 2 money test for increase
             if (handCount != state.handCount[player]){
                 printf("Adventurer added cards that it should not have\n");
             }
         } 

      }


      printf("%d\n", i);




printf("Tests Complete\n");

return 0;
}
