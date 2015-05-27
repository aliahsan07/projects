#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

const char* cardName(int cardVal){

    switch(cardVal){
    case curse: return "curse";
    case estate:return "estate";
    case duchy: return "duchy";
    case province: return "province";
    case copper: return "copper";
    case silver: return "silver";
    case gold: return "gold";
    case gardens: return "gardens";
    case adventurer: return "adventurer";
    case council_room: return "council room";
    case feast: return "feast";
    case mine: return "mine";
    case remodel: return "remodel";
    case smithy: return "smithy";
    case village: return "village";
    case baron: return "baron";
    case great_hall: return "great hall";
    case minion: return "minion";
    case steward: return "steward";
    case tribute: return "tribute";
    case ambassador: return "ambassador";
    case cutpurse: return "cutpurse";
    case embargo: return "embargo";
    case outpost: return "outpost";
    case salvager: return "salvager";
    case sea_hag: return "sea hag";
    case treasure_map: return "treasure map";
    }
    
    return "\n \n!!! NOT A VALID CARD WAS HAD WOE IS ME !!!\n \n ";
}

int main(int argc, char *argv[]){
  char *newline = "\n";
  srand(time(NULL));
  int randSeed, randChoice;
  int totalPlayers, totalMoney, roundCount;
  int smithyPosition, adventurerPosition, gardenPosition;
  int embargoPosition, villagePosition, minionPosition;
  int minePosition, cutpursePosition, seaHagPosition;
  int tribePosition;
  int i,j;
  int players[5] = {-1,-1,-1,-1,-1};
  
  struct gameState state;
  
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  
  if (argc <= 1){
    randSeed = rand();
    totalPlayers = (rand() % 4) + 1;
  }
  else if (argc == 2) {
    printf("That was silly of you to do command is testdominion randSeed totalPlayers");
  }
  else if (argc >= 3) {
    randSeed = atoi(argv[2]);
    totalPlayers = atoi(argv[1]);
  }
  
  printf ("Starting game with '%d' players.\n", totalPlayers);
  
  initializeGame(totalPlayers, k, randSeed, &state);

  //loop until game is over
  while (isGameOver(&state) == 0){

    printf("\n%d players turn\n", whoseTurn(&state)+1);
    randChoice = randSeed % 101;
    totalMoney = 0, smithyPosition = -1, adventurerPosition = -1;
    gardenPosition = -1, embargoPosition = -1, villagePosition= -1; 
    minionPosition = -1, minePosition = -1, cutpursePosition = -1; 
    seaHagPosition = -1, tribePosition = -1;
    

    //draw cards until 5 is in the hand
    while(numHandCards(&state) < 5){
      drawCard(whoseTurn(&state) , &state);
    }

    //print out the players hand
    printf("Hand is: ");
    for (i = 0; i < numHandCards(&state); i++){
      printf("%s   ", cardName(handCard(i, &state)));
    }
    puts(newline);
    for (j = 0; j < numHandCards(&state); j++) { // position
      if (handCard(j, &state) == copper){
	totalMoney += 1;
	//printf("have copper\n");
	playCard(j, -1, -1, -1, &state);
      }
      else if (handCard(j, &state) == silver){
	totalMoney += 2;
	//printf("have silver\n");
	playCard(j, -1, -1, -1, &state);
      }
      else if (handCard(j, &state) == gold){
	totalMoney += 3;
	//printf("have gold\n");
	playCard(j, -1, -1, -1, &state);
      }
      else if (handCard(j, &state) == smithy){
	smithyPosition = j;
      }
      else if (handCard(j, &state) == adventurer){
	adventurerPosition = j;
      }
      else if (handCard(j, &state) == gardens){
	gardenPosition = j;
      }
      else if (handCard(j, &state) == embargo){
	embargoPosition = j;
      }
      else if (handCard(j, &state) == village){
	villagePosition = j;
      }
      else if (handCard(j, &state) == minion){
	minionPosition = j;
      }
      else if (handCard(j, &state) == mine){
	minePosition = j;
      }
      else if (handCard(j, &state) == cutpurse){
	cutpursePosition = j;
      }
      else if (handCard(j, &state) == sea_hag){
	seaHagPosition = j;
      }
      else if (handCard(j, &state) == tribute){
	tribePosition = j;
      }
    } // position loop
    
		
    if (adventurerPosition != -1){
      printf("Played adventurer Card\n");
      playCard(adventurerPosition, -1, -1, -1, &state);
    }
    if (smithyPosition != -1){
      printf("Played smithy Card\n");
      playCard(smithyPosition, -1, -1, -1, &state);
    }
    if (minePosition != -1){
      printf("Played mine Card\n");
      playCard(minePosition, -1,-1,-1, &state);
    }
    if (minionPosition != -1) {
      printf("Played minion Card\n");
      playCard(minionPosition,-1,-1,-1,&state);
    }
    if (tribePosition != -1) {
      printf("Played tribute Card\n");
      //playCard(tribePosition,-1,-1,-1,&state);
    }
    if (cutpursePosition != -1) {
      printf("Played cutpurse\n");
      playCard(cutpursePosition,-1,-1,-1,&state);
    }
    if (gardenPosition != -1) {
      printf("Played gardens\n");
      playCard(gardenPosition,-1,-1,-1,&state);
    }
    if (seaHagPosition != -1) {
      printf("Played sea hag\n");
      playCard(seaHagPosition,-1,-1,-1,&state);
    }
    if (villagePosition != -1){
      printf("Played village Card\n");
      playCard(villagePosition,-1,-1,-1,&state);
    }
    if (embargoPosition != -1){
      printf("Played embargo Card\n");
      playCard(embargoPosition, -1,-1,-1,&state);
    }    
    printf("Current money: %d\n", totalMoney);
    if (totalMoney >= 8) {
      printf("bought province\n"); 
      buyCard(province, &state);
    }
    else if (totalMoney >= 6) {
      if (randChoice <= 50){
	printf("bought me some adventurer\n");
	buyCard(adventurer, &state);
      }
      else {
	printf("bought gold\n"); 
	buyCard(gold, &state);
      }
    }
    else if (totalMoney >= 5){
      if (randChoice <= 33) {
	printf("Bought mine\n");
	buyCard(mine, &state);
      }
      else if (randChoice > 33 && randChoice <=66){
	printf("Bought minion\n");
	buyCard(minion, &state);
      }
      else if (randChoice > 66){
	printf("Bought tribute\n");
	buyCard(tribute, &state);
      }
    }
    else if (totalMoney >= 4) {
      if (randChoice <= 25){
	printf("bought gardens\n"); 
	buyCard(gardens, &state);
      }
      else if (randChoice > 25 && randChoice <= 50) {
	printf("bought smithy\n"); 
	buyCard(smithy, &state);
      }
      else if (randChoice > 50 && randChoice <= 75) {
	printf("bought cutpurse\n"); 
	buyCard(cutpurse, &state);
      }
      else if (randChoice > 75){
	printf("bought sea hag\n"); 
	buyCard(sea_hag, &state);
      }
    }
    else if (totalMoney >= 3) {
      if (randChoice <= 50){
	printf("bought silver\n"); 
	buyCard(silver, &state);
      }
      else {
	printf("bought village\n");
	buyCard(village, &state);
      }
    }
    else if (totalMoney >= 2){
      if(randChoice <=50){
	printf("bought estate\n");
	buyCard(estate, &state);
      }
      else if(randChoice >50){
	printf("bought embargo\n");
	buyCard(embargo, &state);
      }
    }
    endTurn(&state);
    roundCount++;
    if (roundCount >= 25000){
      break; // too many
    }
  } // game while
  //End of Game
  
  printf ("Finished game with %d roundCounts.\n", roundCount);
  getWinners(players, &state);
  for (i = 0; i < totalPlayers; i++){
    //printf("Player '%d' scored '%d'\n", i+1, scoreFor(i, &state));
  }
  puts(newline);
  for (i = 0; i < totalPlayers; i++){
    if (players[i] != 0){
      //printf("Player '%d' won!\n", i+1);
    }
  }
  
  return 1;
}
