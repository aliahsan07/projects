#include "dominion.h"
#include "rngs.h"

#include <assert.h>
#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void pickCards();
void makeTurn(struct gameState *p);
int actionCard(int handPos, struct gameState *p);
int getCard(struct gameState *p);
void info(struct gameState *g);

int cards[10];

int main (int argc, char** argv) {
	struct gameState g;
	struct gameState *p;

	int randseed = 1;
	int numplayer;
	int turns;

	int c;

	while ((c = getopt(argc, argv, "r:")) != -1) {
		switch (c) {
		case 'r':
			randseed = atoi(optarg);
			if (randseed <= 0) {
				randseed = 1;
			}
			break;
		default:
			break;
		}
	}
	
	p = &g;
	memset(p, 0, sizeof(struct gameState));
	srand(randseed);
	
	numplayer = rand() % 3 + 2;
	turns = 0;
	
	memset(&cards, -1, sizeof(cards));
	pickCards();
	
	printf("Starting game with seed: %i\n", randseed);
	
	initializeGame(numplayer, cards, randseed, p);
	
	while (isGameOver(p) == 0) {
		//info(p);
		makeTurn(p);
		turns++;
	}
	
	printf("End of game with seed: %i\n", randseed);
	
	for (c = 0; c < p->numPlayers; c++) {
		printf("Player[%i] scored %i\n", c, scoreFor(c, p));
	}
	
	printf("Number turns: %i\n", turns);
	
	return 0;
}

void pickCards() {
	int deckHas;
	int card;
	int ran;
	int i;
	
	card = 0;
	while (card < 10) {
		deckHas = 0; 
		ran = rand() % 20 + 7;
		for (i = 0; i < 10; i++) {
			if (ran == cards[i]) {
				deckHas = 1;
				break;
			}
		}
		if (deckHas == 0) {
			cards[card] = ran;
			card++;
		}
	}
	return;
}

void makeTurn(struct gameState *p) {
	int actions[50][2]; //[0] position [1] card
	int numAct;
	int player;
	int ran;
	int result;
	int i;
	
	memset(&actions, -1, sizeof(actions));
	numAct = 0;
	
	player = whoseTurn(p);
	
	for (i = 0; i < numHandCards(p); i++) {
		if (handCard(i, p) >= 7 && numAct < 50) {
			actions[numAct][0] = i;
			actions[numAct][1] = handCard(i, p);
			numAct++;
		}
	}
	
	// action
	if (numAct == 0) { // no actions pass action phase
		printf("Player[%i] passes action\n", player);
		//break;
	}
	else {
		ran = rand() % numAct;
		printf("Player[%i] plays card: %i (", player, actions[ran][1]);
		result = actionCard(actions[ran][0], p);
		printf(")(result %i)\n", result);
	}
	
	// buy
	printf("Player[%i] buys card: ", player);
	result = getCard(p);
	printf(" (result %i)\n", result);
	
	endTurn(p); // clean up
	
	printf("Player[%i] ends turn Score: %i\n", player, scoreFor(player, p));
	return;
}

