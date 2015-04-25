/*
 * unittest3.c
 *
 * test of int fullDeckCount(int player, int card, struct gameState *state)
 * in dominion.c
 *
 *  Created on: Apr 22, 2015
 *      Author: martich2
 */
#include <stdio.h>
#include <assert.h>

/* prototype here to allow compiling, no linker errors/warnings */
int fullDeckCount(int player, int card, struct gameState *state);

int main(int argc, char** argv)
{
    /* isGameOver only checks supplyCount, all other fields can be uninitialized */
    struct gameState *aGame = newGame();
    aGame->supplyCount[0] = 1;

    printf("Hello World!\n");


	return 0;
}
