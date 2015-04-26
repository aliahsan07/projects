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

#include "dominion.h"
#include "rngs.h"
#include "Verify362.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char **argv) {
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
      remodel, smithy, village, baron, great_hall};
  int randomSeed = 42;
  struct gameState state;

  printf("begin unit test for initializeGame function\n");

  // number of players should not be < 0
  Verify362(0 > initializeGame(-2, kingdomCards, randomSeed, &state));
  Verify362(0 > initializeGame(-1, kingdomCards, randomSeed, &state));

  // number of players should not be 0
  Verify362(0 > initializeGame(0, kingdomCards, randomSeed, &state));

  // number of players should not be 1
  Verify362(0 > initializeGame(1, kingdomCards, randomSeed, &state));

  // number of players should be > 1
  Verify362(0 == initializeGame(2, kingdomCards, randomSeed, &state));
  Verify362(0 == initializeGame(3, kingdomCards, randomSeed, &state));

  printf("unit test passed\n");

  return EXIT_SUCCESS;
}
