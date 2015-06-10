/*
Name: Duy Nguyen
CS 361 - Assigment 4
Randomize playing card
*/

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "interface.h"
#include "time.h"

#define MAX 2
#define KNUM 10

const char* NameCard[27][2] = {
						{"curse","0"},     {"estate","2"},       {"duchy","5"},      {"province","8"}, {"copper","0"},  {"silver","3"},      {"gold","6"},
						{"adventurer","6"},{"council room","5"}, {"feast","4"},      {"gardens","4"},  {"mine","5"},    {"remodel","4"},     {"smithy","4"},
						{"village","3"},   {"baron","4"},        {"great hall","3"}, {"minion","5"},   {"steward","3"}, {"tribute","5"},     {"ambassador","3"},
						{"cutpurse","4"},  {"embargo","2"},      {"outpost","5"},    {"salvager","4"}, {"sea hag","4"}, {"treasure map","4"}
						};

/*
This function print all the cards of the source
*/
void printCards(int len, int* numSource) {
	int i;
	for (i = 0; i < len; ++i){
		printf("The number: %2d, card name %-15s, the cost is %d\n",numSource[i],NameCard[numSource[i]][0],atoi(NameCard[numSource[i]][1]));
	}
}


/*
returns true if in toCheck false otherwise
*/
int check(int* toCheck, int num) {
	int j;
	for (j = 0; j < KNUM; ++j) {
		if (toCheck[j] == num) {
			return 1;
		}
	}
	return 0;
}

/*
get the hand for the strategy (cards that the player will only buy)
*/
void getHand(int* p, int* k, int CardsOfP){		
	int checkInDeck = 1; 
	int i = 0, num = 0, checkRan = 0;
	
	printf("\n\nNumber in hand: %d\n\n", CardsOfP);
	while (i < CardsOfP){
		num = rand() % 27;
		checkRan = 0;

		checkInDeck = (num < 7) ? 0 : !check(k, num); 

		if (checkInDeck == 0) {
			checkRan = (i > 0) ? check(p, num) : 0;

			if (checkRan == 0){
				p[i] = num;
				++i;
			}	
		}
	}
}

/*
check for duplicate int the deck (for debuging)
*/
void checkDup(int* k, int length){ 
	int i, j;
	int check = 0;
	for (i = 0; i < length; ++i){
		for (j = 0; j < i; ++j){
			if (k[j] == k[i]){
				check = 1;
				break;
			}
		}
		if (check == 1) break;
	}
	if (check == 1) printf("BADDDD");	
}

/*
initation the player strategy
*/
int initPlayer(int **p, int* k) {		
	int CardsOfP = rand() % 5 + 1;
	*p = (int*)malloc (sizeof(int) * CardsOfP);
	getHand(*p, k, CardsOfP);
	printCards(CardsOfP, *p); 
	return CardsOfP;
}

/*
initation the first 10 cards
*/
void initCard(int* k ){		
	int i = 0;
	int num, checkRan;

	while (i < KNUM){
		num = rand() % 20 + 7;

		checkRan = (i > 0) ? check(k, num) : 0;
		
		if (checkRan == 0) {
			k[i] = num;
			++i;
		}
	}
}

