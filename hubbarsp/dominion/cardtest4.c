/*
 *  cardtest4.c
 *
 *  Created on: April 22, 2015
 *      Author: Spencer Hubbard
 *
 *  This is a card test that checks the effect of the adventurer card. The
 *  adventurer card effect is to reveal cards from your deck until 2 treasure
 *  cards are revealed, add the 2 treasure cards to your hand, and discard the
 *  other revealed cards.
 */

#include "dominion.h"
#include "rngs.h"
#include "Verify362.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void debug(struct gameState *state) {
  printf("***debugging information for gameState***\n");
  printf("numPlayers     :\t%d\n", state->numPlayers);
  printf("whoseTurn      :\t%d\n", state->whoseTurn);
  printf("phase          :\t%d\n", state->phase);
  printf("numActions     :\t%d\n", state->numActions);
  printf("numBuys        :\t%d\n", state->numBuys);
  printf("coins          :\t%d\n", state->coins);
  printf("deckCount      :\t%d\n", state->deckCount[state->whoseTurn]);
  printf("handCount      :\t%d\n", state->handCount[state->whoseTurn]);
  printf("discardCount   :\t%d\n", state->discardCount[state->whoseTurn]);
  printf("playedCardCount:\t%d\n", state->playedCardCount);
}

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
  state.handCount[whoseTurn] = state.handCount[whoseTurn] > 0 ? state.handCount[whoseTurn] : 1;

  // before test
  state.hand[whoseTurn][0] = adventurer;
  state.discard[whoseTurn][0] = copper;
  state.discard[whoseTurn][1] = curse;
  state.discard[whoseTurn][2] = estate;
  state.discard[whoseTurn][3] = copper;
  state.deck[whoseTurn][0] = estate;
  state.deck[whoseTurn][1] = duchy;
  state.discardCount[whoseTurn] = 4;
  state.deckCount[whoseTurn] = 2;
  int coins = state.coins;

  // should shuffle deck and discard if < 2 treasure cards are revealed before
  // deck is empty
  // don't check return value of playCard because not unit test for playCard
  printf("begin card test for adventurer card\n");
  playCard(0, 0, 0, 0, &state);

  // after test
  Verify362(whoseTurn == state.whoseTurn);
  Verify362(coins + 2 == state.coins);

  printf("card test passed\n");

  return EXIT_SUCCESS;
}
