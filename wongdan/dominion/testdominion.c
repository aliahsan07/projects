#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <time.h>

const char* cardName(int cardVal){

	switch(cardVal){
		case copper:
			return "Copper";
		case silver:
			return "Silver";
		case gold:
			return "Gold";
		case curse:
			return "Curse";
		case estate:
			return "Estate";
		case duchy:
			return "Duchy";
		case province:
			return "Province";
		case adventurer:
			return "Adventurer";
		case gardens:
			return "Gardens";
		case embargo:
			return "Embargo";
		case village:
			return "Village";
		case minion:
			return "Minion";
		case mine:
			return "Mine";
		case cutpurse:
			return "Cutpurse";
		case sea_hag:
			return "Sea Hag";
		case tribute:
			return "Tribute";
		case smithy:
			return "Smithy";
		case council_room:
			return "Council Room";
		case feast:
			return "Feast";
		case remodel:
			return "Remodel";
		case baron:
			return "Baron";
		case great_hall:
			return "Great Hall";
		case steward:
			return "Steward";
		case ambassador:
			return "Ambassador";
		case outpost:
			return "Outpost";
		case salvager:
			return "Salvager";
		case treasure_map:
			return "Treasure Map";
	}	
}

int main(int argc, char** argv) {
	int i, j, numPlayers, currPlayer, cardChoice, seed;
	int failed = 0;
	int money = 0;
	int gamesPlayed = 0;
	int k[21] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy,
		duchy, council_room, feast, remodel, baron, great_hall, steward, ambassador, outpost, salvager,
		treasure_map};
	int adventurerPos, gardensPos, embargoPos, villagePos;
	int minionPos, minePos, cutpursePos, sea_hagPos;
	int tributePos, smithyPos, duchyPos, council_roomPos;
	int feastPos, remodelPos, baronPos, great_hallPos;
	int stewardPos, ambassadorPos, outpostPos, salvagerPos;;
	
	adventurerPos = -1, gardensPos = -1, embargoPos = -1, villagePos = -1;
	minionPos = -1, minePos = -1, cutpursePos = -1, sea_hagPos = -1;
	tributePos = -1, smithyPos = -1, duchyPos = -1, council_roomPos = -1;
	feastPos = -1, remodelPos = -1, baronPos = -1, great_hallPos = -1;
	stewardPos = -1, ambassadorPos = -1, outpostPos = -1, salvagerPos = -1;

	struct gameState state;

	srand(time(NULL));
	numPlayers = 2 + rand() % 3;
	seed = rand();
	currPlayer = rand() % numPlayers;

	printf("Starting the game of Dominion. There are % players.\n\n", numPlayers);
	initializeGame(numPlayers, k, seed, &state);


	while (isGameOver(&state) == 0) {
		printf("Player %d's turn\n", whoseTurn(&state) + 1);
		cardChoice = rand() % 101;

		while(numHandCards(&state) < 5) {
			drawCard(whoseTurn(&state), &state);
		}
		
		printf("Current hand: ");
		for(i = 0; i <numHandCards(&state); i++){
			printf("%s\n", cardName(handCard(i, &state)));
		}

		for (j = 0; j < numHandCards(&state); j++){
			if (handCard(j, &state) == copper){
				money +=1;
				playCard(j,-1,-1,-1,&state);
			}
			else if (handCard(j, &state) == silver) {
				money +=2;
				playCard(j,-1,-1,-1,&state);
			}
			else if (handCard(j, &state) == gold) {
				money +=3;
				playCard(j,-1,-1,-1,&state);
			}
			else if (handCard(j,&state) == adventurer) {
				adventurerPos = j;
			}
			else if (handCard(j,&state) == gardens) {
				gardensPos = j;
			}
			else if (handCard(j,&state) == embargo) {
				embargoPos = j;
			}
			else if (handCard(j,&state) == village) {
				villagePos = j;
			}
			else if (handCard(j,&state) == minion) {
				minionPos = j;
			}
			else if (handCard(j,&state) == mine) {	
				minePos = j;
			}
			else if (handCard(j,&state) == cutpurse) {
				cutpursePos = j;
			}
			else if (handCard(j,&state) == sea_hag) {
				sea_hagPos = j;
			}
			else if (handCard(j,&state) ==  tribute) {
				tributePos = j;
			}
			else if (handCard(j,&state) == smithy) {
				smithyPos = j;
			}
		}
		
		if (adventurerPos != -1) {
			printf("Adventurer card played\n");
			playCard(adventurerPos,-1,-1,-1,&state);
		}
		if (gardensPos != -1) {
			printf("Gardens card played\n");
			playCard(gardensPos,-1,-1,-1,&state);
		}
		if (embargoPos != -1) {
			printf("Embargo card played\n");
			playCard(embargoPos,-1,-1,-1,&state);
		}
		if (villagePos != -1) {
			printf("Village card played\n");
			playCard(villagePos,-1,-1,-1,&state);
		}
		if (minionPos != -1) {
			printf("Minion card played\n");
			playCard(minionPos,-1,-1,-1,&state);
		}
		if (minePos != -1) {
			printf("Mine card played\n");
			playCard(minePos,-1,-1,-1,&state);
		}
		if (cutpursePos != -1) {
			printf("Cutpurse card played\n");
			playCard(cutpursePos,-1,-1,-1,&state);
		}
		if (sea_hagPos != -1) {
			printf("Sea Hag card played\n");
			playCard(sea_hagPos,-1,-1,-1,&state);
		}
		if (tributePos != -1) {
			printf("Tribute card played\n");
			playCard(tributePos,-1,-1,-1,&state);
		}
		if (smithyPos != -1) {
			printf("Smithy card played\n");
			playCard(smithyPos,-1,-1,-1,&state);
		}

		printf("***** Money on hand: %d *****\n", money);
		if (money >= 8) {
		}
		else if (money >= 6){
			if(cardChoice <= 50){
				buyCard(adventurer, &state);
				printf("Purchased Adventurer card\n");
			}
			else{
				buyCard(gold, &state);
				printf("Purchased Gold\n");
			}
		}
		else if (money >= 5){
			if (cardChoice <= 33) {
				buyCard(mine, &state);
				printf("Purchased Mine card\n");
			}
			else if (cardChoice > 33 && cardChoice <= 66){
				buyCard(minion, &state);
				printf("Purchased Minion card\n");
			}
			else if (cardChoice > 66) {
				buyCard(tribute, &state);
				printf("Purchased Tribute card\n");	
			}
		}
		else if (money >= 4){
			if (cardChoice <= 25) {
				buyCard(gardens, &state);
				printf("Purchased Gardens card\n");
			}
			else if (cardChoice > 25 && cardChoice <= 50) {
				buyCard(smithy, &state);
				printf("Purchased Smithy card\n");
			}
			else if (cardChoice > 50 && cardChoice <= 75) {
				buyCard(cutpurse, &state);
				printf("Purchased Cutpurse card\n");
			}
			else if (cardChoice > 75) {
				buyCard(sea_hag, &state);
				printf("Purchased Sea Hag card\n");
			}
		}
		else if (money >= 3){
			if (cardChoice <= 50) {
				buyCard(silver, &state);
				printf("Purchased Silver\n");
			}
			else {
				buyCard(village, &state);
				printf("Purchased Village card\n");
			}
		}
		else if (money >= 2){
			if (cardChoice <= 50){
				buyCard(estate, &state);
				printf("Purchased Estate\n");
			}
			else if (cardChoice > 50) {
				buyCard(embargo, &state);
				printf("Purchased Embargo card\n");
			}
		}
		endTurn(&state);
		gamesPlayed++;
		if (gamesPlayed > 10000) {
			break;
		}

		printf("Played %d games with %d players", gamesPlayed, numPlayers);

	}
return 0;	
}

