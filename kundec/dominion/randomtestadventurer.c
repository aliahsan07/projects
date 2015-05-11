#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "displayDom.h"

void fillCards(int maxFill, int* list) {
	int i;
	for (i = 0; i < maxFill; ++i) {
		list[i] = rand() % (treasure_map + 1);
	}
	return;
}

struct gameState* getGameState() {
	int base = treasure_map - adventurer + 1;
	int *k, testPlyr;
	struct gameState* g;
	int result = -1;
	g = newGame();
	for (result = -1; result == -1;) {
		k = kingdomCards(rand() % base + adventurer, rand() % base + adventurer,
				rand() % base + adventurer, rand() % base + adventurer,
				rand() % base + adventurer, rand() % base + adventurer,
				rand() % base + adventurer, rand() % base + adventurer,
				rand() % base + adventurer, rand() % base + adventurer);
		result = initializeGame(rand() % 3 + 2, k, rand(), g);

		if (result == -1) { free(k); }
	}

	testPlyr = rand() % g->numPlayers;
	g->whoseTurn = testPlyr;

	//Generate test player's hand
	g->handCount[testPlyr] = rand() % (MAX_HAND + 1);

	fillCards(g->handCount[testPlyr], g->hand[testPlyr]);

	//Generate test player's deck
	g->deckCount[testPlyr] = rand() % (MAX_DECK + 1);

	fillCards(g->deckCount[testPlyr], g->deck[testPlyr]);

	g->discardCount[testPlyr] = rand() % (MAX_DECK + 1);

	fillCards(g->discardCount[testPlyr], g->discard[testPlyr]);

	return g;
}

int* countCardTypes(struct gameState *g, int p, int handC, int* c){
	int i;
	for (i = 0; i <= treasure_map; ++i){
		c[i] = 0;
	}

	for (i = 0; i < g->deckCount[p]; ++i){
		c[g->deck[p][i]]++;
	}
	for (i = 0; i < g->discardCount[p]; ++i){
		c[g->discard[p][i]]++;
	}
	for (i = 0; i < handC && g->handCount[p] - i - 1 >= 0; ++i){
		c[g->hand[p][g->handCount[p] - i - 1]]++;
	}
	return c;
}

void printPrePost(struct gameState *pre, struct gameState *post){
	printf("\n\n ***************Before******************\n\n");
	displayState(pre);

	printf("\n\n ***************After******************\n\n");
	displayState(post);

}

