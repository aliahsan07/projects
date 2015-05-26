#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

void printCard(int card) {
	switch(card) {	
		case 0: printf("curse ");
			break;
		case 1: printf("estate ");
			break;
		case 2: printf("duchy ");
			break;
		case 3: printf("province ");
			break;
		case 4: printf("copper ");
			break;
		case 5: printf("silver ");
			break;
		case 6: printf("gold ");			
			break;
		case 7: printf("adventurer ");
			break;
		case 8: printf("council_room ");
			break;
		case 9: printf("feast ");
			break;
		case 10: printf("gardens ");
			break;
		case 11: printf("mine ");
			break;
		case 12: printf("remodel ");
			break;
		case 13: printf("smithy ");
			break;
		case 14: printf("village ");
			break;
		case 15: printf("baron ");
			break;
		case 16: printf("great_hall ");
			break;
		case 17: printf("minion ");
			break;
		case 18: printf("steward ");
			break;
		case 19: printf("tribute ");
			break;
		case 20: printf("ambassador ");
			break;
		case 21: printf("cutpurse ");
			break;
		case 22: printf("embargo ");
			break;
		case 23: printf("outpost ");
			break;
		case 24: printf("salvager ");
			break;
		case 25: printf("seahag ");
			break;
		case 26: printf("treasure_map ");
			break;
		default: printf("INVALID ");
	}
}




int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  int money = 0;
  int smithyPos = -1;
  int villagePos = -1;
  int adventurerPos = -1;
  int i = 0;
  int numSmithies = 0;
  int numAdventurers = 0;
  int numVillages = 0;
  
  /* Make an array of the 10 kingdom cards that will be used in this game */
  int k[] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
			   sea_hag, tribute, smithy};
		   
  printf ("Starting game.\n");
  
  
  
  if (argv[1]) {
	  /* Allocate memory for game. Have number of players be 2 */   
	  initializeGame(2, k, atoi(argv[1]), p);
  }
  
  else {
	  printf("a random number seed must be provided as an argument\n");
	  return 0;
  }
  
  while (!isGameOver(p)) {
    money = 0;
    smithyPos = -1;
    adventurerPos = -1;
	villagePos = -1;
	
	
	
	/* Look through hand of current player and see how much money he has 
	and if he has a smithy or an adventurer */
    for (i = 0; i < numHandCards(p); i++) {
      if (handCard(i, p) == copper)
		money++;
      else if (handCard(i, p) == silver)
		money += 2;
      else if (handCard(i, p) == gold)
		money += 3;
      else if (handCard(i, p) == smithy)
		smithyPos = i;
      else if (handCard(i, p) == adventurer)
		adventurerPos = i;
	  else if (handCard(i, p) == village)
		villagePos = i;
    }

    if (whoseTurn(p) == 0) {
		
	  /* It is player 1's turn */
      if (smithyPos != -1) {
		/* Player 1 plays a smithy if he has one */        
		if (playCard(smithyPos, -1, -1, -1, p) != -1)
			printf("0: smithy played from position %d\n", smithyPos);
		else
			printf("There was a problem  with playing the smithy/n");
		money = 0;
		i=0;
		
		/* Playing the smithy probably affected how much money you have
		in your hand, so recount it. */
		while(i<numHandCards(p)){
		  if (handCard(i, p) == copper){
			playCard(i, -1, -1, -1, p);
			money++;
		  }
		  else if (handCard(i, p) == silver){
			playCard(i, -1, -1, -1, p);
			money += 2;
		  }
		  else if (handCard(i, p) == gold){
			playCard(i, -1, -1, -1, p);
			money += 3;
		  }
		  
		  i++;
		}
      }
	  
	  if (villagePos != -1) {
		/* Player 1 plays a village if he has one */ 
		if (playCard(villagePos, -1, -1, -1, p) != -1)
			printf("0: village played from position %d\n", villagePos);
		else
			printf("There was a problem  with playing the village/n");
		money = 0;
		i=0;
		
		/* Playing the village probably affected how much money you have,
		so recount it. */
		while(i<numHandCards(p)){
		  if (handCard(i, p) == copper){
			playCard(i, -1, -1, -1, p);
			money++;
		  }
		  else if (handCard(i, p) == silver){
			playCard(i, -1, -1, -1, p);
			money += 2;
		  }
		  else if (handCard(i, p) == gold){
			playCard(i, -1, -1, -1, p);
			money += 3;
		  }
		  
		  i++;
		}
      }

      if (money >= 8) {
        printf("0: bought province\n"); 
        buyCard(province, p);
      }
      else if (money >= 6) {
        printf("0: bought gold\n"); 
        buyCard(gold, p);
      }
      else if ((money >= 4) && (numSmithies < 2)) {
		printf("0: bought smithy\n"); 
        buyCard(smithy, p);
        numSmithies++;
      }
	  else if ((money >= 4) && (numVillages < 4)) {
		printf("0: bought village\n"); 
        buyCard(village, p);
        numVillages++;
      }
      else if (money >= 3) {
        printf("0: bought silver\n"); 
        buyCard(silver, p);
      }
  
	int player = whoseTurn(p);
  
	printf("Player %d's hand:\t", player);
	for (i = 0; i < p->handCount[player]; i++)
		printCard(p->hand[player][i]);
	printf("\n");

	printf("Player %d's discard:\t", player);	
	for (i = 0; i < p->discardCount[player]; i++)
		printCard(p->discard[player][i]);
	printf("\n");

	printf("Player %d's deck:\t", player);
	for (i = 0; i < p->deckCount[player]; i++)
		printCard(p->deck[player][i]);
	printf("\n");

	printf("%d: end turn\n", player);
	endTurn(p);
  
  
  
      printf("0: end turn\n");
      endTurn(p);
	  /* Now it's the other player's turn */
    }

    else {
	  /* It is player 2's turn */
      if (adventurerPos != -1) {
		/* Player 2 plays an adventurer if he has one */
        printf("1: adventurer played from position %d\n", adventurerPos);
		playCard(adventurerPos, -1, -1, -1, p); 
		money = 0;
		i=0;
		while(i<numHandCards(p)){
		  if (handCard(i, p) == copper){
			playCard(i, -1, -1, -1, p);
			money++;         
		  }
		  else if (handCard(i, p) == silver){
			playCard(i, -1, -1, -1, p);
			money += 2;
		  }
		  else if (handCard(i, p) == gold){
			playCard(i, -1, -1, -1, p);
			money += 3;
		  }
		  i++;
		}
      }
	
	  /* Buy a province, adventurer, gold, or silver, etc. depending on how much money is in hand */
      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
	  
      else if ((money >= 6) && (numAdventurers < 2)) {
        printf("1: bought adventurer\n");
		buyCard(adventurer, p);
		numAdventurers++;
      }
	  
	  else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
      }
	  
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
	  
      printf("1: endTurn\n");
      
      endTurn(p);
	  /* Now it's the other player's turn */      
    }

      printf ("Player 0 Score: %d\nPlayer 1 Score: %d\n", scoreFor(0, p), scoreFor(1, p));
	    
  } // end of While

  printf ("Finished game.\n");
  printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));

  return 0;
}
