#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 100 

//This randomly tests steward

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, steward, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, j, n, players, player, handCount, deckCount, coins, seed, address, choice, trashchoice1, trashchoice2;
	  //struct gameState state;
	  struct gameState state;

	  printf("Running Random Card Test for Steward\n");


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
          state.hand[player][0] = steward;
          choice = rand() % 3 + 1; 
         if (choice == 1) {//plus 2 cards test for  increase
            playCard(0, 1, -1, -1, &state);
            if (handCount != state.handCount[player] + 2){
                printf("Choice 1 did not increase the number of cards by 2\n");
            }

         }
         if (choice == 2) { //plus 2 money test for increase
            playCard(0, 2, -1, -1, &state);
                if (coins != state.coins + 2){
                    printf("Choice 2 did not increase the number of coins by 2\n");
                }

         }
         if (choice == 3) { //plus 2 money test for increase
             trashchoice1 = -1; 
            trashchoice2 = -1;
            while (trashchoice1 == trashchoice2){  
                if (state.handCount[player] == 0){
                    trashchoice1 = rand() % 1; 
                }
                else{
                    trashchoice1 = rand() % state.handCount[player];  
                }
                if (state.handCount[player] == 0){

                trashchoice2 = rand() % 1; 
                }
                else{
                trashchoice2 = rand() % state.handCount[player]; 
            
                }
                if (handCount != state.handCount[player] -2 ){
                    printf("Choice 3 did not trash two cards\n");
                }
            } 
            playCard(0, 3, trashchoice1, trashchoice2, &state);

         }


         printf("%d\n", i);

      }


      printf("Tests Complete\n");

      return 0;
}
