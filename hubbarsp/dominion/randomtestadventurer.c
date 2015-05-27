/*
 *  randomtestadventurer.c
 *
 *  Created on: May 2, 2015
 *      Author: Spencer Hubbard
 *
 *  This is a random test generator for the adventurer card.
 */

#include <assert.h>  // for assert()
#include <stdbool.h> // for bool type (true, false)
#include <stdio.h>   // for NULL, printf()
#include <stdlib.h>  // for malloc(), free(), exit(), rand(), srand()
#include <time.h>    // for time()

#include "dominion.h"
#include "rngs.h"
#include "Verify362.h"

#define RANDOM_SEED 42
#define MAX_TESTS 100
#define MIN_PLAYERS 2
#define NUM_TREASURE 2

static int kingdom_cards[10] = {adventurer, council_room, feast, gardens, mine,
    remodel, smithy, village, baron, great_hall};

// TODO: comment
static void helper(int cards[], int numCard, int numTreasure);

static void helper(int cards[], int numCard, int numTreasure) {
  if (numCard > 0) {
    // fill with kingdom cards
    for (int i = 0; i < numCard; i++) {
      cards[i] = kingdom_cards[rand() % 10];
    }
    // place treasure cards
    for (int i = 0; i < numTreasure; i++) {
      cards[rand() % numCard] = copper;
    }
  }
}

int main(int argc, char **argv) {
  /*
  unsigned int seed = (unsigned int) time(NULL);
  srand(seed);
  printf("begin random test for adventure card (seed = %d)\n", seed);
  */
  srand(RANDOM_SEED);
  
  for (int i = 0; i < MAX_TESTS; i++) {
    // initial setup
    struct gameState state;
    int randomSeed = rand();
    int numPlayers = rand() % (MAX_PLAYERS - MIN_PLAYERS + 1) + MIN_PLAYERS;
    initializeGame(numPlayers, kingdom_cards, randomSeed, &state);
    int whoseTurn = state.whoseTurn;

    // make sure phase = 0, numActions > 0, handCount > 0
    state.phase = 0;
    state.numActions = state.numActions > 0 ? state.numActions : 1;
    state.handCount[whoseTurn] = state.handCount[whoseTurn] > 0 ? state.handCount[whoseTurn] : 1;
    state.hand[whoseTurn][0] = adventurer;

    // pick random number of cards and split cards between deck and discard
    int numCard = rand() % (MAX_DECK - NUM_TREASURE + 1) + NUM_TREASURE;
    int splitTreasure = rand() % (NUM_TREASURE + 1);
    int splitCard = rand() % (numCard - splitTreasure + 1) + splitTreasure;
    state.deckCount[whoseTurn] = splitCard;
    state.discardCount[whoseTurn] = numCard - splitCard;
    helper(state.deck[whoseTurn], state.deckCount[whoseTurn], splitTreasure);
    helper(state.discard[whoseTurn], state.discardCount[whoseTurn], NUM_TREASURE - splitTreasure);
    
    // expected state after test
    int coins = state.coins + NUM_TREASURE;

    // should shuffle deck and discard if < 2 treasure cards are revealed before
    // deck is empty
    // don't check return value of playCard because not unit test for playCard
    playCard(0, 0, 0, 0, &state);

    // test state after card effect
    Verify362(whoseTurn == state.whoseTurn);
    Verify362(coins == state.coins);
  }

  printf("random test for adventure card passed\n");

  return EXIT_SUCCESS;
}
