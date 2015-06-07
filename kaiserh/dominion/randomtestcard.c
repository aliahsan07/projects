#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define TEST_COUNT 5000

int main (int argc, char *argv[]){
	struct gameState testState;
	int k[10] = {steward, adventurer, embargo, village, minion, mine, cutpurse, 
	    sea_hag, tribute, smithy};
	int i, j, seed, players, saveCount, saveCoin, x;
	int currentPlayer = 0;
	int choice1;
	int choice2;
	int choice3;
	srand(time(NULL));
	printf("Begin Steward Test...\n");
	
	for(i = 0; i < TEST_COUNT; i++){
		seed = rand();
		choice1 = rand() % 3;
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
			gainCard(5, &testState, 0, currentPlayer);
			gainCard(6, &testState, 0, currentPlayer);
		}
		gainCard(steward, &testState, 2, currentPlayer);
		if(testState.handCount[currentPlayer] >= 2){
			choice2 = rand() % (testState.handCount[currentPlayer]-1);
			choice3 = rand() % (testState.handCount[currentPlayer]-1);
		}
		else{
			if((choice1 != 1) && (choice1 != 2)){
				choice1 = ((rand() % 2) + 1);
			}
		}
		if (choice2 == choice3)
			choice2--;
		playCard((testState.handCount[currentPlayer]-1), choice1, choice2, choice3, 
			&testState);
			
		if (choice1 == 1)
			assert(testState.handCount[currentPlayer] == (saveCount + (2)));
		else if (choice1 == 2){
			assert(testState.coins == (saveCoin + (2)));
			assert(testState.handCount[currentPlayer] == (saveCount));
		}
		else
			assert(testState.handCount[currentPlayer] == (saveCount - (2)));
	}
	printf("\nSteward Test Complete\n");	
	return 0;
}
