#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState G;
	int i;

	G.supplyCount[province] = 0;

	int gameOver = isGameOver(&G);
	assert(gameOver == 1);

	printf("Test passes: game is over when no provinces remaining\n");

	G.supplyCount[province] = 1;

	for (i = 0; i < 3; i++)
	{
		G.supplyCount[i] = 0;

	}

	for (i = 3; i < 25; i++)
	{
		G.supplyCount[i] = 1;

	}

	gameOver = isGameOver(&G);
	assert(gameOver == 1);

	printf("Test passes: game is over when 3 or more supplies are 0\n");

	for (i = 0; i < 2; i++)
	{
		G.supplyCount[i] = 0;

	}

	for (i = 2; i < 25; i++)
	{
		G.supplyCount[i] = 1;

	}

	gameOver = isGameOver(&G);
	assert(gameOver == 0);

	printf("Test passes: game continues when fewer than 3 supplies are 0\n");

	return 0;


}


