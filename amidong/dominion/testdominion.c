#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define NUM_GAMES 10
//How many games will be played
#define SEED_VALUE 15
//Seed value for rand


//Keeps track of card positions if they are in your hand. 
struct posTrack{
	int adventurerPos;
	int gardensPos;
	int embargoPos;
	int villagePos;
	int minionPos;
	int minePos;
	int cutpursePos;
	int sea_hagPos;
	int tributePos;
	int smithyPos;
	int duchyPos;
	int council_roomPos;
	int feastPos;
	int remodelPos;
	int baronPos;
	int great_hallPos;
	int stewardPos;
	int ambassadorPos;
	int outpostPos;
	int salvagerPos;
	int treasure_mapPos;
};
//Initializes all positions to -1
void structInitializer(struct posTrack *p){
	p->adventurerPos = -1;
	p->gardensPos = -1;
	p->embargoPos = -1;
	p->villagePos = -1;
	p->minionPos = -1;
	p->minePos = -1;
	p->cutpursePos = -1;
	p->sea_hagPos = -1;
	p->tributePos = -1;
	p->smithyPos = -1;
	p->duchyPos = -1;
	p->council_roomPos = -1;
	p->feastPos = -1;
	p->remodelPos = -1;
	p->baronPos = -1;
	p->great_hallPos = -1;
	p->stewardPos = -1;
	p->ambassadorPos = -1;
	p->outpostPos = -1;
	p->salvagerPos = -1;
	p->treasure_mapPos = -1;
}
//Sets the card positions and returns number of money
int setPos(struct posTrack *pt,struct gameState *p){
	int i;
	int money = 0;
	for (i = 0; i < numHandCards(p); i++) {
	  if (handCard(i, p) == copper)
			money++;
	  else if (handCard(i, p) == silver)
			money += 2;
	  else if (handCard(i, p) == gold)
			money += 3;
	  else if (handCard(i, p) == cutpurse)
			pt->cutpursePos = i;
	  else if (handCard(i, p) == adventurer)
			pt->adventurerPos = i;
	  else if (handCard(i, p) == gardens)
			pt->gardensPos = i;	
	  else if (handCard(i, p) == embargo)
			pt->embargoPos = i;
	  else if (handCard(i, p) == village)
			pt->villagePos = i;			
	  else if (handCard(i, p) == minion)
			pt->minionPos = i;		
	  else if (handCard(i, p) == mine)
			pt->minePos = i;				
	  else if (handCard(i, p) == sea_hag)
			pt->sea_hagPos = i;			
	  else if (handCard(i, p) == tribute)
			pt->tributePos = i;			
	  else if (handCard(i, p) == smithy)
			pt->smithyPos = i;		
	  else if (handCard(i, p) == duchy)
			pt->duchyPos = i;			
	  else if (handCard(i, p) == council_room)
			pt->council_roomPos = i;			
	  else if (handCard(i, p) ==  feast)
			pt->feastPos = i;			
	  else if (handCard(i, p) == baron)
			pt->baronPos = i;			
	  else if (handCard(i, p) == remodel)
			pt->remodelPos = i;			
	  else if (handCard(i, p) == great_hall)
			pt->great_hallPos = i;			
	  else if (handCard(i, p) == steward)
			pt->stewardPos = i;			
	  else if (handCard(i, p) == ambassador)
			pt->ambassadorPos = i;			
	  else if (handCard(i, p) == outpost)
			pt->outpostPos = i;			
	  else if (handCard(i, p) == salvager)
			pt->salvagerPos = i;			
	  else if (handCard(i, p) == treasure_map)
			pt->treasure_mapPos = i;					
	}
	return money;
}
//Gets random Kingdom Cards
int* getCard()
{	
	int k[21] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
			   sea_hag, tribute, smithy, duchy, council_room, feast, remodel,baron,great_hall,
			   steward, ambassador, outpost, salvager, treasure_map};
	int * k2 = malloc(sizeof(int)*10);
	int i = 0;
	int numCards = 21;
	int cardNumber;
	for(; i< 10; i++){
		cardNumber = rand()%numCards;
		k2[i]= k[cardNumber];
		int j = cardNumber;
		for (;j<numCards - 1;j++){
				k[j] = k[j+1];
		}
		numCards--;
	}
	return k2;
}

char * printCard(int n){ 
	switch(n){
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
			return "Sea_hag";
		case tribute:
			return "Tribute";
		case smithy:
			return "Smithy";
		case duchy:
			return "Duchy";
		case council_room:
			return "Council_room";
		case feast:
			return "Feast";
		case remodel:
			return "Remodel";
		case baron:
			return "Baron";
		case great_hall:
			return "Great_hall";
		case steward:
			return "Steward";
		case ambassador:
			return "Ambassador";
		case outpost:
			return "Outpost";
		case salvager:
			return "Salvager";
		case treasure_map:
			return "Treasure_map";
		case gold:
			return "Gold";
		case silver:
			return "Silver";
		case estate:
			return "Estate";
		case province:
			return "Province";
	}
	return "Nothing";
}

