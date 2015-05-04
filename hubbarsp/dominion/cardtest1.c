/*
 *  cardtest1.c
 *
 *  Created on: April 22, 2015
 *      Author: Spencer Hubbard
 *
 *  This is a card test that checks the effect of the smithy card. The smithy
 *  card effect is +3 cards.
 */

#include <assert.h>  // for assert()
#include <stdbool.h> // for bool type (true, false)
#include <stdio.h>   // for NULL, printf()
#include <stdlib.h>  // for malloc(), free(), exit(), rand(), srand()

#include "dominion.h"
#include "rngs.h"
#include "Verify362.h"

#define RANDOM_SEED 42
#define NUM_PLAYERS 2

static int kingdom_cards[10] = {adventurer, council_room, feast, gardens, mine,
    remodel, smithy, village, baron, great_hall};

int main(int argc, char **argv) {
  // initial setup
  struct gameState state;
  initializeGame(NUM_PLAYERS, kingdom_cards, RANDOM_SEED, &state);
  int whoseTurn = state.whoseTurn;

  // make sure phase = 0, numActions > 0, and deckCount > 3, handCount > 0
  state.phase = 0;
  state.numActions = state.numActions > 0 ? state.numActions : 1;
  state.deckCount[whoseTurn] = state.deckCount[whoseTurn] > 3 ? state.deckCount[whoseTurn] : 4;
  state.handCount[whoseTurn] = state.handCount[whoseTurn] > 0 ? state.handCount[whoseTurn] : 1;

  // record state before card effect
  state.hand[whoseTurn][0] = smithy;
  int handCount = state.handCount[whoseTurn];
  int deckCount = state.deckCount[whoseTurn];
  int playedCardCount = state.playedCardCount;

  // should play 1 card, remove 3 cards from deck and add to hand
  // don't check return value of playCard because not unit test for playCard
  playCard(0, 0, 0, 0, &state);

  // test state after card effect
  Verify362(whoseTurn == state.whoseTurn);
  Verify362(handCount + 3 - 1 == state.handCount[whoseTurn]);
  Verify362(deckCount - 3 == state.deckCount[whoseTurn]);
  Verify362(playedCardCount + 1 == state.playedCardCount);

  printf("unit test for smithy card passed\n");

  return EXIT_SUCCESS;
}
