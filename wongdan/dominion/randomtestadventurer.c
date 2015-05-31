#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 500

int main() {
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	int i, j, numPlayers, currPlayer, handCount, deckCount, seed;
	int T1 = 0;
	int T2 = 0;
	int fails = 0;

	struct gameState state;	

	printf("***** Testing Random Adventurer Test *****\n\n");
	
	for (i = 0; i < MAX_TESTS; i++) {
		printf("*** Test %d ***\n", i+1);
			
		numPlayers = 2 + (rand() % 3);
		currPlayer = rand() % numPlayers;
		seed = rand();

		initializeGame(numPlayers, k, seed, &state);

		state.deckCount[currPlayer] = (rand() % MAX_DECK);
		state.discardCount[currPlayer] = rand() % MAX_DECK;
		state.handCount[currPlayer] = rand() % MAX_HAND;
		
		if (seed % 3 == 0) {
			state.deckCount[currPlayer] = 0;
		}

		handCount = state.handCount[currPlayer];
		deckCount = state.deckCount[currPlayer];

		for(j = 0; j < state.handCount[currPlayer]; j++) {
			if(state.hand[currPlayer][j] == copper) { 
				T1++;
			}
			if(state.hand[currPlayer][j] == silver) {
				T1++;
			}
			if(state.hand[currPlayer][j] == gold) {
				T1++;
			}
		}
	}
		
		cardEffect(adventurer, 0, 0, 0, &state, 0, 0);
		
		for(j = 0; j < state.handCount[currPlayer]; j++) {
			if(state.hand[currPlayer][j] == copper) { 
					T2++;
			}
			if(state.hand[currPlayer][j] == silver) { 
					T2++;
			}	
			if(state.hand[currPlayer][j] == gold) { 
					T2++;
			}
		}	
		printf("Treasures before playing Adventurer card: %d\n\n", T1);
		printf("Treasures after playing Adventurer card: %d\n\n", T2);

		if((T1 + 2) == T2) {
			printf("Test Passed!\n\n");
		}
		else{
			fails++;
		}

	printf("Tests failed: %d/%d\n\n",fails, MAX_TESTS);
return 0;
}
