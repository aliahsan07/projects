#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dominion.h"
#define MAX_TEST 100




enum CARD getMoneyMine(){
	int ran = rand()%3;
	
	switch(ran){
		case 0: return gold; break;
		case 1: return copper; break;
		case 2: return silver; break;
		default: return copper; break;
	}
	
	}

char* returnEnum(int card){

	switch(card){
	case gold:
		return "gold";break;
	case silver: 
		return "silver"; break;
	case copper: 
		return "copper"; break;
	case province:
		return "province";  break;
	case duchy: 
		return "duchy"; break;
	case estate:
		return "estate"; break;
	case gardens:
		return "gardens"; break;
   	case adventurer:
		 return "adventurer"; break;
   /* If no/only 1 treasure found, stop when full deck seen */
   	case council_room : 
		return "council_room"; break;
  	 case feast :
		 return "feast"; break; /* choice1 is supply # of card gained) */
   	case mine: 
		return "mine"; /* choice1 is hand# of money to trash, choice2 is supply# of
	    money to put in hand */
   	case remodel: 
		return "remodel";break; /* choice1 is hand# of card to remodel, choice2 is supply# */
   	case smithy: 
		return "smithy";break;
   	case village:  
		return "village" ;break;
	case baron: 
		return "baron"; break;/* choice1: boolean for discard of estate */
   /* Discard is always of first (lowest index) estate */
   	case great_hall: 
		return "great_hall"; break;
   	case minion: 
		return "minion"; break;/* choice1:  1 = +2 coin, 2 = redraw */
   	case steward: 
		return "steward"; break; /* choice1: 1 = +2 card, 2 = +2 coin, 3 = trash 2 (choice2,3) */
   	case tribute:
		 return "tribute"; break;
   	case ambassador :
		 return "ambassador"; /* choice1 = hand#, choice2 = number to return to supply */
   	case cutpurse: 
		return "cutpurse";break;
   	case embargo:
		 return "embargo"; break;/* choice1 = supply# */
   	case outpost:
		 return "outpost";break;
	default:
		return "unknown card"; break; 
	}
}


int determineChoice(int choice){
	switch(choice){
		case 0: return -1;break;
		
		case 1: return 0;break;
		
		case 2: return 1;break;
		
		default: return 1; break;
	}
}


void printState(struct gameState *p){
	int i,j;
	
	printf("printing state\n");
	printf("Number of players: %d \n", p->numPlayers);
	printf("Player %d's turn\n", p->whoseTurn);
	printf("numActions: %d\n", p->numActions);
	printf("numBuys: %d\n", p->numBuys);
	printf("Numcards played: %d\n", p->playedCardCount);
	printf("Number of provinces: %d\n", p->supplyCount[province]);
	for (i = 0 ; i < p->numPlayers; i++){
		printf("player %d's hand:\n", i);
		for (j = 0; j < p->handCount[i]; j++){
		printf("card :%s\n", returnEnum(p->hand[i][j]));
		}

	printf("\n");		
	}

	for (i = 0 ; i < p->numPlayers; i++){
		printf("player %d's discard:\n", i);
		for (j = 0; j < p->discardCount[i]; j++){
		printf("card :%s\n", returnEnum(p->discard[i][j]));
		}
	
	printf("\n");		
	}
	
	for(i = 0; i < p->numPlayers; i++){
			printf("Player %d's current score:%d \n", i, scoreFor(i, p));
	}
	printf("\n");
	
	printf("Cards In Decks");	
	for (i = 0 ; i < p->numPlayers; i++){
		printf("player %d's deck:\n", i);
		for (j = 0; j < p->deckCount[i]; j++){
		printf("card :%s\n", returnEnum(p->deck[i][j]));
		}
	printf("\n");
	}


	printf("playedCards\n");
	for( i = 0 ; i < p->playedCardCount ; i++){
		printf("Card played: %s\n", returnEnum(p->playedCards[i]));
	} 
		
}
	
	
enum CARD getRandomCard(){

	int ranCard =(rand()%20) + 1;

	switch(ranCard){
	case 1: return adventurer; break;
   /* If no/only 1 treasure found, stop when full deck seen */
   case 2 : return council_room; break;
   case 3: return feast; break; /* choice1 is supply # of card gained) */
   case 4: return gardens; break;
   case 5: return mine; /* choice1 is hand# of money to trash, choice2 is supply# of
	    money to put in hand */
   case 6: return remodel;break; /* choice1 is hand# of card to remodel, choice2 is supply# */
   case 7: return smithy;break;
   case 8:  return village;break;

	case 9: return baron; break;/* choice1: boolean for discard of estate */
   /* Discard is always of first (lowest index) estate */
   case 10: return great_hall; break;
   case 11: return minion; break;/* choice1:  1 = +2 coin, 2 = redraw */
   case 12: return steward; break; /* choice1: 1 = +2 card, 2 = +2 coin, 3 = trash 2 (choice2,3) */
   case 13: return tribute; break;
   case 14: return ambassador; /* choice1 = hand#, choice2 = number to return to supply */
   case 15: return cutpurse;break;
   case 16: return embargo; break;/* choice1 = supply# */
   case 17: return outpost;break;
   case 18: return salvager; break;/* choice1 = hand# to trash */
   case 19: return sea_hag; break;
   case 20: return treasure_map; break;
   default: return gardens;break;
	}
}

