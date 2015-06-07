#include "dominion.h"
#include "rngs.h"
#include "interface.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 12
#define INT_RAND_MAX 26 //useable cards numbered 7-26
#define INT_RAND_MIN 7
#define TOTAL_CARDS 27
#define MAX_HAND 500
#define MAX_DECK 500
#define MAX_DISCARD 500

void printArray(int arr[], int n)
{
	printf("Cards Selected: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int compare_ints(int x, int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (x == arr[i])
			return 1;
	}
		return 0;
}
//rand_int function based on Floyd's algorithm / code from http://stackoverflow.com/questions/1608181/unique-random-numbers-in-an-integer-array-in-the-c-programming-language
void rand_int(int arr[], int n)
{
	unsigned char is_used[INT_RAND_MAX] = { 0 }; 
	int i, j;
	int mod = INT_RAND_MAX - INT_RAND_MIN+1;

	j = 0;

	for (i = INT_RAND_MAX - n; i < INT_RAND_MAX && j < n; ++i) {
		int r = rand() % mod; 

		while (is_used[r])
			r = rand() % mod;
		

		assert(!is_used[r]);
		arr[j] = r + INT_RAND_MIN; 
		j++;
		is_used[r] = 1;
	}

	assert(j == n);
}


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void shuffle_array(int arr[], int n)
{

	for (int i = n - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);

		swap(&arr[i], &arr[j]);
	}
}

void setup_cards(int arr[], int n)
{
	rand_int(arr, n);
	shuffle_array(arr, n);
	printArray(arr, n);
}

//Used bot code from interface.h for testing purposes.
void executeTurn(int player, struct gameState *game)
{
	int coins = countHandCoins(player, game);
	int currentPlayer;

	printf("***************** Executing Player %d's Turn *****************\n", player);
	printSupply(game);
	printState(game);
	printHand(player, game);

	if (coins >= PROVINCE_COST && supplyCount(province, game) > 0) {
		buyCard(province, game);
		printf("Player %d buys card Province\n\n", player);
	}
	else if (supplyCount(province, game) == 0 && coins >= DUCHY_COST) {
		buyCard(duchy, game);
		printf("Player %d buys card Duchy\n\n", player);
	}
	else if (coins >= GOLD_COST && supplyCount(gold, game) > 0) {
		buyCard(gold, game);
		printf("Player %d buys card Gold\n\n", player);
	}
	else if (coins >= SILVER_COST && supplyCount(silver, game) > 0) {
		buyCard(silver, game);
		printf("Player %d buys card Silver\n\n", player);

	}

	endTurn(game);
	if (!isGameOver(game)) {
		currentPlayer = whoseTurn(game);

	}
}



int main()
{
	srand(time(NULL));
	
	int k[10];
	int i, n, j, y = 0, numPlayers, gameSeed, curPlayer, turnCount = 0, coins, indexTotal = 0, count = 0, handCount, deckCount, choice1, choice2, choice3;
	int startingPlayer;
	int cardsToBuy[TOTAL_CARDS - 1];

	struct gameState G;
	n = 10;
	for (i = 0; i < MAX_TESTS; i++)
	{
		setup_cards(k, n);
		gameSeed = rand();
		printf("Game Seed: %d\n", gameSeed);
		numPlayers = (rand() % 3) + 2;
		initializeGame(numPlayers, k, gameSeed, &G);
		printSupply(&G);
		//**********************************

		startingPlayer = rand() % numPlayers + 1;
		printf("Starting Player: %d\n", startingPlayer);

		G.whoseTurn = startingPlayer;
		while (!isGameOver(&G))
		{
			executeTurn(G.whoseTurn, &G);

			//**********************************initial info
		/*	printf("Player #: %d\n", G.whoseTurn);

			printHand(G.whoseTurn, &G);
			//**********************************action phase
			//action_phase();
			//**********************************buy phase
			
			
			if (G.coins < 2)
			{
				buyCard(copper, &G);
				return;
			}
			else if (G.coins >= getCardCost(silver) && G.coins < 6)
			{
				i = rand() % 10; //40% chance of buying silver
				if (i < 4)
				{
					buyCard(silver, &G);
					return;
				}
			}
			else
			{
				for (j = 0; j < G.numBuys; j++)
				{
				
					indexTotal = 0;
					for (j = 1; j < 6; j++)
					{
						if (getCardCost(j) <= G.coins && G.supplyCount[j] > 0)
							cardsToBuy[indexTotal++] = j;
					}
					for (j = 0; j < 10; j++)
					{
						if (getCardCost(k[j]) <= G.coins && G.supplyCount[k[j]] > 0)
							cardsToBuy[indexTotal++] = j;

					}
					if (indexTotal == 0)
					{
						return;
					}
					buyCard(cardsToBuy[rand() % indexTotal], &G);
					
				}
			}

			//**********************************

			//**********************************
			endTurn(&G);
			turnCount++;

			//**********************************
			*/
		}
		
		printScores(&G);
		//free(&G);
		//**********************************

		//**********************************

		//**********************************

		//**********************************

		//**********************************
		
	}

	return 0;
}