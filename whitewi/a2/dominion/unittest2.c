#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

/*************************************************
 ** This unittest checks to see if shuffle()	**
 ** works by checking that the deck before and	**
 ** after shuffle are not in the same order.	**
 **												**
 ** This test assumes that initializeGame() is  **
 ** working and will correctly populate a deck. **
 *************************************************/

int main (int argc, char** argv) {
	
	if(argv[1] == NULL)
	{
		printf ("Enter a positive integer argument for the random number generator seed.\n");
		return 0;
	}
	
	int oldDeck[MAX_PLAYERS][10];
	struct gameState G;
	int i, j;
	unsigned long notShuffled;
	float percentShuffled;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	printf ("\n*********************\n");
	printf ("Testing shuffle().\n");
  
	int r = initializeGame(MAX_PLAYERS, k, atoi(argv[1]), &G);

	assert (r == 0);
  
	for(i=0; i<MAX_PLAYERS; i++)
	{
		for(j=0; j<5; j++)
		{
		oldDeck[i][j] = G.deck[i][j];
		}
	}
	
	for(i=0; i<MAX_PLAYERS; i++)
	{
		shuffle(i, &G);
	}
	
	for(i=0; i<MAX_PLAYERS; i++)
	{
		for(j=0; j<5; j++)
		{
			if(oldDeck[i][j] == G.deck[i][j])
			{
				notShuffled++;
			}
		}
	}
	
	percentShuffled = (100-((float)notShuffled/(5*(float)MAX_PLAYERS)*100));
	
	printf ("%lu out of %d cards are in the same position.  This is %f%% shuffled.\n", notShuffled, (5*MAX_PLAYERS), percentShuffled);

	printf ("Test passed.\n");
    printf ("*********************\n");
	
  return 0;
}