/*
buy the card on the strategy of the player randomlly 
*/
void  buyRanCard(struct gameState *p, int* numCardInStrat, int** player, int numOfPlayer, int money){
	int r = 0;
	int cardWillBuy;
	while (p->numBuys > 0){////////////////////////////need check for all the r
		cardWillBuy = player [whoseTurn(p)][rand() % numCardInStrat[whoseTurn(p)]];
		if (money >= 8) {
			r = buyCard(province, p);
			if (r != 0) {
				printf ("Error buying province from player %d\n",whoseTurn(p));
				break;
			}	
			else printf("Player %d bought province, the cost is 8\n",whoseTurn(p)); 
			
		}
		else if (money >= 6) {
			r = buyCard(gold, p);
			if (r != 0) {
				printf ("Error buying gold from player %d\n",whoseTurn(p));
				break;
			}	
			else printf("Player %d bought gold, the cost is 6\n",whoseTurn(p));  
		}
		else if (money >= atoi(NameCard[cardWillBuy][1])) {
			r = buyCard(cardWillBuy, p);
			if (r != 0) {
				printf ("Error buying %-15s from player %d\n",NameCard[cardWillBuy][0],whoseTurn(p));
				break;
			}
			else printf("Player %d bought %-15s, the cost is %d\n",whoseTurn(p),NameCard[cardWillBuy][0],atoi(NameCard[cardWillBuy][1])); 
		}
		else if (rand()%3 == 0 && money >= 5) {
			r = buyCard(duchy, p);
			if (r != 0){
				printf ("Error buying duchy from player %d\n",whoseTurn(p));
				break;
			} 
			else printf("Player %d bought duchy, the cost is 5\n",whoseTurn(p));
		}	
		else if (money >= 3) {
			r = buyCard(silver, p);
			if (r != 0){
				printf ("Error buying silver from player %d\n",whoseTurn(p));
				break;
			} 
			else printf("Player %d bought silver, the cost is 3\n",whoseTurn(p));  
		}
		else if (rand()%3 == 0 && money >= 2) {
			r = buyCard(estate, p);
			if (r != 0){
				printf ("Error buying estate from player %d\n",whoseTurn(p));
				break;
			} 
			else printf("Player %d bought estate, the cost is 2\n",whoseTurn(p));  
		}
		else if (rand()%10 == 2){
			if (rand()%5 == 0){
				r = buyCard(curse, p);
				if (r != 0) {
					printf ("Error buying curse from player %d\n",whoseTurn(p));
					break;
				}
				else printf("Player %d bought curse, the cost is 0\n",whoseTurn(p));

			}
			else{
				r = buyCard(copper, p);
				if (r != 0){
					printf ("Error buying gold from player %d\n",whoseTurn(p));
					break;
				} 				
				else printf("Player %d bought copper, the cost is 0\n",whoseTurn(p));
			}	
		}
	}	
}

/*
playing the dominion game
*/
void playingGame(struct gameState *p, int* numCardInStrat, int** player, int numOfPlayer){
	int money = 0, i = 0, j = 0;
	int cardPos,cardWillPlay;
	while (!isGameOver(p) && j < 1000){
		cardWillPlay = -1;	
		money = 0;
		for (i = 0; i < numHandCards(p); ++i){//get the money
			if (handCard(i, p) == copper)		money++;
			else if (handCard(i, p) == silver)	money += 2;
			else if (handCard(i, p) == gold)	money += 3;
		}	
		
		for (i = 0; i < numHandCards(p); ++i){
			if (handCard(i, p) >= adventurer){//play the first playable card on the hand 
				cardWillPlay = handCard(i,p);
				cardPos = i;
				break;
			}
		}
				
		if (cardWillPlay != -1){
			printf("Player %d played %-15s\n",whoseTurn(p),NameCard[cardWillPlay][0]);
			playCard(cardPos,1,1,1,p); //this could be set to random but i don't understand the rule of each card
		}
		
		buyRanCard(p, numCardInStrat, player, numOfPlayer,money);	
		printf ("\n");	
		endTurn(p);
		j++;
	}
	if (j >= 1000){
		printf("Error Game take way TOO LONG TO FINISH\n");
	}
	printf("end\n");
}

int main (int argc, char** argv) {
	int k[KNUM];

	int i = 0;
	int h = 0;
	int c1;
	int c2;
	int numOfPlayer;

	struct gameState G;
	struct gameState *domi = &G;	

	int r;
	srand(time(0));
	while (h < MAX){
		int* p1;
		int* p2;
		int** player;
		int* numCardInStrat;

		numOfPlayer = rand()%3 + 2;
		player = (int**)malloc (sizeof(int*) * numOfPlayer);
		numCardInStrat = (int*) malloc (sizeof(int) * numOfPlayer);

		initCard(k);

		printf("__________________DECK______________________\n");
		printCards(KNUM, k);
		printf("_______Total player%d___________\n",numOfPlayer);
		for (i = 0; i < numOfPlayer; ++i){
			numCardInStrat[i] = initPlayer(&player[i], k);
		}	

		r = initializeGame(numOfPlayer, k, rand(), domi);
		assert (r == 0);
		playingGame(domi,numCardInStrat,player,numOfPlayer);

		for (i = 0; i < numOfPlayer; ++i){
			free(player[i]);
		}
		free(player);
		free(numCardInStrat);
		++h;
	}
	return 0;
}
