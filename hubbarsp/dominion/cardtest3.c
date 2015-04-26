/*
 *  cardtest3.c
 *
 *  Created on: April 22, 2015
 *      Author: Spencer Hubbard
 *
 *  This is a card test that checks the effect of the village card. The village
 *  cards effect is +2 action and +1 card.
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

  // make sure phase = 0, numActions > 0, handCount > 0
  state.phase = 0;
  state.numActions = state.numActions > 0 ? state.numActions : 1;
  state.deckCount[whoseTurn] = state.deckCount[whoseTurn] > 0 ? state.deckCount[whoseTurn] : 2;
  state.handCount[whoseTurn] = state.handCount[whoseTurn] > 0 ? state.handCount[whoseTurn] : 1;

  // before test
  state.hand[whoseTurn][0] = village;
  int numActions = state.numActions;
  int handCount = state.handCount[whoseTurn];
  int deckCount = state.deckCount[whoseTurn];
  int playedCardCount = state.playedCardCount;

  // should play 1 card, remove 1 card from deck and add to hand
  // should play 1 action and gain 2 action
  // don't check return value of playCard because not unit test for playCard
  printf("begin card test for village card\n");
  playCard(0, 0, 0, 0, &state);

  // after test
  Verify362(whoseTurn == state.whoseTurn);
  Verify362(handCount - 1 + 1 == state.handCount[whoseTurn]);
  Verify362(deckCount - 1 == state.deckCount[whoseTurn]);
  Verify362(numActions - 1 + 2 == state.numActions);
  printf("card test passed\n");

  return EXIT_SUCCESS;
}
