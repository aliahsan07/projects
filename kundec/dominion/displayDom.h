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
	default: printf("Error, not a card (%i)", card); break;
	}
	return;
}

void displayState(struct gameState* G)
{
	int numPlayers = G->numPlayers;
	int i, j;

	printf("\nGame State values\n");
	printf("Outpost Played:  %i, Outpost Turn:  %i, Number of Players:  %i\n", G->outpostPlayed, G->outpostTurn, G->numPlayers);
	printf("Player's Turn:  %i, Phase:  %i, Actions Remaining:  %i, Buys Remaining:  %i, Coins:  %i,\n\t Cards Played:  %i\n",
		G->whoseTurn, G->phase, G->numActions, G->numBuys, G->coins, G->playedCardCount);

	if (G->playedCardCount > 0){
		printf("Played Cards: ");
		for (i = 0; i < MAX_DECK && i < G->playedCardCount; ++i){
			printCardName(G->playedCards[i]);
			printf(" ");
		}
		printf("\n");
	}

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

	for (i = 0; i < numPlayers; ++i)
	{
		printf("\nPlayer %i: \tHand:  %i\tDeck:  %i\tDiscard:  %i\n", 
			i+1, G->handCount[i], G->deckCount[i], G->discardCount[i]);
		
		if (G->handCount[i] > 0){
			printf("Player Hand:  ");
			for (j = 0; j < MAX_HAND && j < G->handCount[i]; ++j){
				printCardName(G->hand[i][j]);
				printf(" ");
			}
			printf("\n");
		}
		
		if (G->deckCount[i] > 0){
			printf("Player Deck:  ");
			for (j = 0; j < MAX_DECK && j < G->deckCount[i]; ++j){
				printCardName(G->deck[i][j]);
				printf(" ");
			}
			printf("\n");
		}

		if (G->discardCount[i] > 0){
			printf("Player Discard:  ");
			for (j = 0; j < MAX_DECK && j < G->discardCount[i]; ++j){
				printCardName(G->discard[i][j]);
				printf(" ");
			}
			printf("\n");
		}
	}

	printf("\n");
	return;
}

void printResult(int result){ printf("\nResult = %i\n", result); }

void printScoreBoard(struct gameState *g){
	int i;
	printf("Scoreboard:  ");
	for (i = 0; i < g->numPlayers; ++i){
		printf("Player %i:  %i\t", i + 1, scoreFor(i, g));
	}
	printf("\n\n");
}


void printState(struct gameState *g, struct gameState *gcpy){
	printf("\n\n ***************State Changed******************\n\n");
	displayState(g);
	printf("\n\n*******************End State********************\n\n");
	memcpy(gcpy, g, sizeof(struct gameState));
}

int stateChanged(struct gameState *g, struct gameState *gcpy){
	int i, j, chgFlag = 0;

	if (g->numPlayers != gcpy->numPlayers){
		printf("State change (number of Players)\n"); chgFlag = 1;
		if (g->numPlayers > MAX_DECK){
			printf("ERROR: State numPlayers exceeds max %i\n", g->numPlayers);
		}
	}
	if (g->outpostPlayed != gcpy->outpostPlayed){
		printf("State change (outpost flag)\n"); chgFlag = 1;
	}
	if (g->outpostTurn != gcpy->outpostTurn){
		printf("State change (outpost Turn)\n"); chgFlag = 1;
	}
	if (g->whoseTurn != gcpy->whoseTurn){
		printf("State change (Turn changed)\n"); chgFlag = 1;
	}
	if (g->phase != gcpy->phase){
		printf("State change (Phase changed)\n"); chgFlag = 1;
	}
	if (g->numActions != gcpy->numActions){
		printf("State change (Actions count changed)\n"); chgFlag = 1;
	}
	if (g->coins != gcpy->coins){
		printf("State change (Coins available changed)\n"); chgFlag = 1;
	}
	if (g->numBuys != gcpy->numBuys){
		printf("State change (Buys count changed)\n");  chgFlag = 1;
	}

	if (g->playedCardCount != gcpy->playedCardCount){
		printf("State change (played card count)\n"); chgFlag = 1;
		if (g->playedCardCount > MAX_DECK){
			printf("ERROR: State playedCardCount exceeds max (%i)\n", g->playedCardCount);
		}
	}
	for (i = 0; i < MAX_DECK && i < g->playedCardCount; ++i){
		if (i == gcpy->playedCardCount || g->playedCards[i] != gcpy->playedCards[i]){
			printf("State change (played Cards at index %i)\n", i); chgFlag = 1;
		}
	}

	for (i = 0; i < MAX_PLAYERS && i < g->numPlayers; ++i){
		if (g->handCount[i] != gcpy->handCount[i]){
			printf("Player %i handCount changed \n", i + 1); chgFlag = 1;
			if (g->handCount[i] > MAX_DECK){
				printf("ERROR: Player %i handCount exceeds max (%i)\n", i + 1, g->handCount[i]);
			}
		}
		for (j = 0; j < MAX_DECK && j < gcpy->handCount[i]; ++j){
			if (g->hand[i][j] != gcpy->hand[i][j]){
				printf("Player %i hand changed at index %i\n", i + 1, j); chgFlag = 1;
			}
		}

		if (g->deckCount[i] != gcpy->deckCount[i]){
			printf("Player %i deckCount changed \n", i + 1); chgFlag = 1;
			if (g->deckCount[i] > MAX_HAND){
				printf("ERROR: Player %i deckCount exceeds max (%i)\n", i, g->deckCount[i]);
			}
		}
		for (j = 0; j < MAX_DECK && j < gcpy->deckCount[i]; ++j){
			if (g->deck[i][j] != gcpy->deck[i][j]){
				printf("Player %i deck changed at index %i\n", i + 1, j); chgFlag = 1;
			}
		}

		if (g->discardCount[i] != gcpy->discardCount[i]){
			printf("Player %i discardCount changed \n", i + 1); chgFlag = 1;
			if (g->discardCount[i] > MAX_DECK){
				printf("ERROR: Player %i discardCount exceeds max (%i)\n", i + 1, g->discardCount[i]);
			}
		}
		for (j = 0; j < MAX_DECK && j < gcpy->discardCount[i]; ++j){
			if (g->discard[i][j] != gcpy->discard[i][j]){
				printf("Player %i discard changed at index %i\n", i + 1, j); chgFlag = 1;
			}
		}
	}

	return chgFlag;
}

int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);


#endif /* DISPLAYDOM_H_ */
