#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "dominion.h"
#include "rngs.h"

#define MAX_CARDS_TEST 10

int main(int argc, char *argv[])
{
	struct gameState state;
	
	int card_array[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int player_array[3] = {2, 3, 4};
	int pos_array[500];
	int *kingdom;
	int player_num, seed, init, next, turn = 0;
	int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
	int i, count;
	
	srand(time(0));
	printf("Starting to test game of dominion ......\n");
	
	for(count = 0; count < MAX_CARDS_TEST; count ++)
	{
		player_num = player_array[rand() % 3];
		seed = rand();
			
		k1 = card_array[rand() % 10];
		k2 = card_array[rand() % 10];
		k3 = card_array[rand() % 10];
		k4 = card_array[rand() % 10];
		k5 = card_array[rand() % 10];
		k6 = card_array[rand() % 10];
		k7 = card_array[rand() % 10];
		k8 = card_array[rand() % 10];
		k9 = card_array[rand() % 10];
		k10 = card_array[rand() % 10];	
		
		kingdom = kingdomCards(k1, k2, k3, k4, k5, k6, k7, k8, k9, k10);
		init = initializeGame(player_num, kingdom, seed, &state);
		
		printf("$$$$$ Round %d $$$$$\n", count + 1);
		printf("Number of Players: %d\n", state.numPlayers);		
		printf("Printing kingdom cards: \n");
		
		for(i = 0; i < 10; i ++)
			printf("Kingdom %d: %d\n", i + 1, kingdom[i]);
		
		while(!isGameOver(&state))
		{
			turn = whoseTurn(&state);
			printf("Player Turn: %d\n", turn);
			
			while(state.numActions >= 1)
			{
				next = 0;
				
				for (int i = 0; i < numHandCards(&state); i++)
				{
					printf("Player %d has: %d\n", turn, handCard(i, &state));
					pos_array[next] = i;
					next ++;
				}
							
				printf("Hand Position: %d\n", pos_array[rand() % next]);
				printf("Card Number: %d\n", handCard(pos_array[rand() % next], &state));
				
				switch(handCard(pos_array[rand() % next], &state))
				{
					
				}
			}
		}
	}	
	
	printf("Ending to test cards ......\n");
	
	return EXIT_SUCCESS;
}
