/*
 * randomtestadventurer.c
 *
 * Test of adventurer
 *
 *  Created on: May 5, 2015
 *      Author: martich2
 */
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"

#define MAX_TESTS 100

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

    int i = 0, card = 0, player = 0, players = 0, seed = 0;
    int handCount = 0, deckCount = 0;
    struct gameState *aGame = NULL;

    for (i = 0; i < MAX_TESTS; i++)
    {
        // set up game state
        aGame = newGame();          // allocate new memory
        srand(time(NULL));          // init libc random seed
        seed = rand();              // any value will do
        players = (rand() % 3) + 2; // 2 to 4 players
        player = rand() % players;  // randomly pick a player to play
        initializeGame(players, k, seed, aGame);
        aGame->whoseTurn = player;  // set player asss active player

        // set up player hand to between a minimum of 5 and max hand;
        do
        {
            handCount = rand() % (MAX_HAND + 1);
        }
        while( (handCount < 5));
        aGame->handCount[player] = handCount;

        // set up player deck deck size at minimum 10;
        do
        {
            deckCount = rand() % (MAX_DECK + 1);
        }
        while(deckCount < 10);
        aGame->deckCount[player] = deckCount;

        // set first in hand card to be adventurer
        aGame->hand[player][0] = adventurer;

        // fill hand with random cards
        for (card = 1; card < handCount; card++)
        {
            aGame->hand[player][card] = rand() % NUMBER_OF_CARDS;
        }

        // fill deck with random cards
        for (card = 0; card < deckCount; card++)
        {
            aGame->deck[player][card] = rand() % NUMBER_OF_CARDS;
        }

        // run tests
        cardEffect(adventurer, 0, 0, 0, aGame, 0, NULL);
        //assert ... ?


        //clean up
        free(aGame);
        player = 0, players = 0, seed = 0, handCount = 0, deckCount = 0;
    }

    return 0;
}

void test(int expr, char *msg)
{
    if (!expr)
    {
        printf("Test FAIL:%s\n", msg);
    }
    else
    {
        printf("passes.\n");
    }
}
