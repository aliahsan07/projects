#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
  //The random card values are between 0 and 26, so mod by 27, you should be
  //pretty jevo about it. As for initiating games, super easy to randomize
  //number of players playing, however, playing games is still intersting,
  //ask about in class on Tuesday (May 19th, 2015)
  struct gameState G;
  struct gameState *p = &G;

  srand(atoi(argv[1]));

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
	//	printf("Card in hand: %d\n", handCard(j, p));
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
	    printf("***Played Adventurer***\n");	  
	  }
	  else if (handCard(j,p) == feast){
	    playCard(j, duchy, -1, -1, p);
	    printf("***Played Feast***\n"); 
	  }
	  else if (handCard(j,p) == council_room){
	    playCard(j, -1, -1, -1, p);
	    printf("***Played Council Room***\n");	  
	  }
	  else if (handCard(j,p) == mine){
	    playCard(j, copper, gardens, -1, p);
	    printf("***Played Mine***\n");	  
	  }
	  else if (handCard(j,p) == smithy){
	    playCard(j, -1, -1, -1, p);
	    printf("***Played Smithy***\n");	  
	  }
	  else if (handCard(j,p) == remodel){
	    playCard(j, embargo, duchy, -1, p);
	    printf("***Played Remodel***\n");	  
	  }
	  else if (handCard(j,p) == village){
	    playCard(j, -1, -1, -1, p);
	    printf("***Played Village***\n");	  
	  }
	  else if (handCard(j,p) == baron){
	    playCard(j, -1, -1, -1, p);
	    printf("***Played Baron***\n");   
	  }
	  else if (handCard(j,p) == great_hall){
	    playCard(j, -1, -1, -1, p);
	    printf("***Played Great Hall***\n");	  
	  }
	  else if (handCard(j,p) == minion){
	    playCard(j, adventurer, copper, -1, p);
	    printf("***Played Minion***\n");
	  }
	  else if (handCard(j,p) == steward){
	    playCard(j, 1, -1, -1, p);
	    printf("***Played Stewrd***\n"); 
	  }
	  else if (handCard(j,p) == tribute){
	    playCard(j, -1, -1, -1, p);
	    printf("***Played Tribute***\n"); 
	  }
	  else if (handCard(j,p) == ambassador){
	    playCard(j, 1, 1, -1, p);
	    printf("***Played Ambassador***\n"); 
	  }
	  else if (handCard(j,p) == cutpurse){
	    playCard(j, -1, -1, -1, p);
	    printf("***Played Cutpurse***\n"); 
	  }
	  else if (handCard(j,p) == embargo){
	    playCard(j, copper, -1, -1, p);
	    printf("***Played Embargo***\n"); 
	  }
	  else if (handCard(j,p) == outpost){
	    playCard(j, -1, -1, -1, p);
	    printf("***Played Outpost***\n"); 
	  }	  
	  else if (handCard(j,p) == salvager){
	    playCard(j, copper, -1, -1, p);
	    printf("***Played Salvager***\n"); 
	  }
	  else if (handCard(j,p) == sea_hag){
	    playCard(j, -1, -1, -1, p);
	    printf("***Played Sea Hag***\n"); 
	  }
	  else if (handCard(j,p) == treasure_map){
	    playCard(j, -1, -1, -1, p);
	    printf("***Played Treasure Mp***\n"); 
	  }
	}
	j++;
      }
      
      int check = 0, count = 0;
      //***Buying Phase***
      if (money >= 8){
	printf("Player %d: Bought Province\n", whoseTurn(p));
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
	  printf("Player %d: Bought Adventurer\n", whoseTurn(p));
	  buyCard(adventurer, p);
	}
	else {
	  printf("Player %d: Bought Gold\n", whoseTurn(p));
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
	      printf("Player %d: Bought Council Room\n", whoseTurn(p));
	      buyCard(council_room, p);
	      break;
	    }
	    else if(check > 0 && k[count] == mine && rand()% 5 == 0){
	      printf("Player %d: Bought Mine\n", whoseTurn(p));
	      buyCard(mine, p);
	      break;
	    }
	    else if(check > 0 && k[count] == minion && rand()% 5 == 0){
	      printf("Player %d: Bought Minion\n", whoseTurn(p));
	      buyCard(minion, p);
	      break;
	    }
	    else if(check > 0 && k[count] == tribute && rand()% 5 == 0){
	      printf("Player %d: Bought Tribute\n", whoseTurn(p));
	      buyCard(tribute, p);
	      break;
	    }
	    else if(check > 0 && k[count] == outpost && rand()% 5 == 0){
	      printf("Player %d: Bought Outpost\n", whoseTurn(p));
	      buyCard(outpost, p);
	      break;
	    }
	  }
	}
	else {		      
	  printf("Player %d: Bought Duchy\n", whoseTurn(p));
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
	      printf("Player %d: Bought Feast\n", whoseTurn(p));
	      buyCard(feast, p);
	      break;
	    }
	    else if(check > 0 && k[count] == gardens && rand()% 5 == 0){
	      printf("Player %d: Bought Gardens\n", whoseTurn(p));
	      buyCard(gardens, p);
	      break;
	    }
	    else if(check > 0 && k[count] == smithy && rand()% 5 == 0){
	      printf("Player %d: Bought Smithy\n", whoseTurn(p));
	      buyCard(smithy, p);
	      break;
	    }
	    else if(check > 0 && k[count] == baron && rand()% 5 == 0){
	      printf("Player %d: Bought Baron", whoseTurn(p));
	      buyCard(baron, p);
	      break;
	    }
	    else if(check > 0 && k[count] == cutpurse && rand()% 5 == 0){
	      printf("Player %d: Bought Cutpurse\n", whoseTurn(p));
	      buyCard(cutpurse, p);
	      break;
	    }
	    else if(check > 0 && k[count] == salvager && rand()% 5 == 0){
	      printf("Player %d: Bought Salvager\n", whoseTurn(p));
	      buyCard(salvager, p);
	      break;
	    }
	    else if(check > 0 && k[count] == sea_hag && rand()% 5 == 0){
	      printf("Player %d: Bought Sea Hag\n", whoseTurn(p));
	      buyCard(sea_hag, p);
	      break;
	    }
	    else if(check > 0 && k[count] == treasure_map && rand()% 5 == 0){
	      printf("Player %d: Bought Treasure Map\n", whoseTurn(p));
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
	      printf("Player %d: Bought Embargo\n", whoseTurn(p));
	      buyCard(embargo, p);
	      break;
	    }
	    else if(check > 0 && k[count] == ambassador && rand()% 5 == 0){
	      printf("Player %d: Bought Ambassador\n", whoseTurn(p));
	      buyCard(ambassador, p);
	      break;
	    }
	    else if(check > 0 && k[count] == steward && rand()% 5 == 0){
	      printf("Player %d: Bought Steward\n", whoseTurn(p));
	      buyCard(steward, p);
	      break;
	    }
	    else if(check > 0 && k[count] == great_hall && rand()% 5 == 0){
	      printf("Player %d: Bought Great Hall\n", whoseTurn(p));
	      buyCard(great_hall, p);
	      break;
	    }
	    else if(check > 0 && k[count] == village && rand()% 5 == 0){
	      printf("Player %d: Bought Village\n", whoseTurn(p));
	      buyCard(village, p);
	      break;
	    }
	  }
	}
	else {
	  printf("Player %d: Bought Silver\n", whoseTurn(p));
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
    
    return 0;
}
