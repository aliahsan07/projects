/*
 *  Name: Spencer Hubbard
 *  Date: 5/4/15
 *  CS 362 Assignment 2
 *
 *  This is a card test that checks the effect of the adventurer card. The
 *  adventurer card effect is to reveal cards from your deck until 2 treasure
 *  cards are revealed, add the 2 treasure cards to your hand, and discard the
 *  other revealed cards.
 */

#include <stddef.h>  // for NULL, size_t
#include <stdbool.h> // for bool
#include <stdio.h>   // for printf()
#include <stdlib.h>  // for malloc(), free(), exit(), rand(), srand()

#include "dominion.h"
#include "rngs.h"
#include "CS362.h"

#define RANDOM_SEED 42
#define NUM_PLAYERS 2

static int kingdom_cards[10] = {adventurer, council_room, feast, gardens, mine,
    remodel, smithy, village, baron, great_hall};

int main(int argc, char **argv) {
  // initial setup
  struct gameState state;
  initializeGame(NUM_PLAYERS, kingdom_cards, RANDOM_SEED, &state);
  int whoseTurn = state.whoseTurn;

  // make sure phase = 0, numActions > 0, handCount > 0
  state.phase = 0;
  state.numActions = state.numActions > 0 ? state.numActions : 1;
  state.handCount[whoseTurn] = state.handCount[whoseTurn] > 0 ? state.handCount[whoseTurn] : 1;

  // record state before card effect
  state.hand[whoseTurn][0] = adventurer;
  state.discard[whoseTurn][0] = copper;
  state.discard[whoseTurn][1] = curse;
  state.discard[whoseTurn][2] = estate;
  state.discard[whoseTurn][3] = copper;
  state.deck[whoseTurn][0] = estate;
  state.deck[whoseTurn][1] = duchy;
  state.discardCount[whoseTurn] = 4;
  state.deckCount[whoseTurn] = 2;
  int coins = state.coins;

  // should shuffle deck and discard if < 2 treasure cards are revealed before
  // deck is empty
  // don't check return value of playCard because not unit test for playCard
  playCard(0, 0, 0, 0, &state);

  // test state after card effect
  Verify362(whoseTurn == state.whoseTurn);
  Verify362(coins + 2 == state.coins);

  printf("unit test for adventurer card passed\n");

  return EXIT_SUCCESS;
}
