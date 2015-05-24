//Test to run random games of Dominion
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main(){
	printf("Playing random Dominon games\n");

	struct gameState G;
	struct gameState *p = &G;
	int i, kingCounter, r, players, testNum, money, smithyPos, adventurerPos;
	int NUM_TESTS = 5;
	int resetKingCards[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	int resetKingCardsDeck[20] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, 
	embargo, outpost, salvager, sea_hag, treasure_map};
	int kingCards[10]; 
	int kingCardsDeck[20];
	int numSmithies = 0;
	int numAdventurers = 0;
	int seed = 7;
	srand(seed);
	//srand(time(NULL));
	r = rand();

	for(testNum = 0; testNum < NUM_TESTS; testNum++){

		for(i = 0; i < 10; i++){
			kingCards[i] = resetKingCards[i]; 
		}
		for(i = 0; i < 20; i++){
			kingCardsDeck[i] = resetKingCardsDeck[i]; // reset decks
		}
		/*							
		for(kingCounter = 0; kingCounter < 10; kingCounter++){	//TOFIX: Duplicate cards
			kingCards[kingCounter] = 8 + (rand() % 13);  
			printf("%d\n", kingCards[kingCounter]);
		}
		*/

		printf("Kingdom Cards: ");
		for (kingCounter = 0; kingCounter < 10; kingCounter++){ //Modified Fisher-Yates shuffle - two decks
			while(kingCards[kingCounter] == -1){
				r = rand() % 21;
				if(kingCardsDeck[r] != -1){
					kingCards[kingCounter] = kingCardsDeck[r];
					kingCardsDeck[r] = -1;
					printf("%d ", kingCards[kingCounter]);
				}
			}
		}
		printf("\n");

		players = (2 + (rand() % 3)); //2-4 players
		
		if(initializeGame(players, kingCards, r, p) == -1){
			printf("initializeGame() returned -1\n");
		}
		else{
			while(!isGameOver(p)){
				money = 0;
				smithyPos = -1;
				adventurerPos = -1;
				for (i = 0; i < numHandCards(p); i++) {
					if (handCard(i, p) == copper){
						money++;
					}
					else if (handCard(i, p) == silver){
						money += 2;
					}
					else if (handCard(i, p) == gold){
						money += 3;
					}
					else if (handCard(i, p) == smithy){
						smithyPos = i;
					}
					else if (handCard(i, p) == adventurer){
						adventurerPos = i;
					}
				}
				if (rand() % 2 == 0) {
					if (smithyPos != -1) {
						printf("%d: smithy played from position %d\n", whoseTurn(p) + 1, smithyPos); 
						playCard(smithyPos, -1, -1, -1, p);

						money = 0;
						for(i = 0; i < numHandCards(p); i++){
							if (handCard(i, p) == copper){
								playCard(i, -1, -1, -1, p);
								money++;
							}
							else if (handCard(i, p) == silver){
								playCard(i, -1, -1, -1, p);
								money += 2;
							}
							else if (handCard(i, p) == gold){
								playCard(i, -1, -1, -1, p);
								money += 3;
							}
						}
						
					}
					if (money >= 8) {
						printf("%d: bought province\n", whoseTurn(p) + 1); 
						buyCard(province, p);
					}
					else if (money >= 6) {
						printf("%d: bought gold\n", whoseTurn(p) + 1); 
						buyCard(gold, p);
					}
					else if ((money >= 4) && (numSmithies < 2)) {
						printf("%d: bought smithy\n", whoseTurn(p) + 1); 
						buyCard(smithy, p);
						numSmithies++;
					}
					else if (money >= 3) {
						printf("%d: bought silver\n", whoseTurn(p) + 1); 
						buyCard(silver, p);
					}
					printf("%d: end turn\n", whoseTurn(p) + 1);
					endTurn(p);
				}
				else{
					if (adventurerPos != -1) {
						printf("%d: adventurer played from position %d\n", whoseTurn(p) + 1, adventurerPos); 
						playCard(adventurerPos, -1, -1, -1, p);

						money = 0;
						for(i = 0; i < numHandCards(p); i++){
							if (handCard(i, p) == copper){
								playCard(i, -1, -1, -1, p);
								money++;
							}
							else if (handCard(i, p) == silver){
								playCard(i, -1, -1, -1, p);
								money += 2;
							}
							else if (handCard(i, p) == gold){
								playCard(i, -1, -1, -1, p);
								money += 3;
							}
						}

					}
					if (money >= 8) {
						printf("%d: bought province\n", whoseTurn(p) + 1); 
						buyCard(province, p);
					}
					else if (money >= 6) {
						printf("%d: bought gold\n", whoseTurn(p) + 1); 
						buyCard(gold, p);
					}
					else if ((money >= 4) && (numAdventurers < 2)) {
						printf("%d: bought adventurer\n", whoseTurn(p) + 1); 
						buyCard(adventurer, p);
						numAdventurers++;
					}
					else if (money >= 3) {
						printf("%d: bought silver\n", whoseTurn(p) + 1); 
						buyCard(silver, p);
					}
					printf("%d: end turn\n", whoseTurn(p) + 1);
					endTurn(p);
				}
				for(i = 1; i < players; i++){
					printf("Player %d: %d\n", i, scoreFor(i, p));
				}
			}
			printf("Game %d finished\n", testNum + 1);
			for(i = 1; i < players; i++){
				printf("Player %d: %d\n", i, scoreFor(i, p));
			}
		}
	}
	printf("All tests ran\n");
	return 0;
}