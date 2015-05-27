/*
 *  unittest1.c
 *
 *  Created on: April 22, 2015
 *      Author: Spencer Hubbard
 *
 *  This is a unit test for the initializeGame function. According to the
 *  specification, initializeGame accepts a number of players, an array of
 *  kingdom cards, a random seed, and game state return parameter as parameters;
 *  it initializes all supplies, shuffles decks, and draws a starting hands for
 *  all players, and returns -1 if it fails (and does not change game state),
 *  otherwise it returns 0. This unit test checks that initializeGame fails if
 *  the the number of players is < 2 and passes if the number of players is > 1.
 */

#include <assert.h>  // for assert()
#include <stdbool.h> // for bool type (true, false)
#include <stdio.h>   // for NULL, printf()
#include <stdlib.h>  // for malloc(), free(), exit(), rand(), srand()

#include "dominion.h"
#include "rngs.h"
#include "Verify362.h"

#define RANDOM_SEED 42

static int kingdom_cards[10] = {adventurer, council_room, feast, gardens, mine,
    remodel, smithy, village, baron, great_hall};

int main(int argc, char **argv) {
  struct gameState state;

  // number of players should not be < 0
  Verify362(0 > initializeGame(-2, kingdom_cards, RANDOM_SEED, &state));
  Verify362(0 > initializeGame(-1, kingdom_cards, RANDOM_SEED, &state));

  // number of players should not be 0
  Verify362(0 > initializeGame(0, kingdom_cards, RANDOM_SEED, &state));

  // number of players should not be 1
  Verify362(0 > initializeGame(1, kingdom_cards, RANDOM_SEED, &state));

  // number of players should be > 1
  Verify362(0 == initializeGame(2, kingdom_cards, RANDOM_SEED, &state));
  Verify362(0 == initializeGame(3, kingdom_cards, RANDOM_SEED, &state));

  printf("unit test for initializeGame function passed\n");

  return EXIT_SUCCESS;
}
