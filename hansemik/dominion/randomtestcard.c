#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define NUM_TESTS 1000

int main (int argc, char** argv)
{
	printf("Random test minion.\n");

	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
		remodel, smithy, village, baron, great_hall};

	int cards[17] = {curse, estate, duchy, province, copper, silver,
 	gold, adventurer, council_room, feast, gardens, mine, 
	remodel, smithy, village, baron, minion};

	srand(time(NULL));

	int rand_seed = rand() % 10 + 1;
	int num_players = rand() % 3 + 2;// 2 to 4 players

	initializeGame(num_players, k, rand_seed, &G);

	int player = rand() % num_players;
	G.whoseTurn = player;

	int num_cards_hand = 0;
	int num_cards_deck = 0;
	int num_cards_discard = 0;
	int rand_card = 0;
	int choice1 = 0;
	int temp = 0;
	int minion_pos = 0;
	int old_sum = 0;
	int new_sum = 0;

	int before_hand_count[num_players];
	int before_deck_count[num_players];
	int before_discard_count[num_players];

	for (int a = 0; a < NUM_TESTS; a++)
	{
		G.coins = 0;
		G.numActions = 0;
		for (int n = 0; n < G.numPlayers; n++)
		{
			//Clear hand
			for (int i = 0; i < G.handCount[n]; i++)
			{
				G.hand[n][i] = -1;
			}
			G.handCount[n] = 0;

			//Clear deck
			for (int i = 0; i < G.deckCount[n]; i++)
			{
				G.deck[n][i] = -1;
			}
			G.deckCount[n] = 0;

			//Clear discard pile
			for (int i = 0; i < G.discardCount[n]; i++)
			{
				G.discard[n][i] = -1;
			}
			G.discardCount[n] = 0;

			//Populate hand
			num_cards_hand = rand() % 9 + 2;
			before_hand_count[n] = num_cards_hand;
			G.handCount[n] = num_cards_hand;

			for (int i = 0; i < G.handCount[n]; i++)
			{
				rand_card = rand() % 17;
				G.hand[n][i] = cards[rand_card];
			}

			//Populate deck
			num_cards_deck = rand() % 9 + 2;
			before_deck_count[n] = num_cards_deck;
			G.deckCount[n] = num_cards_deck;
			for (int i = 0; i < G.deckCount[n]; i++)
			{
				rand_card = rand() % 17;
				G.deck[n][i] = cards[rand_card];
			}

			//Populate discard pile
			num_cards_discard = rand() % 9 + 2;
			before_discard_count[n] = num_cards_discard;
			G.discardCount[n] = num_cards_discard;
			for (int i = 0; i < G.discardCount[n]; i++)
			{
				rand_card = rand() % 17;
				G.discard[n][i] = cards[rand_card];
			}
		}


		minion_pos = rand() % G.handCount[player];
		G.hand[player][minion_pos] = minion;

		printf("Playing minion card\n");
		temp = rand() % 4;
		if(temp == 3)
			choice1 = 1;
		else
			choice1 = 2;
				
		int ret_val = cardEffect(minion, choice1, 0, 0, &G, minion_pos,0);

		if(choice1 == 1)
		{
			assert(G.coins == 2 && "Coins != 2");
		}
		else if(choice1 == 2)
		{
			//Check Player
			old_sum = before_hand_count[player] + before_discard_count[player] + before_deck_count[player];
			new_sum = G.handCount[player] + G.discardCount[player] + G.deckCount[player];
			assert(new_sum == old_sum 
				&& "Sum of cards before and after minion card are not equal (Player)");
			
			//Check other players		
			for (int n = 0; n < G.numPlayers; n++)
			{
				if(n != player)
				{
					if(before_hand_count[n] > 4)
					{
						assert(G.handCount[n] == 4 
							&& "Incorrect new handCount");
		
						old_sum = before_hand_count[n] + before_discard_count[n] + before_deck_count[n];
						new_sum = G.handCount[n] + G.discardCount[n] + G.deckCount[n];
						assert(new_sum == old_sum 
							&& "Sum of cards before and after minion card are not equal");
					}
				}
			}
		}
	}
	printf("All tests passed.\n");
}