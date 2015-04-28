/*
 * unittest2.c
 *
 * test of int isGameOver(struct gameState *state) in dominion.c
 *
 *  Created on: Apr 22, 2015
 *      Author: martich2
 */

#include <stdio.h>
#include <assert.h>
#include "dominion.h"

/* prototype here to allow compiling, no linker errors/warnings */
int isGameOver(struct gameState *state);

int main(int argc, char** argv)
{
    int card;
    int result;

    // Test 1
    /* isGameOver only checks supplyCount, all other fields can be uninitialized */
    // after newGame() supplyCount all 0, game over.
    struct gameState *aGame = newGame();
    printf("Test 1: card count uninitialized. Invalid game state, and game is over...");
    result = isGameOver(aGame);
    assert(result == 1);
    printf("passes\n");

    // Test 2
    /* populate supplyCount with valid values */
    for (card = curse; card <= great_hall; card++)
    {
        aGame->supplyCount[card] = 10;
    }

    /* set all unused card to count of -1  */
    for (; card <= treasure_map; card++)
    {
        aGame->supplyCount[card] = -1;
    }

    /* 17 cards count are 10 and rest are -1. Normal game state, game not over. */
    printf("Test 2: 17 cards is count 10, the rest are count -1. Game not over...");
    result = isGameOver(aGame);
    assert(result == 0);
    printf(" passes\n");

    // Test 3
    /* set all card count to 10, invalid game state, but game not over */
    for (card = great_hall + 1; card <= treasure_map; card++)
    {
        aGame->supplyCount[card] = 10;
    }
    printf("Test 3: all cards are count 10. Invalid game state, but game not over...");
    result = isGameOver(aGame);
    assert(result == 0);
    printf("passes\n");

    // Test 4
    /* set all cards count to 0. Invalid games state and game is over */
    for (card = curse; card <= treasure_map; card++)
    {
        aGame->supplyCount[card] = 0;
    }
    printf("Test 4: all cards are count 0. Invalid game state, and game is over...");
    result = isGameOver(aGame);
    assert(result == 1);
    printf("passes\n");

    // Test 5
    /* set all cards count to -1. Invalid games state and game not over */
    for (card = curse; card <= treasure_map; card++)
    {
        aGame->supplyCount[card] = -1;
    }
    printf("Test 5: all cards are count -1. Invalid game state, and game not over...");
    result = isGameOver(aGame);
    assert(result == 0);
    printf("passes\n");

    // Test 6 commented out so scripts will run
    /* set game state struct to null. will cause seg fault */
//    printf("Test 6: null game state, invalid state, will seg fault\n");
//    aGame = NULL;
//    result = isGameOver(aGame);

    return 0;
}
