/*
 *  unittest4.c
 *
 *  Created on: April 22, 2015
 *      Author: Spencer Hubbard
 *
 *  This is a unit test for the fullDeckCount function. According to the
 *  specification, fullDeckCount accepts a player, a card, and a gameState as
 *  parameters and returns the sum of the cards in the given players hand,
 *  discard, and deck.
 *
 *  Aside: It is unclear what the card parameter is used for.
 */

#include "dominion.h"
#include "rngs.h"
#include "Verify362.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void helper(int player, int handCount, int deckCount, int discardCount, struct gameState *state);

int main(int argc, char **argv) {
  struct gameState state;

  // check deck for all counts > 0
  helper(0, 5, 6, 2, &state);

  // check deck for one count = 0
  helper(0, 5, 6, 0, &state);
  helper(0, 5, 0, 2, &state);
  helper(0, 0, 6, 2, &state);

  // check deck for two counts = 0
  helper(0, 5, 0, 0, &state);
  helper(0, 0, 0, 2, &state);
  helper(0, 0, 6, 0, &state);

  // check deck for all counts = 0
  helper(0, 0, 0, 0, &state);

  printf("unit test for fullDeckCount function passed\n");

  return EXIT_SUCCESS;
}

void helper(int player, int handCount, int deckCount, int discardCount, struct gameState *state) {
  state->handCount[player] = handCount;
  state->deckCount[player] = deckCount;
  state->discardCount[player] = discardCount;
  int total = handCount + deckCount + discardCount;
  Verify362(total == fullDeckCount(player, 0, state));
}
