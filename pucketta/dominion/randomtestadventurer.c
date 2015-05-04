#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//#define MAX_TESTS 4;

main(){

	printf("Running randomtestadventurer\n");
	
	int kingCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState G;
	struct gameState *p = &G;
	srand(time(NULL));
	int testPlayer = 1;
	int i;
	int players;
	int maxTests = 500;

	for(i = 0; i < maxTests; i++){

		players = rand() % 5;

		initializeGame(players, kingCards, rand(), p);

		p->discardCount[testPlayer] = rand() % MAX_DECK;
		p->deckCount[testPlayer] = rand() % MAX_DECK;
		p->handCount[testPlayer] = rand() % MAX_HAND;

		cardEffect(adventurer, -1, -1, -1, p, 1, -1);
	}
	printf("randomtestadventurer ran, all tests passed\n");
}