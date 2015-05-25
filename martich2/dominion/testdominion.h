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
char *getCardName(int card);

/**
 * Determines if a card is the game, supply is not -1 and not 0,
 * @param cardNumb The card to check
 * @return 0 if the card is not in or left in the game, 1 if it is in the game
 */
int isInGame(int card, struct gameState *aGame);

/**
 * Determines which card to buy based on player's coins and if the card is in
 * the game.
 * @param coins the number of coins to check against. decrements if more expensive
 * cards are not viable.
 * @param aGame the game's current state
 * @return -1 if no card selected, 0 if no card to buy else the card to buy.
 */
int pickACard(int *coins, struct gameState *aGame);

/**
 * prints out the cards in current player's hand on one line
 * @param aGame the game's current state
 */
void printHand(struct gameState *aGame);

/**
 * Prints out the 10 kingdom cards that are in the game
 * @param gameState the game's current state
 */
void printKCards(struct gameState *aGame);

/**
 * These are the card type options for buying.
 */
enum buy_options {NO_BUY = 0, TREASURE, VICTORY, KINGDOM, SIZE_BUY_OPTS};

// collection of cards that all cost the same price
int cost3cards[5] = {silver, village, great_hall, steward, ambassador};
int cost4cards[9] = {feast, gardens, remodel, smithy, baron, cutpurse, salvager, sea_hag, treasure_map};
int cost5cards[6] = {duchy, council_room, mine, minion, tribute, outpost};

// size of each card cost array
#define NUM_COST3 sizeof(cost3cards)/(sizeof(cost3cards[1]))
#define NUM_COST4 sizeof(cost4cards)/(sizeof(cost4cards[1]))
#define NUM_COST5 sizeof(cost5cards)/(sizeof(cost5cards[1]))



#endif /* TESTDOMINION_H_ */
