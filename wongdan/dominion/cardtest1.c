#include "dominion.h"
#include "rngs.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	struct gameState G;
	int cards;
	int bonus = 0;
	int handPos = 5;
	int choice1 = 0;
	int k[10] = {adventurer, cutpurse, embargo, gardens, mine, minion, sea_hag, smithy, tribute, village};
	
	printf("******************************\n");
	printf("\t\t\tCARD TEST 1\t\t\t\n");
	printf("******************************\n");
	
	printf("Testing smithy...\n");
	
	cards = initializeGame(2, k, 3, &G);

	cards = cardEffect(smithy, gold, province, choice1, &G, handPos, &bonus);
	if (cards != 3){
		printf("Cards = %d\nTest failed!\n", cards);	
	}

return 0;
}
