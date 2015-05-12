#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1000

//This randomly tests feast

int main() {

	int k[10] = {feast, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};

	int init, i, players, seed;
  int treasure_before = 0;
  int treasure_after = 0;
	int player;

  struct gameState state;



	printf("STARTING Random Feast Test\n");

	for (i = 0; i < MAX_TESTS; i++) {

		players = rand() % 4;

    if (players < 2)
			players += 2;

    player = rand() % players;

		seed = rand();

		printf("Initalizing Game\n");

		init = initializeGame(players, k, seed, &state);
		assert(init == 0);

		printf("Game is initialized\n\n");


		//Set deckCount, discardCount and handCount
		state.deckCount[player] = rand() % MAX_DECK;
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_HAND;

    if (seed % 3 == 0) {

			state.deckCount[player] = 0;
		}

		printf("Hand count before adventurer is %d\n", state.handCount[player]);
		printf("Deck count before adventurer is %d\n", state.deckCount[player]);
		printf("Discard count before adventurer is %d\n\n", state.discardCount[player]);

    for(int j = 0; j < state.handCount[player]; j++) {
			if(state.hand[player][j] == copper || state.hand[player][j] == silver || state.hand[player][j] == gold)
				treasure_before++;
		}



		cardEffect(feast, 0, 0, 0, &state, 0, 0);

		printf("Hand count after adventurer is %d\n", state.handCount[player]);
		printf("Deck count after adventurer is %d\n", state.deckCount[player]);
		printf("Discard count after adventurer is %d\n\n", state.discardCount[player]);

    for(int j = 0; j < state.handCount[player]; j++) {
			if(state.hand[player][j] == copper || state.hand[player][j] == silver || state.hand[player][j] == gold)
				treasure_after++;
		}

    printf("treasure before is %d\n", treasure_before);
    printf("treasure after is %d\n", treasure_after);



}

printf("Tests Complete\n\n");

return 0;
}
