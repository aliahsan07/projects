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

char testname[] = "unittest1";

// tests the isGameOver function

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
	
	memset(&g, 0, sizeof(struct gameState));
	memset(&t, 0, sizeof(struct gameState));

	initializeGame(numplayer, cards, randseed, &g);	
	g.supplyCount[province] = 0;
	t = g;
	
	assert(isGameOver(&t) == 1); // should be over run out of province cards
	assert(memcmp(&t, &g, sizeof(struct gameState)) == 0); // game state altered
	
	initializeGame(numplayer, cards, randseed, &g);
	g.supplyCount[estate] = 0;
	g.supplyCount[duchy] = 0;
	g.supplyCount[gold] = 0;	
	t = g;
	assert(isGameOver(&t) == 1); // should be over 3 supplies empty
	assert(memcmp(&t, &g, sizeof(struct gameState)) == 0); // game state altered
	
	printf("%s passed\n", testname);

	return 0;
}