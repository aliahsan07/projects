#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);
int play_council_room(int player, struct gameState *state, int handPos);
int play_mine(int player, struct gameState *state, int handPos, int choice1, int choice2);
int play_remodel(int player, struct gameState *state, int handPos, int choice1, int choice2);	   
int play_smithy(int player, struct gameState *state, int handPos);
int play_village(int player, struct gameState *state, int handPos);
int total_card(int player, struct gameState *state);

int randomCards(int *cards, int seed);
int whatToBuy(int money, int k[10]);
int printCardName(int card);
		   
#endif
