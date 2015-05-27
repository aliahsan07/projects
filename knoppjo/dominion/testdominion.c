#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//cd Desktop/Current/School/362/projects/knoppjo/dominion/

void printCard(int card){
	switch(card){
	case 0:
		printf("curse ");
		break;
	case 1:
		printf("estate ");
		break;
	case 2:
		printf("duchy ");
		break;
	case 3:
		printf("province ");
		break;
	case 4:
		printf("copper ");
		break;
	case 5:
		printf("silver ");
		break;
	case 6:
		printf("gold ");
		break;
	case 7:
		printf("adventurer ");
		break;
	case 8:
		printf("council_room ");
		break;
	case 9:
		printf("feast ");
		break;
	case 10:
		printf("gardens ");
		break;
	case 11:
		printf("mine ");
		break;
	case 12:
		printf("remodel ");
		break;
	case 13:
		printf("smithy ");
		break;
	case 14:
		printf("village ");
		break;
	case 15:
		printf("baron ");
		break;
	case 16:
		printf("great_hall ");
		break;
	case 17:
		printf("minion ");
		break;
	case 18:
		printf("steward ");
		break;
	case 19:
		printf("tribute ");
		break;
	case 20:
		printf("ambassador ");
		break;
	case 21:
		printf("cutpurse ");
		break;
	case 22:
		printf("embargo ");
		break;
	case 23:
		printf("outpost ");
		break;
	case 24:
		printf("salvager ");
		break;
	case 25:
		printf("sea_hag ");
		break;
	case 26:
		printf("treasure_map ");
		break;
	}
}

void printAnyDeck(int *deck, int deckNum){
	for(int i = 0 ; i <deckNum; i++){
		printCard(deck[i]);
	}
	printf("\n");
}


void fyshuffle(int *array, int arraySize) {
	int i, j, tmp;

	for (i = arraySize - 1; i > 0; i--) {
		j = rand() % (i + 1);
		tmp = array[j];
		array[j] = array[i];
		array[i] = tmp;
	}
}

int* getRandomKingdomCards(int totalKingdom, int numCards){
	int i;
	int* array = malloc(totalKingdom * sizeof(int));
	int* k = malloc(numCards * sizeof(int));

	for(i = 0; i <= totalKingdom; i++){
		array[i] = i;
	}
	fyshuffle(array, totalKingdom);

	for(i = 0; i < numCards; i++){
		k[i] = array[i] + 7;
		//printf("%d ", k[i]);
	}
	//printf("\n");
	return k;

}

int* getBuyableCards(int *kingdomCards){
	int i = 0;
	int* r = malloc(17 * sizeof(int));
	for(i = 0; i < 7; i++){
		r[i] = i;
	}
	for(i = 0; i <= 10; i++){
		r[i+7] = kingdomCards[i];
	}
	return r;

}

int main (int argc, char** argv) {
	struct gameState G;
	struct gameState *p = &G;

	//srand((unsigned int)time(NULL));

	int totalKingdomCards = 20;
	int playableKingdomCards = 10;

	int seed = atoi(argv[1]);

	int* k = malloc(playableKingdomCards * sizeof(int));
	k = getRandomKingdomCards(totalKingdomCards, playableKingdomCards);

	int* buyableCards = getBuyableCards(k);
	//printf("Buyable Cards: ");
	//printAnyDeck(buyableCards, 17);


	int players = 2 + (rand() % 3);

	printf("Starting game with %d players.\nUsing Kingdom Cards: ", players);
	printAnyDeck(k, 10);
	printf("\n");

	initializeGame(players, k, seed, p);

	int money = 0;
	int playableCard = -1;
	int i=0;

	while (!isGameOver(p)) {
		int currentPlayer = p->whoseTurn;
		printf("***Player %d's turn***\n", currentPlayer);
		printf("*Action Phase*\n");
		printf("Cards: ");
		printAnyDeck(p->hand[currentPlayer], numHandCards(p));
		//ACTION PHASE
		while(p->numActions > 0){
			printf("Num Actions = %d\n", p->numActions);
			for (i = 0; i < numHandCards(p); i++) {
				if (handCard(i, p) >= 7)
					playableCard = i;
			}
			//always play card if you have one
			if(playableCard != -1){
				printf("Played Card: ");
				printCard(handCard(playableCard, p));
				playCard(playableCard, -1, -1, -1, p);
				printf("\n");

				break;
				//ADD TESTS
			}
			else{
				printf("No Card Played\n");
				break;
			}

		}
		//BUY PHASE
		printf("*Buy Phase*\n");
		printf("Cards: ");
		printAnyDeck(p->hand[currentPlayer], numHandCards(p));


		int randBuy = rand () % 17;
		int buyReturn = buyCard(buyableCards[randBuy], p);
		while(p->numBuys != 0 && buyReturn != 0){
			randBuy = rand () % 17;
			buyReturn = buyCard(buyableCards[randBuy], p);
			/*printf("tried to buy: ");
			printCard(randBuy);
			printf("\n");*/
		}
		printf("Bought: ");
		printCard(randBuy);
		printf("\n");


		endTurn(p);
		for(i = 0; i<players; i++){
				printf ("Player %d: %d ", i, scoreFor(i, p));
			}
		printf("\nEND TURN\n\n");

	}

	printf ("***FINISHED GAME***\n");
	for(i = 0; i<players; i++){
		printf ("Player %d: %d ", i, scoreFor(i, p));
	}
	printf ("\n");


	return 0;
}
