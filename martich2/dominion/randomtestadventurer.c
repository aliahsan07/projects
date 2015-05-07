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
//#include "rngs.h" ?

#define MAX_TESTS 4

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
        srand(time(NULL));
        players = (rand() % 3) + 2; // 2 to 4 players
        player = rand() % players;  // randomly pick a player to play
        seed = rand();              // any value will do
        aGame = newGame();          // allocate new memory
        initializeGame(players, k, seed, aGame);

        // set up player hand to minimum 5 and less than max;
        do { handCount = rand(); } while((handCount < MAX_HAND) && (handCount >= 5));
        aGame->handCount[player] = handCount;

        // set up player deck
        deckCount = rand();         // deck size at minimum 10;
        do { deckCount = rand(); } while((deckCount < MAX_DECK) && (deckCount >= 10));
        aGame->deckCount[player] = deckCount;

        // fill hand with random cards
        for (card = 0; card < handCount; card++)
        {
            aGame->hand[player][card] = rand() % NUMBER_OF_CARDS;
        }


        // run tests
        cardEffect(adventurer, 0, 0, 0, aGame, 0, NULL);
        //assert ...


        //clean up
        free(aGame);
        players = 0;
        seed = 0;
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
