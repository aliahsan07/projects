#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>



int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("Starting  test for updateCoins.\n");
  
  int r = initializeGame(2, k, atoi(argv[1]), p);

  assert (r == 0);
  		//fill hand with multiple of every card
  
  
    //Test if update coins calculates correct values in hand
	//takes a player,state,bonus
	p->handCount[p->whoseTurn] = 0;
	updateCoins(p->whoseTurn, p, 0);
	assert(p->coins == 0);
	
	//reset hand and fill with max copper
	p->handCount[p->whoseTurn] = 0;
	for (int i =0; i< MAX_HAND; i ++){
		p->hand[p->whoseTurn][i] = copper;
		p->handCount[p->whoseTurn]++;
	}
	updateCoins(p->whoseTurn, p, 0);
	assert(p->coins == 1 * MAX_HAND);
	
		//reset hand and fill with max silver
	p->handCount[p->whoseTurn] = 0;
	for (int i =0; i< MAX_HAND; i ++){
		p->hand[p->whoseTurn][i] = silver;
		p->handCount[p->whoseTurn]++;
	}
	updateCoins(p->whoseTurn, p, 0);
	assert(p->coins == 2 * MAX_HAND);
	
		//reset hand and fill with max gold
	p->handCount[p->whoseTurn] = 0;
	for (int i =0; i< MAX_HAND; i ++){
		p->hand[p->whoseTurn][i] = gold;
		p->handCount[p->whoseTurn]++;
	}
	updateCoins(p->whoseTurn, p, 0);
	assert(p->coins == 3 * MAX_HAND);
	
	
		//fill hand with multiple of every card
	p->handCount[p->whoseTurn] = 0;
	for(int x= 0; x < 20; x++){
			for (int i = curse; i < treasure_map ; i++){
				p->hand[p->whoseTurn][x*treasure_map + i] = i;
				p->handCount[p->whoseTurn]++;
		
		}
	}
	updateCoins(p->whoseTurn, p, 0);
	assert(p->coins == 20 * 3 + 2 * 20 + 1 * 20);
	
	printf("test passed for update Coins\n");
  return 0;
}
