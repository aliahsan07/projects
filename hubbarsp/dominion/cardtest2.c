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

#include "dominion.h"
#include "rngs.h"
#include "Verify362.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char **argv) {
  // initial setup
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};
  int numPlayers = 2;
  int randomSeed = 42;
  struct gameState state;
  initializeGame(numPlayers, kingdomCards, randomSeed, &state);
  int whoseTurn = state.whoseTurn;

  // make sure phase = 0, numActions > 0, handCount > 1
  state.phase = 0;
  state.numActions = state.numActions > 0 ? state.numActions : 1;
  state.handCount[whoseTurn] = state.handCount[whoseTurn] > 0 ? state.handCount[whoseTurn] : 1;

  // before test
  state.hand[whoseTurn][0] = mine;
  state.hand[whoseTurn][1] = copper;
  int coins = state.coins;
  int handCount = state.handCount[whoseTurn];
  int playedCardCount = state.playedCardCount;

  // should not be allowed to buy treasure card costing > 3 more
  // don't check return value of playCard because not unit test for playCard
  playCard(0, 1, gold, 0, &state);

  // after test
  Verify362(whoseTurn == state.whoseTurn);
  Verify362(coins == state.coins);
  Verify362(handCount - 2 + 1 == state.handCount[whoseTurn]);
  printf("unit test for mine card passed\n");

  return EXIT_SUCCESS;
}