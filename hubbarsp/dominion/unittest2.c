/*
 *  Name: Spencer Hubbard
 *  Date: 4/23/15
 *  CS 362 Assignment 2
 *
 *  This is a unit test for the numHandCards function. According to the
 *  specification, numHandCards accepts a game state as a parameter and returns
 *  the number of cards current player has in his or her hand.
 */

#include <stddef.h>  // for NULL, size_t
#include <stdbool.h> // for bool
#include <stdio.h>   // for printf()
#include <stdlib.h>  // for malloc(), free(), exit(), rand(), srand()

#include "dominion.h"
#include "rngs.h"
#include "CS362.h"

// TODO: comment
static void helper(int whoseTurn, int handCount, struct gameState *state);

static void helper(int whoseTurn, int handCount, struct gameState *state) {
  state->whoseTurn = whoseTurn;
  state->handCount[whoseTurn] = handCount;
  Verify362(handCount == numHandCards(state));
}

int main(int argc, char **argv) {
  struct gameState state;

  // check hand count > 0
  helper(0, 5, &state);
  helper(0, 1, &state);

  // check hand count = 0
  helper(0, 0, &state);

  printf("unit test for numHandCards function passed\n");

  return EXIT_SUCCESS;
}
