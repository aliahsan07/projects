/*
 *Cooper Gale
 *testdominion.c
 *full implementation of dominon testing
 */

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv) {
  printf ("testdominion.d running\n");

  srand(8675309); 
  //srand(time(NULL));
  struct gameState x;
  struct gameState *state = &x;

//  int k[10] = {rand()%20+7,rand()%20+7,rand()%20+7,rand()%20+7,rand()%20+7,rand()%20+7,rand()%20+7,rand()%20+7,rand()%20+7,rand()%20+7}; 
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy};
  int player_num = rand() % 3 + 2; //Random amount of players
  printf("number of players: %d\n", player_num);
  
  int seed = rand() % 50000 + 1;
  printf("seed: %d\n", seed);
  initializeGame(player_num, k, seed, state);
  
  int money = 0;
  int smithyPos = -1;
  int cutpursePos = -1;
  int adventurerPos = -1;
  int i=0;
  
  int numSmithies = 0;
  int numAdventurers = 0;
 
  while (!isGameOver(state)) {
    money = 0;
    smithyPos = -1;
    adventurerPos = -1;
    for (i = 0; i < numHandCards(state); i++) {
      if (handCard(i,state) == copper)
        money++;
      else if (handCard(i,state) == silver)
        money += 2;
      else if (handCard(i,state) == gold)
        money += 3;
      else if (handCard(i,state) == smithy)
        smithyPos = i;
      else if (handCard(i,state) == adventurer)
        adventurerPos = i;
    }
    if (whoseTurn(state) == 0) {
      if (smithyPos != -1) {
        printf("player0: smithy played from position %d\n", smithyPos);
        playCard(smithyPos, -1, -1, -1,state);
        printf("smithy played.\n");
        money = 0;
        i=0;
        while(i<numHandCards(state)){
          if (handCard(i,state) == copper){
            playCard(i, -1, -1, -1,state);
            money++;
          }
          else if (handCard(i,state) == silver){
            playCard(i, -1, -1, -1,state);
            money += 2;
          }
          else if (handCard(i,state) == gold){
            playCard(i, -1, -1, -1,state);
            money += 3;
          }
          i++;
        }
      }
      if (money >= 8) {
        printf("player0: bought province\n");
        buyCard(province,state);
      }
      else if (money >= 6) {
        printf("player0: bought gold\n");
        buyCard(gold,state);
      }
      else if ((money >= 4) && (numSmithies < 2)) {
        printf("player0: bought smithy\n");
        buyCard(smithy,state);
        numSmithies++;
      }
      else if (money >= 3) {
        printf("player0: bought silver\n");
        buyCard(silver,state);
      }
      
      printf("player0: end turn\n");
      endTurn(state);
    }
    else if (whoseTurn(state) == 1) {
      if (cutpursePos != -1) {
        printf("player1: cutpurse played from position %d\n", cutpursePos);
        playCard(cutpursePos, -1, -1, -1,state);
        printf("cutpurse played.\n");
        money = 0;
        i=0;
        while(i<numHandCards(state)){
          if (handCard(i,state) == copper){
            playCard(i, -1, -1, -1,state);
            money++;
          }
          else if (handCard(i,state) == silver){
            playCard(i, -1, -1, -1,state);
            money += 2;
          }
          else if (handCard(i,state) == gold){
            playCard(i, -1, -1, -1,state);
            money += 3;
          }
          i++;
        }
      }
      if (money >= 8) {
        printf("player1: bought province\n");
        buyCard(province,state);
      }
      else if ((money >= 6) && (numAdventurers < 2)) {
        printf("player1: bought adventurer\n");
        buyCard(adventurer,state);
        numAdventurers++;
      }else if (money >= 6){
        printf("player1: bought gold\n");
        buyCard(gold,state);
      }
      else if (money >= 3){
        printf("player1: bought silver\n");
        buyCard(silver,state);
      }
      printf("player1: endTurn\n");
      
      endTurn(state);
    }
    else if (whoseTurn(state) == 2) {
      if(adventurerPos != -1) {
        printf("player2: adventurer played from position %d\n", adventurerPos);
        playCard(adventurerPos, -1, -1, -1,state);
        money = 0;
        i=0;
        while(i<numHandCards(state)){
          if (handCard(i,state) == copper){
            playCard(i, -1, -1, -1,state);
            money++;
          }
          else if (handCard(i,state) == silver){
            playCard(i, -1, -1, -1,state);
            money += 2;
          }
          else if (handCard(i,state) == gold){
            playCard(i, -1, -1, -1,state);
            money += 3;
          }
          i++;
        }
      }
      if (money >= 8) {
        printf("player2: bought province\n");
        buyCard(province,state);
      }
      else if ((money >= 6) && (numAdventurers < 2)) {
        printf("player2: bought adventurer\n");
        buyCard(adventurer,state);
        numAdventurers++;
      }else if (money >= 6){
        printf("player2: bought gold\n");
        buyCard(gold,state);
      }
      else if (money >= 3){
        printf("player2: bought silver\n");
        buyCard(silver,state);
      }
      printf("player2: endTurn\n");
      
      endTurn(state);
    }
    else if (whoseTurn(state) == 3) {
      if (gardens != -1) {
        printf("player3: bought gardens");
        buyCard(gardens,state);
      }
      if (money >= 8) {
        printf("player3: bought province\n");
        buyCard(province,state);
      }
      else if ((money >= 6) && (numAdventurers < 2)) {
        printf("player3: bought adventurer\n");
        buyCard(adventurer,state);
        numAdventurers++;
      }else if (money >= 6){
        printf("player3: bought gold\n");
        buyCard(gold,state);
      }
      else if (money >= 3){
        printf("player3: bought silver\n");
        buyCard(silver,state);
      }
      printf("player3: endTurn\n");
      
      endTurn(state);
    }
    if(player_num == 2){
      printf ("Player player0: %d\nPlayer player1: %d\n", scoreFor(0,state), scoreFor(1,state));
    } else if (player_num == 3){
      printf ("Player player0: %d\nPlayer player1: %d\nPlayer player2: %d\n", scoreFor(0,state), scoreFor(1,state), scoreFor(2,state));
    }else if (player_num == 4){
      printf ("Player player0: %d\nPlayer player1: %d\nPlayer player2: %d\nPlayer 4: %d\n", scoreFor(0,state), scoreFor(1,state), scoreFor(2,state), scoreFor(3,state));
    }
  } // end of While
  printf ("Finished game.\n");
  if(player_num == 2){
      printf ("Player player0: %d\nPlayer player1: %d\n", scoreFor(0,state), scoreFor(1,state));
    } else if (player_num == 3){
      printf ("Player player0: %d\nPlayer player1: %d\nPlayer player2: %d\n", scoreFor(0,state), scoreFor(1,state), scoreFor(2,state));
    }else if (player_num == 4){
      printf ("Player player0: %d\nPlayer player1: %d\nPlayer player2: %d\nPlayer 4: %d\n", scoreFor(0,state), scoreFor(1,state), scoreFor(2,state), scoreFor(3,state));
    }
  return 0;
}
