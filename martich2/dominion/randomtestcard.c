/*
 * randomtestadventurer.c
 *
 * Test of village
 *
 *  Created on: May 9, 2015
 *      Author: martich2
 */

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "dominion.h"
#include "dominion_helpers.h"

#define MAX_TESTS 10
// uncommentign this macro will highly likely cause the program to crash
//#define SEG_FAULT

/**
 * Prints a fail message or "passes" based on passed in expression.
 * @param expr  expression to evaluated. if false fail message is printed
 * @param msg   fail message to be displayed on failed test
 */
void test(int expr, char *msg);

int main()
{
    int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy };

    int i = 0, player = 0, players = 0, seed = 0;
    int the_test = 0, handCount = 0;
    int numActions = 0;
#ifdef SEG_FAULT
    int currentPlayer = 0, handPos = 0;
#endif
    struct gameState *aGame = NULL;

    srand(time(NULL));          // init libc random seed
    for (i = 0; i < MAX_TESTS; i++)
    {
        // set up game state
        aGame = newGame();          // allocate new memory
        seed = rand();              // any value will do
        players = (rand() % 3) + 2; // 2 to 4 players
        player = rand() % players;  // randomly pick a player to play

        initializeGame(players, k, seed, aGame);
        aGame->whoseTurn = player;  // set player as active player
        aGame->hand[player][0] = village;

        // set up player hand to between a minimum of 5 and max hand;
        do
        {
            handCount = rand() % (MAX_HAND + 1);
        }
        while( (handCount < 5));
        aGame->handCount[player] = handCount;

#ifdef SEG_FAULT
        currentPlayer = rand();
        handPos = rand();
#endif
        printf("Test %d: ", i);
#ifdef SEG_FAULT
        if (currentPlayer > player)
            fprintf(stderr, "current player out of bounds, likely seg fault...\n");
        if (handPos > handCount)
            fprintf(stderr, "hand position out of bounds, likely seg fault...\n");
#endif
        numActions = aGame->numActions;
#ifdef SEG_FAULT
        villageEffect(currentPlayer, aGame, handPos);
#endif
        villageEffect(player, aGame, 0);

        the_test = (handCount == aGame->handCount[player]);
        printf("drew a card, discarded a card...");
        test(the_test, "hand size changed incorrectly");

        the_test = ((numActions + 2) == aGame->numActions);
        printf("...actions increased by two...");
        test(the_test, "number actions did not change by two.");

        printf("\n");

        //clean up
        free(aGame);
        player = 0, players = 0; seed = 0; the_test = 0, numActions = 0;
        handCount = 0;
    }

    return EXIT_SUCCESS;
}

void test(int expr, char *msg)
{
    if (!expr)
    {
        printf("FAILES: %s", msg);
    }
    else
    {
        printf("passes");
    }
}
