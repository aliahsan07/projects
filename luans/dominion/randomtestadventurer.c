#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

#include "dominion.h"
#include "rngs.h"

#define MAX_TEST 10

int main() {
	struct gameState first, second, third;

	int card_array[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int i, seed, player_num, temp_hand, choice, player, pos;	
	int handle, sum, discard, result, init;
	
	srand(time(0));
	printf("Starting to test adventure ......\n");
	
	printf("-----Part I-----\n");
	
	for(i = 0; i < MAX_TEST; i ++)
	{
		printf("Round %d: \n", i + 1);
		
		player_num = rand() % 4;
		seed = rand();		
		init = initializeGame(player_num, card_array, seed, &first);
		printf("Player Number: %d\tSeed: %d\tInitial: %d\n", player_num, seed, init);

		player = rand() % 4;
		choice = card_array[rand() % 10];
		first.deckCount[player] = rand() % MAX_DECK;
		first.discardCount[player] = rand() % MAX_DECK;
		first.handCount[player] = rand() % MAX_HAND;
		
		handle = first.handCount[player];
		discard = first.discardCount[player];
		sum = first.deckCount[player];
		
		result = cardEffect(card_array[0], choice, choice, choice, &first, temp_hand, &pos);
		printf("Handle Card: %d\tDiscard Card: %d\tTotal Card: %d\t-----\tResult: %d\n", handle, discard, sum, result);
	}
	
	printf("-----Part II-----\n");
	
	for(i = 0; i < MAX_TEST; i ++)
	{
		printf("Round %d: \n", i + 1);
		
		player_num = rand() % 8;
		seed = rand();		
		init = initializeGame(player_num, card_array, seed, &second);
		printf("Player Number: %d\tSeed: %d\tInitial: %d\n", player_num, seed, init);

		player = rand() % 8;
		choice = card_array[rand() % 10];
		second.deckCount[player] = rand() % MAX_DECK;
		second.discardCount[player] = rand() % MAX_DECK;
		second.handCount[player] = rand() % MAX_HAND;
		
		handle = second.handCount[player];
		discard = second.discardCount[player];
		sum = second.deckCount[player];
		
		result = cardEffect(card_array[0], choice, choice, choice, &first, temp_hand, &pos);
		printf("Handle Card: %d\tDiscard Card: %d\tTotal Card: %d\t-----\tResult: %d\n", handle, discard, sum, result);
	}
	
	printf("-----Part III-----\n");
	
	for(i = 0; i < MAX_TEST; i ++)
	{
		printf("Round %d: \n", i + 1);
		
		player_num = rand() % 2;
		seed = rand();		
		init = initializeGame(player_num, card_array, seed, &third);
		printf("Player Number: %d\tSeed: %d\tInitial: %d\n", player_num, seed, init);

		player = rand() % 2;
		choice = card_array[rand() % 10];
		third.deckCount[player] = rand() % MAX_DECK;
		third.discardCount[player] = rand() % MAX_DECK;
		third.handCount[player] = rand() % MAX_HAND;
		
		handle = third.handCount[player];
		discard = third.discardCount[player];
		sum = third.deckCount[player];
		
		result = cardEffect(card_array[0], choice, choice, choice, &first, temp_hand, &pos);
		printf("Handle Card: %d\tDiscard Card: %d\tTotal Card: %d\t-----\tResult: %d\n", handle, discard, sum, result);
	}
	
	printf("Ending to test advanture ......");
	return EXIT_SUCCESS;
}
