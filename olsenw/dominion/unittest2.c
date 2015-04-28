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

char testname[] = "unittest2";

// test gainCard

int main (int argc, char** argv) {
	struct gameState g;
	struct gameState t;

	int numplayer = 2;
	int randseed = 1234;
	int cards[10] = {adventurer, feast, mine, smithy, village, great_hall,
			 ambassador, cutpurse, outpost, salvager};

	int c;

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
	g.supplyCount[adventurer] = 0;
	t = g;
	
	assert(gainCard(adventurer, &t, 0, 1) == -1); // should be unable to gain adventurer
	assert(memcmp(&t, &g, sizeof(struct gameState)) == 0); // game state match
	
	g.supplyCount[mine]--;
	g.discard[1][0] = mine;
	g.discardCount[1] = 1;
	
	assert(gainCard(mine, &t, 0, 1) == 0); // should buy mine
	assert(memcmp(&t, &g, sizeof(struct gameState)) == 0); // game state match
	
	g.supplyCount[mine]--;
	g.deck[1][10] = mine;
	g.deckCount[1] = 11;	
	
	assert(gainCard(mine, &t, 1, 1) == 0); // should buy mine
	assert(memcmp(&t, &g, sizeof(struct gameState)) == 0); // game state match
	
	g.supplyCount[mine]--; // player 2 not initialized until first turn
	g.hand[1][0] = mine;
	g.handCount[1] = 1;
	assert(gainCard(mine, &t, 2, 1) == 0); // should buy mine
	assert(memcmp(&t, &g, sizeof(struct gameState)) == 0); // game state match
	
	printf("%s passed\n", testname);

	return 0;
}
