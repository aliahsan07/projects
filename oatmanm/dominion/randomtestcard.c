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
	printf("Starting random testing for council room...\n");
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int cur, players, handCount, deckCount, discardCount, seed, councilPos;
	int errorHandCount = 0, errorNumBuys = 0, errorOtherHandCount = 0, errorCardCount = 0;
	int countBefore[4], countAfter[4];
	int z = 0, y = 0;
	int cardDrawn;
	srand(time(NULL));

	for (int i = 0; i < MAX_TESTS; i++){
		seed = rand();
		players = 2 + (rand() % 3);
		//printf("players = %d\n", players);
		cur = initializeGame(players, k, seed, &G);

		for (int j = 0; j < players; j++){

			G.whoseTurn = j;
			G.numBuys = 1;
			//printf("currentPlayer = %d\n", j);

			handCount = 1 + (rand() % (MAX_HAND-1));
			deckCount = handCount + (rand() % (MAX_DECK - handCount));
			discardCount = rand() % MAX_DISCARD;

			for (int k = 0; k < players; k++)
				G.handCount[k] = 0;
			G.deckCount[j] = deckCount;
			G.discardCount[j] = discardCount;

			for (int i = 0; i < deckCount; i++){
				/*if ((rand() % 2) == 0)
					G.deck[j][i] = 4 + (rand() % 3);
				else
					G.deck[j][i] = 7 + (rand() % 20);*/
				G.deck[j][i] = rand() % 27;
			}
			for (int i = 0; i < discardCount; i++){
				/*if ((rand() % 2) == 0)
					G.discard[j][i] = 4 + (rand() % 3);
				else
					G.discard[j][i] = 7 + (rand() % 20);*/
				G.discard[j][i] = rand() % 27;
			}

			councilPos = 1 + (rand() % handCount);
			G.deck[j][(deckCount - councilPos)] = council_room;

			for (int k = 0; k < handCount; k++)
				drawCard(j, &G);

			/*printf("handCount = %d\n", handCount);
			printf("deckCount = %d\n", deckCount);
			printf("discardCount = %d\n", discardCount);*/

			for(int k = 0; k < players; k++)
				countBefore[k] = G.handCount[k];

			cardEffect(council_room, 0, 0, 0, &G, (councilPos - 1), 0);

			for(int k = 0; k < players; k++)
				countAfter[k] = G.handCount[k];

			/*printf("G.handCount = %d\n", G.handCount[j]);
			printf("G.deckCount = %d\n", G.deckCount[j]);
			printf("G.discardCount = %d\n", G.discardCount[j]);*/

			if(G.handCount[j] != (handCount+3)){
				printf("Hand Count Error %d: Parameters: handCount = %d, deckCount = %d, discardCount = %d\n", (errorHandCount+1), handCount, (deckCount - handCount), discardCount);
				printf("	Final Parameters: handCount = %d, deckCount = %d, discardCount = %d\n", G.handCount[j], G.deckCount[j], G.discardCount[j]);
				printf("	Test number: %d/%d\n", i, MAX_TESTS);
				errorHandCount++;
			}
			for(int k = 0; k < players; k++){
				if(k != j){
					if(G.handCount[k] != 1){
						printf("Other Player Hand Count Error %d: currentPlayer: %d Player: %d\n 	Parameters: handCount = %d, deckCount = %d, discardCount = %d\n", (errorHandCount+1), j, k, G.handCount[k], G.deckCount[k], G.discardCount[k]);
						printf("	Current Player Parameters: handCount = %d, deckCount = %d, discardCount = %d\n", G.handCount[j], G.deckCount[j], G.discardCount[j]);
						//printf("countBefore = %d\n", countBefore[k]);
						//printf("countAfter = %d\n", countAfter[k]);
						printf("	Test number: %d/%d\n", i, MAX_TESTS);
						errorOtherHandCount++;
					}
				}
			}
			if(G.numBuys != 2){
				printf("numBuys Error: The number of buys should be 2, it is: %d\n", G.numBuys);
				printf("	Test number: %d/%d\n", i, MAX_TESTS);
				errorNumBuys++;
			}
			if ((G.handCount[j] + G.deckCount[j] + G.discardCount[j]) != (deckCount + discardCount)){
				printf("Missing Card Error %d: Total number of cards at the start: %d\n 	Total number of cards at the finish: %d\n", (errorCardCount+1), (deckCount + discardCount), (G.handCount[j] + G.deckCount[j] + G.discardCount[j]));
				printf("	Test number: %d/%d\n", i, MAX_TESTS);
				errorCardCount++;
			}
		}
	}
	printf("Total number of errors in the handCount: %d/%d times played\n", errorHandCount, (MAX_TESTS * players));
	printf("Total number of errors in the other players handCount: %d/%d times played\n", errorOtherHandCount, (MAX_TESTS * players));
	printf("Total number of errors in the numBuys for the player: %d/%d times played\n", errorNumBuys, (MAX_TESTS * players));
	printf("Total number of errors in the total card count: %d/%d times played\n", errorCardCount, (MAX_TESTS * players));
	printf("Finished random testing council room.\n");
	return 0;
}