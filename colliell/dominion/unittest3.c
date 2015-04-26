#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char* argv[]) 
{
  srand(time(NULL));
  int i, j;

  printf("Testing kingdomCards.\n");

  for(j = 0; j < 10; j++)
  {
	  for(i = 0; i < 10; i++) 
	  	{
	  		int *k = kingdomCards(rand()%27, rand()%27, rand()%27, rand()%27, rand()%27, rand()%27, rand()%27, rand()%27, rand()%27, rand()%27);
	  		printf("k[i] = %d\t", k[i]);
	  	}
	  	printf("\n");
  }

  printf("Test complete.\n");

  return 0;
}