void buyCost2(struct gameState *p, int * k){
	int i = 0;
	int counter = 0;
	int j = 0;
	for(;i<10;i++){
		if (k[i] == embargo)
			counter++;
	}
	int * costTwo = malloc(sizeof(int)*counter);
	for(i =0; i<10;i++){
		if (k[i] == embargo)
			costTwo[j] = k[i];
	}
	if(counter != 0){
		int num = rand() % counter;
		buyCard(costTwo[num],p);
		printf("%s bought\n",printCard(costTwo[num]));
		}
	else{
		buyCard(estate,p);
		printf("%s bought\n",printCard(estate));
		}
}


void buyCost3(struct gameState *p, int * k){
	int i = 0;
	int counter = 0;
	int j = 0;
	for(;i<10;i++){
		if (k[i] == village || k[i] == great_hall || k[i] == steward || k[i] == ambassador)
			counter++;
	}
	int * costThree = malloc(sizeof(int)*counter);
	for(i =0; i<10;i++){
		if (k[i] == village || k[i] == great_hall || k[i] == steward || k[i] == ambassador)
			costThree[j] = k[i];
	}
	if(counter != 0){
		int num = rand() % counter;
		buyCard(costThree[num],p);
		printf("%s bought\n",printCard(costThree[num]));
		}
	else{
		buyCard(silver,p);
		printf("%s bought\n",printCard(silver));
		}
}

void buyCost4(struct gameState *p, int * k){
	int i = 0;
	int counter = 0;
	int j = 0;
	for(;i<10;i++){
		if (k[i] == cutpurse || k[i] == baron || k[i] == feast)
			counter++;
		else if(k[i] == gardens || k[i] == remodel || k[i] == smithy)
			counter++;
		else if(k[i] == salvager || k[i] == sea_hag || k[i] == treasure_map)
			counter++;
	}
	int * costFour = malloc(sizeof(int)*counter);
	for(i =0; i<10;i++){
		if (k[i] == cutpurse || k[i] == baron || k[i] == feast){
			costFour[j] = k[i];
			j++;}
		else if(k[i] == gardens || k[i] == remodel || k[i] == smithy){
			costFour[j] = k[i];
			j++;}
		else if(k[i] == salvager || k[i] == sea_hag || k[i] == treasure_map){
			costFour[j] = k[i];
			j++;}
	}
	if(counter != 0){
		int num = rand() % counter;
		buyCard(costFour[num],p);
		printf("%s bought\n",printCard(costFour[num]));
		}
	else{
		buyCard(silver,p);
		printf("%s bought\n",printCard(silver));
		}
}

void buyCost5(struct gameState *p, int * k){
	int i = 0;
	int counter = 0;
	int j = 0;
	for(;i<10;i++){
		if (k[i] == outpost || k[i] == minion || k[i] == duchy)
			counter++;
		else if(k[i] == council_room || k[i] == mine || k[i] == tribute)
			counter++;
	}
	int * costFive = malloc(sizeof(int)*counter);
	for(i =0; i<10;i++){
		if (k[i] == outpost || k[i] == minion || k[i] == duchy)
			costFive[j] = k[i];
		else if(k[i] == council_room || k[i] == mine || k[i] == tribute)
			costFive[j] = k[i];
	}
	if(counter != 0){
		int num = rand() % counter;
		buyCard(costFive[num],p);
		printf("%s bought\n",printCard(costFive[num]));
		}
	else{
		buyCard(silver,p);
		printf("%s bought\n",printCard(silver));
		}
}

int countPlayable(struct gameState *p){
	int i = 0;
	int counter = 0;
	while(i<numHandCards(p)){
		if (handCard(i,p) == outpost || handCard(i,p) == minion || handCard(i,p) == duchy
			|| (handCard(i,p) == council_room || handCard(i,p) == mine || handCard(i,p) == tribute)
			|| (handCard(i,p) == cutpurse || handCard(i,p) == baron || handCard(i,p) == feast)
			|| (handCard(i,p) == gardens || handCard(i,p) == remodel || handCard(i,p) == smithy)
			|| (handCard(i,p) == salvager || handCard(i,p) == sea_hag || handCard(i,p) == treasure_map)
			|| (handCard(i,p) == village || handCard(i,p) == great_hall || handCard(i,p) == steward || handCard(i,p) == ambassador)
			|| (handCard(i,p) == embargo)){
				counter++;
				i++;
			}	
		else
			i++;
	}
	return counter;
}
//Stores the area in the hand there is a playable card. 
void makePlayable(struct gameState *p, int * pc){
	int i = 0;
	int j = 0;
	while(i<numHandCards(p)){
		if (handCard(i,p) == outpost || handCard(i,p) == minion || handCard(i,p) == duchy
			|| (handCard(i,p) == council_room || handCard(i,p) == mine || handCard(i,p) == tribute)
			|| (handCard(i,p) == cutpurse || handCard(i,p) == baron || handCard(i,p) == feast)
			|| (handCard(i,p) == gardens || handCard(i,p) == remodel || handCard(i,p) == smithy)
			|| (handCard(i,p) == salvager || handCard(i,p) == sea_hag || handCard(i,p) == treasure_map)
			|| (handCard(i,p) == village || handCard(i,p) == great_hall || handCard(i,p) == steward || handCard(i,p) == ambassador)
			|| (handCard(i,p) == embargo)){
				pc[j] = i;
				j++;
				i++;
			}
		else
			i++;
	}
}

