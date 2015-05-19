#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void testDomCode(struct gameState *s);
void testControl(struct gameState *s);
void info(struct gameState *g, struct gameState *t);


// random test adventurer

int main (int argc, char** argv) {
	struct gameState g;
	struct gameState t;
			 
	char testname[] = "Random Test Adventurer";
	int numtests = 12;
	int randseed = 123;
	int silent = 0;
	
	int i;
	int players;
	int c;
	while ((c = getopt(argc, argv, "t:r:q")) != -1) {
		switch (c) {
		case 't':
			numtests = atoi(optarg);
			break;
		case 'r':
			randseed = atoi(optarg);
			break;
		case 'q':
			silent = 1;
			break;
		default:
			break;
		}
	}
	
	srand(randseed);
	
	printf("Start %s\n", testname);
	
	for (i = 0; i < numtests; i++)
	{
		printf("\tRandom test number %i\n", i);
		
		memset(&g, 0, sizeof(struct gameState));
		g.numPlayers = rand() % 4 + 1;
		g.whoseTurn = rand() % g.numPlayers;
		g.phase = 0;
		g.numActions = 1;
		g.numBuys = 1;
		for (players = 0; players <= g.numPlayers; players++)
		{
			int numcards = rand() % 90 + 10; // cards player has is in range 10 - 100
			int discard = rand() % numcards;
			int cards;
			
			g.deckCount[players] = numcards;
			for (cards = 0; cards < numcards; cards++)
			{
				g.deck[players][cards] = rand() % 3 + 4; // only have copper through adventurer in deck
			}
			for (cards = 0; cards < discard; cards++) // discard some cards
			{
				drawCard(players, &g);
				g.discard[players][g.discardCount[players]++] = g.hand[players][0];
				discardCard(0, players, &g, 1);
			}
			for (cards = 0; cards < 5; cards++) // draw 5 cards
			{
				drawCard(players, &g);
			}
		}
		g.coins = updateCoins(g.whoseTurn, &g, 0);
		
		t = g;
		
		testControl(&g);
		testDomCode(&t);
		
		if (memcmp(&t, &g, sizeof(struct gameState)) == 0)
		{
			printf("\t\tPASS\n");
		}
		else 
		{
			printf("\t\tFAIL\n");
			if (silent == 0)
			{
				info(&g, &t);
			}
		}
	}
	
	printf("End %s\n", testname);

	return 0;
}

void testDomCode(struct gameState *s) {
	cardAdventurer(s);
	return;
}

void testControl(struct gameState *s) {
	int turn = s->whoseTurn;
	int moneydraw = 0;
	
	while(moneydraw < 2)
	{
		drawCard(turn, s);
		if (s->hand[turn][s->handCount[turn] - 1] == copper ||
			s->hand[turn][s->handCount[turn] - 1] == silver ||
			s->hand[turn][s->handCount[turn] - 1] == gold)
		{
			moneydraw ++;
		}
		else
		{
			s->discard[turn][s->discardCount[turn]++] = s->hand[turn][s->handCount[turn] - 1];
			discardCard(s->handCount[turn] - 1, turn, s, 1);
		}
	}
	return;
}

void info(struct gameState *g, struct gameState *t) {
	int i;
	int j;
	int players = 5;
	int cards = 101;
	if (t->numPlayers != g->numPlayers)
	{
		printf("\t\t\tnumPlayers %i  %i\n", t->numPlayers, g->numPlayers);
	}
	for (i = 0; i < treasure_map+1; i++)
	{
		if (t->supplyCount[i] != g->supplyCount[i])
		{
			printf("\t\t\tsupplyCount[%i] %i  %i\n", i, t->supplyCount[i], g->supplyCount[i]);
		}
	}
	for (i = 0; i < treasure_map+1; i++)
	{
		if (t->embargoTokens[i] != g->embargoTokens[i])
		{
			printf("\t\t\tembargoTokens[%i] %i  %i\n", i, t->embargoTokens[i], g->embargoTokens[i]);
		}
	}
	if (t->outpostPlayed != g->outpostPlayed)
	{
		printf("\t\t\toutpostPlayed %i  %i\n", t->outpostPlayed, g->outpostPlayed);
	}
	if (t->outpostTurn != g->outpostTurn)
	{
		printf("\t\t\toutpostTurn %i  %i\n", t->outpostTurn, g->outpostTurn);
	}
	if (t->whoseTurn != g->whoseTurn)
	{
		printf("\t\t\twhoseTurn %i  %i\n", t->whoseTurn, g->whoseTurn);
	}
	if (t->phase != g->phase)
	{
		printf("\t\t\tphase %i  %i\n", t->phase, g->phase);
	}
	if (t->numActions != g->numActions)
	{
		printf("\t\t\tnumActions %i  %i\n", t->numActions, g->numActions);
	}
	if (t->coins != g->coins)
	{
		printf("\t\t\tcoins %i  %i\n", t->coins, g->coins);
	}
	if (t->numBuys != g->numBuys)
	{
		printf("\t\t\tnumBuys %i  %i\n", t->numBuys, g->numBuys);
	}	
	for (i = 0; i < players; i++)
	{
		for (j = 0; j < cards; j++)
		{
			if (t->hand[i][j] != g->hand[i][j])
			{
				printf("\t\t\thand[%i][%i] %i  %i\n", i, j, t->hand[i][j], g->hand[i][j]);
			}
		}
	}
	for (i = 0; i < players; i++)
	{
		if (t->handCount[i] != g->handCount[i])
		{
			printf("\t\t\thandCount[%i] %i  %i\n", i, t->handCount[i], g->handCount[i]);
		}
	}	
	for (i = 0; i < players; i++)
	{
		for (j = 0; j < cards; j++)
		{
			if (t->deck[i][j] != g->deck[i][j])
			{
				printf("\t\t\tdeck[%i][%i] %i  %i\n", i, j, t->deck[i][j], g->deck[i][j]);
			}
		}
	}
	for (i = 0; i < players; i++)
	{
		if (t->deckCount[i] != g->deckCount[i])
		{
			printf("\t\t\tdeckCount[%i] %i  %i\n", i, t->deckCount[i], g->deckCount[i]);
		}
	}	
	for (i = 0; i < players; i++)
	{
		for (j = 0; j < cards; j++)
		{
			if (t->discard[i][j] != g->discard[i][j])
			{
				printf("\t\t\tdiscard[%i][%i] %i  %i\n", i, j, t->discard[i][j], g->discard[i][j]);
			}
		}
	}
	for (i = 0; i < players; i++)
	{
		if (t->discardCount[i] != g->discardCount[i])
		{
			printf("\t\t\tdiscardCount[%i] %i  %i\n", i, t->discardCount[i], g->discardCount[i]);
		}
	}
	for (i = 0; i < cards; i++)
	{
		if (t->playedCards[i] != g->playedCards[i])
		{
			printf("\t\t\tplayedCards[%i] %i  %i\n", i, t->playedCards[i], g->playedCards[i]);
		}
	}
	if (t->playedCardCount != g->playedCardCount)
	{
		printf("\t\t\tplayedCardCount %i  %i\n", t->playedCardCount, g->playedCardCount);
	}
	return;
}