int main()
{
	srand(time(NULL));
	struct gameState* g;
	struct gameState* gcpy;
	int testPlyr, deckCtr, i, j;
	int bonus = 0, errFlag = 0, errCount = 0;
	int cardCtr[2][treasure_map + 1];

	int testCount, maxTests = 100000;
	for (testCount = 0; testCount < maxTests; ++testCount){
		g = getGameState();
		gcpy = newGame();
		memcpy(gcpy, g, sizeof(struct gameState));

		testPlyr = g->whoseTurn;

		cardEffect(adventurer, 0, 0, 0, g, 0, &bonus);

		if (g->handCount[testPlyr] - gcpy->handCount[testPlyr] > 2){
			//Too many cards added error
			errFlag = 1;
			printf("Too many cards added error\n");
		}

		//Count cards by type and compare
		countCardTypes(gcpy, testPlyr, 0, cardCtr[0]);
		countCardTypes(g, testPlyr, g->handCount[testPlyr] - gcpy->handCount[testPlyr], cardCtr[1]);

		//Shuffle required?
		deckCtr = 0;
		for (i = 0; i < gcpy->deckCount[testPlyr]; ++i){
			if (gcpy->deck[testPlyr][i] >= copper && gcpy->deck[testPlyr][i] <= gold)
				++deckCtr;
		}

		for (i = 0; i < treasure_map + 1; ++i){
			if (cardCtr[0][i] != cardCtr[1][i]){
				errFlag = 1;
				printf("Card count changed for ");
				printCardName(i);
				printf(" by %i.\n", cardCtr[1][i] - cardCtr[0][i]);
			}
		}

		//Ensure original hand wasn't altered
		if (g->handCount[testPlyr] < gcpy->handCount[testPlyr] + (deckCtr>2 ? 2 : deckCtr)){
			errFlag = 1;
			printf("Hand alteration error.\n");
		}
		else{
			for (i = 0; i < gcpy->handCount[testPlyr]; ++i){
				if (g->hand[testPlyr][i] != gcpy->hand[testPlyr][i]){
					//Hand alteration error
					errFlag = 1;
					printf("Hand alteration error\n");
				}
			}
		}

		//Ensure deck wasn't altered without a shuffle needed
		if (deckCtr >= 2){
			for (i = 0; i < g->deckCount[testPlyr]; ++i){
				if (g->deck[testPlyr][i] != gcpy->deck[testPlyr][i]){
					//Deck alteration error
					errFlag = 1;
					printf("Deck alteration error\n");
				}
			}
		}

		//Not enough treasure in the combined deck and discard
		deckCtr = (cardCtr[0][copper] + cardCtr[0][silver] + cardCtr[0][gold]);
		if (deckCtr < 2){
			if (g->discardCount[testPlyr] <
				(gcpy->discardCount[testPlyr] + gcpy->deckCount[testPlyr]) - deckCtr){
				//Treasure count exception error
				errFlag = 1;
				printf("Treasure count exception error\n");
			}
		}

		//Check card supply numbers to ensure changes are only made to the chosen card
		for (i = curse; i <= treasure_map; ++i){
			if (gcpy->supplyCount[i] != g->supplyCount[i]){
				errFlag = 1;
				printf("Supply adjustment error.  ");  printCardName(i);
				printf(" changed by %i\n", gcpy->supplyCount[i] - g->supplyCount[i]);

			}
		}

		//Check for valid discard changes
		if (g->discardCount[testPlyr] > MAX_DECK){
			printf("\nExceeded discard size limit, player %i\n", testPlyr);
			errFlag = 1;
		}
		if (g->deckCount[testPlyr] > MAX_DECK){
			printf("\nExceeded deck size limit, player %i\n", testPlyr);
			errFlag = 1;
		}
		if (g->handCount[testPlyr] > MAX_DECK){
			printf("\nExceeded hand size limit, player %i\n", testPlyr);
			errFlag = 1;
		}

		if (g->whoseTurn != gcpy->whoseTurn){
			printf("\nState change error (Turn changed)\n");
			errFlag = 1;
		}
		if (g->phase != gcpy->phase){
			printf("\nState change error (Phase changed)\n");
			errFlag = 1;
		}
		if (g->numActions != gcpy->numActions){
			printf("\nState change error (Actions count changed)\n");
			errFlag = 1;
		}
		if (g->coins != gcpy->coins){
			printf("\nState change error (Coins available changed)\n");
			errFlag = 1;
		}
		if (g->numBuys != gcpy->numBuys){
			printf("\nState change error (Buys count changed)\n");
			errFlag = 1;
		}

		for (i = 0; i < g->numPlayers; ++i){
			if (i != testPlyr){

				if (g->handCount[i] != gcpy->handCount[i]){
					printf("Player %i handCount changed \n", i); errFlag = 1;
				}
				for (j = 0; j < gcpy->handCount[i]; ++j){
					if (g->hand[i][j] != gcpy->hand[i][j]){
						printf("Player %i hand changed at index %i\n", i, j); errFlag = 1;
					}
				}

				if (g->deckCount[i] != gcpy->deckCount[i]){
					printf("Player %i deckCount changed \n", i); errFlag = 1;
				}
				for (j = 0; j < gcpy->deckCount[i]; ++j){
					if (g->deck[i][j] != gcpy->deck[i][j]){
						printf("Player %i deck changed at index %i\n", i, j); errFlag = 1;
					}
				}

				if (g->discardCount[i] != gcpy->discardCount[i]){
					printf("Player %i discardCount changed \n", i); errFlag = 1;
				}
				for (j = 0; j < gcpy->discardCount[i]; ++j){
					if (g->discard[i][j] != gcpy->discard[i][j]){
						printf("Player %i discard changed at index %i\n", i, j); errFlag = 1;
					}
				}
			}
		}

		if (errFlag != 0){ 

			printf("\n\nTest Run:  %i, Err Number:  %i\n", testCount+1, ++errCount);

			printPrePost(gcpy, g); 
			printf("\n******End Error %i*******\n\n\n", errCount-1);
			
			errFlag = 0; 
		}
		free(g);
		free(gcpy);
	}

	printf("\n\n******************Testing Completed*********************\n\n");
	printf("Tests:  %i  Errors Found:  %i\n\n", maxTests, errCount);

	return 0;
}
