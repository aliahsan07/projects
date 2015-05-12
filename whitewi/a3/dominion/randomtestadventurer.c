#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define DIE_ON_ASSERT 0
#define MAX_TESTS 100

//This randomly tests Adventurer

int massert(int b, char* s) {
  if (!b) {
    printf ("ASSERTION FAILURE: %s\n", s);
    if (DIE_ON_ASSERT) {
      exit(1);
    }
	return 1;
  }
  return 0;
}

int main(int argc, char** argv) {

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	int i;
	int seed;
	int choice1, choice2, choice3;
	int testfailed, totalfailed;
	struct gameState G;
  
	if(argv[1] == NULL)
	{
		printf ("Enter a positive integer argument for the random number generator seed.\n");
		return 0;
	}
	srand(atoi(argv[1]));
  
	for(i=0; i<MAX_TESTS; i++){
		
		testfailed = 0;
		
		seed = rand() + i;
		choice1 = ((rand() + i) % 2);
		choice2 = ((rand() + i) % 2);
		choice3 = ((rand() + i) % 2);
		
		initializeGame(2, k, seed, &G);

		G.hand[0][0] = adventurer;
		int handCount = G.handCount[0];
		int coins = G.coins;
		playCard(0, choice1, choice2, choice3, &G);
		if(massert (G.handCount[0] == handCount + 2, "handCount incorrect")){
			printf ("cards (after, before):  ");
			printf ("%d, %d\n", G.handCount[0], handCount);
			testfailed++;
		}
		if(massert (G.coins >= coins + 2, "coins incorrect")){
			printf ("coins(after, before):  ");
			printf ("%d, %d\n", G.coins, coins);
			testfailed++;
		}
		
		if(testfailed){
			printf ("\n\n");
		}
		totalfailed += testfailed;
	  
	}
	printf ("Failed %d out of %d\n\n", totalfailed, MAX_TESTS);
	return 0;
}