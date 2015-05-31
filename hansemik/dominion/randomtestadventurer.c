#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define NUM_TESTS 1000

int main (int argc, char** argv)
{
	printf("Random test adventurer.\n");

	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
		remodel, smithy, village, baron, great_hall};

	int cards[17] = {curse, estate, duchy, province, copper, silver,
 	gold, adventurer, council_room, feast, gardens, mine, 
	remodel, smithy, village, baron, great_hall};

	initializeGame(2, k, 5, &G);

	int player = 0;

	srand(time(NULL));

	for (int a = 0; a < NUM_TESTS; a++)
	{

		//Clear hand
		for (int i = 0; i < G.handCount[player]; i++)
		{
			G.hand[player][i] = -1;
		}
		G.hand[player][0] = adventurer;
		G.handCount[player] = 1;

		//Clear deck
		for (int i = 0; i < G.deckCount[player]; i++)
		{
			G.deck[player][i] = -1;
		}
		G.deckCount[player] = 0;

		//Clear discard pile
		for (int i = 0; i < G.discardCount[player]; i++)
		{
			G.discard[player][i] = -1;
		}
		G.discardCount[player] = 0;

		int num_cards_deck = rand() % 101; //Random 100
		G.deckCount[player] = num_cards_deck;
		int rand_card = 0;

		int num_coins = 0;

		//Populate deck
		for (int i = 0; i < G.deckCount[player]; i++)
		{
			rand_card = rand() % 17;
			G.deck[player][i] = cards[rand_card];
			if(rand_card == 4 || rand_card == 5 || rand_card == 6)
				num_coins ++;
		}

		printf("Playing adventurer card\n");
		int ret_val = cardEffect(adventurer, 0, 0, 0, &G, 1, 0);

		if(num_coins >= 2)
		{
			int num_hand_coins = 0;
			for (int i = 0; i < G.handCount[player]; i++)
			{
				if(G.hand[player][i] == 4 || G.hand[player][i] == 5 || G.hand[player][i] == 6)
				num_hand_coins ++;
			}

			assert(G.handCount[player] == 2 && num_hand_coins == 2
				&& "Player does not have 2 cards in hand as expected.");		
			assert(num_cards_deck == G.deckCount[player] + G.discardCount[player] + G.handCount[player] - 1 && 
				"Sum of deckCount, handCount, and discardCount do not add to original num_cards_deck"); // -1 for discarded adventurer card
		
		}
		else
		{
			printf("Not enough coins in deck/discard pile. Could not properly test card.\n");
		}
	}
	printf("All tests passed.\n");
}