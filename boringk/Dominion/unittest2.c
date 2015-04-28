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

  printf ("Starting test for fullDeckCount.\n");
  
  int r = initializeGame(2, k, atoi(argv[1]), p);

  assert (r == 0);
    //Test if FullDeckCount works, should count the total number of cards in deck,hand, and discard pile
   	
  //check starting deck of 7 copper , 3 estates
  int i = 0;
  for (i = curse; i < treasure_map; i++) {
	  //printf("i = %d and deck count =%d\n", i, fullDeckCount(p->whoseTurn,  i , p) );
	 if (i == copper){
		 assert(fullDeckCount(p->whoseTurn,  i , p) == 7);
	 }
	 else if (i == estate){
		 assert(fullDeckCount(p->whoseTurn,  i , p) == 3);
	 }
	else{
		assert(fullDeckCount(p->whoseTurn,  i , p) == 0); 
	}
  }
  
	
	for (int n = 0; n < 8; n++){
		for (i= curse; i < treasure_map; i++){
			
			struct gameState prevState;
			memcpy(&prevState, p, sizeof(struct gameState));
			p->numBuys++;
			p->coins = 9;
			if(buyCard(i,p) == 0){
				for (int x= curse; x < treasure_map; x++){
					if (x != i ) {
						assert(fullDeckCount(p->whoseTurn, x,p) == fullDeckCount(prevState.whoseTurn,x,&prevState));
					}
					else{
						assert(fullDeckCount(p->whoseTurn, x,p) == (fullDeckCount(prevState.whoseTurn,x,&prevState) + 1));
					}

				}
			}
		}
	}
	
		printf("passed test for fullDeckCount\n");
	
  return 0;
}
