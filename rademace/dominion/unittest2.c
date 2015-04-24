/*
 * unittest2.c
 *
 *  Created on: Apr 20, 2015
 *      Author: Elias
 */
 
#include "dominion.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "rngs.h"

#define TEST_INT INT_MAX
#define NUM_PLAYERS 5

int main(int argc, char** argv) {
	
	int* i;
	int j;
	struct gameState* g;
	g = newGame();
	
	assert(g != NULL);
	
	g->numPlayers = NUM_PLAYERS;
	assert(NUM_PLAYERS == g->numPlayers);
	
	for (j = 0, i = (int*) g; j < sizeof(struct gameState) / sizeof(int); j++, i++) {
		*i = TEST_INT;
	}
	
	for (j = 0, i = (int*) g; j < sizeof(struct gameState) / sizeof(int); j++, i++) {
		assert(*i == TEST_INT);
	}
	
	free(g);
	
	printf("newGame() passed all tests\n");
		
    return 1;	
}