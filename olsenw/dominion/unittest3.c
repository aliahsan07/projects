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

char testname[] = "unittest3";

// updateCoins

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
	g.hand[1][0] = copper;
	g.hand[1][1] = copper;
	g.hand[1][2] = silver;
	g.hand[1][3] = silver;
	g.hand[1][4] = gold;
	g.handCount[1] = 5;
	t = g;

	assert(updateCoins(1, &t, 0) == 0); // should have coins
	g.coins = 9;
	assert(memcmp(&t, &g, sizeof(struct gameState)) == 0); // game state match

	assert(updateCoins(1, &t, 3) == 0); // should have coins
	g.coins = 12;
	assert(memcmp(&t, &g, sizeof(struct gameState)) == 0);
	
	assert(updateCoins(1, &t, -3) == 0); // should have coins
	g.coins = 6;
	assert(memcmp(&t, &g, sizeof(struct gameState)) == 0);

	printf("%s passed\n", testname);

	return 0;
}
