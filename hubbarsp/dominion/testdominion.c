/*
 *  Name: Spencer Hubbard
 *  Date: 5/21/15
 *  CS 362 Assignment 4
 *
 *  This is a random tester that plays a complete game of dominion.
 */

#include <stddef.h>  // for NULL, size_t
#include <stdbool.h> // for bool
#include <stdio.h>   // for printf()
#include <stdlib.h>  // for malloc(), free(), exit(), rand(), srand()
#include <string.h>  // for strcat()

#include "dominion.h"
#include "rngs.h"
#include "CS362.h"
#include "ll.h"

/* symbolic constants */

#define RANDOM_SEED 42
#define MIN_PLAYERS 2
#define NUM_KINGDOM_CARDS 10
#define NUM_CARDS_TO_BUY 8
#define NUM_CARDS_TO_PLAY 4
#define MAX_STR_LEN 100
#define FILE_NAME "gameResults.txt"

/* global variables */

/* function prototypes */

// post: return string representation of given array in return parameter
static void toString(int a[], int n, char *s);

// TODO: comment
static void debug(FILE *fp, struct gameState *oldState, struct gameState *newState);

// TODO: comment
static void recordTransitions(Node *queue);

// TODO: comment
static void recordResultsHelper(FILE *fp, struct gameState *state1, struct gameState *state2, char *play);

// TODO: comment
static void recordResult(Node **queue1, Node **queue2, struct gameState *state, char play[]);

// TODO: comment
static void recordResults(Node *queue1, Node *queue2);

// pre : NUM_KINGDOM_CARDS < treasure_map - adventurer
// post: makes random game
static void makeGame(Node **queue1, Node **queue2, struct gameState *state);

// post: returns number of coins from treasure cards in hand
static int countCoins(struct gameState *state);

// pre : card is smithy, mine, village, adventurer, silver, gold, duchy, or province
// post: returns cost of given card
static int cardToBuyCost(int card);

// post: returns smithy, mine, village, adventurer, silver, gold, duchy, or province
static int randomCardToBuy();

// post: returns smithy, mine, village, or adventurer
static int randomCardToPlay();

// pre : 0 <= len
// post: returns true if card is in cards, otherwise false
static bool hasCard(int cards[], int len, int card);

// pre : 0 <= len
// post: returns hand position of card if card is in cards, otherwise -1
static int findCard(int cards[], int len, int card);

// post: returns supply position of card to buy or -1 if couldn't find one
static int findCardToBuy(struct gameState *state);

// post: returns hand position of card to play or -1 if couldn't find one
static int findCardToPlay(struct gameState *state);

// TODO: comment
static void playTurn(Node **queue1, Node **queue2, struct gameState *state);

/* function definitions */

static void toString(int a[], int n, char *s) {
  if (n == 0) {
    strcat(s, "[]");
  } else {
    char tmp[MAX_STR_LEN];
    sprintf(tmp, "[%d", a[0]);
    strcat(s, tmp);
    for (int i = 1; i < n; i++) {
      sprintf(tmp, ", %d", a[i]);
      strcat(s, tmp);
    }
    strcat(s, "]");
  }
}

static void debug(FILE *fp, struct gameState *oldState, struct gameState *newState) {
  fprintf(fp, "\n***debugging information***\n");
  fprintf(fp, "whoseTurn       : %d -> %d\n", oldState->whoseTurn,  newState->whoseTurn);
  fprintf(fp, "phase           : %d -> %d\n", oldState->phase,  newState->phase);
  fprintf(fp, "numActions      : %d -> %d\n", oldState->numActions, newState->numActions);
  fprintf(fp, "numBuys         : %d -> %d\n", oldState->numBuys, newState->numBuys);
  fprintf(fp, "coins           : %d -> %d\n", oldState->coins, newState->coins);
  fprintf(fp, "playedCardCount : %d -> %d\n", oldState->playedCardCount, newState->playedCardCount);
  fprintf(fp, "handCount       : %d -> %d\n", oldState->handCount[oldState->whoseTurn], newState->handCount[newState->whoseTurn]);
  fprintf(fp, "deckCount       : %d -> %d\n", oldState->deckCount[oldState->whoseTurn], newState->deckCount[newState->whoseTurn]);
  fprintf(fp, "discardCount    : %d -> %d\n", oldState->discardCount[oldState->whoseTurn], newState->discardCount[newState->whoseTurn]);
  char tmp1[MAX_STR_LEN] = {'\0'};
  char tmp2[MAX_STR_LEN] = {'\0'};
  toString(oldState->hand[oldState->whoseTurn], oldState->handCount[oldState->whoseTurn], tmp1);
  toString(newState->hand[newState->whoseTurn], newState->handCount[newState->whoseTurn], tmp2);
  fprintf(fp, "old hand        : %s\n", tmp1);
  fprintf(fp, "new hand        : %s\n", tmp2);
}

