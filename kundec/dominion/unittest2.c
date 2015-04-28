#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

int *tempKC;
struct gameState *G;
int result;

void minTest()
{
	G = newGame();
	result = initializeGame(1, tempKC, 1, G);
	printf("minTest result %i\n", result);
	assert(result == -1);
	free(G);
	return;
}

void maxTest()
{
	G = newGame();
	result = initializeGame(5, tempKC, 1, G);
	printf("maxTest result %i\n", result);
	assert(result == -1);
	free(G);
	return;
}

void duplicateTest()
{
	G = newGame();
	int *dupTst = kingdomCards(feast, feast, mine, great_hall, cutpurse,
		treasure_map, outpost, smithy, gardens, embargo);
	result = initializeGame(2, dupTst, 1, G);
	printf("duplicateTest result %i\n", result);
	assert(result == -1);
	free(dupTst);
	free(G);
	return;
}

void printCardName(int card)
{
	switch (card)
	{
	case curse: printf("Curse"); break;
	case estate: printf("Estate"); break;
	case duchy: printf("Duchy"); break;
	case province: printf("Province"); break;
	case copper: printf("Copper"); break;
	case silver: printf("Silver"); break;
	case gold: printf("Gold"); break;
	case adventurer: printf("Adventurer"); break;
	case council_room: printf("Council Room"); break;
	case feast: printf("Feast"); break;
	case gardens: printf("Gardens"); break;
	case mine: printf("Mine"); break;
	case remodel: printf("Remodel"); break;
	case smithy: printf("Smithy"); break;
	case village: printf("Village"); break;
	case baron: printf("Baron"); break;
	case great_hall: printf("Great Hall"); break;
	case minion: printf("Minion"); break;
	case steward: printf("Steward"); break;
	case tribute: printf("Tribute"); break;
	case ambassador: printf("Ambassador"); break;
	case cutpurse: printf("Cutpurse"); break;
	case embargo: printf("Embargo"); break;
	case outpost: printf("Outpost"); break;
	case salvager: printf("Salvager"); break;
	case sea_hag: printf("Sea Hag"); break;
	case treasure_map: printf("Treasure Map"); break;
	default: printf("Error, not a card"); break;
	}
	return;
}

