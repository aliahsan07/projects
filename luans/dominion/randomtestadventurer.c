#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

#include "dominion.h"
#include "rngs.h"

#define MAX_TEST 10

int main() {
	struct gameState state;

	int card_array[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int choice1, choice2, choice3;
	int i, seed, player_num, temp_hand, player, pos;	
	int handle, sum, discard, result, init;
	int fail = 0;
	
	srand(time(0));
	printf("Starting to test adventure ......\n");
	
	for(i = 0; i < MAX_TEST; i ++)
	{
		printf("Round %d: \n", i + 1);
		
		player_num = rand() % 4;
		seed = rand();		
		init = initializeGame(player_num, card_array, seed, &state);
		printf("Player Number: %d\tSeed: %d\tInitial: %d\n", player_num, seed, init);

		player = rand() % 4;
		choice1 = card_array[rand() % 10];
		choice2 = card_array[rand() % 10];
		choice3 = card_array[rand() % 10];
		
		state.deckCount[player] = rand() % MAX_DECK;
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_HAND;
		
		handle = state.handCount[player];
		discard = state.discardCount[player];
		sum = state.deckCount[player];
		
		result = cardEffect(adventurer, choice1, choice2, choice3, &state, temp_hand, &pos);
		printf("Handle Card: %d\tDiscard Card: %d\tTotal Card: %d\t-----\tResult: %d\n", handle, discard, sum, result);
		
		if(handle != state.handCount[player] + 1 || discard != state.discardCount[player] + 1 || sum != state.deckCount[player] + 1 || result != adventurer)
			fail += 1;
	}
	
	printf("Passing Coverage: %d out of total %d\n", MAX_TEST - fail, MAX_TEST);
	printf("Ending to test advanture ......");
	
	return EXIT_SUCCESS;
}
