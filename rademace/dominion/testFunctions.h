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
