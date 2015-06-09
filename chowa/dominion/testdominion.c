#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main (int argc, char** argv) {
	
  struct gameState G;
  struct gameState *p = &G;
  int players, cp = 0;
  
  int k[10],play[4];
  int i,j, seed, turns = 0, money, buy, temp, action, winner;
  	
	
	printf ("\nLet the games begin.\n");
	seed = atoi(argv[1]); //for testing manual seeds
	//seed = rand();
	srand(seed);
	players = 2 + rand() % 3 ;//2-4 players always	
	randomCards(k);	 
	
  initializeGame(players, k, seed, p);
	printf("\nThe kingdom cards this round are:");
	  for (i = 0; i < 10; i++){
			printf("\n\t %d \t", supplyCount(k[i], p));
			printCardName(k[i]);
		}
	printf("\n");
	for(i = 0; i<players; i++){
		p->whoseTurn = i;
		printf("\nPlayer %d is starting with:", i);
		printf("\n\tVictory Pts = %d", scoreFor(i,p));
		printf("\n\tCards in Hand = %d", p->handCount[i]);
		printf("\n\tCards in Deck = %d", p->deckCount[i]);
		printf("\n\tCards in Discard = %d", p->discardCount[i]);
	}
	cp = rand() % players; //pick starting player
	p->whoseTurn = cp;
  while (!isGameOver(p)) {
	turns++;
	
	printf("\nTurn %d for Player %d", turns, p->whoseTurn);
	
    action = 0;
	for(i = 0; i < numHandCards(p); i++){
		temp = handCard(i,p);
		for(j = 0; j<10; j++){
			if(temp == k[j]){
				action = temp;
				i = numHandCards(p);
				break;
			}
		}
	}
	if(action == 0)
		printf("\n\t\t*Playing nothing:");
	else{
	
	printf("\n\t\t *Playing card:");
	printCardName(action);
	
	playCard(action, 0, 0, 0, p);
	}
	
	//buying cards
	updateCoins(p->whoseTurn, p, 0);
	money = p->coins;
	
	buy = whatToBuy(money,k);
	buyCard(buy, p);
	printf("\n\t\t *MONEY: %d", money);
	printf("\n\t\t *BUY: ");
	printCardName(buy);
	printf("\n\tEnd Turn for %d\n", p->whoseTurn);
	endTurn(p);
      for(i=0; i < players; i++){
		printf ("\tPlayer %d: %d\n", i, scoreFor(i, p));    
		}  
  } // end of While

  printf ("\n\nThe game has ended. Final Scores! \n");
  for(i=0; i < players; i++){
	printf ("\tPlayer %d: %d\n", i, scoreFor(i, p));    
  }
  winner = getWinners(play,p);
  printf("Thus congrats to player %d for being the winner", winner);
  
	
  return 0;
}

int randomCards(int *cards){
	int i,j = 0, randNum, addCard, stop=0;
	
	
	while(stop != 10){
		randNum = rand() % 20;
		switch( randNum ) 
		{
		case 0:
		  addCard = adventurer;
		  break;
		case 1:
		  addCard = council_room;
		  break;
		case 2:
		  addCard = feast;
		  break;
		case 3:
		  addCard = gardens;
		  break;
		case 4:
		  addCard = mine;
		  break;
		case 5:
		  addCard = remodel;
		  break;
		case 6:
		  addCard = smithy;
		  break;
		case 7:
		  addCard = village;
		  break;
		case 8:
		  addCard = baron;
		  break;
		case 9:
		  addCard = great_hall;
		  break;
		case 10:
		  addCard = minion;
		  break;
		case 11:
		  addCard = steward;
		  break;
		case 12:
		  addCard = tribute;
		  break;
		case 13: 
		  addCard = ambassador;
		  break;
		case 14:
		  addCard = cutpurse;
		  break;
		case 15:
		  addCard = embargo; 
		  break;
		case 16:
		  addCard = outpost;
		  break;
		case 17:
		  addCard = salvager;
		  break;
		case 18:
		  addCard = sea_hag;
		  break;
		case 19:
		  addCard = treasure_map;
		  break;
		}
	
		for (i = 0; i < stop; i++)
		{
			if (cards[i] == addCard){
				//printf("duplicate %d with %d\n", addCard, cards[i]);
				j = 1; //duplicate card chosen :(
			}
		}
		if (j == 1)
			j = 0;
		else{
			cards[stop] = addCard;
			stop++;
		}
	}
  return 0;

}

int whatToBuy(int money, int k[10]){
	int choice = 0, i, holder;
	
	if(money < 2) //can't afford anything else
		return copper;
	if(money >= getCost(silver) && money < 6){ //but also not buying all silver in later rounds
		i = rand()%3;	//lets make it a %33 chance of buying silver
		if(i)
			return silver;	
	}
	
	while(!choice){
		i = rand() % 17; //for 10 kingdom cards, 3 victories and 3 treasures and 1 chance for a curse
		
		if(i < 10)
			holder = k[i];
		else{
			i = i-10;
			switch (i){
				case 0: 
					holder = estate;
					break;
				case 1: 
					holder = duchy;
					break;
				case 2: 
					holder = province;
					break;
				case 3: 
					holder = copper;
					break;
				case 4: 
					holder = silver;
					break;
				case 5: 
					holder = gold;
					break;
				case 6:
					holder = curse;
					break;
			}	
		}
		if(money >= getCost(holder))
			choice = holder;
	}

	return choice;	
	
}

int printCardName(int card){
	//yes I'm using a fucking switch statement to print card names, get over it
	switch(card){
		case 0:
			printf("curse");
			return 0;
		case 1:
		  printf("estate");
		  return 0;
		case 2:
		  printf("duchy");
		  return 0;
		case 3:
		  printf("province");
		  return 0;
		case 4:
		  printf("copper");
		  return 0;
		case 5:
		  printf("silver");
		  return 0;
		case 6:
		  printf("gold");
		  return 0;
		case 7:
		  printf("adventurer");
		  return 0;
		case 8:
		  printf("council room");
		  return 0;
		case 9:
		  printf("feast");
		  return 0;
		case 10:
		  printf("gardens");
		  return 0;
		case 11:
		  printf("mine");
		  return 0;
		case 12:
		  printf("remodel");
		  return 0;
		case 13:
		  printf("smithy");
		  return 0;
		case 14:
		  printf("village");
		  return 0;
		case 15:
		  printf("baron");
		  return 0;
		case 16:
		  printf("great hall");
		  return 0;
		case 17:
		  printf("minion");
		  return 0;
		case 18:
		  printf("steward");
		  return 0;
		case 19:
		  printf("tribute");
		  return 0;
		case 20:
		  printf("ambassador");
		  return 0;
		case 21:
		  printf("cutpurse");
		  return 0;
		case 22: 
		  printf("embargo");
		  return 0;
		case 23:
		  printf("outpost");
		  return 0;
		case 24:
		  printf("salvager");
		  return 0;
		case 25:
		  printf("sea hag");
		  return 0;
		case 26:
		  printf("treasure map");
		  return 0;
    
	}
	return -1;	
}