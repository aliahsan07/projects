#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 12

//This randomly tests Adventurer

int main() {
	int r;
	int i;
	int j;
	int treasureCount;
	int treasureCountHand;
	int cardCheck;
	int oldDiscardCount;
	int oldDeckCount;
	int insufficentTreasures = 0;
	int assertFails = 0;
	int handTreasureFails = 0;
	int handCountFails = 0;
	int deckDiscardFails = 0;
	int players;
	int bonus = 0;
	int predictedHandCount;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
				sea_hag, tribute, smithy};
	struct gameState *game;
	srand(time(NULL));
	
	printf("Running random test for adventurer card\n");
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
		predictedHandCount = game->handCount[whoseTurn(game)] +1;
		oldDiscardCount = game->discardCount[whoseTurn(game)];
		oldDeckCount = game->deckCount[whoseTurn(game)];
		//two loops to check that there are enough treasures.
		//with the dominion implementation, if there aren't at least 2
		//treasure cards, the adventurer will loop infinitely.
		treasureCount=0;
		for(j = 0; j<game->deckCount[whoseTurn(game)]; j++){
			cardCheck = game->deck[whoseTurn(game)][i];
			if( cardCheck == copper || cardCheck == silver || cardCheck == gold) treasureCount++;
		}
		for(j = 0; j<game->discardCount[whoseTurn(game)]; j++){
			cardCheck = game->discard[whoseTurn(game)][i];
			if( cardCheck == copper || cardCheck == silver || cardCheck == gold) treasureCount++;
		}
		//establishes how many treasures are held.
		treasureCountHand = 0;
		for(j = 0; j<game->handCount[whoseTurn(game)]; j++){
			cardCheck = game->hand[whoseTurn(game)][i];
			if( cardCheck == copper || cardCheck == silver || cardCheck == gold) treasureCountHand++;
		}
		if (treasureCount >= 2){
			r = cardEffect(adventurer,0,0,0,game,1,&bonus);
			if(r != 0) {
				printf("Assert failed!\n");
				assertFails++;
			}
			for(j = 0; j<game->handCount[whoseTurn(game)]; j++){
				cardCheck = game->hand[whoseTurn(game)][i];
				if( cardCheck == copper || cardCheck == silver || cardCheck == gold) treasureCountHand--;
			}
			if(treasureCountHand != 0) {
				printf("Wrong number of treasures in hand!\n");
				handTreasureFails++;
			}
			if(predictedHandCount != game->handCount[whoseTurn(game)]) {
				printf("Hand count is wrong!\n");
				handCountFails++;
			}
			if((oldDeckCount+oldDiscardCount-1) != (game->deckCount[whoseTurn(game)]+game->discardCount[whoseTurn(game)])) {
				printf("Deck or discard counts were mangled!\n");
				deckDiscardFails++;
			}
		}
		else {
			printf("Loop predicted! Insufficient treasure.\n");
			insufficentTreasures++;
		}
		
		free(game);
	}
	printf("%d tests completed.\n",MAX_TESTS);
	printf("There were %d insufficient treasures.\n", insufficentTreasures);
	printf("There were %d assert fails.\n", assertFails);
	printf("There were %d treasure taken fails.\n", handTreasureFails);
	printf("There were %d hand count fails.\n", handCountFails);
	printf("There were %d deck or discard count mangles.\n", deckDiscardFails);
	printf("In total, %d tests failed.\n", insufficentTreasures+assertFails+handTreasureFails+handCountFails+deckDiscardFails);
}