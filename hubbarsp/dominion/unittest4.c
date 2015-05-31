/*
 *  Name: Spencer Hubbard
 *  Date: 4/23/15
 *  CS 362 Assignment 2
 *
 *  This is a unit test for the fullDeckCount function. According to the
 *  specification, fullDeckCount accepts a player, a card, and a gameState as
 *  parameters and returns the sum of the cards in the given players hand,
 *  discard, and deck.
 *
 *  Aside: It is unclear what the card parameter is used for.
 */

#include <stddef.h>  // for NULL, size_t
#include <stdbool.h> // for bool
#include <stdio.h>   // for printf()
#include <stdlib.h>  // for malloc(), free(), exit(), rand(), srand()

#include "dominion.h"
#include "rngs.h"
#include "CS362.h"

// TODO: comment
static void helper(int player, int handCount, int deckCount, int discardCount, struct gameState *state);

static void helper(int player, int handCount, int deckCount, int discardCount, struct gameState *state) {
  state->handCount[player] = handCount;
  state->deckCount[player] = deckCount;
  state->discardCount[player] = discardCount;
  int total = handCount + deckCount + discardCount;
  Verify362(total == fullDeckCount(player, 0, state));
}

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
