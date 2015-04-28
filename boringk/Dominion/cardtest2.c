#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int checkState(struct gameState *prevState, struct gameState *nextState, int coin_bonus){
		assert((nextState->handCount[nextState->whoseTurn] - 3) == prevState->handCount[prevState->whoseTurn]);
		assert((nextState->numActions )== prevState->numActions);
		assert((nextState->numBuys - 1)== prevState->numBuys);
		assert((nextState->coins )== prevState->coins);
		assert((nextState->playedCardCount - 1) == prevState->playedCardCount);
		assert(coin_bonus == 0);
		//does not increment discardCount
		//assert((nextState->discardCount[nextState->whoseTurn] - 1) == prevState->discardCount[prevState->whoseTurn] );
		assert((nextState->deckCount[nextState->whoseTurn] + 4) == prevState->deckCount[prevState->whoseTurn]);		
		
		//Check that all other players draw a card
		  for (int i = 0; i < nextState->numPlayers; i++)
		{
		  if ( i != nextState->whoseTurn && prevState->deckCount[i] > 0)
			{
			  //printf("hand = %d\n",nextState->handCount[i]);
			  assert(nextState->handCount[i] - 1 == prevState->handCount[i]);
			}
		}
		return 0;
}


int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("Starting test for council room\n");
  
  int r = initializeGame(2, k, atoi(argv[1]), p);

  assert (r == 0);
    //Test card council room
	//action card that gives
	//	+4 Cards
	//  +1 Buy
	// all other players must draw one card
	int coin_bonus = 0; 		//tracks coins gain from actions
	struct gameState prevState;
	
	memcpy(&prevState, p, sizeof(struct gameState));
	if(cardEffect(council_room, -1, -1, -1, p, 0, &coin_bonus) == 0){
		checkState(&prevState,p,coin_bonus);
	}

	//test for a full hand with random cards fails 
	//with a full deck
	srand(time(0));

	p->handCount[p->whoseTurn] = 0;
	for (int i=0; i < 100; i++){
		p->hand[p->whoseTurn][i] = rand() %(treasure_map);
		p->handCount[p->whoseTurn]++;
	}
	for (int i=0; i < MAX_DECK; i++){
		p->deck[p->whoseTurn][i] = rand() %(treasure_map);
		p->deckCount[p->whoseTurn]++;
	}
	
	
	for(int x =0; x <= 100; x++){
		memcpy(&prevState, p, sizeof(struct gameState));
		if(cardEffect(council_room, -1, -1, -1, p, 0, &coin_bonus) == 0){
			checkState(&prevState,p,coin_bonus);
		}
	}
	
	//check for only 1 card in hand
	p->hand[p->whoseTurn][0] = council_room;
	p->handCount[p->whoseTurn] = 1;
	memcpy(&prevState, p, sizeof(struct gameState));
	if(cardEffect(council_room, -1, -1, -1, p, 0, &coin_bonus) == 0){
			checkState(&prevState,p,coin_bonus);
	}
	

	

	printf("passed test for council room\n");
  return 0;
}
