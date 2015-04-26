/*
 *  unittest2.c
 *
 *  Created on: April 22, 2015
 *      Author: Spencer Hubbard
 *
 *  This is a unit test for the numHandCards function. According to the
 *  specification, numHandCards accepts a game state as a parameter and returns
 *  the number of cards current player has in his or her hand.
 */

#include "dominion.h"
#include "rngs.h"
#include "Verify362.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void helper(int whoseTurn, int handCount, struct gameState *state);

int main(int argc, char **argv) {
  struct gameState state;

  printf("begin unit test for numHandCards function\n");

  // check hand count > 0
  helper(0, 5, &state);
  helper(0, 1, &state);

  // check hand count = 0
  helper(0, 0, &state);

  printf("unit test passed\n");

  return EXIT_SUCCESS;
}

void helper(int whoseTurn, int handCount, struct gameState *state) {
  state->whoseTurn = whoseTurn;
  state->handCount[whoseTurn] = handCount;
  Verify362(handCount == numHandCards(state));
}
