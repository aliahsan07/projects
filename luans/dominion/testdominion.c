#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include "interface.h"

void randomCards(int k[10])
{
	int i, j, temp;

	for(i = 0; i < 10; i++) 
	{
		while(k[i] == 0) 
		{
			j = rand()%10;
			temp = k[j];
			k[j] = k[i];
			k[i] = temp;   
        }
	}
}

void print_info(struct gameState state)
{
	printSupply(&state);
	printHand(state.whoseTurn, &state);
	printDeck(state.whoseTurn, &state);
	printDiscard(state.whoseTurn, &state);
	printPlayed(state.whoseTurn, &state);
	printState(&state);
	printScores(&state);
}

int main(int argc, char *argv[])
{
	struct gameState state;
	int k[20] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
	
	int seed = rand() % 100;
	int player_num = rand() % 3 + 2;
	int i;
	char card_name[64];
	
	srand(time(0));

	printf("Starting to test complete dominion ......\n");
	printf("\n$$$$$ Starting to show entire process of playing this Dominion Game $$$$$\n\n");
	
	if(strcmp(argv[1], "--test") == 0)
	{
		printf("Numbers of players: %d\n", player_num);	
		
		for(i = 0; i < 10; i ++)
		{
			cardNumToName(k[i], card_name);
			printf("Kingdom Card %d: %d (%s)\n", i + 1, k[i], card_name);
		}
	}
	
	if(strcmp(argv[1], "--game") == 0)
	{
		printf("\nInitializing dominion ......\n\n");
		initializeGame(player_num, k, seed, &state);
			
		while(!isGameOver(&state))
		{
			int after_draw, after_buy, add_card;
			int choice = rand() % 3;
			int hand_count = state.handCount[state.whoseTurn];
			int card_draw;
								
			cardNumToName(hand_count, card_name);
				
			switch(choice)
			{
				case 0: 
					{
						card_draw = hand_count;
						cardNumToName(card_draw, card_name);
						after_draw = playCard(card_draw, 0, 0, 0, &state);					
						print_info(state);
					}
					break;
				case 1:
					{
						add_card = rand() % 20;
						after_buy = buyCard(add_card, &state);
						print_info(state);
					}
					break;
				case 2:
					{
						printf("It's turn to next Player %d\n", state.whoseTurn);
						endTurn(&state);
					}
					break;
				default:
					printf("!!!!! Choice Error !!!!!");
					exit(EXIT_FAILURE);
			}
				
			if(choice == 0 || choice == 1)
			{
				if(after_draw == -1)
					printf("Player %d is drawing card [%s]\n", state.whoseTurn, card_name);
				else
					printf("Turn to next player\n");
			}
		}
			
		print_info(state);
	}
	printf("Ending to test complete dominion ......\n");
	
	return EXIT_SUCCESS;
}
