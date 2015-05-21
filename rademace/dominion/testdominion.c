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


int getCardCost(int card) {
	switch(card) {	
		case 1: return 2;
		case 2: return 5;
		case 3: return 8;
		case 4: return 0;
		case 5: return 3;
		case 6: return 6;
		case 7: return 6;
		case 8: return 5;
		case 9: return 4;
		case 10: return 4;
		case 11: return 5;
		case 12: return 4;
		case 13: return 4;
		case 14: return 4;
		case 15: return 4;
		case 16: return 3;
		case 17: return 5;
		case 18: return 3;
		case 19: return 5;
		case 20: return 3;
		case 21: return 4;
		case 22: return 2;
		case 23: return 5;
		case 24: return 4;
		case 25: return 4;
		case 26: return 4;
		default: return -1;
	}
}


int countMoney(struct gameState *state) {
	int money = 0;
	int i;

	for (i = 0; i < numHandCards(state); i++){
	  if (handCard(i, state) == copper){
		playCard(i, -1, -1, -1, state);
		money++;
	  }
	  else if (handCard(i, state) == silver){
		playCard(i, -1, -1, -1, state);
		money += 2;
	  }
	  else if (handCard(i, state) == gold){
		playCard(i, -1, -1, -1, state);
		money += 3;
	  }
	}
	
	return money;
}
	

int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  int money;
  int i, j, randomIndex, randomCategory, randomNumberSeed, curCard;
  int player;
  int numPlayers;
  int k[10];
  int kingdomCard;
  int cardFound;
  
  if (!argv[1]) {
	printf("a random number seed may be provided as an argument\n");
	randomNumberSeed = 1;	
  }
  
  else
	randomNumberSeed = atoi(argv[1]);
  
  srand(randomNumberSeed);
  
  /* random number of players (from 2-4) */
  numPlayers = (rand() % 3) + 2;
  // numPlayers = 2;
  
  /* Make an array of the 10 kingdom cards (#7-26) that will be used in this game */
  printf("Kingdom Cards:\n");
  i = 0;
  while (i < 10) {
	kingdomCard = (rand() % 20) + 7;
	cardFound = 0;
	
	for (j = 0; j < i; j++) {
		if (kingdomCard == k[j]) {
			cardFound = 1;
			break;
		}
	}
	  
	if (!cardFound) {	
		k[i] = kingdomCard;
		printCard(k[i]);
		i++;
	}
  }
  
  printf ("\nStarting game.\n");
  
  /* Allocate memory for game. */   
	initializeGame(numPlayers, k, randomNumberSeed, p);
 
  while (!isGameOver(p)) {
    money = countMoney(p);	
	player = whoseTurn(p);
	
	/* Loop through current player's hand and play the first kingdom card
	encountered. */
	for (i = 0; i < numHandCards(p); i++) {
		
		curCard = handCard(i, p);
		
		if ((curCard <= 26) && (curCard >= 7) && (curCard != gardens)) {
			
			
			/* gardens: can't play until end of game.
			ambassador: need to give choices (locations of cards to trash).
			treasure map: need two treasure maps in hand for this to work.
			mine: need to provide choices (card to trash and card to gain). */
			
			
			
			if (curCard == ambassador) {
				for (j = 0; j < numHandCards(p); j++) {
					if (handCard(j, p) == curse) {
						if (playCard(i, j, -1, -1, p) != -1) {
							printf("%d: ambassador played from position %d\n", player, i);
							break;
						}
						else {
							printf("%d: There was a problem with playing ambassador\n", player);
							return -1;
						}				
					}
				}	
				money = countMoney(p);
				break;
			}
			
			else if (curCard == treasure_map) {
				continue;
			}
			
			else if (curCard == mine) {
				continue;
			}
			
			else if (curCard == remodel) {
				for (j = 0; j < numHandCards(p); j++) {
					if (getCardCost(handCard(j, p)) >= 3) {
						if (playCard(i, j, duchy, -1, p) == 0) {
							printf("%d: remodel played from position %d!\n", player, i);
							money = countMoney(p);
							break;
						}
						else {
							printf("%d: There was a problem with playing remodel!\n\n", player);
							return -1;
						}
					}
				}					
				break;
			}
			
			else {	
				if (playCard(i, -1, -1, -1, p) != -1) {
					printf("%d: ", player);
					printCard(curCard);
					printf("played from position %d\n", i);
				}
				else {
					printf("%d: ", player);
					printf("There was a problem with playing ");
					printCard(curCard);
					printf("\n");
					return -1;
				}			
				money = countMoney(p);
				break;
			}
		}
	}
	
	
	randomCategory = (rand() % 100) + 1;	
	
	/* Always buy a province if you can afford it */
	if (money >= 8) {
		if (buyCard(province, p) == 0)
			printf("%d: bought province\n", player);
		else
			printf("%d: failed to buy province\n", player);
	}
	
	
	/* Buy money 55% of the time */
	else if (randomCategory > 45) {
		if (money >= 6) {
			if (buyCard(gold, p) == 0)
				printf("%d: bought gold\n", player); 
			else
				printf("%d: failed to buy gold\n", player); 
		}
		
		else if (money >= 3) {
			if (buyCard(silver, p) == 0)
				printf("%d: bought silver\n", player); 
			else
				printf("%d: failed to buy silver\n", player); 
		}
	}
	
	/* Buy a Kingdom card 40% of the time */
	else if (randomCategory > 5) {
		for (i = 0; i < 20; i++) {
			randomIndex = rand() % 10;
			
			if (getCardCost(k[randomIndex]) <= money) {
				if (buyCard(k[randomIndex], p) == 0) {
					printf("%d: bought ", player);
					printCard(k[randomIndex]);
					printf("\n");
					break;
				}
				
				else {
					printf("%d: failed to buy ", player);
					printCard(k[randomIndex]);
					printf("\n");
				}
			}		
		}
	}
	
	/* Buy a duchy 5% of the time */
	else {
		if (money >= 5) {
			if (buyCard(duchy, p) == 0)
				printf("%d: bought duchy\n", player);
			else
				printf("%d: failed to buy duchy\n", player);
		}
	}
		
		
		

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
	
	for (i = 0; i < numPlayers; i++) {
		printf ("Player %d Score: %d\n", i, scoreFor(i, p));
	}
	printf("\n");
			
			
		/* Now it's the other player's turn */
		
	
	
 
  }

	printf ("Finished game.\n");
	for (i = 0; i < numPlayers; i++) {
		printf ("Player %d Score: %d\n", i, scoreFor(i, p));
	}
	printf("\n");

  return 0;
}
