#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {

  int k[27] = {curse,estate,duchy,province,copper,silver,gold,adventurer,council_room, feast,gardens,mine,remodel,smithy,village,baron,great_hall,minion,steward,tribute,ambassador,cutpurse,embargo,outpost,salvager,sea_hag,treasure_map};
	
	if(getCost(k[0])!= 0)
		printf("Cost for curse is wrong\n");
	if(getCost(k[1])!= 2)
		printf("Cost for estate is wrong\n");
	if(getCost(k[2])!= 5)
		printf("Cost for duchy is wrong\n");
	if(getCost(k[3])!= 8)
		printf("Cost for province is wrong\n");
	if(getCost(k[4])!= 0)
		printf("Cost for copper is wrong\n");
	if(getCost(k[5])!= 3)
		printf("Cost for silver is wrong\n");
	if(getCost(k[6])!= 6)
		printf("Cost for gold is wrong\n");
	if(getCost(k[7])!= 6)
		printf("Cost for adventurer is wrong\n");
	if(getCost(k[8])!= 5)
		printf("Cost for council room is wrong\n");
	if(getCost(k[9])!= 4)
		printf("Cost for feast is wrong\n");
	if(getCost(k[10])!= 4)
		printf("Cost for gardens is wrong\n");
	if(getCost(k[11])!= 5)
		printf("Cost for mine is wrong\n");
	if(getCost(k[12])!= 4)
		printf("Cost for remodel is wrong\n");
	if(getCost(k[13])!= 4)
		printf("Cost for smithy is wrong\n");
	if(getCost(k[14])!= 3)
		printf("Cost for village is wrong\n");
	if(getCost(k[15])!= 4)
		printf("Cost for baron is wrong\n");
	if(getCost(k[16])!= 3)
		printf("Cost for great hall is wrong\n");
	if(getCost(k[17])!= 5)
		printf("Cost for minion is wrong\n");
	if(getCost(k[18])!= 3)
		printf("Cost for steward is wrong\n");
	if(getCost(k[19])!= 5)
		printf("Cost for tribute is wrong\n");
	if(getCost(k[20])!= 3)
		printf("Cost for ambassador is wrong\n");
	if(getCost(k[21])!= 4)
		printf("Cost for cutpurse is wrong\n");
	if(getCost(k[22])!= 2)
		printf("Cost for embargo is wrong\n");
	if(getCost(k[23])!= 5)
		printf("Cost for outpost is wrong\n");
	if(getCost(k[24])!= 4)
		printf("Cost for salvager is wrong\n");
	if(getCost(k[25])!= 4)
		printf("Cost for sea hag is wrong\n");
	if(getCost(k[26])!= 4)
		printf("Cost for treasure map is wrong\n");
	printf("Test is done\n");
  return 0;
}
