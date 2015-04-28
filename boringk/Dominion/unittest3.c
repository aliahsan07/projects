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

  printf ("Starting test of get cost .\n");
  
  int r = initializeGame(2, k, atoi(argv[1]), p);

  assert (r == 0);
    //Test if getCost returns a vaild number for the 26 cards and invalid if out of bounds
	for(int i = -10; i <= 100; i++){
		//printf("i = %d and cost = %d\n",i,getCost(i));
		if(i < 0){
			assert(getCost(i) == -1);
		}
		if(i >= 0 && i <= treasure_map){
			assert(getCost(i) >= 0 && getCost(i) <= 8);
		}
		if(i > treasure_map){
			assert(getCost(i) == -1);
		}
	}
	
	
		printf("passed test fro getCost\n");
  return 0;
}