void storePlayable(struct gameState *p, int * pc){
	int i = 0;
	int j = 0;
	while(i<numHandCards(p)){
		if(handCard(i, p) != copper && (handCard(i, p) != silver) && (handCard(i, p) != gold)){
			if((handCard(i, p) != estate) && (handCard(i, p) != province) && (handCard(i, p) != curse)){
				if(printCard(handCard(i,p)) != ""){
					pc[j] = handCard(i,p);
					i++;
					j++;}
			}
			else 
				i++;
		}
		else
			i++;
	}
}


int main (int argc, char** argv) {
	int y = 0;
	int l = 0;
	int moneyError = 0; 
	srand (SEED_VALUE);
	struct gameState G;
	struct gameState *p = &G;
	struct posTrack o;
	struct posTrack *pt = &o;
	int z;
	int breakNum = 0;
	int * k = malloc(sizeof(int)*10);
	for(;y<NUM_GAMES;y++){
		p = newGame();
		k = getCard(); //get random kingdom cards; 
		//ger Random Number of Players
		int numPlayers = (rand() % 2) + 2;
		printf("-------------------------------------\n");
		printf ("Starting game with %d players.\n", numPlayers);
		printf("-------------------------------------\n");
		int countTurn = 0;
		initializeGame(numPlayers, k,5, p);
		int money = 0;
		int i=0;


		while (!isGameOver(p)) {
		if(countTurn >= 100){
			break;
			moneyError++;}
			
		printf("Start player %d's turn\n", p->whoseTurn);
		
		if(countTurn % numPlayers != p->whoseTurn){
			breakNum++;
			break;	
			}			//If a player gets skipped. end the game 
		structInitializer(pt);
		money = 0;
		money = setPos(pt,p); //gets card positions and money amount
		int hold = countPlayable(p); //counts action cards in hand
		int track = 0; //tracker that makes sure we don't check for another action card when all have been played
		int * playableCards = malloc(sizeof(int)*hold);
		int * cardPos = malloc(sizeof(int)*hold);
		makePlayable(p, playableCards);
		storePlayable(p,cardPos);
		if(hold != 0){ // if there is 1 or more action cards
			printf("Cards Played:");
			while(p->numActions != 0 && track < hold){ // while there are still actions left and not all the actions cards have been played
				playCard(playableCards[track], -1,-1,-1,p);
				if(printCard(cardPos[track]) != "Nothing")
					printf(" %s, ", printCard(playableCards[track]));
				track++;
			}
			printf("\n");
		}
		else
			printf("Nothing played.\n");
			money = 0;
			i=0;
			while(i<numHandCards(p)){
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
			  i++;
			} 
		  printf("Total money: %d\n", money);
		  if (money >= 8) {
			buyCard(province, p);
			printf("%s bought\n",printCard(province));
		  }
		  else if (money >= 6) {
			z = rand() % 3;
			if(z == 0){
				buyCard(gold, p);
				printf("%s bought\n",printCard(gold));
				}
			else if(z == 1)
				buyCost5(p,k); //buys random kingdom card that is 5
		  }
		  else if ((money >= 4)) 
				buyCost4(p,k); //buys random card that costs 4
		  else if ((money >= 3)){
			z = rand() %2;
			if( z==0){
				buyCard(silver,p);
				printf("%s bought\n",printCard(silver));
				}
			else
				buyCost3(p,k); //buys random card that costs 3
		  
		  }
		  else if ((money >= 2)){
			z = rand() %2;
			if ( z == 0){
				buyCard(estate,p);
				printf("%s bought\n",printCard(estate));
				}
			else
				buyCost2(p,k);
			}
		  printf("%d: end turn\n", p->whoseTurn);
		  endTurn(p);
		for(l=0;l<numPlayers;l++)
			printf ("Player %d: %d\n", l, scoreFor(l, p));
		 // End of Game
		 countTurn++;
		}
		int * players;
		players = malloc(sizeof(int)*4);
		getWinners(players,p);
		printf ("Finished game.\n");
		for(l=0;l<numPlayers;l++)
			printf ("Score for Player %d: %d\n", l, scoreFor(l, p));
		for(l=0; l<4;l++){
			if(players[l] == 1)
				printf("Player %d wins!\n", l);
		}
		
	}
	printf("Of %d Games: Break was ran %d times.\n", NUM_GAMES, breakNum);
	printf("Number of money count loss: %d\n", moneyError);
	return 0;
}