static void recordTransitions(Node *queue) {
  FILE *fp = Fopen(FILE_NAME, "w");
  fprintf(fp, "***beginning of testdominon transitions***\n");

  // record states
  struct gameState *oldState = Dequeue(queue, &queue);
  while (queue != NULL && queue != NULL) {
    // record transition from old state to new state
    struct gameState *newState = Dequeue(queue, &queue);
    debug(fp, oldState, newState);

    // clean-up and update old state
    Free(oldState);
    oldState = newState;
  }

  fprintf(fp, "***end of testdominon transitions***\n");

  // clean-up old state and file
  Free(oldState);
  Fclose(fp);
}

static void recordResultsHelper(FILE *fp, struct gameState *state1, struct gameState *state2, char *play) {
  fprintf(fp, "***next play result***\n");
  fprintf(fp, "play            : %s\n", play);
  fprintf(fp, "whoseTurn       : %d -> %d\n", state1->whoseTurn,  state2->whoseTurn);
  fprintf(fp, "phase           : %d -> %d\n", state1->phase,  state2->phase);
  fprintf(fp, "numActions      : %d -> %d\n", state1->numActions, state2->numActions);
  fprintf(fp, "numBuys         : %d -> %d\n", state1->numBuys, state2->numBuys);
  fprintf(fp, "coins           : %d -> %d\n", state1->coins, state2->coins);
  fprintf(fp, "playedCardCount : %d -> %d\n", state1->playedCardCount, state2->playedCardCount);
  fprintf(fp, "handCount       : %d -> %d\n", state1->handCount[state2->whoseTurn], state2->handCount[state2->whoseTurn]);
  fprintf(fp, "deckCount       : %d -> %d\n", state1->deckCount[state2->whoseTurn], state2->deckCount[state2->whoseTurn]);
  fprintf(fp, "discardCount    : %d -> %d\n", state1->discardCount[state2->whoseTurn], state2->discardCount[state2->whoseTurn]);
  char s1[MAX_STR_LEN] = {'\0'};
  char s2[MAX_STR_LEN] = {'\0'};
  toString(state1->hand[state1->whoseTurn], state1->handCount[state1->whoseTurn], s1);
  toString(state2->hand[state2->whoseTurn], state2->handCount[state2->whoseTurn], s2);
  fprintf(fp, "hand            : %s -> %s\n", s1, s2);
}

static void recordResult(Node **queue1, Node **queue2, struct gameState *state, char play[]) {
  // record game state
  struct gameState *tmp1 = (struct gameState *)Malloc(sizeof(struct gameState));
  *tmp1 = *state;
  Enqueue(queue1, tmp1);
  // record play
  char *tmp2 = (char *)Malloc(sizeof(char) * strlen(play));
  strcpy(tmp2, play);
  Enqueue(queue2, tmp2);
}

