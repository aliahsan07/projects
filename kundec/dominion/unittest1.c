#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	
	printf("Starting Unit Test 1\n");
	
	int *tempKC = kingdomCards(council_room, feast, mine, steward, cutpurse, 
		treasure_map, outpost, smithy, gardens, embargo);

	assert(tempKC[0] == council_room);
	assert(tempKC[1] == feast);
	assert(tempKC[2] == mine);
	assert(tempKC[3] == steward);
	assert(tempKC[4] == cutpurse);
	assert(tempKC[5] == treasure_map);
	assert(tempKC[6] == outpost);
	assert(tempKC[7] == smithy);
	assert(tempKC[8] == gardens);
	assert(tempKC[9] == embargo);

	printf("\n*********************************************************\n");
	printf("Successfully finished Unit Test 1\n");
	printf("*********************************************************\n");

	return 0;
}