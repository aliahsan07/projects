#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define NUMTESTS 2000000

int printCard(int card);

int main(int argc, char** argv)
{
  int testcounter = 0;
  while(testcounter != NUMTESTS){
  //The random card values are between 0 and 26, so mod by 27, you should be
  //pretty jevo about it. As for initiating games, super easy to randomize
  //number of players playing, however, playing games is still intersting,
  //ask about in class on Tuesday (May 19th, 2015)
  struct gameState G;
  struct gameState *p = &G;

  srand(time(NULL));

  /*  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
      sea_hag, tribute, smithy};
  */
  int k[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int r; //Store our random card values;
  int i, j;
  int numPlayers = rand() % 5; 
  int money = 0;

  //Make sure I have more than 2 players
  if (numPlayers < 2){
    while(1){
      numPlayers = rand() % 5;
      if (numPlayers < 2)
	continue;
      else
	break;
    }
  }
  int players[numPlayers];
  //intialize deck with cards ( have to be greater than or equal to 7)
  for (i = 0; i < 10; i++){
    r = rand() % 27;
    while (r < 7){
      r = rand() % 27;
    }
    k[i] = r;
  }
  
  //Make sure kingdom cards are random
  for (i = 0; i < 10; i++){
    r = rand() % 27;
    while (r < 7){
      r = rand() % 27;
    }
    if (k[i] == 0)
      k[i] = r;
    for (j = i+1; j < 10; j++){
      if (k[i] == k[j]){
	k[i] = r;
	i = -1;
	break;
      }     
    }
  }
  

 
  printf("***STARTING GAME***\n");
  initializeGame(numPlayers, k, atoi(argv[1])+ rand(), p);
  
  while (!isGameOver(p)){
    
    printf("\nCards in player %d's hand:  ", whoseTurn(p));
    for (i = 0; i < numHandCards(p); i++){
      if (i < 4){
	printCard(handCard(i, p));
	printf(", ");
      }
      else{
	printCard(handCard(i, p));
      }
    }
    printf("\n");

    //Not entirely sure what this phase does, 
    for (i = 0; i < numHandCards(p); i++){
      if (handCard(i, p) == copper)
	money++;
      else if (handCard(i, p) == silver)
	money += 2;
      else if (handCard(i, p) == gold)
	money += 3;
    }
    
    //How much money does the player have
    for (i = 0; i < numPlayers; i++){
      money = 0;
      j = 0;     
      while (j < numHandCards(p)){
        r = rand() % 2;

	if (handCard(j, p) == copper){
	  playCard(j, -1, -1, -1, p);
	  money++;
	}
	else if (handCard(j, p) == silver){
	  playCard(j, -1, -1, -1, p);
	  money += 2;
	}
	else if (handCard(j, p) == gold){
	  playCard(j, -1, -1, -1, p);
	  money += 3;
	}
	
	// 1/3 chance of being able to play another card besides money:

	if (r == 0){
	  if (handCard(j,p) == adventurer){
	    playCard(j, -1, -1, -1, p);
	    printf("Player %d: ***Played Adventurer***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == feast){
	    playCard(j, copper, -1, -1, p);
	    printf("Player %d: ***Played Feast***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == council_room){
	    playCard(j, -1, -1, -1, p);
	    printf("Player %d: ***Played Council Room***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == mine){
	    playCard(j, copper, gardens, -1, p);	    
	    printf("Player %d: ***Played Mine***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == smithy){
	    playCard(j, -1, -1, -1, p);
	    printf("Player %d: ***Played Smithy***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == remodel){
	    playCard(j, embargo, duchy, -1, p);	    
	    printf("Player %d: ***Played Remodel***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == village){
	    playCard(j, -1, -1, -1, p);
	    printf("Player %d: ***Played Village***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == baron){
	    playCard(j, -1, -1, -1, p);
	    printf("Player %d: ***Played Baron***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == great_hall){
	    playCard(j, -1, -1, -1, p);	    
	    printf("Player %d: ***Played Great Hall***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == minion){
	    playCard(j, adventurer, copper, -1, p);
	    printf("Player %d: ***Played Minion***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == steward){
	    playCard(j, 1, -1, -1, p);	    
	    printf("Player %d: ***Played Steward***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == tribute){
	    playCard(j, -1, -1, -1, p);
	    printf("Player %d: ***Played Tribute***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == ambassador){
	    playCard(j, 1, 1, -1, p);
	    printf("Player %d: ***Played Ambassador***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == cutpurse){
	    playCard(j, -1, -1, -1, p);
	    printf("Player %d: ***Played Cutpurse***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == embargo){
	    playCard(j, copper, -1, -1, p);
	    printf("Player %d: ***Played Embargo***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == outpost){
	    playCard(j, -1, -1, -1, p);	    
	    printf("Player %d: ***Played Outpost***\n", whoseTurn(p));
	  }	  
	  else if (handCard(j,p) == salvager){
	    playCard(j, copper, -1, -1, p);
	    printf("Player %d: ***Played Salvager***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == sea_hag){
	    playCard(j, -1, -1, -1, p);	    
	    printf("Player %d: ***Played Sea Hag***\n", whoseTurn(p));
	  }
	  else if (handCard(j,p) == treasure_map){
	    playCard(j, -1, -1, -1, p);	    
	    printf("Player %d: ***Played Treasure Map***\n", whoseTurn(p));
	  }
	}
	j++;
      }
      
      int check = 0, count = 0;
      //***Buying Phase***
      if (money >= 8){
	printf("Player %d: Bought Province\n\n", whoseTurn(p));
	buyCard(province, p);
	}
      else if (money >= 6){
	// adventurer
	for (count = 0; count < 10; count++){
	  if (k[count] == adventurer){
	    check = 1;
	  }
	}
	if (check == 1 && (rand() % 3 == 0)){ // 1/3 to buy adventurer
	  printf("Player %d: Bought Adventurer\n\n", whoseTurn(p));
	  buyCard(adventurer, p);
	}
	else {
	  printf("Player %d: Bought Gold\n\n", whoseTurn(p));
	  buyCard(gold, p);
	}
      }
      else if (money >= 5){
	//council_room, mine, minion, tribute, outpost
	for (count = 0; count < 10; count++){
	  if (k[count] == council_room || k[count] == mine ||
	      k[count] == minion || k[count] == tribute ||
	      k[count] == outpost){
	    
	    check += 1;
	  }
	}
	if (rand() % 5 == 0){
	  for (count = 0; count < 10; count++){
	    if(check > 0 && k[count] == council_room && rand()% 5 == 0){
	      printf("Player %d: Bought Council Room\n\n", whoseTurn(p));
	      buyCard(council_room, p);
	      break;
	    }
	    else if(check > 0 && k[count] == mine && rand()% 5 == 0){
	      printf("Player %d: Bought Mine\n\n", whoseTurn(p));
	      buyCard(mine, p);
	      break;
	    }
	    else if(check > 0 && k[count] == minion && rand()% 5 == 0){
	      printf("Player %d: Bought Minion\n\n", whoseTurn(p));
	      buyCard(minion, p);
	      break;
	    }
	    else if(check > 0 && k[count] == tribute && rand()% 5 == 0){
	      printf("Player %d: Bought Tribute\n\n", whoseTurn(p));
	      buyCard(tribute, p);
	      break;
	    }
	    else if(check > 0 && k[count] == outpost && rand()% 5 == 0){
	      printf("Player %d: Bought Outpost\n\n", whoseTurn(p));
	      buyCard(outpost, p);
	      break;
	    }
	  }
	}
	else {		      
	  printf("Player %d: Bought Duchy\n\n", whoseTurn(p));
	  buyCard(duchy, p);
	}
      }
      else if (money >= 4){
	//feast, gardens, remodel, smithy, baron, cutpurse, salvager, sea_hag
	// treasure_map
	for (count = 0; count < 10; count++){
	  if (k[count] == feast || k[count] == gardens || k[count] == remodel
	      || k[count] == smithy || k[count] == baron || 
	      k[count] == cutpurse || k[count] == salvager ||
	      k[count] == sea_hag || k[count] == treasure_map) {	   
	    
	      check += 1;
	  }
	}
	// 1/5 chance of buying a card in deck
	if (rand() % 5 == 0){
	  for (count = 0; count < 10; count++){
	    if(check > 0 && k[count] == feast && rand()% 5 == 0){
	      printf("Player %d: Bought Feast\n\n", whoseTurn(p));
	      buyCard(feast, p);
	      break;
	    }
	    else if(check > 0 && k[count] == gardens && rand()% 5 == 0){
	      printf("Player %d: Bought Gardens\n\n", whoseTurn(p));
	      buyCard(gardens, p);
	      break;
	    }
	    else if(check > 0 && k[count] == smithy && rand()% 5 == 0){
	      printf("Player %d: Bought Smithy\n\n", whoseTurn(p));
	      buyCard(smithy, p);
	      break;
	    }
	    else if(check > 0 && k[count] == baron && rand()% 5 == 0){
	      printf("Player %d: Bought Baron\n\n", whoseTurn(p));
	      buyCard(baron, p);
	      break;
	    }
	    else if(check > 0 && k[count] == cutpurse && rand()% 5 == 0){
	      printf("Player %d: Bought Cutpurse\n\n", whoseTurn(p));
	      buyCard(cutpurse, p);
	      break;
	    }
	    else if(check > 0 && k[count] == salvager && rand()% 5 == 0){
	      printf("Player %d: Bought Salvager\n\n", whoseTurn(p));
	      buyCard(salvager, p);
	      break;
	    }
	    else if(check > 0 && k[count] == sea_hag && rand()% 5 == 0){
	      printf("Player %d: Bought Sea Hag\n\n", whoseTurn(p));
	      buyCard(sea_hag, p);
	      break;
	    }
	    else if(check > 0 && k[count] == treasure_map && rand()% 5 == 0){
	      printf("Player %d: Bought Treasure Map\n\n", whoseTurn(p));
	      buyCard(treasure_map, p);
	      break;
	    }
	  }
	}
      }
      else if (money >= 3){
	//embargo, ambassador, steward, great_hall,village
	for (count = 0; count < 10; count++){
	  if (k[count] == embargo || k[count] == ambassador || 
	      k[count] == steward || k[count] == great_hall || 
	      k[count] == village){
	    
	    check += 1;
	  }	  
	}
	if (rand() % 5 == 0) {
	  for (count = 0; count < 10; count++){
	    if(check > 0 && k[count] == embargo && rand()% 5 == 0){
	      printf("Player %d: Bought Embargo\n\n", whoseTurn(p));
	      buyCard(embargo, p);
	      break;
	    }
	    else if(check > 0 && k[count] == ambassador && rand()% 5 == 0){
	      printf("Player %d: Bought Ambassador\n\n", whoseTurn(p));
	      buyCard(ambassador, p);
	      break;
	    }
	    else if(check > 0 && k[count] == steward && rand()% 5 == 0){
	      printf("Player %d: Bought Steward\n\n", whoseTurn(p));
	      buyCard(steward, p);
	      break;
	    }
	    else if(check > 0 && k[count] == great_hall && rand()% 5 == 0){
	      printf("Player %d: Bought Great Hall\n\n", whoseTurn(p));
	      buyCard(great_hall, p);
	      break;
	    }
	    else if(check > 0 && k[count] == village && rand()% 5 == 0){
	      printf("Player %d: Bought Village\n\n", whoseTurn(p));
	      buyCard(village, p);
	      break;
	    }
	  }
	}
	else {
	  printf("Player %d: Bought Silver\n\n", whoseTurn(p));
	  buyCard(silver, p);
	}
      }
      endTurn(p);
      
      for (i = 0; i < numPlayers; i++){
	printf("Player %d: %d\n", i, scoreFor(i, p));  
      }
    }
  }
    //***End of Game***
    printf("***GAME FINISHED***\n");
    
    for (i = 0; i < numPlayers; i++){
      printf("Player %d: %d\n", i, scoreFor(i, p));
    }
    getWinners(players, p);
    testcounter++;
  }    
      return 0;
}
int printCard(int card)
{
  switch(card){
  case curse:
    printf("Curse");
    return 0;
  case estate:
    printf("Estate");
    return 0;
  case duchy:
    printf("Duchy");
    return 0;
  case province:
    printf("Province");
    return 0;
  case copper:
    printf("Copper");
    return 0;
  case silver:
   printf("Silver");
   return 0;
  case gold:
    printf("Gold");
    return 0;
  case adventurer:
    printf("Adventurer");
    return 0;
  case council_room:
    printf("Council Room");
    return 0;
  case feast:
    printf("Feast");
    return 0;
  case gardens:
    printf("Gardens");
    return 0;
  case mine:
    printf("Mine");
    return 0;
  case remodel:
    printf("Remodel");
    return 0;
  case smithy:
    printf("Smithy");
    return 0;
  case village:
    printf("Village");
    return 0;
  case baron:
    printf("Baron");
    return 0;
  case great_hall:
    printf("Great Hall");
    return 0;
  case minion:
    printf("Minion");
    return 0;
  case steward:
    printf("Steward");
    return 0;
  case tribute:
    printf("Tribute");
    return 0;
  case ambassador:
    printf("Ambassador");
    return 0;
  case cutpurse:
    printf("Cutpurse");
    return 0;
  case embargo:
    printf("Embargo");
    return 0;
  case outpost:
    printf("Outpost");
    return 0;
  case salvager:
    printf("Salvager");
    return 0;
  case sea_hag:
    printf("Sea Hag");
    return 0;
  case treasure_map:
    printf("Treasure Map");
    return 0;
  }
  return -1;
}