static void recordResults(Node *queue1, Node *queue2) {
  FILE *fp = Fopen(FILE_NAME, "w");
  fprintf(fp, "***beginning of testdominon results***\n");

  // record inital result
  struct gameState *state1 = Dequeue(queue1, &queue1);
  char *play = Dequeue(queue2, &queue2);
  fprintf(fp, "***initializeGame result***\n%s\n", play);
  Free(play);

  while (queue1 != NULL && queue2 != NULL) {
    // record next result
    struct gameState *state2 = Dequeue(queue1, &queue1);
    play = Dequeue(queue2, &queue2);
    recordResultsHelper(fp, state1, state2, play);

    // clean-up
    Free(state1);
    Free(play);
    state1 = state2;
  }

  // record final result
  fprintf(fp, "***end result***\n");
  for (int i = 0; i < state1->numPlayers; i++) {
    fprintf(fp, "score for player %d : %d\n", i, scoreFor(i, state1));
  }
  fprintf(fp, "***end of testdominon results***\n");
  Free(state1);

  Fclose(fp);
}

static void makeGame(Node **queue1, Node **queue2, struct gameState *state) {
  // check precondition
  Verify362(NUM_KINGDOM_CARDS < treasure_map - adventurer);

  srand(RANDOM_SEED);
  int randomSeed = rand();
  int numPlayers = rand() % (MAX_PLAYERS - MIN_PLAYERS + 1) + MIN_PLAYERS;

  // pick random kingdom cards
  int kingdomCards[NUM_KINGDOM_CARDS];
  for (int i = 0; i < NUM_KINGDOM_CARDS; i++) {
    int card = rand() % (treasure_map - adventurer + 1) + adventurer;
    bool tmp = hasCard(kingdomCards, i, card);
    while (tmp) {
      card = rand() % (treasure_map - adventurer + 1) + adventurer;
      tmp = hasCard(kingdomCards, i, card);
    }
    kingdomCards[i] = card;
  }

  char play[MAX_STR_LEN] = { '\0' };
  char s[MAX_STR_LEN] = { '\0' };
  int result = initializeGame(numPlayers, kingdomCards, randomSeed, state);
  toString(kingdomCards, NUM_KINGDOM_CARDS, s);
  sprintf(play, "initializeGame(numPlayers, kingdomCards, randomSeed, state) = %d\nnumPlayers = %d\nkingdom_cards = %s\nrandomSeed = %d", result, numPlayers, s, randomSeed);
  recordResult(queue1, queue2, state, play);
}

static int countCoins(struct gameState *state) {
  int coin = 0;
  int numCards = numHandCards(state);
  for (int i = 0; i < numCards; i++) {
    int card = handCard(i, state);
    if (card == copper) {
      coin += 1;
    } else if (card == silver) {
      coin += 2;
    } else if (card == gold) {
      coin += 3;
    }
  }
  return coin;
}

static int cardToBuyCost(int card) {
  if (card == estate) {
    return 2;
  } else if (card == village || card == silver) {
    return 3;
  } else if (card == smithy) {
    return 4;
  } else if (card == mine || card == duchy) {
    return 5;
  } else if (card == adventurer || card == gold) {
    return 6;
  } else {
    Verify362(card == province);
    return 8;
  }
}

static int randomCardToBuy() {
  int num = rand() % NUM_CARDS_TO_BUY;
  if (num == 0) {
    return smithy;
  } else if (num == 1) {
    return mine;
  } else if (num == 2) {
    return village;
  } else if (num == 3) {
    return adventurer;
  } else if (num == 4) {
    return silver;
  } else if (num == 5) {
    return gold;
  } else if (num == 6) {
    return duchy;
  } else {
    return province;
  }
}

static int randomCardToPlay() {
  int num = rand() % NUM_CARDS_TO_PLAY;
  if (num == 0) {
    return smithy;
  } else if (num == 1) {
    return mine;
  } else if (num == 2) {
    return village;
  } else {
    return adventurer;
  }
}

static bool hasCard(int cards[], int len, int card) {
  // check preconditions
  Verify362(len >= 0);

  // find card
  for (int i = 0; i < len; i++) {
    if (cards[i] == card) {
      // card found
      return true;
    }
  }

  // card not found
  return false;
}

static int findCard(int cards[], int len, int card) {
  // check preconditions
  Verify362(len >= 0);

  // find card
  for (int i = 0; i < len; i++) {
    if (cards[i] == card) {
      // card found
      return i;
    }
  }

  // card not found
  return -1;
}

