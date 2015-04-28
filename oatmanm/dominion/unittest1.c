#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv[1]){
	struct gameState G;

  	int k[10] = {adventurer, village, feast, gardens, remodel, mine, steward, outpost, council_room, smithy};

 	 printf ("Unit Test 1.\n");
 	 printf("Testing initializeGame\n");

 	 printf("Testing function with correct amount of players.\n");
 	 int t = initializeGame(2, k, 2, &G);
 	 assert (t == 0);

 	 printf("Testing function with too little players.\n");
 	 t = initializeGame(1, k, 1, &G);
 	 assert(t == -1);
 	 printf("Function fails as expected.\n");

 	 printf("Testing function with too many players.\n");
 	 t = initializeGame(5, k, 5, &G);
 	 assert(t == -1);
 	 printf("Function fails as expected.\n");

 	 printf("Testing if all cards inputted are unique.\n");
 	 int l[10] = {adventurer, adventurer, feast, gardens, remodel, mine, steward, outpost, council_room, smithy};
 	 t = initializeGame(2, l, 2, &G);
 	 assert(t == -1);
 	 printf("Function fails with two of the same card.\n");

 	 t = initializeGame(2, k, 2, &G);

 	 printf("Testing if the supply cards are correct.\n");
 	 assert(G.numPlayers == 2);
 	 assert(G.supplyCount[curse] == 10);
 	 assert(G.supplyCount[estate] == 8);
 	 assert(G.supplyCount[duchy] == 8);
 	 assert(G.supplyCount[province] == 8);
 	 assert(G.supplyCount[copper] == 46);
 	 assert(G.supplyCount[silver] == 40);
 	 assert(G.supplyCount[gold] == 30);

 	 printf("Checking if the supply of kingdom cards is correct.\n");
 	 int c = 0;
 	 for (int i = adventurer; i <= treasure_map; i++){
 	 	//printf("%d\n", G.supplyCount[i]);
 	 	if (G.supplyCount[i] > 0)
 	 		c++;
 	 }
 	 //printf("c = %d\n", c);
 	 assert(c == 10);

 	 printf("Final preparations before the game starts...\n");
 	 assert(G.numActions == 1);
 	 assert(G.numBuys == 1);
 	 assert(G.handCount[0] == 5);

 	 printf("Function works!\n");

  return 0;
}