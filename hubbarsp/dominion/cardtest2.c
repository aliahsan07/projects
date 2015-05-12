/*
 *  cardtest2.c
 *
 *  Created on: April 22, 2015
 *      Author: Spencer Hubbard
 *
 *  This is a card test that checks the effect of the mine card. The mine card
 *  effect is to trash a treasure card from your hand and add a treasure card
 *  costing up to 3 more to your hand.
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

  // make sure phase = 0, numActions > 0, handCount > 1
  state.phase = 0;
  state.numActions = state.numActions > 0 ? state.numActions : 1;
  state.handCount[whoseTurn] = state.handCount[whoseTurn] > 1 ? state.handCount[whoseTurn] : 2;

  // record state before card effect
  state.hand[whoseTurn][0] = mine;
  state.hand[whoseTurn][1] = copper;
  int coins = state.coins;
  int handCount = state.handCount[whoseTurn];
  int playedCardCount = state.playedCardCount;

  // should not be allowed to buy treasure card costing > 3 more
  // don't check return value of playCard because not unit test for playCard
  playCard(0, 1, gold, 0, &state);

  // test state after card effect
  Verify362(whoseTurn == state.whoseTurn);
  Verify362(coins == state.coins);
  //Verify362(handCount == state.handCount[whoseTurn]);
  //Verify362(playedCardCount == state.playedCardCount);

  printf("unit test for mine card passed\n");

  return EXIT_SUCCESS;
}
