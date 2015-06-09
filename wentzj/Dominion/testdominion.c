#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main () {
	struct gameState G;
	srand(time(NULL));
	int list[500];
	int next = 0;
	int nextToo = 0;
	int toPlay;
	int toTake;
	int moneyCards[3];
	int supply[3];
    int players =((rand() %3) + 2);
    int seed = rand() % 1000 + 1;

	int k[20] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room, feast, remodel, baron, great_hall, steward, ambassador, outpost, salvager, treasure_map};

	
	for (int i = 0; i < 67; ++i)
	{
		int *a;
		a = k + (rand() % 20);
		int *b;
		b = k + (rand() % 20);
		
		int temp = *a;
		*a = *b;
		*b = temp;
		
		//swap(k + rand() % 20, k + rand() % 20);
	}
	printf("Kingdom cards: ");
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", k[i]);
	}
	initializeGame(players, k, seed, &G);
	printf("Number of Players: %d\n", players);
	int turn_number = 0;
    char str1[20];
    printf("PAUSED: ");
    scanf("%s", &str1);
	while(!isGameOver(&G)){
		printf("Whose turn it is: %d\n Turn number: %d", G.whoseTurn, turn_number);
		//char tempi[20];
		//fgets(tempi, 20, stdin);
		turn_number++;
		while(G.numActions>=1){
			next = 0;
			printf("hand: ");
			for (int i = 0; i < G.handCount[G.whoseTurn]; i++){
				printf("%d", G.hand[G.whoseTurn][i]);
				if (G.hand[G.whoseTurn][i] > gold && G.hand[G.whoseTurn][i] != gardens){
					list[next] = i;
					next++;
				}
			}
			printf("\n");
			//list contains cards we can play
			//and has length next
			if (next == 0){
				break;
			}
			
			toPlay = list[rand() % next];
			printf("Hand Position: %d\n", toPlay);
			printf("Card number: %d\n", G.hand[G.whoseTurn][toPlay]);
			nextToo = 0;
			int nextThree = 0;
			switch(G.hand[G.whoseTurn][toPlay]){
				case feast: ;

					int cardsToTake[17];
					for (int i = 0; i < 27; ++i)
					{
						if (G.supplyCount[i] > 0 && getCost(i)){
							cardsToTake[nextToo] = i;
							nextToo++;
						}
					}
					
					if (nextToo == 0){
						toTake = copper;
					}else{
						toTake = cardsToTake[rand() % nextToo];
					}
					
					
					playCard(toPlay, toTake, 0, 0, &G);
					printf("Choice 1 for Feast: %d\n", toTake);
					break;
				case mine:
					for (int i = 0; i < G.handCount[G.whoseTurn]; ++i)
					{
						if (G.hand[G.whoseTurn][i] == 4 || G.hand[G.whoseTurn][i] == 5 || G.hand[G.whoseTurn][i] == 6){
							moneyCards[nextToo] = i;
							nextToo++;

						}
					}
					int toTrash;
					if (nextToo == 0){
						toTrash = rand() % G.handCount[G.whoseTurn];
					}else{
						toTrash = moneyCards[rand() % nextToo];
					}
					
					int trashCost = getCost(G.hand[G.whoseTurn][toTrash]);
					for (int i = 4; i < 7; ++i)
					{
						if (G.supplyCount[i] > 0 && trashCost+3 >= getCost(i))
						{
							supply[nextThree] = i;
							nextThree++;
						}
					}
					int toPick;
					if (nextThree == 0)
					{
						toPick = copper;
					}else{
						toPick = supply[rand() % nextThree];
					}
					playCard(toPlay, toTrash, toPick, 0, &G);
					printf("Choice 1 & 2 for Mine: %d, %d\n", toTrash, toPick);
					break;
				case remodel:
					for (int i = 0; i < G.handCount[G.whoseTurn]; ++i)
					{
						
						moneyCards[nextToo] = i;
						nextToo++;

						
					}
					
					if (nextToo == 0){
						toTrash = rand() % G.handCount[G.whoseTurn];;
					} else{
						toTrash = moneyCards[rand() % nextToo];
					}
					
					trashCost = getCost(G.hand[G.whoseTurn][toTrash]);
					for (int i = 0; i < 27; ++i)
					{
						if (G.supplyCount[i] > 0 && trashCost+2 >= getCost(i))
						{
							supply[nextThree] = i;
							nextThree++;
						}
					}
					
					if (nextThree == 0)
					{
						toPick = copper;
					}else{
						toPick = supply[rand() % nextThree];
					}
					playCard(toPlay, toTrash, toPick, 0, &G);
					printf("Choice 1 & 2 for Remodel: %d, %d\n", toTrash, toTake);

					break;
				case baron: ;
					int disFlag;
			
					for (int i = 0; i < G.handCount[G.whoseTurn]; ++i){
						if (G.hand[G.whoseTurn][i] == estate){
							disFlag = 1;
							break;
						}
					}
					int option_1 = (rand() % 2) && disFlag;
					playCard(toPlay, option_1, 0, 0, &G);
					printf("Choice 1 for Baron: %d\n", option_1);
					break;
				case minion: ;
					int choice = (rand() % 2) +1;
					playCard(toPlay, choice, 0, 0, &G);
					printf("Choice 1 for Minion: %d\n", choice);
					break;
				case steward: ;
					int option = (rand() % 3) +1;
					if (option == 1)
					{
						playCard(toPlay, option, 0, 0, &G);
						printf("Choice 1 for Steward: %d\n", option);
					}
					else if (option == 2)
					{
						playCard(toPlay, option, 0, 0, &G);
						printf("Choice 2 for Steward: %d\n", option);
					}
					else if (option == 3)
					{
						int choice2 = rand() % G.handCount[G.whoseTurn];
						int choice3 = rand() % G.handCount[G.whoseTurn]; 
						playCard(toPlay, option, choice2, choice3, &G);
						printf("Choice 3 for Steward: %d, %d, %d\n", option, choice2, choice3);
					}
					break;
				case ambassador: ;
					int rand_card = rand() % G.handCount[G.whoseTurn];
					int countCard = 0;
					for (int i = 0; i < G.handCount[G.whoseTurn]; ++i)
					{
						if (G.handCount[G.whoseTurn] == rand_card)
						{
							countCard++;
							if (countCard == 2)
							{
								break;
							}
						}

					}
					playCard(toPlay, rand_card, countCard, 0,&G);
					printf("Choice 1, 2 for Ambassador: %d, %d\n", rand_card, countCard);
					break;
				case embargo: ;
					int supplies[27];
					//int chosen;
					for (int i = 0; i < 27; ++i)
					{
						if (G.supplyCount[i] > 0)
						{
							supplies[nextThree] = i;
							nextThree++;
						}
					}
					
					int chosen;
					if (nextThree == 0){
						chosen = copper;
					} else{
						chosen = supplies[rand() % nextThree];
					}

					playCard(toPlay, chosen, 0, 0, &G);
					printf("Choice 1 for Embargo: %d\n", chosen);
					break;
				case salvager:
					;
					int random_card = rand() % G.handCount[G.whoseTurn];
					playCard(toPlay, random_card, 0, 0, &G);
					printf("Choice 1 for Salvager: %d\n", random_card);
					break;
				default:
					playCard(toPlay, 0, 0, 0, &G);
					printf("All choices for Default: %d\n", 0);
					break;
			}
		}
		
		while(G.numBuys > 0){

			int other_list[27];
			int next_four = 0;
			for (int i = 0; i < 27; ++i)
			{
				if (G.supplyCount[i] > 0 && G.coins >= getCost(i))
				{
					other_list[next_four] = i;
					next_four++;
				}
			}
			if (next_four == 0)
			{
				break;
			}
			int pick = other_list[rand() % next_four];
			printf("Money to Spend: %d\n", G.coins);
			buyCard(pick, &G);
			printf("Card to buy: %d\n", pick);

		}
		endTurn(&G);
	}
}