static int findCardToBuy(struct gameState *state) {
  // randomly order cards to buy
  int coins = countCoins(state);
  int cards[NUM_CARDS_TO_BUY];
  for (int i = 0; i < NUM_CARDS_TO_BUY; i++) {
    // pick card to check
    int card = randomCardToBuy();
    bool tmp = hasCard(cards, i, card);
    while (tmp) {
      card = randomCardToBuy();
      tmp = hasCard(cards, i, card);
    }
    cards[i] = card;

    // check card
    int cost = cardToBuyCost(card);
    int supply = supplyCount(card, state);
    if (supply > 0 && cost <= coins) {
      // found card to buy
      return card;
    }
  }

  // didn't find any card to buy
  return -1;
}

static int findCardToPlay(struct gameState *state) {
  // randomly order cards to play
  int cards[NUM_CARDS_TO_PLAY];
  for (int i = 0; i < NUM_CARDS_TO_PLAY; i++) {
    // pick card to check
    int card = randomCardToPlay();
    bool tmp = hasCard(cards, i, card);
    while (tmp) {
      card = randomCardToPlay();
      tmp = hasCard(cards, i, card);
    }
    cards[i] = card;

    // check card
    int n = numHandCards(state);
    for (int j = 0; j < n; j++) {
      int tmp = handCard(j, state);
      if (card == tmp) {
        return j;
      }
    }
  }

  // didn't find card to play
  return -1;
}

static void playTurn(Node **queue1, Node **queue2, struct gameState *state) {
  // action phase
  int handPos = findCardToPlay(state);
  if (state->numActions > 0 && handPos >= 0) {
    int choice1;
    int choice2;
    int choice3;
    int card = handCard(handPos, state);
    if (card == smithy) {
      // play smithy card
      choice1 = 0;
      choice2 = 0;
      choice3 = 0;
    } else if (card == mine) {
      // play mine card
      if (hasCard(state->hand[state->whoseTurn], numHandCards(state), copper)) {
        choice1 = findCard(state->hand[state->whoseTurn], numHandCards(state), copper);
        choice2 = silver;
        playCard(handPos, choice1, choice2, 0, state);
      } else if (hasCard(state->hand[state->whoseTurn], numHandCards(state), silver)) {
        choice1 = findCard(state->hand[state->whoseTurn], numHandCards(state), silver);
        choice2 = gold;
        playCard(handPos, choice1, choice2, 0, state);
      } else if (hasCard(state->hand[state->whoseTurn], numHandCards(state), gold)) {
        choice1 = findCard(state->hand[state->whoseTurn], numHandCards(state), gold);
        choice2 = gold;
      }
      choice3 = 0;
    } else if (card == village) {
      // play village card
      choice1 = 0;
      choice2 = 0;
      choice3 = 0;
    } else {
      Verify362(card == adventurer);
      // play adventurer card
      choice1 = 0;
      choice2 = 0;
      choice3 = 0;
    }
    char play[MAX_STR_LEN] = { '\0' };
    int result = playCard(handPos, choice1, choice2, choice3, state);
    sprintf(play, "playCard(%d, %d, %d, %d, state) = %d", handPos, choice1, choice2, choice3, result);
    recordResult(queue1, queue2, state, play);
  }

  // buy phase
  int supplyPos = findCardToBuy(state);
  if (supplyPos >= 0) {
    char play[MAX_STR_LEN] = { '\0' };
    int result = buyCard(supplyPos, state);
    sprintf(play, "buyCard(%d, state) = %d", supplyPos, result);
    recordResult(queue1, queue2, state, play);
  }

  // clean-up phase
  char play[MAX_STR_LEN] = { '\0' };
  int result = endTurn(state);
  sprintf(play, "endTurn(state) = %d", result);
  recordResult(queue1, queue2, state, play);
}

/* main program */

int main(int argc, char **argv) {
  // make random game
  Node *queue1 = NULL;
  Node *queue2 = NULL;
  struct gameState state;
  makeGame(&queue1, &queue2, &state);

  // play game
  while (!isGameOver(&state)) {
    playTurn(&queue1, &queue2, &state);
  }

  // record sequence of states of game
  recordResults(queue1, queue2);

  return EXIT_SUCCESS;
}
