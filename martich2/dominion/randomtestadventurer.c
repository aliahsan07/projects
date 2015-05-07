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

#include "dominion.h"
#include "dominion_helpers.h"

#define MAX_TESTS 200

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
    int the_test = 0, handCount = 0, deckCount = 0, discardCount = 0;
    int tmpCard = 0, treasureCount = 0;
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

        // set up player hand to between a minimum of 5 and max hand;
        do
        {
            handCount = rand() % (MAX_HAND + 1);
        }
        while( (handCount < 5));
        aGame->handCount[player] = handCount;

        // set up player deck deck size at minimum 10;
        /* !! SEG FAULT if deck is 0 !! */
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

        // are there two treasure cards in deck?
        for (card = 0; card < deckCount; card++)
        {
            tmpCard = aGame->deck[player][card];
            if (tmpCard == gold || tmpCard == silver ||tmpCard == copper)
                treasureCount++;

            if (treasureCount >= 2) break;
        }

        printf("Test %d: ", i);

        // run a different tests based on the number of treasure cards in deck
        if (treasureCount >= 2)
        {
            discardCount = aGame->discardCount[player];
            cardEffect(adventurer, 0, 0, 0, aGame, 0, NULL);

            // adventurer draws two treasure cards
            the_test = (handCount + 2 == aGame->handCount[player]);
            printf("Two Treasure cards drawn...");
            test(the_test, "Did not draw two cards");
        }
        else if (treasureCount == 1)
        {
            cardEffect(adventurer, 0, 0, 0, aGame, 0, NULL);
            the_test = (handCount + 1 == aGame->handCount[player]);
            printf("One Treasure cards drawn...");
            test(the_test, "Did not draw two cards");
        }
        else
        {
            printf("Zero treasure cards drawn...");
            the_test = (handCount == aGame->handCount[player]);
            cardEffect(adventurer, 0, 0, 0, aGame, 0, NULL);
            test(the_test, "Hand size changed when it should not");
        }

        // adventurer discards drawn cards that are not treasure
        // if the one treasure card is the first card in the deck, no discarding
        the_test = (discardCount <= aGame->discardCount[player]);
        printf(" ... Discard pile grew or unchanged ...");
        test(the_test, "Did not discard any cards");

        printf("\n");

        //clean up
        free(aGame);
        player = 0, players = 0, seed = 0, handCount = 0, deckCount = 0;
        the_test = 0, treasureCount = 0, tmpCard = 0;
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
