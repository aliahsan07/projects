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

int main(int argc, char** argv)
{
    int kingdom_cards[10] = {0};
    int *card_checklist;
    int i = 0, j = 0;
    int card = 0;
    struct gameState *aGame = newGame();


	srand(time(NULL));          // init libc random seed
    int players = (rand() % 3) + 2; // 2 to 4 players

    card_checklist = (int*)calloc(19, sizeof(int)); // 19 kingdom cards in our game.
    if (card_checklist == NULL)
        printf("card_checklist is NULL");
    //assert(card_checklist == NULL);

	// random unique list of kingdom cards
	while(i < 10)
	{
		card = (rand() % 19); // 19 kingdom cards
		if (card_checklist[card] == 0)
		{
			card_checklist[card] = (card + 7); // offset to cards 7 thru 26
			i++;
		}
	}

	// go thru the check list and assign the selected card to the card list
	for (i = 0; i < 10; i++)
	{
	    while (j <= 19)
	    {
			if (card_checklist[j] != 0)
			{
				kingdom_cards[i] = card_checklist[j];
				j++;
				break;
			}
			j++;
		}
	}
    free(card_checklist);

	initializeGame(players,kingdom_cards, 42, aGame);

    printf("Hello World: %d!\n", players);


	return 0;
}
