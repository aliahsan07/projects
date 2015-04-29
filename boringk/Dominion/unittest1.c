#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("Starting test for isGameOver.\n");
  
  int r = initializeGame(2, k, atoi(argv[1]), p);

  assert (r == 0);

    //Test if isGameOVer performs as expected, games is over 
	//  if provinces cards = 0 or any three supply cards are empty
  //What should happen
  //return 1 == game over
  //return 0 == game still going
  
  
  //checks province card being empty
  int i = 100;
  while(!isGameOver(p)){
	  if(i > 0){
		  assert(isGameOver(p) != 1);
	  }
	  //printf("games is not over %d provinces \n",p->supplyCount[province]);
	  p->supplyCount[province] = i;
	  i--;

	  if (i < -1){
		  assert(isGameOver(p) != 0);
	  }
  }
  //printf("game over provinces = %d\n\n",p->supplyCount[province]);
  
  p->supplyCount[province] = 8;
  
  
  
  //checks if 3 decks have been empty
  int a = 20;
  int b = 15;
  int c = 10;

  while(!isGameOver(p)){
	  int j = 0;
	  for (i = 0; i < 25; i++){
		  if (p->supplyCount[i] == 0){
			  j++;
			}
		}
	  //printf("games is not over total empty supply piles = %d\n",j);
	  p->supplyCount[village] = a;
	  p->supplyCount[smithy] = b;
	  p->supplyCount[steward] = c;
	  if (a != 0) {
		a--;  
	  }
		if (b != 0) {
		b--;		  
	  }
		if (c != 0) {
		c--;		  
	  }
	if ( a <= -1){
		assert(j != 3);
	}
  }
  int j = 0;
  for (i = 0; i < 25; i++){
	  if (p->supplyCount[i] == 0){
		  j++;
		}
	}
  //printf("games is now over total empty supply piles = %d \n",j);
  
  printf("test passed for isGameOver\n");
  
  return 0;
}
