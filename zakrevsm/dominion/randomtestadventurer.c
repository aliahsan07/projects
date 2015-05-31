/******************************************
 *Matthew Zakrevsky
 *testrandomadventurer.c
 *
 *****************************************/ 

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "rngs.h"
#include "dominion_helpers.h"
#include "dominion.h"

#define MAX_TEST 100

int main(int argc, char* argv[]){
	srand(time(NULL));
	int k[10] = {village,steward , council_room, gardens, mine, baron, sea_hag, smithy, minion, outpost};
	int num_players;
	int i,j;
	int seed;
	int cur_player;
	int bonus_coin;
	int pos = -1;

	
	printf(" line:28\n" );

	for (i = 0; i< MAX_TEST; i++){
	//memset(&p, 0, sizeof(struct gameState));
	struct gameState *p = malloc (sizeof(struct gameState));
	
	
	bonus_coin = (rand()%100);
	num_players = (rand()%2+2);
	seed = (rand() % 2000+1);
	

	//INITIALIZE THE GAME
	initializeGame(num_players,k, seed,p); 
	p->whoseTurn = rand()%4; 	 
	cur_player = whoseTurn(p);		
	p->coins = 1000; //this should cover all of your prchasing needs;
	p->numBuys = 100;//this should cover number of purchases
	p->numActions =20;
	
	
	
	for( j = 0; j < (rand() % 10);j++){
	buyCard(k[rand()%10], p);
	}
	
	for( j = 0; j < (rand() % 3);j++){	
	buyCard(gold, p);
	}
	
	for( j = 0; j < (rand() % 5);j++){	
	buyCard(silver, p);
	}
	
	for( j = 0; j < (rand() % 7);j++){	
	buyCard(copper, p);
	}
	

	//setting up after purchase
	
	
	//printf("Drawing cards 5 cards\n");
	
	//for(j = 0 ; j < 5; j++){
	//drawCard(cur_player, p);	
	//}
	
	
	cardEffect(adventurer, -1 , -1, -1, p, pos, &bonus_coin);//adventurer does not have a choice so -1
	
	
	printf("test complete done: %d\n", i);
	
	
	free(p);
	}

return 0;
}
