#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "interface.h"

#define MAX_TESTS 1
#define MAX_HAND 500
#define MAX_DECK 500
#define MAX_DISCARD 500

int main(){
	printf("Starting random testing for dominion...\n");
	srand(time(NULL));
	struct gameState G;
	int k[10], check[10];
	int z;
	int players, seed;
	int count = 0, totalCount = 0, initializeCount = 0, cardErrorCount = 0, turnCount = 0;
	int action, coinsToSpend, cardToBuy;
	int possibleCards[27];
	int possibleActions[MAX_HAND];
	int choice1, choice2, choice3;
	int index = 0;
	int decision;
	int handCount, deckCount, discardCount, numActions, numBuys, cardCount;
	int treasureCount = 0;
	int temp[MAX_HAND];
	char card[12];

	for (int i = 0; i < 10; i++)
		check[i] = 0;
	for (int x = 0; x < MAX_TESTS; x++){
		for (int i = 0; i < 10; i++)
			k[i] = 7 + (rand() % 20);
		for(int i = 0; i < 10; i++){
			z = k[i];
			for(int j = (i+1); j < 10; j++){
				if(z == k[j]){
					while(z == k[j]){
						k[j] = 7 + (rand() % 20);
						check[j]++;
					}
					i = -1;
				}
			}
		}
		seed = rand();
		players = 2 + (rand() % 3);
		initializeGame(2, k, 2, &G);

		printSupply(&G);

		for (int i = 0; i < 10; i++){
			if(G.supplyCount[k[i]] != 10){
				//printf("G.supplyCount for %d = %d\n", k[i], G.supplyCount[k[i]]);
				if(k[i] != great_hall && k[i] != gardens)
					count++;
			}
		}

		if(G.handCount[0] == 0 || count > 0){
			totalCount++;
			initializeCount++;
			/*for(int i = 0; i < 10; i++)
				printf("k[%d] = %d\n", i, k[i]);
			for(int i = 0; i < 10; i++)
				printf("check[%d] = %d\n", i, check[i]);*/
			printf("Error initializing game. Test number: %d\n", x);
			printSupply(&G);
			//printf("count = %d\n", count);
		}
		count = 0;

		while(!isGameOver(&G)){
		//for(int m = 0; m < 20; m++){
			printf("Player %d's Turn:******************************************************\n", G.whoseTurn);
			for(int i = 0; i < MAX_HAND; i++)
				possibleActions[i] = 0;

			//G.hand[G.whoseTurn][1] = treasure_map;

			//ACTION PHASE*************************************************************************************************
			printf("Action Phase...\n\n");
			printHand(G.whoseTurn, &G);

			for(int i = 0; i < G.numActions; i){

				for (int j = 0; j < MAX_HAND; j++)
					possibleActions[j] = -1;

				index = 0;
				for (int j = 0; j < G.handCount[G.whoseTurn]; j++){
					if(G.hand[G.whoseTurn][j] > 6 && G.hand[G.whoseTurn][j] != gardens && G.hand[G.whoseTurn][j] != great_hall){
						possibleActions[index] = j;
						index++;
					}
				}
				//index = 0;

				/*for(int j = 0; j < MAX_HAND; j++){
					if(possibleActions[j] != -1){
						printf("possibleActions[%d] = %d\n", j, possibleActions[j]);
						index++;
					}
				}*/


				//printf("decision = %d\n", decision);
				if (index > 0){

					action = rand() % index;

					cardNumToName(G.hand[G.whoseTurn][possibleActions[action]], &card);
					printf("Playing %s...\n", card);
					index = 0;
					switch(G.hand[G.whoseTurn][possibleActions[action]]){

						case adventurer:

							playCard(possibleActions[action], 0, 0, 0, &G);

							break;

						case council_room:

							playCard(possibleActions[action], 0, 0, 0, &G);

							break;

						case feast:

							for(int j = 1; j < 7; j++){
								if(getCost(j) < 6 && G.supplyCount[j] > 0){
									possibleCards[index] = j;
									index++;
								}
							}
							for(int j = 0; j < 10; j++){
								if(getCost(k[j]) < 6 && G.supplyCount[k[j]] > 0){
									possibleCards[index] = k[j];
									index++;
								}
							}

							decision = 1 + (rand() % index);

							playCard(possibleActions[action], possibleCards[decision], 0, 0, &G);

							index = 0;
							break;

						case mine:

							if(index > 0){
								for (int j = 0; j < G.handCount[G.whoseTurn]; j++){
									if(G.hand[G.whoseTurn][j] == copper || G.hand[G.whoseTurn][j] == silver || G.hand[G.whoseTurn][j] == gold){
										temp[index] = j;
										index++;
									}
								}
								choice1 = rand() % index;
							} else {
								break;
							}

							if(G.hand[G.whoseTurn][temp[choice1]] == copper)
								choice2 = 4 + (rand() % 2);
							if(G.hand[G.whoseTurn][temp[choice1]] == silver)
								choice2 = 4 +(rand() % 3);
							if(G.hand[G.whoseTurn][temp[choice1]] == gold)
								choice2 = 4 +(rand() % 4);

							playCard(possibleActions[action], temp[choice1], choice2, -1, &G);

							index = 0;
							break;

						case remodel:

							choice1 = rand() % G.handCount[G.whoseTurn];

							if(choice1 == possibleActions[action]){
								while(choice1 == possibleActions[action])
									choice1 = rand() % G.handCount[G.whoseTurn];
							}

							for(int j = 1; j < 7; j++){
								if((getCost(G.hand[G.whoseTurn][choice1])+2) >= getCost(j) && G.supplyCount[j] > 0){
									possibleCards[index] = j;
									index++;
								}
							}
							for(int j = 0; j < 10; j++){
								if((getCost(G.hand[G.whoseTurn][choice1])+2) >= getCost(k[j]) && G.supplyCount[k[j]] > 0){
									possibleCards[index] = k[j];
									index++;
								}
							}

							choice2 = possibleCards[(rand() % index)];

							z = playCard(possibleActions[action], choice1, choice2, -1, &G);

							break;

						case smithy:

							playCard(possibleActions[action], 0, 0, 0, &G);
							break;

						case village:

							playCard(possibleActions[action], 0, 0, 0, &G);
							break;

						case baron:

							choice1 = rand() % 2;
							playCard(possibleActions[action], choice1, -1, -1, &G);
							break;

						case minion:

							choice1 = 1 + (rand() % 2);
							playCard(possibleActions[action], choice1, -1, -1, &G);
							break;

						case steward:

							choice1 = 1 + (rand() % 3);
							choice2 = rand() % G.handCount[G.whoseTurn];
							if (choice2 == possibleActions[action]){
								while(choice2 == possibleActions[action])
									choice2 = rand() % G.handCount[G.whoseTurn];
							}
							choice3 = rand() % G.handCount[G.whoseTurn];
							if (choice3 == possibleActions[action] || choice3 == choice2){
								while(choice3 == possibleActions[action] || choice3 == choice2)
									choice3 = rand() % G.handCount[G.whoseTurn];
							}
							playCard(possibleActions[action], choice1, choice2, choice3, &G);
							break;

						case tribute:

							playCard(possibleActions[action], -1, -1, -1, &G);
							break;

						case ambassador:

							choice1 = rand() % G.handCount[G.whoseTurn];
							choice2 = rand() % 3;
							if (choice1 == possibleActions[action]){
								while(choice1 == possibleActions[action])
									choice1 = rand() % G.handCount[G.whoseTurn];
							}
							playCard(possibleActions[action], choice1, choice2, -1, &G);
							break;

						case cutpurse:

							playCard(possibleActions[action], -1, -1, -1, &G);
							break;

						case embargo:

							index = 0;
							for(int j = 1; j < 27; j++){
								if(G.supplyCount[j] > 0){
									possibleCards[index] = j;
									index++;
								}
							}
							choice1 = possibleCards[(rand() % index)];
							playCard(possibleActions[action], choice1, -1, -1, &G);
							break;

						case outpost:

							playCard(possibleActions[action], -1, -1, -1, &G);
							break;

						case salvager:

							choice1 = rand() % G.handCount[G.whoseTurn];
							if (choice1 == possibleActions[action]){
								while(choice1 == possibleActions[action])
									choice1 = rand() % G.handCount[G.whoseTurn];
							}
							playCard(possibleActions[action], choice1, -1, -1, &G);
							break;

						case sea_hag:

							playCard(possibleActions[action], -1, -1, -1, &G);
							break;

						case treasure_map:

							playCard(possibleActions[action], -1, -1, -1, &G);
							break;

					}
				}
				if (count == 10){
						//printf("Potential inifinite loop error. Breaking out of Action Phase.\n");
						//printState(&G);
						//printPlayed(G.whoseTurn, &G);
						//totalCount++;
						break;
				}
				count++;
			}

			printPlayed(G.whoseTurn, &G);
			printHand(G.whoseTurn, &G);
			printState(&G);

			//BUY PHASE*****************************************************************************************************

			printf("Buy Phase...\n\n");

			if(G.coins > 0)
				coinsToSpend = 1 + (rand() % G.coins);
			//printf("coinsToSpend = %d\n", coinsToSpend);

			index = 0;
			for (int j = 1; j < 7; j++){
				if(getCost(j) <= G.coins && G.supplyCount[j] > 0 && getCost(j) > 0){
					possibleCards[index] = j;
					index++;
				}
			}
			for (int j = 0; j < 10; j++){
				if(getCost(k[j]) <= G.coins && G.supplyCount[k[j]] > 0){
					possibleCards[index] = k[j];
					index++;
				}
			}

			count = 0;
			for (int j = 0; j < G.numBuys; j){

				if (index > 0){
					cardToBuy = rand() % index;
					buyCard(possibleCards[cardToBuy], &G);
					cardNumToName(possibleCards[cardToBuy], &card);
					printf("Buying %s...\n", card);
					//printf("G.coins = %d\n", G.coins);
				}
				if (count == 10){
					//printf("Potential inifinite loop error. Breaking out of Buy Phase.\n");
					//printState(&G);
					//printPlayed(G.whoseTurn, &G);
					//totalCount++;
					break;
				}
				count++;
			}
			index = 0;

			//printDiscard(G.whoseTurn, &G);

			printf("Ending Turn...\n\n");
			turnCount++;
			endTurn(&G);
		}

		printSupply(&G);
		printScores(&G);

		for (int i = 0; i < 10; i++)
			check[i] = 0;
		count = 0;
	}
	printf("The number of turns played in the game = %d\n", turnCount);
	/*printf("Initialize Errors = %d/%d\n", initializeCount, MAX_TESTS);
	printf("Card Errors = %d/%d\n", cardErrorCount, MAX_TESTS);
	printf("Total Number of Errors = %d/%d\n", totalCount, MAX_TESTS);*/
	return 0;
}