/*
 * displayDom.h
 *
 *  Created on: May 7, 2015
 *      Author: Chad Kunde
 */

#ifndef DISPLAYDOM_H_
#define DISPLAYDOM_H_

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

void displayState(struct gameState* G)
{
	int numPlayers = G->numPlayers;

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
		
		for (j = 0; j < G->handCount[i]; ++j)
		{
			printCardName(G->hand[i][j]);
			printf(" ");
		}
		
		printf("\nPlayer Deck Count:  %i\nPlayer Deck:  ", G->deckCount[i]);
		
		for (j = 0; j < G->deckCount[i]; ++j)
		{
			printCardName(G->deck[i][j]);
			printf(" ");
		}
		
		printf("\nPlayer Discard Count:  %i\nPlayer Discard: ", G->discardCount[i]);
		for (j = 0; j < G->discardCount[i]; ++j)
		{
			printCardName(G->discard[i][j]);
			printf(" ");
		}
	}

	printf("\nGame State values\n");
	printf("Outpost Played:  %i, Outpost Turn:  %i\n", G->outpostPlayed, G->outpostTurn);
	printf("Player's Turn:  %i, Phase:  %i, Actions Remaining:  %i, Buys Remaining:  %i, Coins:  %i, Cards Played:  %i\n",
		G->whoseTurn, G->phase, G->numActions, G->numBuys, G->coins, G->playedCardCount);

	return;
}

int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);


#endif /* DISPLAYDOM_H_ */
