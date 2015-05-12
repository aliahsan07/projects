#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define TEST_COUNT 2500

int main (int argc, char *argv[]){
	struct gameState testState;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	    sea_hag, tribute, smithy};
	int i, j, seed, players, saveCount, saveCoin, x;
	int currentPlayer = 0;
	int choice1;
	int choice2;
	int choice3;
	srand(time(NULL));	
	printf("Begin Adventurer Test...\n");
	
	for(i = 0; i < TEST_COUNT; i++){
		seed = rand();
		choice1 = rand() % 3;
		choice2 = rand() % 3;
		choice3 = rand() % 3;		
		players = (rand() % 3) + 2;
		assert(players < 5);
		currentPlayer = rand() % 4;
		assert(currentPlayer < 4);
		if (currentPlayer >= players)
			currentPlayer = players - 1;
		x = initializeGame(players, k, seed, &testState);
        if (x == -1)
            printf("INITIALIZE ERROR\n");
        testState.whoseTurn = currentPlayer;
		j = rand() % 6;
		for (; j < 5; j++){
			x = drawCard(currentPlayer, &testState);
		    if (x == -1)
                printf("DRAW ERROR\n");
        }
		assert(testState.handCount[currentPlayer] >= 0);		
		saveCount = testState.handCount[currentPlayer];
		updateCoins(currentPlayer, &testState, 0);
		saveCoin = testState.coins;
		if (testState.deckCount[currentPlayer] < 5){
			gainCard(silver, &testState, 0, currentPlayer);
			gainCard(gold, &testState, 0, currentPlayer);
		}
		testState.hand[currentPlayer][testState.handCount[currentPlayer]] = adventurer;
		testState.handCount[currentPlayer]++;
		playCard((testState.handCount[currentPlayer]-1), choice1, choice2, 
			choice3, &testState);
				
		assert(testState.handCount[currentPlayer] == (saveCount+2));
        
		updateCoins(currentPlayer, &testState, 0);
		assert(testState.coins >= (saveCoin + 2));
        
		memset(&testState, 0, sizeof(struct gameState));
	}
	printf("\nAdventurer Test Complete\n");
	
	return 0;
}
