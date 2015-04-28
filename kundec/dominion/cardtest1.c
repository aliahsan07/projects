#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

struct gameState *G;

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
		printf("\nPlayer %i:  \n", i + 1);
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
		for (j = 0; j < G->discardCount[i]; ++j)
		{
			printCardName(G->discard[i][j]);
			printf(" ");
		}
		printf("\n");
	}

	printf("Game State values\n");
	printf("Outpost Played:  %i, Outpost Turn:  %i\n", G->outpostPlayed, G->outpostTurn);
	printf("Player's Turn:  %i, Phase:  %i, Actions Remaining:  %i, Buys Remaining:  %i, Coins:  %i, Cards Played:  %i\n",
		G->whoseTurn, G->phase, G->numActions, G->numBuys, G->coins, G->playedCardCount);

	return;
}


int main() {
	printf("\nStarting Card Test 1 (Smithy)\n");

	int *tempKC = kingdomCards(council_room, feast, mine, great_hall, cutpurse,
		treasure_map, outpost, smithy, gardens, embargo);
	G = newGame();
	initializeGame(2, tempKC, 4, G);
	int turn1 = G->whoseTurn;
	int turn2 = turn1 + 1;

	//Assign first hand draw (deck must be identifiable)
	G->hand[turn1][0] = smithy;
	G->hand[turn1][1] = copper;
	G->hand[turn1][2] = copper;
	G->hand[turn1][3] = copper;
	G->hand[turn1][4] = copper;

	//Each Deck position should be different (identification)
	G->deck[turn1][0] = estate;
	G->deck[turn1][1] = silver;
	G->deck[turn1][2] = gold;
	G->deck[turn1][3] = village;
	G->deck[turn1][4] = minion;

	//Set 2nd player to keep deck identifiable
	G->deck[turn2][0] = estate;
	G->deck[turn2][1] = estate;
	G->deck[turn2][2] = copper;
	G->deck[turn2][3] = copper;
	G->deck[turn2][4] = copper;
	G->deck[turn2][5] = tribute;
	G->deck[turn2][6] = salvager;
	G->deck[turn2][7] = adventurer;
	G->deck[turn2][8] = baron;
	G->deck[turn2][9] = remodel;

	printf("\n*********Before card effect***********\n");
	displayState(2);

	int prevHandCount1 = G->handCount[turn1];
	int prevDeckCount1 = G->deckCount[turn1];
	int prevHandCount2 = G->handCount[turn2];
	int prevDeckCount2 = G->deckCount[turn2];

	cardEffect(smithy, 0, 0, 0, G, 0, 0);
	printf("\n*********After card effect***********\n");
	displayState(2);

	printf("Hand Count Before:  %i, Hand Count After:  %i\n", prevHandCount1, G->handCount[turn1]);
	printf("Deck Count Before:  %i, Deck Count After:  %i\n", prevDeckCount1, G->deckCount[turn1]);
	
	printf("2 - Hand Count Before:  %i, Hand Count After:  %i\n", prevHandCount2, G->handCount[turn2]);
	printf("2 - Deck Count Before:  %i, Deck Count After:  %i\n", prevDeckCount2, G->deckCount[turn2]);

	printf("\n*********************************************************\n");
	printf("*********Successfully finished Card Test 1***********\n");
	printf("*********************************************************\n\n");
	return 0;
}