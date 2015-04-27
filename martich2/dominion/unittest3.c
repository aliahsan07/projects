/*
 * unittest3.c
 *
 * test of int updateCoins(int player, struct gameState *state, int bonus)
 * in dominion.c
 *
 *  Created on: Apr 22, 2015
 *      Author: martich2
 */
#include <stdio.h>
#include <assert.h>
#include "dominion.h"


/* prototype here to allow compiling, no linker errors/warnings */
int updateCoins(int player, struct gameState *state, int bonus);

int main(int argc, char** argv)
{
    /* updateCoins only reads handCount and hand; all other fields can be uninitialized. */
    struct gameState *aGame = newGame();
    aGame->handCount[0] = 5;

    // Test 1
    // give player0 2 copper, 2 silver, 1 gold.
    aGame->hand[0][0] = copper; aGame->hand[0][1] = copper;
    aGame->hand[0][2] = silver; aGame->hand[0][3] = silver;
    aGame->hand[0][4] = gold;

    printf("Test 1: player0 has 9 coins...");
    updateCoins(0, aGame, 0);
    assert(aGame->coins == 9);
    printf("passes\n");

    // Test 2
    // give player0 2 copper, 2 silver, 1 gold and a bonus.
    printf("Test 2: player0 has 10 coins...");
    updateCoins(0, aGame, 1);
    assert(aGame->coins == 10);
    printf("passes\n");

    // Test 3
    // give player0 2 copper, 2 silver, 1 gold and -10 bonus. invalid game state
    printf("Test 3: player0 has -1 coins...");
    updateCoins(0, aGame, -10);
    assert(aGame->coins == -1);
    printf("passes\n");

    // Test 4
    //call updateCoin on player 7, who does not exist, but has 0 coins.
    printf("Test 4: player7 has 0 coins...");
    updateCoins(7, aGame, 0);
    assert(aGame->coins == 0);
    printf("passes\n");

    // Test 4
    /* set game state struct to null. will cause seg fault */
    printf("Test 6: null game state, invalid state, will seg fault\n");
    aGame = NULL;
    updateCoins(0, aGame, 0);

    return 0;
}
