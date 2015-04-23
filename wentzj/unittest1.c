//Unit Test 1
//Function: getCost
//Parameters: cardNumber

#include "dominion.h"
#include "assert.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"
#include <math.h>

int main(){
 	int v;

	printf("-------------------------\nTesting Function: getCost\n-------------------------\n");

	printf("-----\nCurse\n");
	v = getCost(curse);
	assert(v==0);
	printf("-----\n");

	printf("\n------\nEstate\n");
	v = getCost(estate);
	assert(v==2);
	printf("------\n");

	printf("------\nDuchy\n");
	v = getCost(duchy);
	assert(v==5);
	printf("------\n\n");

	printf("--------\nProvince\n");
	v = getCost(province);
	assert(v==8);
	printf("--------\n");

	printf("------\nCopper\n");
	v = getCost(copper);
	assert(v==0);
	printf("------\n\n");

	printf("------\nSilver\n");
	v = getCost(silver);
	assert(v==3);
	printf("------\n\n");

	printf("----\nGold\n");
	v = getCost(gold);
	assert(v==6);
	printf("----\n\n");

	printf("----------\nAdventurer\n");
	v = getCost(adventurer);
	assert(v==6);
	printf("----------\n\n");

	printf("------------\nCouncil_room\n");
	v = getCost(council_room);
	assert(v==5);
	printf("------------\n\n");

	printf("-----\nFeast\n");
	v = getCost(feast);
	assert(v==4);
	printf("-----\n\n");

	printf("-------\nGardens\n");
	v = getCost(gardens);
	assert(v==4);
	printf("-------\n\n");

	printf("----\nMine\n");
	v = getCost(mine);
	assert(v==5);
	printf("----\n\n");

	printf("-------\nRemodel\n");
	v = getCost(remodel);
	assert(v==4);
	printf("-------\n\n");

	printf("------\nSmithy\n");
	v = getCost(smithy);
	assert(v==4);
	printf("------\n\n");

	printf("-------\nVillage\n");
	v = getCost(village);
	assert(v==3);
	printf("-------\n\n");

	printf("-----\nBaron\n");
	v = getCost(baron);
	assert(v==4);
	printf("-----\n\n");

	printf("----------\nGreat_Hall\n");
	v = getCost(great_hall);
	assert(v==3);
	printf("----------\n\n");

	printf("------\nMinion\n");
	v = getCost(minion);
	assert(v==5);
	printf("------\n\n");

	printf("-------\nSteward\n");
	v = getCost(steward);
	assert(v==3);
	printf("-------\n\n");

	printf("-------\nTribute\n");
	v = getCost(tribute);
	assert(v==5);
	printf("-------\n\n");

	printf("----------\nAmbassador\n");
	v = getCost(ambassador);
	assert(v==3);
	printf("----------\n\n");

	printf("--------\nCutpurse\n");
	v = getCost(cutpurse);
	assert(v==4);
	printf("--------\n\n");

	printf("-------\nEmbargo\n");
	v = getCost(embargo);
	assert(v==2);
	printf("-------\n\n");

	printf("-------\nOutpost\n");
	v = getCost(outpost);
	assert(v==5);
	printf("-------\n\n");

	printf("--------\nSalvager\n");
	v = getCost(salvager);
	assert(v==4);
	printf("--------\n\n");

	printf("-------\nSea_Hag\n");
	v = getCost(sea_hag);
	assert(v==4);
	printf("-------\n\n");

	printf("------------\nTreasure_Map\n");
	v = getCost(treasure_map);
	assert(v==4);
	printf("------------\n\n");

   return 0;
}