void displayState(int numPlayers)
{
	printf("\nTreasure Cards:\n");
	printf("Copper:  %i, Silver:  %i, Gold:  %i\n",
		G->supplyCount[copper], G->supplyCount[silver], G->supplyCount[gold]);

	printf("\nVictory Cards:\n");
	printf("Standard - Estate:  %i, Duchy:  %i,  Province:  %i,  Curse:  %i\n",
		G->supplyCount[estate], G->supplyCount[duchy], G->supplyCount[province], G->supplyCount[curse]);
	printf("Non-Standard (Count/Embargo)- Gardens:  %i/%i, Great Hall:  %i/%i\n",
		G->supplyCount[gardens], G->embargoTokens[gardens], G->supplyCount[great_hall], G->embargoTokens[great_hall]);

	printf("\nNon-Victory Cards (Count/Embargo):  \n");
	printf("Council Room:  %i/%i, Feast:  %i/%i,  Mine:  %i/%i,  Cutpurse:  %i/%i\n",
		G->supplyCount[council_room], G->embargoTokens[council_room], G->supplyCount[feast], G->embargoTokens[feast],
		G->supplyCount[mine], G->embargoTokens[mine], G->supplyCount[cutpurse], G->embargoTokens[cutpurse]);
	printf("Treasure Map:  %i/%i, Outpost:  %i/%i,  Smithy:  %i/%i,  Embargo:  %i/%i\n",
		G->supplyCount[treasure_map], G->embargoTokens[treasure_map], G->supplyCount[outpost], G->embargoTokens[treasure_map],
		G->supplyCount[smithy], G->embargoTokens[smithy], G->supplyCount[embargo], G->embargoTokens[embargo]);

	printf("\nUnused Cards (Count/Embargo):  \n");
	printf("Adventurer:  %i/%i, Remodel:  %i/%i, Village:  %i/%i, Baron:  %i/%i\n",
		G->supplyCount[adventurer], G->embargoTokens[adventurer], G->supplyCount[remodel], G->embargoTokens[remodel],
		G->supplyCount[village], G->embargoTokens[village], G->supplyCount[baron], G->embargoTokens[baron]);
	printf("Minion:  %i/%i, Steward:  %i/%i, Tribute:  %i/%i, Ambassador:  %i/%i\n",
		G->supplyCount[minion], G->embargoTokens[minion], G->supplyCount[steward], G->embargoTokens[steward],
		G->supplyCount[steward], G->embargoTokens[steward], G->supplyCount[ambassador], G->embargoTokens[ambassador]);
	printf("Salvager:  %i/%i, Sea Hag:  %i/%i\n",
		G->supplyCount[salvager], G->embargoTokens[salvager], G->supplyCount[sea_hag], G->embargoTokens[sea_hag]);

	int i, j; 
	for (i = 0; i < numPlayers; ++i)
	{
		printf("\nPlayer %i:  \n", i+1);
		printf("Player Hand Count:  %i\nPlayer Hand:  ", G->handCount[i]);
		int c = 5;
		if (G->handCount[i] != 5){ c = G->handCount[i]; }
		for (j = 0; j < c; ++j)
		{
			printCardName(G->hand[i][j]);
			printf(" ");
		}
		printf("\nPlayer Deck Count:  %i\nPlayer Deck:  ", G->deckCount[i]);
		c = 5;
		if (G->deckCount[i] != 5){ c = G->deckCount[i]; }
		for (j = 0; j < c; ++j)
		{
			printCardName(G->deck[i][j]);
			printf(" ");
		}
		printf("\nPlayer Discard Count:  %i\n", G->discardCount[i]);
	}

	printf("Game State values\n");
	printf("Outpost Played:  %i, Outpost Turn:  %i\n", G->outpostPlayed, G->outpostTurn);
	printf("Player's Turn:  %i, Phase:  %i, Actions Remaining:  %i, Buys Remaining:  %i, Coins:  %i, Cards Played:  %i\n", 
		G->whoseTurn, G->phase, G->numActions, G->numBuys, G->coins, G->playedCardCount);

	return;
}

void twoPlayerTest()
{
	printf("\n****************2-Player Setup Values********************\n");
	G = newGame();
	result = initializeGame(2, tempKC, 2, G);
	printf("twoPlayerTest result %i\n", result);
	assert(result == 0);
	assert(G->numPlayers == 2);
	
	displayState(2);

	free(G);
	return;
}

void threePlayerTest()
{
	printf("\n****************3-Player Setup Values********************\n");
	G = newGame();
	result = initializeGame(3, tempKC, 3, G);
	printf("threePlayerTest result %i\n", result);
	assert(result == 0);
	assert(G->numPlayers == 3);

	displayState(3);

	free(G);
	return;
}

void fourPlayerTest()
{
	printf("\n****************4-Player Setup Values********************\n");
	G = newGame();
	result = initializeGame(4, tempKC, 4, G);
	printf("fourPlayerTest result %i\n", result);
	assert(result == 0);
	assert(G->numPlayers == 4);

	displayState(4);

	free(G);
	return;
}

int main(int argc, char** argv) {
	
	printf("\n\nStarting Unit Test 2 (-initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)-)\n\n");
	
	tempKC = kingdomCards(council_room, feast, mine, great_hall, cutpurse,
		treasure_map, outpost, smithy, gardens, embargo);

	minTest();
	maxTest();
	duplicateTest();
	twoPlayerTest();
	threePlayerTest();
	fourPlayerTest();

	printf("\n*********************************************************\n");
	printf("Successfully finished Unit Test 2\n");
	printf("*********************************************************\n\n");
	return 0;
}