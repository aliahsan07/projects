/******************************************
 * Dominion Test **************************
 ******************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define DIE_ON_ASSERT 0
#define MAX_TESTS 10
//#define RAND_MAX 1000

void massert(int b, char* s);

void randomKingdomCards(int k[10]);
char *cardNumToName(int card);

void actionPhase(int player, struct gameState *Game);
void buyPhase(int player, struct gameState *Game, int k[10]);

void printSupply(struct gameState *Game, int k[10]);

int main (int argc, char** argv) {

  printf ("******************************************\n");
  printf ("* Dominion Test START ********************\n");
  printf ("******************************************\n\n");
  
  int i, r, playerNum;
  int randomSeed = atoi(argv[1]);    // create a random seed
  srand(randomSeed);
	printf("randomSeed :%d\n", randomSeed);
  
  int k[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  randomKingdomCards(k);
  int players = rand() % 3 + 2;   // create random numbers of players (2-4)
    
  //int cards[20] = {council_room, remodel, smithy, village, great_hall, adventurer, feast, gardens, mine, baron, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
  //int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

  struct gameState Game;
  struct gameState *player = &Game;

  // Initialize game
  r = initializeGame(players, k, randomSeed, &Game);
  printf ("Initializing game...\n");
  massert(r == 0, "Game didn't initialized!");

  printSupply(&Game, k);

  while (!isGameOver(player)) {
    playerNum = Game.whoseTurn;
    printf ("************ Player %d's turn ************\n", playerNum);
    Game.coins = 0;

    // Count coins
    for (i = 0; i < Game.handCount[playerNum]; i++) {
      if (Game.hand[playerNum][i] == copper)
        Game.coins++;
      else if (Game.hand[playerNum][i] == silver)
        Game.coins += 2;
      else if (Game.hand[playerNum][i] == gold)
        Game.coins += 3;
    }
    printf ("Coins = %d \n", Game.coins);

    // Call action phase
    actionPhase(playerNum, &Game);

    // Call buy phase
    buyPhase(playerNum, &Game, k);

    // End turn
    printf ("End of Player %d's turn.\n", Game.whoseTurn);
    endTurn(&Game);

    // Display score
    printf ("*********** Score ***********\n");
    for (i = 0; i < players; i++) {
      printf ("Player %d: %d  \n", i, scoreFor(i, &Game));
    }

  }
  
  printf ("******************************************\n");
  printf ("* Dominion Test FINISHED *****************\n");
  printf ("******************************************\n\n");
  
  return 0;
}

void massert(int b, char* s) {
    if (!b) {
        printf ("ASSERTION FAILURE: %s\n", s);
        if (DIE_ON_ASSERT) {
            exit(1);
        }
    }
}

void randomKingdomCards(int k[10]) {
  int i, kUsed, kSelected;
  int numSelected = 0;
  //int k[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
 
  while(numSelected < 10) {
    kUsed = 0;

    // Generate random kingdom card
    kSelected = adventurer + (rand() % 20);
    
    // Check if selected card is an action card
    // if(kSelected < adventurer) continue;
    if (kSelected < adventurer || kSelected > treasure_map)
      continue;

    // Check if generated kingdom card is already selected
    for(i = 0; i < numSelected; i++) {
      if(k[i] == kSelected) {
        kUsed = 1;
        break;
      }
    }

    // Ignore rest of code if kingdom card is duplicate
    if(kUsed == 1)
      continue;
      
    k[numSelected] = kSelected;
    numSelected++;
  }
}

char *cardNumToName(int card){
  char *name = malloc(15 * sizeof(int));
  
  switch(card){
    case curse:         strcpy(name,"Curse");
      break;
    case estate:        strcpy(name,"Estate");
      break;
    case duchy:         strcpy(name,"Duchy");
      break;
    case province:      strcpy(name,"Province");
      break;
    case copper:        strcpy(name,"Copper");
      break;
    case silver:        strcpy(name,"Silver");
      break;
    case gold:          strcpy(name,"Gold");
      break;
    case adventurer:    strcpy(name,"Adventurer");
      break;
    case council_room:  strcpy(name,"Council Room");
      break;
    case feast:         strcpy(name,"Feast");
      break;
    case gardens:       strcpy(name,"Gardens");
      break;
    case mine:          strcpy(name,"Mine");
      break;
    case remodel:       strcpy(name,"Remodel");
      break;
    case smithy:        strcpy(name,"Smithy");
      break;
    case village:       strcpy(name,"Village");
      break;
    case baron:         strcpy(name,"Baron");
      break;
    case great_hall:    strcpy(name,"Great Hall");
      break;
    case minion:        strcpy(name,"Minion");
      break;
    case steward:       strcpy(name,"Steward");
      break;
    case tribute:       strcpy(name,"Tribute");
      break;
    case ambassador:    strcpy(name,"Ambassador");
      break;
    case cutpurse:      strcpy(name,"Cutpurse");
      break;
    case embargo:       strcpy(name,"Embargo");
      break;
    case outpost:       strcpy(name,"Outpost");
      break;
    case salvager:      strcpy(name,"Salvager");
      break;
    case sea_hag:       strcpy(name,"Sea Hag");
      break;
    case treasure_map:  strcpy(name,"Treasure Map");
      break;

    default:            strcpy(name,"?");
  }

  return name;
}

void actionPhase(int player, struct gameState *Game) {
  int handPos, r;
  int counter = 0;

  printf("******* Action Phase ********\n");
  printf ("Actions = %d \n", Game->numActions);

  while (Game->numActions > 0) {
    handPos = rand() % Game->handCount[player];
    
    // Check if selected card is an action card
    if (Game->hand[player][handPos] < adventurer || Game->hand[player][handPos] > treasure_map){
      counter++;
      if (counter == Game->handCount[player])
        break;
        
      continue;
    }

    // Play action card
    printf ("Playing %s...\n", cardNumToName(Game->hand[player][handPos]) );
    r = playCard(handPos, 1, 1, 1, Game);
    massert(r == 0, "Failed to play card!");
    
  }
}

void buyPhase(int player, struct gameState *Game, int k[10]) {
  int kSelected, r;

  printf("********* Buy Phase *********\n");
  printf ("Buys = %d \n", Game->numBuys);
  printf ("Coins = %d \n", Game->coins);

  // Repeat until out of buys
  while (Game->numBuys > 0) {
    
    // Buy a province if player has 8 or more coins
    if (Game->coins >= 8) {
      printf ("Buying Province (Cost 8)...\n");
      r = buyCard(province, Game);
      massert(r == 0, "Failed to buy card!");
    }

    else if (Game->coins == 6) {
      printf ("Buying Gold (Cost 6)...\n");
      r = buyCard(gold, Game);
      massert(r == 0, "Failed to buy card!");
    }
    
    else if (Game->coins == 3) {
      if ((rand()%2) == 1){
        printf ("Buying Silver (Cost 3)...\n");
        r = buyCard(silver, Game);
        massert(r == 0, "Failed to buy card!");
      }
    }
    
    // Else buy a random card
    else {
      kSelected = k[rand()%10];
      if (getCost(kSelected) <= Game->coins){
        printf ("Buying %s (Cost %d)...\n", cardNumToName(kSelected),  getCost(kSelected));
        r = buyCard(kSelected, Game);
        massert(r == 0, "Failed to buy card!");
      }
    }

    // 1/10 chance to break out of buy loop if keeps failing
    if ((rand()%10) == 1)
      break;
    
  }
}

void printSupply(struct gameState *Game, int k[10]) {
  int cardNum, cardCost, cardCount;
  
  printf("#   Card          Cost   Copies\n");
  
  for(cardNum = 0; cardNum < 10; cardNum++){
    cardCount = Game->supplyCount[k[cardNum]];
    
    if(cardCount == -1) continue;
    
    cardCost = getCost(k[cardNum]);
    printf("%-2d  %-13s %-5d  %-5d", cardNum, cardNumToName(k[cardNum]), cardCost, cardCount);
    printf("\n");
  }
  
  printf("\n");
}
