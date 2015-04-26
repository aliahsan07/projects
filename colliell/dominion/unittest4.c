#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char* argv[]) 
{

  printf("Testing newGame.\n");
  int i;

  for(i = 0; i < 50; i++)
  {
  	struct gameState *g = newGame();
  	assert(g != NULL);
  	free(g);
  }

  printf("Test complete.\n");

  return 0;
}

