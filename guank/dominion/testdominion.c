#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"
#include <string.h>

#define MAX_STRING_LENGTH 32
#define MAX_TESTS 10

void randomizer(int k[]);
int check(int k[], int randcard, int idx);
void printGame(struct gameState *G);
char * cardNumToName(int card);
void performBuys(struct gameState* G, int* numCoins, int* whoTurn);

int main(){
	int i, j, x;
	int numCoins = 0;

	struct gameState G;
	int k[10];
	
	int players, randseed, numTest;
	int whoTurn;
	 
	numTest = 0;
	srand(time(NULL)); 


	for (j = 0; j < MAX_TESTS; j++){ 
    
    printf("Starting Test #%d \n", numTest+1);
    randomizer(k);
	
	printf("Randomizing players...\n");
	players = (rand() % 3) + 2;
	
	randseed = rand(); 
	
	initializeGame(players, k, randseed, &G);
    printf("DONE. \n%d players will be playing. \n", G.numPlayers);
	printf("Randomizing kingdom cards...\n");
    printf("DONE. \nDesignated Kingdom Cards for Test #%d:\n", numTest+1);
    for (x = 0; x < 10; x++){
      	switch(k[x]){
			case adventurer:
			  printf("Adventurer\n");
			  break;
			case council_room:
			  printf("Council room\n");
			  break;
			case feast:
			  printf("Feast\n");
			  break;
			case gardens:
			   printf("Gardens\n");
			  break;
			case mine:
			   printf("Mine\n");
			  break;
			case remodel:
			  printf("Remodel\n");
			  break;
			case smithy:
			   printf("Smithy\n");
			  break;
			case village:
			   printf("Village\n");
			  break;
			case baron:
			  printf("Baron\n");
			  break;
			case great_hall:
			 printf("Great hall\n");
			  break;
			case minion:
			  printf("Minion\n");
			  break;
			case steward:
			  printf("Steward\n");
			  break;
			case tribute:
			  printf("Tribute\n");
			  break;
			case ambassador:
			  printf("Ambassador\n");
			  break;
			case cutpurse:
			  printf("Cutpurse\n");
			  break;
			case embargo: 
			  printf("Embargo\n");
			  break;
			case outpost:
			  printf("Outpost\n");
			  break;
			case salvager:
			  printf("Salvager\n");
			  break;
			case sea_hag:
			  printf("Sea hag\n");
			  break;
			case treasure_map:
			  printf("Treasure map\n");
			  break;
			}
    }

	printf("\nGame Initialized and starting...\n");
    
	while (!isGameOver(&G)){
		whoTurn = whoseTurn(&G);
		printGame(&G);
		
		int i = 0;
		int coin = 0;
		int r;
		int k;
		printf("Action phase started\n");
		while(i<numHandCards(&G)){
		  if (handCard(i, &G) == copper){
			playCard(i, -1, -1, -1, &G);
			coin++;
		  }
		  else if (handCard(i, &G) == silver){
			playCard(i, -1, -1, -1, &G);
			coin += 2;
		  }
		  else if (handCard(i, &G) == gold){
			playCard(i, -1, -1, -1, &G);
			coin += 3;
		  }
		  else if(handCard(i, &G) == feast){
			  printf("    ");
		  }
		  else{
			r = playCard(i, 1, 1, 1, &G);
			k = G.hand[i][0];
			if (k > 6){
				
				printf("Activated %s\n", cardNumToName(k));
			}
		  }
		  i++;
		}
	
	printf("Action phase ended\n");
	numCoins = coin;

	printf("Buy phase\n");
	performBuys(&G, &numCoins, &whoTurn);

		printf("Player %d: Ended Turn.\n", whoTurn +1);
		printf("\n******************\n\n"); 
		endTurn(&G); 
		
  			
    }

	printf ("Test #%d complete.\nFinal Scores:\n", numTest+1);

      for (i = 0; i < G.numPlayers; i++){
        printf ("Player %d: %d\n", (i + 1), scoreFor(i, &G));
      }
      printGame(&G);
      printf("\n\n\n\n");
      numTest = numTest + 1;
	} 

	return 0;
}

int check(int k[], int randcard, int idx){
	int x;
	for (x = 0; x < idx; x++){
		if(k[x] == randcard)
			return 1;
		}
	return 0;
}


void randomizer(int k[]){
	int y;
	int randcard;
	for(y = 0; y < 10; y++){
		randcard = (rand() % 20) + 1;
		k[y] = randcard+7;
		while(check(k,k[y],y) == 1){
			int randcard = (rand() % 20) + 1;
			k[y] = randcard+7;
		}
	}
}

char * cardNumToName(int card){
	switch(card)
	{
   		case 0: return "curse";
   		case 1: return "estate";
   		case 2: return "duchy";
   		case 3: return "province";
   		case 4: return "copper";
   		case 5: return "silver";
   		case 6: return "gold";
		case 7: return "adventurer";
		case 8: return "council_room";
		case 9: return "feast";
		case 10: return "gardens";
		case 11: return "mine";
		case 12: return "remodel";
		case 13: return "smithy";
		case 14: return "village";

		case 15: return "baron";
		case 16: return "great_hall";
		case 17: return "minion";
		case 18: return "steward";
		case 19: return "tribute";

		case 20: return "ambassador";
		case 21: return "cutpurse";
		case 22: return "embargo";
		case 23: return "outpost";
		case 24: return "salvager";
		case 25: return "sea_hag";
		case 26: return "treasure_map";
		default: return "error";
	}
}


