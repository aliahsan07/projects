#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int checkState(struct gameState *prevState, struct gameState *nextState, int coin_bonus){
		
		//printf("# of handCount = %d and prev %d\n",nextState->handCount[nextState->whoseTurn],prevState->handCount[prevState->whoseTurn]);	
		//printf("# of actions = %d and prev %d\n",nextState->numActions,prevState->numActions);
		//printf("# of buys = %d and prev %d\n",nextState->numBuys,prevState->numBuys);
		//printf("# of played Count = %d and prev %d\n",nextState->playedCardCount,prevState->playedCardCount);	
		if((nextState->handCount[nextState->whoseTurn] - 1 ) != prevState->handCount[prevState->whoseTurn]){
			printf("Bug:  hand Count is not what it should be. Found %d and should be %d\n",nextState->handCount[nextState->whoseTurn] ,prevState->handCount[prevState->whoseTurn] + 1);
			return -1;
		}
		//***************************assert((nextState->handCount[nextState->whoseTurn] - 1 ) == prevState->handCount[prevState->whoseTurn]);		
		assert((nextState->numActions) == prevState->numActions);
		//assert((nextState->numBuys )== prevState->numBuys);
		assert((nextState->coins )== prevState->coins);
		if((nextState->playedCardCount - 1) != prevState->playedCardCount){
			printf("Bug:  played card Count is not what it should be. Found %d and should be %d\n",nextState->playedCardCount,prevState->playedCardCount + 1);
			return -1;
		}
		//**************************assert((nextState->playedCardCount - 1) == prevState->playedCardCount);

		assert(coin_bonus == 0);
		//does not increment discardCount
		//assert((nextState->discardCount[nextState->whoseTurn] - 1) == prevState->discardCount[prevState->whoseTurn] );
		//printf("# of deckCoutn = %d and prev %d\n",nextState->deckCount[nextState->whoseTurn],prevState->deckCount[prevState->whoseTurn]);		
		//assert((nextState->deckCount[nextState->whoseTurn] + 1) == prevState->deckCount[prevState->whoseTurn]);		

		return 0;
}


int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  int run_test_z_times = 3000; 
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("Starting test for village\n");




   srand(time(0)); 
  
    //Test card village
	//action card that gives
	//	+1 Card
	//  +2 Actions



	
	for (int z =0; z < run_test_z_times; z ++){
		int r = initializeGame(2, k, atoi(argv[1]), p);
		assert (r == 0);
		
		//get random number of players
		p->numPlayers = rand() % MAX_PLAYERS;
		
		p->numBuys = rand() % sizeof(int);
		p->coins = rand() % sizeof(int);
		p->numActions = rand() % sizeof(int);
		p->outpostPlayed = rand() % sizeof(int);
		p->outpostTurn = rand() % sizeof(int);
		p->phase = rand() % sizeof(int);
		for(int n = 0; n < p->numPlayers ; n++){
			p->whoseTurn = n;
			int coin_bonus = 0; 		//tracks coins gain from actions	
			//get a random size hand and fill it with random cards
			int hand_size = rand() % MAX_HAND;

			p->handCount[p->whoseTurn] = 0;
			for (int i=0; i < hand_size; i++){
				p->hand[p->whoseTurn][i] = rand() %(treasure_map);
				p->handCount[p->whoseTurn]++;
			}
			
			//get a random size deck and fill it with random cards
			int deck_size = rand() % MAX_HAND;
			p->deckCount[p->whoseTurn] = 0;
			for (int i=0; i < deck_size; i++){
				p->deck[p->whoseTurn][i] = rand() %(treasure_map);
				p->deckCount[p->whoseTurn]++;
			}
			
			//get a random size discard and fill it with random cards
			int  random_discard_size = rand() % MAX_HAND;
			p->discardCount[p->whoseTurn] = 0;
			for (int i=0; i < random_discard_size; i++){

				p->discard[p->whoseTurn][i] = rand() %(treasure_map);
				p->discardCount[p->whoseTurn]++;
			}
			
			//check if playing a card works
			struct gameState prevState;	
			memcpy(&prevState, p, sizeof(struct gameState));
			if(p->deckCount[p->whoseTurn] > 0){
				//printf("z= %d",z);
				if(cardEffect(adventurer, -1, -1, -1, p, 0, &coin_bonus) == 0){
					if(checkState(&prevState,p,coin_bonus) == -1){
							printf("passed failed for adventurer\n");
					}
					else{
							printf("passed test for adventurer\n");
					}
				}
			}
		}
	}


  return 0;
}
