#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char testname[] = "cardtest4";

// test card village

int main (int argc, char** argv) {
	struct gameState g;
	struct gameState t;

	int numplayer = 2;
	int randseed = 1234;
	int cards[10] = {adventurer, feast, mine, smithy, village, great_hall,
			 ambassador, cutpurse, outpost, salvager};

	int c;
	int bonus = 123456789;

	while ((c = getopt(argc, argv, "p:r:")) != -1) {
		switch (c) {
		case 'p':
			numplayer = atoi(optarg);
			break;
		case 'r':
			randseed = atoi(optarg);
			break;
		default:
			break;
		}
	}
	
	printf("Start %s\n", testname);
	
	initializeGame(numplayer, cards, randseed, &g);
	g.hand[0][1] = village;
	g.deck[0][4] = salvager;
	t = g;

	g.numActions = 3;
	g.hand[0][1] = salvager;
	g.hand[0][5] = -1;
	g.playedCards[0] = village;
	g.playedCardCount = 1;
	g.deckCount[0] = 4;
	
	assert(cardEffect(village, 0, 0, 0, &t, 1, &bonus) == 0); 
	assert(memcmp(&t, &g, sizeof(struct gameState)) == 0); // game state altered
	
	/*
	printf("whoseTurn %i  %i\n", t.whoseTurn, g.whoseTurn);
	printf("phase %i  %i\n", t.phase, g.phase);
	printf("numActions %i  %i\n", t.numActions, g.numActions);
	printf("coins %i  %i\n", t.coins, g.coins);
	printf("numBuys %i  %i\n", t.numBuys, g.numBuys);
	printf("hand0 %i  %i\n", t.hand[0][0], g.hand[0][0]);
	printf("hand1 %i  %i\n", t.hand[0][1], g.hand[0][1]);
	printf("hand2 %i  %i\n", t.hand[0][2], g.hand[0][2]);
	printf("hand3 %i  %i\n", t.hand[0][3], g.hand[0][3]);
	printf("hand4 %i  %i\n", t.hand[0][4], g.hand[0][4]);
	printf("hand5 %i  %i\n", t.hand[0][5], g.hand[0][5]);
	printf("hand6 %i  %i\n", t.hand[0][6], g.hand[0][6]);
	printf("hand7 %i  %i\n", t.hand[0][7], g.hand[0][7]);
	printf("hand8 %i  %i\n", t.hand[0][8], g.hand[0][8]);
	printf("hand9 %i  %i\n", t.hand[0][9], g.hand[0][9]);
	printf("hand10 %i  %i\n", t.hand[0][10], g.hand[0][10]);
	printf("handCount %i  %i\n", t.handCount[0], g.handCount[0]);
	printf("deck0 %i  %i\n", t.deck[0][0], g.deck[0][0]);
	printf("deck1 %i  %i\n", t.deck[0][1], g.deck[0][1]);
	printf("deck2 %i  %i\n", t.deck[0][2], g.deck[0][2]);
	printf("deck3 %i  %i\n", t.deck[0][3], g.deck[0][3]);
	printf("deck4 %i  %i\n", t.deck[0][4], g.deck[0][4]);
	printf("deck5 %i  %i\n", t.deck[0][5], g.deck[0][5]);
	printf("deck6 %i  %i\n", t.deck[0][6], g.deck[0][6]);
	printf("deck7 %i  %i\n", t.deck[0][7], g.deck[0][7]);
	printf("deck8 %i  %i\n", t.deck[0][8], g.deck[0][8]);
	printf("deck9 %i  %i\n", t.deck[0][9], g.deck[0][9]);
	printf("deck10 %i  %i\n", t.deck[0][10], g.deck[0][10]);
	printf("deckCount %i  %i\n", t.deckCount[0], g.deckCount[0]);
	printf("discard0 %i  %i\n", t.discard[0][0], g.discard[0][0]);
	printf("discard1 %i  %i\n", t.discard[0][1], g.discard[0][1]);
	printf("discard2 %i  %i\n", t.discard[0][2], g.discard[0][2]);
	printf("discard3 %i  %i\n", t.discard[0][3], g.discard[0][3]);
	printf("discard4 %i  %i\n", t.discard[0][4], g.discard[0][4]);
	printf("discard5 %i  %i\n", t.discard[0][5], g.discard[0][5]);
	printf("discard6 %i  %i\n", t.discard[0][6], g.discard[0][6]);
	printf("discard7 %i  %i\n", t.discard[0][7], g.discard[0][7]);
	printf("discard8 %i  %i\n", t.discard[0][8], g.discard[0][8]);
	printf("discard9 %i  %i\n", t.discard[0][9], g.discard[0][9]);
	printf("discard10 %i  %i\n", t.discard[0][10], g.discard[0][10]);
	printf("discardCount %i  %i\n", t.discardCount[0], g.discardCount[0]);
	printf("playedCards0 %i  %i\n", t.playedCards[0], g.playedCards[0]);
	printf("playedCards1 %i  %i\n", t.playedCards[1], g.playedCards[1]);
	printf("playedCards2 %i  %i\n", t.playedCards[2], g.playedCards[2]);
	printf("playedCardCount %i  %i\n", t.playedCardCount, g.playedCardCount);
	*/
	
	printf("%s passed\n", testname);

	return 0;
}
