#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int main (int argc, char** argv) {

	printf("***Testing isgameOver***\n");
	struct gameState G;
	int i;

	printf("Setting game so no provinces remain...\n");
	G.supplyCount[province] = 0;
	int gameOver = isGameOver(&G);
	assert(gameOver == 1);
	printf("Test passes, gameOver is %d\n", gameOver);

	printf("Setting game so 1 province remains and 3 supplies are 0...\n");
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
	printf("Test passes, gameOver is %d\n", gameOver);

	printf("Setting game so 1 province remains and only 2 supplies are 0...\n");
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
	printf("Test passes, gameOver is %d\n", gameOver);


	//gameOver = isGameOver(NULL);

	return 0;

}


