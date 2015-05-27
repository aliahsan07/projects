#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 2000

int main(int argc, char **argv) {

      int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, great_hall};

      int i, j, n, players, player, handCount, deckCount, seed, address;
      int choice1, choice2, choice3;
      int success = 0;
      int failure = 0;
      int action_status = -1;
      int card_choice = 0;
      int action_choice = 0;
      int end_flag = 0;
      int r = 0;
      struct gameState state;
      for(j = 0; j < MAX_TESTS; j++)
      {
         if(argc > 1)
         {
            srand(argv[1]);
         }
         else
         {
            srand(time(NULL));
         }
         players = 2 + rand() % 3; //between 2 and 4 players
         seed = rand();     //pick random seed
         player = rand() % players;

         initializeGame(players, k, seed, &state);  //initialize Gamestate

         //Initiate valid state variables
         state.discardCount[player] = rand() % MAX_DECK;
         state.handCount[player] = rand() % MAX_HAND;


         //Copy state variables
         handCount = state.handCount[player];
         deckCount = state.deckCount[player];

         if(seed % 3 == 0)
         {
             state.deckCount[player] = 0;
         }
            
         //while there is not winner 
         while(end_flag != 1)
         {

            printf("------ Before Turn ------\n");
            printf("whoseTurn: %d\n", state.whoseTurn);
            printf("phase: %d\n", state.phase);
            printf("numActions: %d\n", state.numActions);
            printf("numBuys: %d\n", state.numBuys);
            printf("coins %d\n", state.coins);
            printf("playedCardCount: %d\n", state.playedCardCount);
            printf("handCount: %d\n", state.handCount[state.whoseTurn]);
            printf("deckCount: %d\n", state.deckCount[state.whoseTurn]);
            printf("discardCount: %d\n", state.discardCount[state.whoseTurn]);

            action_choice = rand() % 4;
            card_choice = rand() % 10;
            choice1 = rand() % 2;
            choice2 = rand() % 2;
            choice3 = rand() % 2;
                
            action_status = playCard(action_choice, choice1, choice2, choice3, &state);
            printf("Action Card Choice: %d\n", action_choice); 
            for(i = 0; i < state.numBuys; i++)
            {
                r = buyCard(k[card_choice], &state);
                if (r == -1)
                {
                    card_choice = rand() % 10;
                }
            }
            printf("Buy Card Choice: %d\n", card_choice);
          
            printf("------ After Turn ------\n");
            printf("whoseTurn: %d\n", state.whoseTurn);
            printf("phase: %d\n", state.phase);
            printf("numActions: %d\n", state.numActions);
            printf("numBuys: %d\n", state.numBuys);
            printf("coins %d\n", state.coins);
            printf("playedCardCount: %d\n", state.playedCardCount);
            printf("handCount: %d\n", state.handCount[state.whoseTurn]);
            printf("deckCount: %d\n", state.deckCount[state.whoseTurn]);
            printf("discardCount: %d\n", state.discardCount[state.whoseTurn]); 

            endTurn(&state);
            end_flag = isGameOver(&state);
        } 
    }
    return 0;
}
