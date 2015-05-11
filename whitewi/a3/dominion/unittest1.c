#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

/*************************************************
 ** This unittest checks to see if newGame()	**
 ** works by checking that the struct returned	**
 ** has all required members.					**
 *************************************************/

int main (int argc, char** argv) {
	
	printf ("\n*********************\n");
	printf("Testing newGame.\n");
	
	struct gameState *G = newGame();
	
	printf("Checking that returned struct contains numPlayers.\n");
	G->numPlayers = 1;
	assert(G->numPlayers == 1);
	printf("Checking that returned struct contains supplyCount.\n");
	G->supplyCount[0] = 1;
	assert(G->supplyCount[0] == 1);
	printf("Checking that returned struct contains embargoTokens.\n");
	G->embargoTokens[0] = 1;
	assert(G->embargoTokens[0] == 1);
	printf("Checking that returned struct contains outpostPlayed.\n");
	G->outpostPlayed = 1;
	assert(G->outpostPlayed == 1);
	printf("Checking that returned struct contains outpostTurn.\n");
	G->outpostTurn = 1;
	assert(G->outpostTurn == 1);
	printf("Checking that returned struct contains whoseTurn.\n");
	G->whoseTurn = 1;
	assert(G->whoseTurn == 1);
	printf("Checking that returned struct contains phase.\n");
	G->phase = 1;
	assert(G->phase == 1);
	printf("Checking that returned struct contains numActions.\n");
	G->numActions = 1;
	assert(G->numActions == 1);
	printf("Checking that returned struct contains coins.\n");
	G->coins = 1;
	assert(G->coins == 1);
	printf("Checking that returned struct contains numBuys.\n");
	G->numBuys = 1;
	assert(G->numBuys == 1);
	printf("Checking that returned struct contains hand.\n");
	G->hand[0][0] = 1;
	assert(G->hand[0][0] == 1);
	printf("Checking that returned struct contains handCount.\n");
	G->handCount[0] = 1;
	assert(G->handCount[0] == 1);
	printf("Checking that returned struct contains deck.\n");
	G->deck[0][0] = 1;
	assert(G->deck[0][0] == 1);
	printf("Checking that returned struct contains deckCount.\n");
	G->deckCount[0] = 1;
	assert(G->deckCount[0] == 1);
	printf("Checking that returned struct contains discard.\n");
	G->discard[0][0] = 1;
	assert(G->discard[0][0] == 1);
	printf("Checking that returned struct contains discardCount.\n");
	G->discardCount[0] = 1;
	assert(G->discardCount[0] == 1);
	printf("Checking that returned struct contains playedCards.\n");
	G->playedCards[0] = 1;
	assert(G->playedCards[0] == 1);
	printf("Checking that returned struct contains playedCardCount.\n");
	G->playedCardCount = 1;
	assert(G->playedCardCount == 1);
	printf("Test passed.  Struct passed in by newGame() has all required parts.\n");
    printf ("*********************\n");

  return 0;
}
