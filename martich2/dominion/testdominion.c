/*
 * testdominion.c
 *
 * random game tester for dominion
 *
 *  Created on: May 13, 2015
 *      Author: martich2
 */

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"

// TODO: put all this code into a header
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

enum buy_options {NO_BUY = 0, TREASURE, VICTORY, KINGDOM, SIZE_BUY_OPTS};

// access by getCardName[cardNum], no bound check!
char* getCardName[NUMBER_OF_CARDS] = {"curse", "estate", "duchy", "provice", "copper", "silver",
        "gold", "adventurer", "council_room", "feast", "gardens", "mine",
        "remodel", "smithy", "village", "baron", "great_hall", "minion",
        "steward", "tribute", "ambassador", "cutpurse", "embargo", "outpost",
        "salvager", "sea_hag", "treasure_map"};

int main(int argc, char** argv)
{
    srand(time(NULL));          // init libc random seed
    int players = (rand() % 3) + 2; // 2 to 4 players
    int seed = rand() % 65536;

    int kingdom_cards[10] = {0};
    genKcards(kingdom_cards);

    struct gameState *aGame = newGame();

	initializeGame(players,kingdom_cards, seed, aGame);


	printf("This game has %d players\n", players);
	// game loop
	while(!isGameOver(aGame))
	{
        printf("Player %d turn\n", aGame->whoseTurn);
        actionPhase(aGame);
        buyPhase(aGame, kingdom_cards);
        cleanupPhase(aGame);
	}

	return 0;
}

void genKcards(int *kcards)
{
    int i = 0, j = 0;
    int card;
    int *card_checklist;

    card_checklist = (int*)calloc(NUM_K_CARDS, sizeof(int));
    if (card_checklist == NULL)
        // TODO: assert check not print
        printf("card_checklist is NULL");

    // random unique list of kingdom cards
    while(i < 10)
    {
        card = (rand() % 20); // 20 kingdom cards
        if (card_checklist[card] == 0)
        {
            // offset to cards 7 thru 26, only good if enum order doesnt change
            card_checklist[card] = (card + adventurer);
            i++;
        }
    }

    // go thru the check list and assign the selected card to the card list
    for (i = 0; i < 10; i++)
    {
        while (j <= 20)
        {
            if (card_checklist[j] != 0)
            {
                kcards[i] = card_checklist[j];
                j++;
                break;
            }
            j++;
        }
    }

    free(card_checklist);
}

void actionPhase(struct gameState *aGame)
{
    int card = 0;
    printf("Action phase\n");

    // while a player has actions
    while(aGame->numActions > 0)
    {
        // does the player have action cards?
        card = hasActionCards(aGame);
        if (card >= 0)
        {
            // all choices will be fixed to 0 for simplicity
            //TODO: randomize card choice, if more than one card pick one randomly
            assert(playCard(card, 0, 0, 0, aGame) == 0);
            // TODO: discard played card
        }
        else
        {
            printf("Player %d has no action cards in hand\n", aGame->whoseTurn);
            return;
        }
    }
}
//TODO: not really the best approach here. returns without buying if randomly
// picks an expensive card, should try harder to buy a card.
void buyPhase(struct gameState *aGame, int *kcards)
{
    int choice = 0;
    int card = -1;
    printf("Buy Phase\n");
    updateCoins(aGame->whoseTurn, aGame, 0);

    while (aGame->numBuys > 0)
    {
        // figure out what card to buy
        choice = rand() % SIZE_BUY_OPTS;
        switch(choice)
        {
            case NO_BUY:
                printf("player %d choose not buy anything\n", aGame->whoseTurn);
                return;
                break;
            case TREASURE:
                if (aGame->coins >= getCost(gold))
                    card = gold;
                else if (aGame->coins >= getCost(silver))
                    card = silver;
                else if (aGame->coins >= getCost(copper))
                    card = copper;
                else
                    card = -1;
                break;
            case VICTORY:
                if (aGame->coins >= getCost(province))
                    card = province;
                else if (aGame->coins >= getCost(duchy))
                    card = duchy;
                else if (aGame->coins >= getCost(estate))
                    card = estate;
                else
                    card = -1;
                break;
            case KINGDOM:
                choice = rand() % 10;
                if (aGame->coins >= getCost(kcards[choice]))
                    card = kcards[choice];
                else
                    card = -1;
                break;
            default:
                card = -1;
                break;
        } // end switch

        if (card == -1)
        {
            printf("Player %d not enough money to buy picked card!\n", aGame->whoseTurn);
            return;
        }
        else
        {
            assert(buyCard(card, aGame) == 0);
            printf("player %d bought a %s card\n", aGame->whoseTurn, getCardName[card]);
        }
    }
}

void cleanupPhase(struct gameState *aGame)
{
    printf("Clean Up Phase\n");
    endTurn(aGame);
}

int hasActionCards(struct gameState *aGame)
{
    int i;
    int result = -1;

    // look for an action card in hand
    for(i = 0; i < aGame->handCount[aGame->whoseTurn]; i++)
    {
        // play that found action card
        if(isActionCard(aGame->hand[aGame->whoseTurn][i]))
        {
            result = i;
            break;
        }
    }

    return result;
}

int isActionCard(int card)
{
    int result = 0;
    if ((card >= adventurer) || (card <= treasure_map))
        result = 1;
    return result;
}
