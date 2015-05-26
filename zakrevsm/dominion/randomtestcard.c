#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEST 100

int determineChoice(int choice){
	switch(choice){
		case 0: 
		return -1;
		
		case 1: 
		return 0;
		
		case 2: 
		return 1;
		
		default: 
		return 1;
	}
	 
}

int main(int argc, char* argv[]){
	srand(time(NULL));
//	struct gameState state;
//	struct gameState *p = &state;
	int k[10] = {village,steward , council_room, gardens, mine, baron, sea_hag, smithy, minion, outpost};
	int i, j,m;
	int pos = -1;
	int coin_bonus = 0;
	int seed = (rand()%2000+1);
	int numplayers;
	int cur_player;
	int c1, c2, c3;

	for (i = 0 ; i < MAX_TEST; i++){
		struct gameState *p = malloc (sizeof(struct gameState));
		
		numplayers = (rand()%2+2);
		seed = (rand() % 2000+1);
		coin_bonus = (rand() % 30);
	
		
		initializeGame(numplayers,k, seed,p); 
		p->whoseTurn = 0; 	 
		cur_player = whoseTurn(p);		
		p->coins = 1000;
		p->numBuys = 100;
		
		//purchase cards for each player
		for (m = 0 ; m < numplayers; m++){
			p->whoseTurn = m; 
			for(j = 0 ; j < (rand() % 10); j++){
				buyCard(k[(rand() % 10)], p);
			}	
		}	
		
		p->whoseTurn = (rand() % 4);
	
		c1 = determineChoice(rand()%3);
		c2 = determineChoice(rand()%3);
		c3 = determineChoice(rand()%3);
		
		cardEffect(minion, c1, c2, c3, p, pos, &coin_bonus);
		
		printf("test %d complete \n", i+1);

		free(p);
	}
	
	
return 0;
}
