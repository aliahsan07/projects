#include "testFunctions.h"

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
	
	FILE *fp;
	fp = fopen("testCase.c", "w");
	randomNumberSeed = 16;
	
fprintf(fp, 	"#include \"testFunctions.h\" \n\
int main (int argc, char** argv) { \n\
	struct gameState G; \n\
	struct gameState *p = &G; \n\
	int money; \n\
	int player; \n\
	int numPlayers;\n" );

  srand(randomNumberSeed);
  
  
  /* Play NUM_GAMES games of dominion. */
  for (h = 0; h < NUM_GAMES; h++) {
	  
	  

  
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
				
			if (!cardFound && (kingdomCard != salvager) && (kingdomCard != tribute)) {
				finalKingdomCards[i][0] = kingdomCard;
				finalKingdomCards[i][1] = 0;
				kingdomCards[i][0] = kingdomCard;
				kingdomCards[i][1] = 0;
				k[i] = kingdomCard;
				printCard(k[i]);
				i++;
			}
	  }
	
	 fprintf(fp, "\n\tint k[10] = {");
	 for (i = 0; i < 9; i++)
		 fprintf(fp, "%d, ", k[i]);
	 fprintf(fp, "%d};", k[9]);
	 
	 /* random number of players (from 2-4) */
		numPlayers = (rand() % 3) + 2;
		fprintf(fp, "\n\tnumPlayers = %d;",numPlayers);
	  
	  
	  /* Allocate memory for game. */   
		initializeGame(numPlayers, k, randomNumberSeed, p);
		
		fprintf(fp, "\n\tinitializeGame(numPlayers, k, 16, p);");
	 
	  while (!isGameOver(p)) {
			money = countMoney(p);
			player = whoseTurn(p);
			
			fprintf(fp, "\n\tmoney = countMoney(p);");
			fprintf(fp, "\n\tplayer = whoseTurn(p);");
			
			
			
			/* Loop through current player's hand and play the first kingdom card
			encountered. */
			for (i = 0; i < numHandCards(p); i++) {
				
				curCard = handCard(i, p);
				
				if (!p->numActions)
					break;
			
				if ((curCard <= 26) && (curCard >= 7) && (curCard != gardens)) {
					
					
					/* This part pushes something onto the stack which corrupts some
						data and causes invalid cards to enter the game */
					// printf("%d: About to play ", player);
					// printCard(curCard);
					// printf("...\n");
					
					switch(curCard) {
						case ambassador:
							for (j = 0; j < numHandCards(p); j++) {
								if (handCard(j, p) == curse) {
									if (playCard(i, j, -1, -1, p) != -1) {
										fprintf(fp, "\n\tplayCard(%d, %d, -1, -1, p);", i, j);
									}
									else
										printf("%d: There was a problem with playing ambassador\n\n\n", player);
									money = countMoney(p);
									break;
								}
							}	
							break;
					
						case baron:
							if (playCard(i, 0, 1, 1, p) != -1) {
								fprintf(fp, "\n\tplayCard(%d, 0, 1, 1, p);", i);
							}
							else {
								printf("%d: ", player);
								printf("There was a problem with playing ");
								printCard(curCard);
								printf("\n\n\n");
							}			
							money = countMoney(p);
							break;
							
						case feast:
							for (j = 0; j < numHandCards(p); j++) {
								if (supplyCount(handCard(j, p), p) > 1
								&& getCardCost(handCard(j, p)) <= 5) {
									if (playCard(i, handCard(j, p), 1, 1, p) == 0) {
										fprintf(fp, "\n\tplayCard(%d, %d, 1, 1, p);", i, handCard(j, p));
									}
									else
										printf("%d: There was a problem with playing feast\n\n\n", player);
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
										fprintf(fp, "\n\tplayCard(%d, %d, silver, -1, p);", i, j);
									}
									else
										printf("%d: There was a problem with playing mine\n\n\n", player);
									money = countMoney(p);
									break;
								}
								
								else if (handCard(j, p) == silver) {
									if (playCard(i, j, gold, -1, p) == 0) {
										fprintf(fp, "\n\tplayCard(%d, %d, gold, -1, p);", i, j);
									}
									else
										printf("%d: There was a problem with playing mine\n\n\n", player);
									money = countMoney(p);
									break;
								}
							}					
							break;
						
						case remodel:
							for (j = 0; j < numHandCards(p); j++) {
								if (getCardCost(handCard(j, p)) >= 3) {
									if (playCard(i, j, duchy, -1, p) == 0) {
										fprintf(fp, "\n\tplayCard(%d, %d, duchy, -1, p);", i, j);
									}
									else 
										printf("%d: There was a problem with playing remodel!\n\n\n", player);
									money = countMoney(p);
									break;
								}
							}					
							break;
						
						
						default:
							if (playCard(i, 1, 1, 1, p) != -1) {
								fprintf(fp, "\n\tplayCard(%d, 1, 1, 1, p);", i);
							}
							else {
								printf("%d: ", player);
								printf("Failed to play ");
								printCard(curCard);
								printf("\n\n");
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
					fprintf(fp, "\n\tbuyCard(province, p);");
				}
				else
					printf("%d: failed to buy province\n", player);
			}
			
			
			/* Buy money 55% of the time */
			else if (randomCategory > 45) {
				if (money >= 6) {
					if (buyCard(gold, p) == 0)
						fprintf(fp, "\n\tbuyCard(gold, p);");
					else
						printf("%d: failed to buy gold\n", player); 
				}
				
				else if (money >= 3) {
					if (buyCard(silver, p) == 0)
						fprintf(fp, "\n\tbuyCard(silver, p);");
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
							fprintf(fp, "\n\tbuyCard(%d, p);", k[randomIndex]);
							incrementCard(k[randomIndex], finalKingdomCards);
							break;
						}
						
						else {
							printf("%d: failed to buy ", player);
							printCard(k[randomIndex]);
							printf("\n");
							break;
						}
					}		
				}
			}
			
			/* Buy a duchy 5% of the time */
			else {
				if (money >= 5) {
					if (buyCard(duchy, p) == 0)
						fprintf(fp, "\n\tbuyCard(duchy, p);");
					else
						printf("%d: failed to buy duchy\n", player);
				}
			}
				
			endTurn(p);
			fprintf(fp, "\n\tendTurn(p);\n");
			
			for (i = 0; i < numPlayers; i++) {
				printf ("Player %d Score: %d\n", i, scoreFor(i, p));
			}
			printf("\n");


			




			
			/* Look through every card in play */
			for (j = 0; j < numPlayers; j++) {
				
				/* Check hand */
				for (i = 0; i < p->handCount[j]; i++) {
					
					curCard = p->hand[j][i];
					
					if (contains(k, curCard))
						incrementCard(curCard, kingdomCards);
					
					if (!(curCard <= treasure_map && curCard >= curse)) {
						printf("\n\n");
						printCard(curCard);
						printf("\n\n");
					}
					assert(curCard <= treasure_map && curCard >= curse);
				}
				
				/* Check discard pile */
				for (i = 0; i < p->discardCount[j]; i++) {
					
					curCard = p->discard[j][i];
					
					if (contains(k, curCard))
						incrementCard(curCard, kingdomCards);
					
					if (!(curCard <= treasure_map && curCard >= curse)) {
						printf("\n\n");
						printCard(curCard);
						printf("\n\n");
					}
					assert(curCard <= treasure_map && curCard >= curse);
				}

				/* Check deck */
				for (i = 0; i < p->deckCount[j]; i++) {
					
					curCard = p->deck[j][i];
					
					if (contains(k, curCard))
						incrementCard(curCard, kingdomCards);
					
					if (!(curCard <= treasure_map && curCard >= curse)) {
						printf("\n\n");
						printCard(curCard);
						printf("\n\n");
					}
					assert(curCard <= treasure_map && curCard >= curse);
				}
			}








		
			/* Now it's the other player's turn */
	  }

		

		printf("All tests passed!\n\n\n\n");
  }
	
	
	fprintf(fp, "\n\treturn 0;\n}");
	fclose(fp);
		
  return 0;
}
