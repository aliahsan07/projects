/*
 *  unittest3.c
 *
 *  Created on: April 22, 2015
 *      Author: Spencer Hubbard
 *
 *  This is a unit test for the handCard function. According to the
 *  specification, handCard accepts a card position and gameState as parameters
 *  and returns the card at the given index in a player's hand. This unit
 *  test checks if the return card is the card at the given position when the
 *  card is in the players hand and fails when the card is not in the players
 *  hand.
 */

#include "dominion.h"
#include "rngs.h"
#include "Verify362.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char **argv) {
  struct gameState state;
  state.whoseTurn = 0;
  state.hand[0][0] = curse;
  state.hand[0][1] = copper;
  state.hand[0][2] = adventurer;
  state.hand[0][3] = baron;
  state.hand[0][4] = ambassador;

  // check hand for count > 1
  state.handCount[0] = 5;
  Verify362(curse == handCard(0, &state));
  Verify362(adventurer == handCard(2, &state));
  Verify362(ambassador == handCard(4, &state));

  // check hand for count = 1
  state.handCount[0] = 1;
  Verify362(curse == handCard(0, &state));

  // should not return card not in hand
  state.handCount[0] = 3;
  Verify362(0 > handCard(3, &state));
  Verify362(0 > handCard(4, &state));

  printf("unit test for handCard function passed\n");

  return EXIT_SUCCESS;
}
