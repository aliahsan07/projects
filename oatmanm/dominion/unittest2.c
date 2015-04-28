#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(){

	printf("Testing getCost...\n");

	int t;

	printf("Testing for incorrect inputs...\n");
	t = getCost(-1);
	assert(t == -1);
	t = getCost("garbage");
	assert(t == -1);

	printf("Testing if all the card costs are correct...\n");
	t = getCost(curse);
	assert(t == 0);
	t = getCost(estate);
	assert(t == 2);
	t = getCost(duchy);
	assert(t == 5);
	t = getCost(province);
	assert(t == 8);
	t = getCost(copper);
	assert(t == 0);
	t = getCost(silver);
	assert(t == 3);
	t = getCost(gold);
	assert(t == 6);
	t = getCost(adventurer);
	assert(t == 6);
	t = getCost(council_room);
	assert(t == 5);
	t = getCost(feast);
	assert(t == 4);
	t = getCost(gardens);
	assert(t == 4);
	t = getCost(mine);
	assert(t == 5);
	t = getCost(remodel);
	assert(t == 4);
	t = getCost(smithy);
	assert(t == 4);
	t = getCost(village);
	assert(t == 3);
	t = getCost(baron);
	assert(t == 4);
	t = getCost(great_hall);
	assert(t == 3);
	t = getCost(minion);
	assert(t == 5);
	t = getCost(steward);
	assert(t == 3);
	t = getCost(tribute);
	assert(t == 5);
	t = getCost(ambassador);
	assert(t == 3);
	t = getCost(cutpurse);
	assert(t == 4);
	t = getCost(embargo);
	assert(t == 2);
	t = getCost(outpost);
	assert(t == 5);
	t = getCost(salvager);
	assert(t == 4);
	t = getCost(sea_hag);
	assert(t == 4);
	t = getCost(treasure_map);
	assert(t == 4);

	printf("getCost works!\n");

	return 0;
}