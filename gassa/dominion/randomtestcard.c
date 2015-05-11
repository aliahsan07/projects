#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1300

//smithy

int main() {

	 int r;
	int i;
	int j;
	int treasureCount;
	int treasureCountHand;
	int cardCheck;
	int oldDiscardCount;
	int oldDeckCount;
	int assertFails = 0;
	int handCountFails = 0;
	int deckDiscardFails = 0;
	int players;
	int bonus = 0;
	int predictedHandCount;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
				sea_hag, tribute, smithy};
	struct gameState *game;
	srand(time(NULL));
	
	printf("Running random test for smithy card\n");
	for(i = 0; i< MAX_TESTS; i++){
		//malloc new
		game = newGame();
		players = (rand() % 3) + 2;
		//Start the game up
		initializeGame(players,k,rand(),game);
		//randomize player conditions
		game->deckCount[whoseTurn(game)] = rand() % MAX_DECK;
		game->discardCount[whoseTurn(game)] = rand() % MAX_DECK;
		game->handCount[whoseTurn(game)] = rand() % MAX_HAND;
		if(rand()%3==0) game->deckCount[whoseTurn(game)] = 0;
		predictedHandCount = game->handCount[whoseTurn(game)] + 2;
		oldDiscardCount = game->discardCount[whoseTurn(game)];
		oldDeckCount = game->deckCount[whoseTurn(game)];
		
		r = cardEffect(smithy,0,0,0,game,rand(),&bonus);
		if(r != 0) {
			printf("Assert failed!\n");
			assertFails++;
		}
		if(predictedHandCount != game->handCount[whoseTurn(game)]) {
			printf("Hand count is wrong!\n");
			handCountFails++;
		}
		if((oldDeckCount+oldDiscardCount-2) != (game->deckCount[whoseTurn(game)]+game->discardCount[whoseTurn(game)])) {
			printf("Deck or discard counts were mangled!\n");
			deckDiscardFails++;
		}
		free(game);
	}
	printf("%d tests completed.\n",MAX_TESTS);
	printf("There were %d assert fails.\n", assertFails);
	printf("There were %d hand count fails.\n", handCountFails);
	printf("There were %d deck or discard count mangles.\n", deckDiscardFails);
	printf("In total, %d tests failed.\n", assertFails+handCountFails+deckDiscardFails);
}