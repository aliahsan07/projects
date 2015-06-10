#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define NUM_GAMES 1

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
	
void incrementCard(int card, int finalKingdomCards[10][2]) {
	int i;
	for (i = 0; i < 10; i++) {
		if (finalKingdomCards[i][0] == card) {
			finalKingdomCards[i][1]++;
			return;
		}
	}	
	
	return;
}

int getNumCards(int card, int finalKingdomCards[10][2]) {
	int i;
	for (i = 0; i < 10; i++) {
		if (finalKingdomCards[i][0] == card) {
			return finalKingdomCards[i][1];
		}
	}	
	
	return -1;
}

int contains(int k[10], int card)	{
	int i;
	
	for (i = 0; i < 10; i++) {
		if (k[i] == card)
			return 1;
	}
	
	return 0;
	
}

/* A wrapper for endTurn() */
int finishTurn(struct gameState* p, int numPlayers, int v) {
	int player, i;
	player = whoseTurn(p);
	
	if (v) {
		printf("Player %d's hand:\t", player);
		for (i = 0; i < p->handCount[player]; i++)
			if (v) printCard(p->hand[player][i]);
		printf("\n");

		printf("Player %d's discard:\t", player);	
		for (i = 0; i < p->discardCount[player]; i++)
			if (v) printCard(p->discard[player][i]);
		printf("\n");

		printf("Player %d's deck:\t", player);
		for (i = 0; i < p->deckCount[player]; i++)
			if (v) printCard(p->deck[player][i]);
		printf("\n");
		printf("%d: end turn\n", player);
		
		for (i = 0; i < numPlayers; i++) {
			printf ("Player %d Score: %d\n", i, scoreFor(i, p));
		}
		printf("\n");
	}
	
	endTurn(p);
	
	return 0;

}



