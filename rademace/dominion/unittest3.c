/*
 * unittest3.c
 *
 *  Created on: Apr 20, 2015
 *      Author: Elias
 */

#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

int main(int argc, char** argv) {

	int* k = kingdomCards(
		cutpurse,
		embargo,
		outpost,
		minion,
		steward,
		tribute,
		adventurer,
		council_room,
		gardens,
		mine);
		
	assert(k != NULL);	
	assert(k[0] == cutpurse);
	assert(k[1] == embargo);
	assert(k[2] == outpost);
	assert(k[3] == minion);
	assert(k[4] == steward);
	assert(k[5] == tribute);
	assert(k[6] == adventurer);
	assert(k[7] == council_room);
	assert(k[8] == gardens);
	assert(k[9] == mine);
	
	free(k);
	
	printf("kindomCards() passed all tests\n");
	
	return 1;

}