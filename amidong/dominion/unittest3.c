#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"

//Testing kingdomCards(...);


int main (int argc, char** argv) {


	int* k = malloc(10 * sizeof(int));
	assert(k != NULL);
	k = kingdomCards(0,1,2,3,4,5,6,7,8,9);
	assert(k[0] == 0);
	assert(k[1] == 1);
	assert(k[2] == 2);
	assert(k[3] == 3);
	assert(k[4] == 4);
	assert(k[5] == 5);
	assert(k[6] == 6);
	assert(k[7] == 7);
	assert(k[8] == 8);
	assert(k[9] == 9);
	return 0; 
}