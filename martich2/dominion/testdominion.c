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

/**
 * Populates passed in array with a unique random list of kingdom cards
 * @param kcards an array to to be filled with kingdom cards
 */
void genKcards(int *kcards);

// access by getCardName[cardNum], no bound check!
char* getCardName[NUMBER_OF_CARDS] = { "curse", "estate", "duchy", "provice", "copper", "silver",
        "gold", "adventurer", "council_room", "feast", "gardens", "mine",
        "remodel", "smithy", "village", "baron", "great_hall", "minion",
        "steward", "tribute", "ambassador", "cutpurse", "embargo", "outpost",
        "salvager", "sea_hag", "treasure_map" };

int main(int argc, char** argv)
{
    srand(time(NULL));          // init libc random seed
    int players = (rand() % 3) + 2; // 2 to 4 players
    int seed = rand() % 65536;

    int kingdom_cards[10] = {0};
    genKcards(kingdom_cards);

    struct gameState *aGame = newGame();

	initializeGame(players,kingdom_cards, seed, aGame);

	// game loop
	printf("This game has %d players\n", players);
	printf("Player %d turn\n", aGame->whoseTurn);
	printf("Action phase\n");
	printf("Buy Phase\n");
	printf("Clean Up Phase\n");

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
            card_checklist[card] = (card + 7); // offset to cards 7 thru 26
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
