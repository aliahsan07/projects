#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>



int main (int argc, char** argv) {
  srand(time(NULL)); 	
  int numberOfPlayers = rand() % 26;
  printf ("Starting game with %d players.\n",numberOfPlayers);

  
  
  
  //Generates random cards to be played
  int k[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  int notDone = 1;
  int kCnt = 0;
  int i=0;
  while(notDone){
	  int genNumber = rand() % 26;
	  int match = 0;
	  if(genNumber > 6){
		  for(i =0; i< kCnt; i++){
			  if (k[i] == genNumber)
				  match = 1;
		  }
		  if(match == 0){
			  k[kCnt] = genNumber;
			  kCnt++;
		  }
		  if(kCnt == 10)
			  notDone = 0;
	  }
  }
  for(i =0; i< kCnt; i++){
		printf("k[%d] = %d\n",i,k[i]);
  }
  
  
  return 0;
}
