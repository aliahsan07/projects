#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dominion.h"
#include "rngs.h"

int main(int argc, char *argv[])
{
	int *card;
	
	card = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy);
		   
	printf("Will print out those cards above......\n");
	
	int i;
	
	for(i = 0; i < 10; i ++)
	{
		printf("CARD-[%d]: %d\n", i + 1, card[i]);
		assert(card[i] == 0);
	}		
		
	return EXIT_SUCCESS;
}