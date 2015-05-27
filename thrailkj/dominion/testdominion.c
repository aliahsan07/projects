#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_TEST 42

char* getCard(int* card) {
    int numCard = *card;
    switch(numCard) {
		case curse: return "Curse";
		case estate: return "Estate";
		case duchy: return "Duchy";
		case province:return "Province";
		case copper: return "Copper";
		case silver: return "Silver";
		case gold: return "Gold";
		case adventurer: return "Adventurer";
		case council_room: return "CouncilRoom";
		case feast: return "Feast";
		case gardens: return "Gardens";
		case mine: return "Mine";
		case remodel: return "Remodel";
		case smithy: return "Smithy";
		case village: return "Village";
		case baron: return "Baron";
		case great_hall: return "GreatHall";
		case minion: return "Minion";
		case steward: return "Steward";
		case tribute: return "Tribute";
		case ambassador: return "Ambassador";
		case cutpurse: return "Cutpurse";
		case embargo: return "Embargo";
		case outpost: return "Outpost";
		case salvager: return "Salvager";
		case sea_hag: return "Sea Hag";
		case treasure_map: return "TreasureMap";
    }
}


int main(int argc, char** argv){
 
	struct gameState G;
	struct gameState *q = &G;

	srand(atoi(argv[1]));

	
	int r; //Stores random values
	int i; 
	int j;
	int numPlayers; 
	int seed = atoi(argv[1]);
	int cash;
	
	int k[10] = {0,0,0,0,0,0,0,0,0,0};

	
	numPlayers = 2 + (rand() % 3);

	//random kingdom cards
	for (i = 0; i < 10; i++){
		r = rand() % 27;
		if (k[i] == 0)
			k[i] = r;
		for (j = i+1; j < 10; j++){
			if (k[i] == k[j]){
				k[i] = r;
				i = -1;	
				break;
			}    
		}
	}	

 
	
 	int cardPlayable = -42;

	printf("***** Starting Game *****\n");
	initializeGame(numPlayers, k, seed, q);

	while (!isGameOver(q)) {
		int currentPlayer = q->whoseTurn;
		printf("~~~Player %d's turn~~~\n", currentPlayer);

		while(q->numActions > 0){
			for (i = 0; i < numHandCards(q); i++){
				if (handCard(i,q) >= 7)
					cardPlayable = i;
			}
			
			if(cardPlayable != -42){
				playCard(cardPlayable, -1, -1, -1, q);
				printf("Played card\n");			
			}
			else{printf("No card played\n");}
			


		}
		
		while(q->numBuys != 0){
			int randomBuy = rand() % 17;
			int buyReturn = buyCard(randomBuy, q);
			printf("Bought %d \n", buyReturn);



			if (cash >= 8){
				buyCard(province, q);
			}
			else if (cash >= 6){
				buyCard(gold, q);
			}
			else if (cash == 3){
				buyCard(silver,q);
			}


		}
		
		printf("~~~Ending Turn~~~\n");		
		endTurn(q);
		





	


	}
	
	printf("***** End of Game *****\n");
	
	for(i = 0; i < numPlayers; i++){
		printf ("Player %d: %d ", i, scoreFor(i, q));
	}

	return 0;
}





