#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "dominion.h"
#include "rngs.h"

#define MAX_TEST 10

int main(int argc, char *argv[])
{
	struct gameState state;
	
	int *card_array = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int *kingdom;
	int player_num, seed, init;
	int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
	int i;
	
	srand(time(0));
	printf("Starting to test game of dominion ......\n");
	
	for(i = 0; i < MAX_TEST; i ++)
	{
		player_num = rand() % 4;
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
	}
	
	printf("Ending to test cards ......\n");
	
	return EXIT_SUCCESS;
}
