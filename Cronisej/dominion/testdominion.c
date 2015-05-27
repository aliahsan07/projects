#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 12
#define INT_RAND_MAX 26 //useable cards numbered 7-26
#define INT_RAND_MIN 7
#define Total_CARDS 27
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


void playgame(int numPlayers, int seed, int k[], struct gameState *G)
{
	int i, j, n, curPlayer, turnCount;
	initializeGame(numPlayers, k, seed, &G);
	
	while (!isGameOver(&G))
	{
		turn(G->whoseTurn, &G, turnCount);
	}

	free(G);
}

int turn(int curPlayer, struct gameState *G, int turnCount)
{
	int i, j, n, curPlayer, handCount, deckCount, numCoins, choice1, choice2, choice3;
		printHand(curPlayer, &G);
		money_phase();
		numCoins = G->coins;
		buy_phase(&G, numCoins, turnCount);

		endTurn(&G);
		return turnCount + 1;
}

void action_phase()
{
	
}

void buy_phase(struct gameState *G, int numCoins, int numTurns)
{
	int buy_switch = numTurns % 2;

		if (buy_switch == 0)
		{
		if (numCoins >= 8)
		{
			buyCard(province, G);
		}
		else if(numCoins >= 6)
		{
			buyCard(gold, G);
		}
		else if (numCoins >= 3)
		{
			buyCard(silver, G);
		}
		else if (numCoins >= 0)
		{
			buyCard(copper, G);
		}
		}
		else
		{

		}
}



int main()
{
	srand(time(NULL));
	
	int k[10];
	int i, n, numPlayers, gameSeed;
	struct gameState *G = NULL;
	n = 10;
	for (i = 0; i < MAX_TESTS; i++)
	{
		setup_cards(k, n);
		gameSeed = rand();
		printf("Game Seed: %d\n", gameSeed);
		numPlayers = (rand() % 3) + 2;
		G = newGame();
		playgame(numPlayers, gameSeed, k, &G);

	}

	return 0;
}