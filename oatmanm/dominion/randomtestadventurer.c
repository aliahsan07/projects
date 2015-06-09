#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 10000
#define MAX_HAND 500
#define MAX_DECK 500
#define MAX_DISCARD 500

//This randomly tests adventurer

int main() {
	printf("Starting random testing for adventurer...\n");
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int cur, players, handCount, deckCount, discardCount, adventurerPos;
	int errorHandCount = 0, errorDiscardCount = 0, errorCardCount = 0, count = 0, treasureCount = 0;;
	int z = 0, y = 0;
	int cardDrawn;
	int drawntreasure = 0;
	int temphand[MAX_HAND];
	int seed;
	int errorTreaureCount = 0;

	srand(time(NULL));

	for (int i = 0; i < MAX_TESTS; i++){
		seed = rand();
		players = 2 + (rand() % 3);
		//printf("players = %d\n", players);
		cur = initializeGame(players, k, seed, &G);
		//printf("Finished initialize. %d\n", i);

		for (int j = 0; j < players; j++){

			G.whoseTurn = j;
			//printf("currentPlayer = %d\n", j);

			handCount = 1 + (rand() % (MAX_HAND - 1));
			//printf("hand = %d\n", handCount);
			deckCount = handCount + (rand() % (MAX_DECK - handCount));
			discardCount = rand() % MAX_DISCARD;
			//printf("Finished setting sizes. %d\n", i);

			G.handCount[j] = 0;
			G.deckCount[j] = deckCount;
			G.discardCount[j] = discardCount;
			//printf("Finished moving sizes. %d\n", i);

			for (int i = 0; i < deckCount; i++){
				if ((rand() % 2) == 0)
					G.deck[j][i] = 4 + (rand() % 3);
				else
					G.deck[j][i] = 7 + (rand() % 20);
				//G.deck[j][i] = rand() % 27;
				//G.deck[j][i] = 4;
			}
			for (int i = 0; i < discardCount; i++){
				if ((rand() % 2) == 0)
					G.discard[j][i] = 4 + (rand() % 3);
				else
					G.discard[j][i] = 7 + (rand() % 20);
				//G.discard[j][i] = rand() % 27;
				//G.discard[j][i] = 4;
			}

			adventurerPos = 1 + (rand() % handCount);
			G.deck[j][(deckCount - adventurerPos)] = adventurer;

			for (int k = 0; k < handCount; k++)
				drawCard(j, &G);
			//printf("Finished drawing. %d\n", i);

			/*printf("handCount = %d\n", handCount);
			printf("deckCount = %d\n", deckCount);
			printf("discardCount = %d\n", discardCount);*/

			count = G.deckCount[j];
			cardEffect(7, 0, 0, 0, &G, (adventurerPos - 1), 0);
			count = count - G.deckCount[j];
			//printf("Finished playing card. %d\n", i);

			/*printf("G.handCount = %d\n", G.handCount[j]);
			printf("G.deckCount = %d\n", G.deckCount[j]);
			printf("G.discardCount = %d\n", G.discardCount[j]);*/

			if (G.handCount[j] != (handCount + 1)){
				for(int i = 0; i < G.deckCount[j]; i++){
					if(G.deck[j][i] == 4 || G.deck[j][i] == 5 || G.deck[j][i] == 6)
						treasureCount++;
				}
				for(int i = 0; i < G.discardCount[j]; i++){
					if(G.discard[j][i] == 4 || G.discard[j][i] == 5 || G.discard[j][i] == 6)
						treasureCount++;
				}
				printf("Hand Count Error %d: Parameters: handCount = %d, deckCount = %d, discardCount = %d\n", (errorHandCount+1), handCount, (deckCount - handCount), discardCount);
				printf("	Final Parameters: handCount = %d, deckCount = %d, discardCount = %d\n", G.handCount[j], G.deckCount[j], G.discardCount[j]);
				printf("	Test number: %d/%d\n", i, MAX_TESTS);
				if(treasureCount < 2){
					printf("	Error caused by not enough treasure existing in the deck/discard\n");
					errorTreaureCount++;
				}
				errorHandCount++;
				treasureCount = 0;
			}
			if (G.discardCount[j] != (discardCount + count - 1)){
				printf("Discard Count Error %d: Parameters: handCount = %d, deckCount = %d, discardCount = %d\n", (errorDiscardCount+1), handCount, (deckCount - handCount), discardCount);
				printf("	Final Parameters: handCount = %d, deckCount = %d, discardCount = %d\n", G.handCount[j], G.deckCount[j], G.discardCount[j]);
				printf("	Test number: %d/%d\n", i, MAX_TESTS);
				errorDiscardCount++;
			}
			if ((G.handCount[j] + G.deckCount[j] + G.discardCount[j]) != (deckCount + discardCount)){
				printf("Missing Card Error %d: Total number of cards at the start: %d\n 	Total number of cards at the finish: %d\n", (errorCardCount+1), (deckCount + discardCount), (G.handCount[j] + G.deckCount[j] + G.discardCount[j]));
				printf("	Test number: %d/%d\n", i, MAX_TESTS);
				errorCardCount++;
			}
			count = 0;
		}
	}
	printf("Total number of errors in the handCount: %d/%d times played\n", errorHandCount, (MAX_TESTS * players));
	printf("Total number of errors in the discardCount: %d/%d times played\n", errorDiscardCount, (MAX_TESTS * players));
	printf("Total number of errors in the total card count: %d/%d times played\n", errorCardCount, (MAX_TESTS * players));
	printf("Total number of errors caused by not enough treasure existing in the deck: %d/%d\n", errorTreaureCount, errorHandCount);
	printf("Finished random testing adventurer.\n");
	return 0;
}