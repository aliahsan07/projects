#include "dominion.h"
#include "dominion_helpers.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	int cost;
	
	
	printf("*************************************\n");
	printf("\t\t\tUNIT TEST 3\t\t\t\n");
	printf("*************************************\n");
	printf("\nGet card gold costs...\n");
	for (i = -5; i < 30; i++){
		cost = getCost(i);
		switch (i){
			case curse:
				assert(cost == 0);
				printf("Curse: %d coins\n",cost);
				break;
			case copper:
				assert(cost == 0);
				printf("Copper: %d coins\n",cost);
				break;
			case silver:
				assert(cost == 3);
				printf("Silver: %d coins\n",cost);
				break;
			case gold:
				assert(cost == 6);
				printf("Gold: %d coins\n",cost);
				break;
			case estate:
				assert(cost == 2);
				printf("Estate: %d coins\n",cost);
				break;
			case duchy:
				assert(cost == 5);
				printf("Duchy: %d coins\n",cost);
				break;
			case province:
				assert(cost == 8);
				printf("Province: %d coins\n",cost);
				break;
			case adventurer:
				assert(cost == 6);
				printf("Adventurer: %d coins\n",cost);
				break;
			case ambassador:
				assert(cost == 3);
				printf("Ambassador: %d coins\n",cost);
				break;
			case baron:
				assert(cost == 4);
				printf("Baron: %d coins\n",cost);
				break;
			case council_room:
				assert(cost == 5);
				printf("Council Room: %d coins\n",cost);
				break;
			case cutpurse:
				assert(cost == 4);
				printf("Cutpurse: %d coins\n",cost);
				break;
			case embargo:
				assert(cost == 2);
				printf("Embargo: %d coins\n",cost);
				break;
			case feast:
				assert(cost == 4);
				printf("Feast: %d coins\n",cost);
				break;
			case gardens:
				assert(cost == 4);
				printf("Gardens: %d coins\n",cost);
				break;
			case great_hall:
				assert(cost == 3);
				printf("Great Hall: %d coins\n",cost);
				break;
			case mine:
				assert(cost == 5);
				printf("Mine: %d coins\n",cost);
				break;
			case minion:
				assert(cost == 5);
				printf("Minion: %d coins\n",cost);
				break;
			case outpost:
				assert(cost == 5);
				printf("Outpost: %d coins\n",cost);
				break;
			case remodel:
				assert(cost == 4);
				printf("Remodel: %d coins\n",cost);
				break;
			case salvager:
				assert(cost == 4);
				printf("Salvager: %d coins\n",cost);
				break;
			case sea_hag:
				assert(cost == 4);
				printf("Sea Hag: %d coins\n",cost);
				break;
			case smithy:
				assert(cost == 4);
				printf("Smithy: %d coins\n",cost);
				break;
			case steward:
				assert(cost == 3);
				printf("Steward: %d coins\n",cost);
				break;
			case treasure_map:
				assert(cost == 4);
				printf("Treasure Map: %d coins\n",cost);
				break;
			case tribute:
				assert(cost == 5);
				printf("Tribute: %d coins\n",cost);
				break;
			case village:
				assert(cost == 3);
				printf("Village: %d coins\n",cost);
				break;
		}
}	
	printf("All tests passed\n");
	
	return 0;
}