int actionCard(int handPos, struct gameState *p) {
	int card;
	int i;
	int c1;
	int c2;
	int c3;
	
	card = handCard(handPos, p);
	c1 = -1;
	c2 = -1;
	c3 = -1;
	
	switch (card) {
	case feast:
		c1 = cards[rand() % 10];
		break;
	case mine: // can pick the card being played...
		c1 = rand() % numHandCards(p);
		c2 = cards[rand() % 10];
		break;
	case remodel: // can pick the card being played...
		c1 = rand() % numHandCards(p);
		c2 = cards[rand() % 10];
		break;
	case baron:
		c1 = 0;
		for (i = 0; i < numHandCards(p); i++) {
			if (handCard(i, p) == estate) {
				c1 = i;
			}
		}
		break;
	case minion:
		c1 = rand() % 2;
		c2 = rand() % 2;
		break;
	case steward:// can pick the card being played...
		c1 = rand() % 3 + 1;
		c2 = rand() % numHandCards(p);
		c3 = rand() % numHandCards(p);
		break;
	case ambassador: // am not doing the choices
		break;
	case embargo:
		c1 = rand() % 27;
		break;
	case salvager: // can pick the card being played...
		c1 = rand() % numHandCards(p);
		break;
	case treasure_map:
		for (i = 0; i < numHandCards(p); i++) {
			if (handCard(i, p) == estate) {
				if (c1 != -1) {
					c2 = i;
				}
				else {
					c1 = i;
				}
			}
		}
		break;
	default:
		break;
	}
	printf("%i %i %i %i", handPos, c1, c2, c3);
	//printf("%i %i %i", c1, c2, c3);
	return playCard(handPos, c1, c2, c3, p);
}

int getCard(struct gameState *p) {
	int card;
	int ran;
	int money;
	int i;
	
	card = 1;
	ran = rand() % 100;
	money = 0;
	for (i = 0; i < numHandCards(p); i++) {
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
	}
	
	if (ran >= 70) { // money
		if (money >= 6) 
			card = gold;
		else if (money >= 3)
			card = silver;
		else
			card = copper;
	}
	else if (ran >= 35) { // land
		if (money >= 8) 
			card = province;
		else if (money >= 5)
			card = duchy;
		else
			card = estate;
	}
	else { // card
		card = cards[rand() % 10];
	}
	printf("%i", card);
	return buyCard(card, p);
}

void info(struct gameState *g) {
	int i;
	int j;
	int players = g->numPlayers;
	int cards = 100;
	printf("\t\t\tnumPlayers %i\n", g->numPlayers);
	for (i = 0; i < treasure_map+1; i++)
	{
		printf("\t\t\tsupplyCount[%i] %i\n", i, g->supplyCount[i]);
	}
	for (i = 0; i < treasure_map+1; i++)
	{
		printf("\t\t\tembargoTokens[%i]  %i\n", i, g->embargoTokens[i]);
	}
	printf("\t\t\toutpostPlayed %i\n", g->outpostPlayed);
	printf("\t\t\toutpostTurn %i\n",  g->outpostTurn);
	printf("\t\t\twhoseTurn %i\n", g->whoseTurn);
	printf("\t\t\tphase %i\n", g->phase);
	printf("\t\t\tnumActions  %i\n", g->numActions);
	printf("\t\t\tcoins %i\n", g->coins);
	printf("\t\t\tnumBuys %i\n", g->numBuys);
	for (i = 0; i < players; i++)
	{
		for (j = 0; j < cards; j++)
		{
			printf("\t\t\thand[%i][%i] %i\n", i, j, g->hand[i][j]);
		}
	}
	for (i = 0; i < players; i++)
	{
		printf("\t\t\thandCount[%i] %i\n", i, g->handCount[i]);
	}
	for (i = 0; i < players; i++)
	{
		for (j = 0; j < cards; j++)
		{
			printf("\t\t\tdeck[%i][%i] %i\n", i, j, g->deck[i][j]);
		}
	}
	for (i = 0; i < players; i++)
	{
		printf("\t\t\tdeckCount[%i] %i\n", i,  g->deckCount[i]);
	}	
	for (i = 0; i < players; i++)
	{
		for (j = 0; j < cards; j++)
		{
			printf("\t\t\tdiscard[%i][%i] %i\n", i, j, g->discard[i][j]);
		}
	}
	for (i = 0; i < players; i++)
	{
		printf("\t\t\tdiscardCount[%i] %i\n", i, g->discardCount[i]);
	}
	for (i = 0; i < cards; i++)
	{
		printf("\t\t\tplayedCards[%i] %i\n", i, g->playedCards[i]);
	}
	printf("\t\t\tplayedCardCount %i\n", g->playedCardCount);
	return;
}