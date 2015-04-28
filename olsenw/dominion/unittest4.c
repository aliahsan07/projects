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

char testname[] = "unittest4";

// handCard

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
	g.hand[0][0] = copper;
	g.hand[0][1] = silver;
	g.hand[0][2] = gold;
	g.hand[0][3] = adventurer;
	g.hand[0][4] = estate;
	g.hand[1][0] = outpost;
	t = g;
	
	assert(handCard(0, &t) == copper); // first card in hand
	assert(memcmp(&t, &g, sizeof(struct gameState)) == 0);
	
	assert(handCard(4, &t) == estate); // last card in hand
	assert(memcmp(&t, &g, sizeof(struct gameState)) == 0);
	
	assert(handCard(MAX_HAND, &t) == outpost); // player one hand...?
	assert(memcmp(&t, &g, sizeof(struct gameState)) == 0);
	
	printf("%s passed\n", testname);

	return 0;
}
