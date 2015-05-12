#include "dominion.h"
#include "dominion_helpers.h"
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

	//Randomize kingdom card quantities
	for (result = copper; result <= treasure_map; ++result){
		//Filter out cards that aren't in this gameState
		if (g->supplyCount[result] != -1){	
			g->supplyCount[result] = rand() % g->supplyCount[result];
		}
	}

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
	int runDebug = 0;

	srand(time(NULL));
	struct gameState* g;
	struct gameState* gcpy;
	int testPlyr, result, i, j;
	int errFlag = 0, errCount = 0;
	int choice, bonus = 0;
	int cardCtr[2][treasure_map + 1];

	int testCount, maxTests = 1000;
	for (testCount = 0; testCount < maxTests; ++testCount){
		g = getGameState();
		gcpy = newGame();
		memcpy(gcpy, g, sizeof(struct gameState));

		testPlyr = g->whoseTurn;

		choice = rand() % (treasure_map + 1);

		result = cardEffect(feast, choice, 0, 0, g, 0, &bonus);
		
		//Count cards by type and compare
		countCardTypes(gcpy, testPlyr, 0, cardCtr[0]);
		countCardTypes(g, testPlyr, 0, cardCtr[1]);

		//All non-chosen card values should not have changed
		for (i = 0; i < treasure_map + 1; ++i){
			if (i != choice && cardCtr[0][i] != cardCtr[1][i]){
				errFlag = 1;
				printf("Card count changed for ");
				printCardName(i);
				printf(" by %i.\n", cardCtr[1][i] - cardCtr[0][i]);
			}
		}

		
		//Ensure original hand wasn't altered
		if (g->handCount[testPlyr] != gcpy->handCount[testPlyr]){
			errFlag = 1;
			printf("Hand count changed error.\n");
		}
		else{
			for (i = 0; i < gcpy->handCount[testPlyr]; ++i){
				if (g->hand[testPlyr][i] != gcpy->hand[testPlyr][i]){
					errFlag = 1;
					printf("Hand alteration error\n");
				}
			}
		}
		
		//Ensure deck wasn't altered
		if (g->deckCount[testPlyr] != gcpy->deckCount[testPlyr]){
			errFlag = 1;
			printf("Deck count changed error.\n");
		}
		for (i = 0; i < g->deckCount[testPlyr]; ++i){
			if (g->deck[testPlyr][i] != gcpy->deck[testPlyr][i]){
				//Deck alteration error
				errFlag = 1;
				printf("Deck alteration error\n");
			}
		}

		//Check card supply numbers to ensure changes are only made to the chosen card
		for (i = curse; i <= treasure_map; ++i){
			if (i == choice && getCost(choice) < 6){
				if (g->supplyCount[i] != gcpy->supplyCount[i] - (gcpy->supplyCount[i] > 0 ? 1 : 0)){
					errFlag = 1;
					printf("Supply adjustment error (chosen card).  ");  printCardName(i); 
					printf(" changed by %i\n", gcpy->supplyCount[i] - g->supplyCount[i]);
				}
			}
			else{
				if (gcpy->supplyCount[i] != g->supplyCount[i]){
					errFlag = 1;
					printf("Supply adjustment error.  ");  printCardName(i);
					printf(" changed by %i\n", gcpy->supplyCount[i] - g->supplyCount[i]);
				}
			}
		}

		//Check for valid discard changes
		if (g->discardCount[testPlyr] > MAX_DECK){
			printf("\nExceeded discard size limit, player %i\n", testPlyr);
			errFlag = 1;
		}
		if (gcpy->supplyCount[choice] > 0 && getCost(choice) < 6 && g->discard[testPlyr][g->discardCount[testPlyr]-1] != choice){
			printf("\nChosen card not placed on discard\n");
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

		if ((gcpy->supplyCount[choice] <= 0 || getCost(choice) >= 6) 
			&& g->discard[testPlyr][g->discardCount[testPlyr] - 1] != choice
			&& result != -1){
			printf("\nFailure not indicated error.  Function returned: %i\n", result);
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
		
		if (runDebug)
		{
			printf("\nCard chosen:  ");	printCardName(choice);  printf("\n");
			printf("\nTest Run:  %i, Err Number:  %i\n", testCount + 1, errCount + errFlag);

			printPrePost(gcpy, g);
			printf("\n******End Error %i*******\n\n\n", errCount + errFlag);
		}

		if (errFlag != 0){
			if (!runDebug){
				printf("\nCard chosen:  ");	printCardName(choice);  printf("\n");
				printf("\nTest Run:  %i, Err Number:  %i\n", testCount + 1, ++errCount);

				printPrePost(gcpy, g);
				printf("\n******End Error %i*******\n\n\n", errCount);
			}
			errFlag = 0;
		}


		free(g);
		free(gcpy);
	}

	printf("\n\n******************Testing Completed*********************\n\n");
	printf("Tests:  %i  Errors Found:  %i\n\n", maxTests, errCount);

	return 0;
}