int main(int argc, char* argv[]){
	srand(atoi(argv[1]));
	int i, j;
	int smithyPos = -1;
	int adventurerPos = -1;
	int seed = (rand()%2000+1);
	int numplayers;
	int match;
	int cur_player;
	int c1, c2, c3;
	int k[10]={feast ,gardens, minion,council_room, outpost, great_hall,village,smithy,sea_hag,baron};;
	int ranCard;
	int endAction= 0;
	int money = 0;
	int ranSupply;
	int turn= 0;
	int isOver = 0;	
	printf("%d, %s\n", __LINE__, __func__);
	
	struct gameState game;
	struct gameState *p = &game;
	 
	//intialize the kingdom cards
/*	for (i = 0; i< 10; i++){
		k[i] = getRandomCard();
		
		//while(match == 0){
			for ( j = 0; j < i ; j++){
				if (k[i] == k[j]){
					k[i] = getRandomCard();
				}
				else {
					match = 1;
				}
			}
	} */
		numplayers = rand()%2+2;
	
		initializeGame(numplayers, k, seed, p);
		
  while (!isGameOver(p)) { 
    turn++;
	printf("current turn:%d\n", turn);
	printState(p);
	cur_player = p->whoseTurn;
	money = 0;
    smithyPos = -1;
    adventurerPos = -1;
    for (i = 0; i < numHandCards(p); i++) {
      if (handCard(i, p) == copper)
    money++;
      else if (handCard(i, p) == silver)
    money += 2;
      else if (handCard(i, p) == gold)
    money += 3;
      else if (handCard(i, p) == smithy)
    smithyPos = i;
      else if (handCard(i, p) == adventurer)
    adventurerPos = i;
    }
	//printf("%d, %s\n", __LINE__, __func__);
		//playcards
		while(p->numActions >  0){
		ranCard = rand()%p->handCount[cur_player];
		ranSupply = rand()%9;
		if(p->hand[cur_player][ranCard] == estate || p->hand[cur_player][ranCard] == duchy || p->hand[cur_player][ranCard] == province || p->hand[cur_player][ranCard] == gardens){ 	
			ranCard = rand()%p->handCount[cur_player];
			endAction++;
			if(endAction == 10){
			break;
		}
			//printf("%d, %s\n", __LINE__, __func__);
		} 
		if(p->hand[cur_player][ranCard] == copper || p->hand[cur_player][ranCard] == silver || p->hand[cur_player][ranCard] == gold || p->hand[cur_player][ranCard] == curse){
			ranCard = rand()%p->handCount[cur_player];
			endAction++;
			if(endAction == 10){
			break;
		}
		//	printf("%d, %s\n", __LINE__, __func__);
		} 
		//printf("%d, %s\n", __LINE__, __func__);
		c1 = determineChoice(rand()%3);
		c2 = determineChoice(rand()%3);
		c3 = determineChoice(rand()%3);
	
		printf("playing card: %s by player:%d\n", returnEnum(ranCard), cur_player);	
		playCard(ranCard, c1, c2, c3, p);
		p->numActions--;
		printf("played card\n");
		//printState(p);
 		if(endAction == 10){
			break;
		}
	//	printf("%d, %s\n", __LINE__, __func__);
	}
	
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
	//printf("money: %d\n", money);	
	ranCard= rand()%9;
	//printf("%d, %s\n", __LINE__, __func__);
		//buy cards
	if ( money >= 8){
		buyCard(province, p);
	}else if ( money >= 6){
		buyCard(gold, p);
		printf("buying card: gold by player:%d\n",  cur_player);	
	}else if ( money < 6 && money > 3){
		buyCard(k[ranCard], p);	
		printf("buying card: %s by player:%d\n", returnEnum(ranCard), cur_player);	
	}else if ( money == 3){
		buyCard(silver,p);	
		printf("buying card: silver  by player:%d\n",  cur_player);	
			
	}else {
		buyCard(estate,p);	
		printf("buying card: estate  by player:%d\n", cur_player);	
	}	
		//printState(p);
	//	turn++;
		endTurn(p);
	
      }
	printf("Final ");
	printState(p);
return 0;
}
