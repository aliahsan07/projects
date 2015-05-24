/*
 * testdominion.h
 *
 *  Created on: May 24, 2015
 *      Author: martich2
 */

#ifndef TESTDOMINION_H_
#define TESTDOMINION_H_

#include "dominion.h"
#include "dominion_helpers.h"

/**
 * Performs the action phase for the current player. Does player have action
 * cards? Pick the action card and play it, while has actions and cards play.
 * @param aGame The current game's state.
 */
void actionPhase(struct gameState *aGame);

/**
 * Performs the buyPhase for the current player. Does the player have coins in
 * had? buy cards for all buy actions and coins.
 * @param aGame The current game's state.
 * @param kcards list of the kingdom cards to pick for buying.
 */
void buyPhase(struct gameState *aGame, int *kcards);

/**
 * Performs the cleanup phase for the current player. Discard played and hand
 * cards. draw new hand, clear some state variables, set next player
 * @param aGame The current game's state.
 */
void cleanupPhase(struct gameState *aGame);

/**
 * Populates passed in array with a unique random list of kingdom cards
 * @param kcards an array to to be filled with kingdom cards
 */
void genKcards(int *kcards);


/**
 * looks through player's hand to find any action cards.
 * @param aGame the current game's state
 * @return -1 if no action cards are found, otherwise position of first found
 *          action card
 */
int hasActionCards(struct gameState *aGame);

/**
 * Determines if a given card is an action card.
 * @param card the card to be inspected for action property
 * @return 1 if card is action card, 0 if it is not an action card.
 */
int isActionCard(int card);

/**
 * Get the string name of a card given its enum value. Does bounds checking
 * @param cardNumb The card number to look up its string name
 * @return the string name of a card or "BAD CARD" if out of range.
 */
char *getCardName(int cardNumb);


/**
 * These are the card type options for buying.
 */
enum buy_options {NO_BUY = 0, TREASURE, VICTORY, KINGDOM, SIZE_BUY_OPTS};

#endif /* TESTDOMINION_H_ */