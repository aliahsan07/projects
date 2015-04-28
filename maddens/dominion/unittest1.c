#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"


# ifndef EQ
# define EQ(A, B) ((A) == (B))
# endif

//Test case for getCost(int)


void assertTrue(int predicate, char* message) {

	printf("%s: ", message);

	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");

}

int main() {

	printf("\nTESTING getCost() method.\n\n");

	assertTrue(EQ(getCost(curse), 0), "Curse value should be 0");
	assertTrue(EQ(getCost(estate), 2), "Estate value should be 2");
	assertTrue(EQ(getCost(duchy), 5), "Duchy value should be 5");
	assertTrue(EQ(getCost(province), 8), "Province value should be 8");
	assertTrue(EQ(getCost(copper), 0), "Copper value should be 0");
	assertTrue(EQ(getCost(silver), 3), "Silver value should be 3");
	assertTrue(EQ(getCost(gold), 6), "Gold value should be 6");
	assertTrue(EQ(getCost(adventurer), 6), "Adventurer value should be 6");
	assertTrue(EQ(getCost(council_room), 5), "Council Room value should be 5");
	assertTrue(EQ(getCost(feast), 4), "Feast value should be 4");
	assertTrue(EQ(getCost(gardens), 4), "Gardens value should be 4");
	assertTrue(EQ(getCost(mine), 5), "Mine value should be 5");
	assertTrue(EQ(getCost(remodel), 4), "Remodel value should be 4");
	assertTrue(EQ(getCost(smithy), 4), "Smithy value should be 4");
	assertTrue(EQ(getCost(village), 3), "Village value should be 3");
	assertTrue(EQ(getCost(baron), 4), "Baron value should be 4");
	assertTrue(EQ(getCost(great_hall), 3), "Great Hall value should be 3");
	assertTrue(EQ(getCost(minion), 5), "Minion value should be 5");
	assertTrue(EQ(getCost(steward), 3), "Steward value should be 3");
	assertTrue(EQ(getCost(tribute), 5), "Tribute value should be 5");
	assertTrue(EQ(getCost(ambassador), 3), "Ambassador value should be 3");
	assertTrue(EQ(getCost(cutpurse), 4), "Cutpurse value should be 4");
	assertTrue(EQ(getCost(embargo), 2), "Embargo value should be 2");
	assertTrue(EQ(getCost(outpost), 2), "Outpost value should be 5");
	assertTrue(EQ(getCost(salvager), 4), "Salvager value should be 4");
	assertTrue(EQ(getCost(sea_hag), 4), "Sea Hag value should be 4");
	assertTrue(EQ(getCost(treasure_map), 4), "Treasure Map value should be 4");

	return 0;
}