void performBuys(struct gameState* G, int* numCoins, int* whoTurn){
    
	int rseed, ret;
	*numCoins = G->coins;
		
	if (G->coins != 0 && G->numBuys > 0){ 
	  
		if (*numCoins >= 8 && G->numBuys > 0){
			ret = buyCard(province, G);
			*numCoins = G->coins;
			if (ret == 0) printf("Player %d: Purchased Province \n", *whoTurn + 1);
		}
 
		if (*numCoins >= 6 && G->numBuys > 0){
			rseed = (rand() % 2) + 1;
			if ((rseed == 1) && (G->supplyCount[adventurer] > 0)){
				ret = buyCard(adventurer, G);
				*numCoins = G->coins;
				if (ret == 0) printf("Player %d: Purchased Adventurer \n", *whoTurn +1);
			}
			else if((rseed == 1) && (G->supplyCount[gold] > 0)){
				ret = buyCard(gold, G);
				*numCoins = G->coins;
				if (ret == 0) printf("Player %d: Purchased Gold \n", *whoTurn +1);
			}	
		}
  
		if (*numCoins == 5 && G->numBuys > 0){
			rseed = (rand() % 6) + 1;
			if((rseed == 1) && (G->supplyCount[duchy]) > 0){
				ret = buyCard(duchy, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Duchy \n", *whoTurn +1);
			}
			else if((rseed == 2) && (G->supplyCount[minion]) > 0){
				ret = buyCard(minion, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Minion \n", *whoTurn +1);
			}
			else if((rseed == 3) && (G->supplyCount[council_room]) > 0){
				ret = buyCard(council_room, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Council Room \n", *whoTurn +1);
			}
			else if((rseed == 4) && (G->supplyCount[tribute]) > 0){
				ret = buyCard(tribute, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Tribute \n", *whoTurn +1);
			}
			else if((rseed == 5) && (G->supplyCount[mine]) > 0){
				ret = buyCard(mine, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Mine \n", *whoTurn +1);
			}
			else if((rseed == 6) && (G->supplyCount[council_room]) > 0){
				ret = buyCard(outpost, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Outpost \n", *whoTurn +1);
			}
		}

		if (*numCoins == 4 && G->numBuys > 0) {
			rseed = (rand() % 9) + 1;
			if((rseed == 1) && (G->supplyCount[feast]) > 0){
				ret = buyCard(feast, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Feast\n", *whoTurn +1);
			}
			else if((rseed == 2) && (G->supplyCount[gardens]) > 0){
				ret = buyCard(gardens, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Gardens \n", *whoTurn +1);
			}
			else if((rseed == 3) && (G->supplyCount[remodel]) > 0){
				ret = buyCard(remodel, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Remodel \n", *whoTurn +1);
			}
			else if((rseed == 4) && (G->supplyCount[smithy]) > 0){
				ret = buyCard(smithy, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Smithy \n", *whoTurn +1);
			}
			else if((rseed == 5) && (G->supplyCount[baron]) > 0){
				ret = buyCard(baron, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Baron \n", *whoTurn +1);
			}
			else if((rseed == 6) && (G->supplyCount[cutpurse]) > 0){
				ret = buyCard(cutpurse, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Cutpurse \n", *whoTurn +1);
			}
			else if((rseed == 7) && (G->supplyCount[salvager]) > 0){
				ret = buyCard(salvager, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Salvager \n", *whoTurn +1);
			}
			else if((rseed == 8) && (G->supplyCount[sea_hag]) > 0){
				ret = buyCard(sea_hag, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Sea Hag \n", *whoTurn +1);
			}
			else if((rseed == 9) && (G->supplyCount[treasure_map]) > 0){
				ret = buyCard(treasure_map, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Treasure Map \n", *whoTurn +1);
			}
		}

		if (*numCoins == 3 && G->numBuys > 0) {
			rseed = (rand() % 5) + 1;
			if((rseed == 1) && (G->supplyCount[silver]) > 0){
				ret = buyCard(silver, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Silver \n", *whoTurn +1);
			}	
			else if((rseed == 2) && (G->supplyCount[village]) > 0){
				ret = buyCard(village, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Village \n", *whoTurn +1);
			}
			else if((rseed == 3) && (G->supplyCount[great_hall]) > 0){
				ret = buyCard(great_hall, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Great Hall \n", *whoTurn +1);
			}
			else if((rseed == 4) && (G->supplyCount[steward]) > 0){
				ret = buyCard(steward, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Steward \n", *whoTurn +1);
			}    
			else if((rseed == 5) && (G->supplyCount[ambassador]) > 0){
				ret = buyCard(ambassador, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Ambassador \n", *whoTurn +1);
			}
		}

		if (*numCoins == 2 && G->numBuys > 0) {
			rseed = (rand() % 2) + 1;
			if((rseed == 1) && (G->supplyCount[embargo]) > 0){
				ret = buyCard(embargo, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Embargo \n", *whoTurn +1);
			}
			else if((rseed == 2) && (G->supplyCount[estate]) > 0){
				ret = buyCard(estate, G);
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Estate \n", *whoTurn +1);
			}
		}

		if (*numCoins <= 1 && G->numBuys > 0){
			ret = buyCard(copper, G);
			if (ret == 0){
				*numCoins = G->coins;
				if(ret == 0) printf("Player %d: Purchased Copper \n", *whoTurn +1);
			}
		}
	}
}

void printGame(struct gameState *G){
  int i, j;
  int gameHand, gameDeck, gameDiscard;
  
  for (i = 0; i < G->numPlayers; i++){
    for (j = 0; j < G->handCount[i]; j++){
		gameHand = G->hand[i][j];
    }
    for (j = 0; j < G->deckCount[i]; j++){
		gameDeck = G->deck[i][j];
    }
    for (j = 0; j < G->discardCount[i]; j++){
		gameDiscard = G->discard[i][j];
    }
  }
}

