//Test for getcost function
//Joseph Cronise CS362

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){

	assert(getCost(curse) == 0);
	assert(getCost(estate) == 2);
	assert(getCost(duchy) == 5);
	assert(getCost(province) == 8);
	assert(getCost(copper) == 0);
	assert(getCost(silver) == 3);
	assert(getCost(gold) == 6);
	assert(getCost(adventurer) == 6);
	assert(getCost(council_room) == 5);
	assert(getCost(feast) == 4);
	assert(getCost(gardens) == 4);
	assert(getCost(mine) == 5);
	assert(getCost(remodel) == 4);
	assert(getCost(smithy) == 4);
	assert(getCost(village) == 3);
	assert(getCost(baron) == 4);
	assert(getCost(great_hall) == 3);
	assert(getCost(minion) == 5);
	assert(getCost(steward) == 3);
	assert(getCost(tribute) == 5);
	assert(getCost(ambassador) == 3);
	assert(getCost(cutpurse) == 4);
	assert(getCost(embargo) == 2);
	assert(getCost(outpost) == 5);
	assert(getCost(salvager) == 4);
	assert(getCost(sea_hag) == 4);
	assert(getCost(treasure_map) == 4);

	printf("All getCost function tests passed\n");

	return 0;
}