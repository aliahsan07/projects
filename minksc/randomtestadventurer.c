#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXIMUM_TESTS 15
#define RAND_MAX 1000

int main() {
	printf("*** Testing adventurer ***\n");

	int k[10] = {adventurer, council_room, feast, gardens, mine, steward, smithy, village, baron, great_hall};
	int i;
	int j;
	int p = 0;
	int players;
	int player;
	int seed;
	int choice;
	int startcards;
	int endcards;
	

	struct gameState g;

	for (i = 1; i <= MAXIMUM_TESTS; i++){
		seed = rand();
		players = rand()%3+1;
		choice = rand()%3;
		
		initializeGame(players, k, seed, &g);
		g.deckCount[players] = rand() % MAX_DECK;
		g.discardCount[players] = rand() % MAX_DECK;
		g.handCount[players] = rand() % MAX_HAND;

		

		j=cardEffect(adventurer, 1, 1, 1, &g, 0, 0);

		if (j == 0){
			printf("*** card run Test %d Passed \n", i);
		}
		else{
			printf("*** card run Test %d Failed \n", i);
			p++;
		}

		

		
	}
	printf("*** End of Test, %d Tests Failed ****\n", p);
	return 0;
}


		