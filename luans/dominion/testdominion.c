#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

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
	int i, x = 0;
	char card_name[64];
	
	srand(time(0));

	printf("Starting to test complete dominion ......\n");
	printf("Numbers of players: %d\n", player_num);
	printf("$$$$$ Printing the kingdom cards $$$$$\n");
	
	for(i = 0; i < 10; i ++)
	{
		cardNumToName(k[i], card_name);
		printf("Kindom card %d: %s and the value: %d\n", i + 1, card_name, k[i]);
	}
	
	printf("Initializing dominion ......\n");
	initializeGame(player_num, k, seed, &state);
	
	while(!isGameOver(&state))
	{
		int afterDraw, afterBuy;
		int choice = rand() % 3;
		int hand_count = game.handCount[game.whoseTurn];
		int card_draw;
                        
		cardNumToName(hand_count, card_name);
		
		switch(choice)
		{
			case 0: 
				{
					card_draw = hand_count;
					cardNumToName(card_draw, card_name);
					afterDraw = playCard(card_draw, 0, 0, 0, &state);					
					print_info(state);
				}
				break;
			case 1:
				{
					int add_card = rand() % 20;
					afterBuy = buyCard(add_card, &state);
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
			if(afterDraw == -1)
				printf("Player %d is drawing card [%s]\n", state.whoseTurn, card_name);
			else
				printf("Turn to next player\n");
		}
	}
	
	print_info(&state);
	printf("Ending to test complete dominion ......\n");
	
	return EXIT_SUCCESS;
}