int main (int argc, char** argv) {
	int finalKingdomCards[10][2];
	int kingdomCards[10][2];
  struct gameState G;
  struct gameState *p = &G;
  int money;
  int i, j, h, randomIndex, randomCategory, randomNumberSeed, curCard;
  int player;
  int numPlayers;
  int k[10];
  int kingdomCard;
  int cardFound;
	int v;  // verbose processing
	
	
	

	
  if (argc < 2)
		randomNumberSeed = 1433808101;
  else
		randomNumberSeed = atoi(argv[1]);
	
	
	if (argc < 3)
		v = 1;
  else
		v = atoi(argv[2]);
  
	
  if (v) printf("Using %d as a random number seed.\n", randomNumberSeed);
  
  srand(randomNumberSeed);
	
	
  
  
  /* Play NUM_GAMES games of dominion. */
  for (h = 0; h < NUM_GAMES; h++) {
	  
	  /* random number of players (from 2-4) */
	  numPlayers = (rand() % 3) + 2;
	  if (v) printf("Number of players: %d\n", numPlayers);

  
	  /* Make an array of the 10 kingdom cards (#7-26) that will be used in this game */
	  if (v) printf("Kingdom Cards:\n");
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
				
			if (!cardFound && (kingdomCard != salvager) && (kingdomCard != tribute)) {
				finalKingdomCards[i][0] = kingdomCard;
				finalKingdomCards[i][1] = 0;
				kingdomCards[i][0] = kingdomCard;
				kingdomCards[i][1] = 0;
				k[i] = kingdomCard;
				if (v) printCard(k[i]);
				i++;
			}
	  }
		
	  if (v) printf ("\nStarting game.\n");
	  
	  
	  /* Allocate memory for game. */   
		initializeGame(numPlayers, k, randomNumberSeed, p);
	 
	  while (!isGameOver(p)) {
			money = countMoney(p);	
			player = whoseTurn(p);
			
			/* Loop through current player's hand and play the first kingdom card
			encountered. */
			for (i = 0; i < numHandCards(p); i++) {
				
				curCard = handCard(i, p);
				
				if (!p->numActions)
					break;
			
				if ((curCard <= 26) && (curCard >= 7) && (curCard != gardens)) {
					
					if (v) {
						printf("%d: About to play ", player);
						printCard(curCard);
						printf("...\n");
					}
					
					switch(curCard) {
						case ambassador:
							for (j = 0; j < numHandCards(p); j++) {
								if (handCard(j, p) == curse) {
									if (playCard(i, j, -1, -1, p) != -1) {
										if (v) printf("%d: ambassador played from position %d\n", player, i);
									}
									else
										if (v) printf("%d: There was a problem with playing ambassador\n\n\n", player);
									money = countMoney(p);
									break;
								}
							}	
							break;
					
						case baron:
							if (playCard(i, 0, 1, 1, p) != -1) {
								if (v) printf("%d: baron played from position %d\n", player, i);
							}
							else {
								if (v) printf("%d: There was a problem with playing baron\n\n\n", player);
							}			
							money = countMoney(p);
							break;
							
						case feast:
							for (j = 0; j < numHandCards(p); j++) {
								if (supplyCount(handCard(j, p), p) > 1
								&& getCardCost(handCard(j, p)) <= 5) {
									if (playCard(i, handCard(j, p), 1, 1, p) == 0) {
										if (v) printf("%d: feast played from position %d\n", player, i);
									}
									else
										if (v) printf("%d: There was a problem with playing feast\n\n\n", player);
									money = countMoney(p);
									break;
								}
							}
							break;
						
						/* Find treasure card to trash (pass as choice1 as position)
						treasure card to gain: pass as choice2 by name. */
						case mine:
							for (j = 0; j < numHandCards(p); j++) {
								if (handCard(j, p) == copper) {
									if (playCard(i, j, silver, -1, p) == 0) {
										if (v) printf("%d: mine played from position %d\n", player, i);
									}
									else
										if (v) printf("%d: There was a problem with playing mine\n\n\n", player);
									money = countMoney(p);
									break;
								}
								
								else if (handCard(j, p) == silver) {
									if (playCard(i, j, gold, -1, p) == 0) {
										if (v) printf("%d: mine played from position %d\n", player, i);
									}
									else
										if (v) printf("%d: There was a problem with playing mine\n\n\n", player);
									money = countMoney(p);
									break;
								}
							}					
							break;
						
						case remodel:
							for (j = 0; j < numHandCards(p); j++) {
								if (getCardCost(handCard(j, p)) >= 3) {
									if (playCard(i, j, duchy, -1, p) == 0) {
										if (v) printf("%d: remodel played from position %d!\n", player, i);
									}
									else 
										if (v) printf("%d: There was a problem with playing remodel!\n\n\n", player);
									money = countMoney(p);
									break;
								}
							}					
							break;
						
						
						default: 	
							if (playCard(i, 1, 1, 1, p) != -1) {
								if (v) {
									printf("%d: ", player);
									printCard(curCard);
									printf("played from position %d\n", i);
								}
							}
							else {
								if (v) {
									printf("%d: ", player);
									printf("Failed to play ");
									printCard(curCard);
									printf("\n\n");
								}
							}			
							money = countMoney(p);
							break;
					}
				}
			}
			
			
			
			
			
			
			
			randomCategory = (rand() % 100) + 1;	
			
			/* Always buy a province if you can afford it */
			if (money >= 8) {
				if (buyCard(province, p) == 0) {
					if (v) printf("%d: bought province\n", player);
				}
				else {
					if (v) printf("%d: failed to buy province\n", player);
				}
			}
			
			
			/* Buy money 55% of the time */
			else if (randomCategory > 45) {
				if (money >= 6) {
					if (buyCard(gold, p) == 0) {
						if (v) printf("%d: bought gold\n", player);
					}						
					else {
						if (v) printf("%d: failed to buy gold\n", player);
					}
				}
				
				else if (money >= 3) {
					if (buyCard(silver, p) == 0) {
						if (v) printf("%d: bought silver\n", player);
					}						
					else {
						if (v) printf("%d: failed to buy silver\n", player);
					}
				}
			}
			
			/* Buy a Kingdom card 40% of the time */
			else if (randomCategory > 5) {
				for (i = 0; i < 20; i++) {
					
					if (p->numBuys < 1)
						break;
					
					randomIndex = rand() % 10;
					
					if (getCardCost(k[randomIndex]) <= money) {
						if (buyCard(k[randomIndex], p) == 0) {
							if (v) printf("%d: bought ", player);
							if (v) printCard(k[randomIndex]);
							if (v) printf("\n");
							incrementCard(k[randomIndex], finalKingdomCards);
						}
						
						else {
							if (v) printf("%d: failed to buy ", player);
							if (v) printCard(k[randomIndex]);
							if (v) printf("\n");
						}
					}		
				}
			}
			
			/* Buy a duchy 5% of the time */
			else {
				if (money >= 5) {
					if (buyCard(duchy, p) == 0) {
						if (v) printf("%d: bought duchy\n", player);
					}
					else {
						if (v) printf("%d: failed to buy duchy\n", player);
					}
				}
			}
				
				
				
			




			
			
			
			/* Make sure count starts from zero */
			for (i = 0; i < 10; i++) {
				kingdomCards[i][1] = 0;
			}
				

			/* Look through every card in play */
			for (j = 0; j < numPlayers; j++) {
			
				/* Check hand */
				for (i = 0; i < p->handCount[j]; i++) {				
					curCard = p->hand[j][i];				
					if (contains(k, curCard))
						incrementCard(curCard, kingdomCards);	
					if (!(curCard >= curse && curCard <= treasure_map))
						exit(-1);
				}
				
				/* Check discard pile */
				for (i = 0; i < p->discardCount[j]; i++) {			
					curCard = p->discard[j][i];				
					if (contains(k, curCard))
						incrementCard(curCard, kingdomCards);
					if (!(curCard >= curse && curCard <= treasure_map))
						exit(-1);
				}

				/* Check deck */
				for (i = 0; i < p->deckCount[j]; i++) {
					curCard = p->deck[j][i];
					if (contains(k, curCard))
						incrementCard(curCard, kingdomCards);
					if (!(curCard >= curse && curCard <= treasure_map))
						exit(-1);
				}
			}
			
			if (finalKingdomCards[0][1] != kingdomCards[0][1])
				exit(-1);
	
	

		
		
			finishTurn(p, numPlayers, v);


		
			/* Now it's the other player's turn */
	  }

		if (v) {
			if (v) printf ("Finished game.\n");
			for (i = 0; i < numPlayers; i++) {
				if (v) printf ("Player %d Score: %d\n", i, scoreFor(i, p));
			}
			
			if (v) printf("\nKingdom cards bought: \n");	
			for (i = 0; i < 10; i++) {
				if (v) printCard(finalKingdomCards[i][0]);
				if (v) printf(": %i\n", finalKingdomCards[i][1]);
			}
		
			if (v) printf("\nKingdom cards in game: \n");
			for (i = 0; i < 10; i++) {
				if (v) printCard(kingdomCards[i][0]);
				if (v) printf(": %i\n", kingdomCards[i][1]);
			}
		}
		
		

		if (v) printf("\n\n\n\n");
  }
		
		
		
  return 0;
}
