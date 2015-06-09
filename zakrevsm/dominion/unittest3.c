/******************************
*Matthew Zakrevsky
*unittest3.c: buycard
******************************/

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

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

int main( int argc, char* argv[]){

//initialize game w/ the random seed.
struct gameState game;
struct gameState* p = &game;
int i,j,m;
int pos = -1;
int money = 0;
int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
		   
	//izeGame(2, k, atoi(argv[1]), p);
	for( i =0  ; i < 10; i++){
		
	initializeGame(2, k, atoi(argv[1]), p);
		for (j = 0 ; j < p->numPlayers; j++){
		printf("player %d's hand:\n", j);
		for (m = 0; m < p->handCount[j]; m++){
		printf("card :%s\n", returnEnum(p->hand[j][m]));
		}
	} 	
   	printf("test %d complete\n", i);
	}

	
   printf("tests complete\n");
   
   return 0;
}	
