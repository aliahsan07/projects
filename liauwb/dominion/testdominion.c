#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define NUMTEST 1000

int main (int argc, char **argv) {
	struct gameState *G = newGame();
	int randseed = atoi(argv[1]);
	printf("Playing game with seed :%d\n", randseed);
	srand(randseed);
	int cardsdeck;
	int seed = rand() %9 +1;
	int players = rand() %2+2;
	int k[10];
	int allcards[17];
	int useturn;
	int handpos;
	int a;
	int tempk[20] = {adventurer,council_room,gardens,mine,remodel,smithy,village,baron,great_hall,minion,steward,tribute,ambassador,cutpurse,embargo,outpost,salvager,sea_hag,treasure_map};
	for(int z = 0; z<10;z++){
		cardsdeck = rand() %19;
		if(tempk[cardsdeck]!=estate){
			k[z] = tempk[cardsdeck];
			allcards[z] = k[z];
			tempk[cardsdeck] = estate;
			switch( k[z]) 
			{
			case adventurer:
			  printf("Adventurer is placed in deck\n");
			  break;
			case council_room:
			  printf("Council room is placed in deck\n");
			  break;
			case feast:
			  printf("Feast is placed in deck\n");
			  break;
			case gardens:
			   printf("Gardens is placed in deck\n");
			  break;
			case mine:
			   printf("Mine is placed in deck\n");
			  break;
			case remodel:
			  printf("Remodel is placed in deck\n");
			  break;
			case smithy:
			   printf("Smithy is placed in deck\n");
			  break;
			case village:
			   printf("Village is placed in deck\n");
			  break;
			case baron:
			  printf("Baron is placed in deck\n");
			  break;
			case great_hall:
			 printf("Great hall is placed in deck\n");
			  break;
			case minion:
			  printf("Minion is placed in deck\n");
			  break;
			case steward:
			  printf("Steward is placed in deck\n");
			  break;
			case tribute:
			  printf("Tribute is placed in deck\n");
			  break;
			case ambassador:
			  printf("Ambassador is placed in deck\n");
			  break;
			case cutpurse:
			  printf("Cutpurse is placed in deck\n");
			  break;
			case embargo: 
			  printf("Embargo is placed in deck\n");
			  break;
			case outpost:
			  printf("Outpost is placed in deck\n");
			  break;
			case salvager:
			  printf("Salvager is placed in deck\n");
			  break;
			case sea_hag:
			  printf("Sea hag is placed in deck\n");
			  break;
			case treasure_map:
			  printf("Treasure map is placed in deck\n");
			  break;
			}
			
		}
		else{ 
				z = z-1;
		}
	}
	allcards[10] = copper;
	allcards[11] = silver;
	allcards[12] = gold;
	allcards[13] = estate;
	allcards[14] = duchy;
	allcards[15] = province;
	allcards[16] = curse;
  printf ("Starting game with %d players.\n", players);
  
  int r = initializeGame(players, k, seed, G);
	printf("Initial Status: \n");
	for(int a = 0; a< players;a++){
		printf("Player %d:\n", a);
		printf("	Deck number: %d\n",G->deckCount[a]);
		printf("	Hand number: %d\n",G->handCount[a]);
	}
	printf("Starting play...\n");
	G->whoseTurn = 0;
	while(1){
			if(isGameOver(G)==1){
				break;
			}
			a = whoseTurn(G);
			printf("Player %d's turn\n",a);
			G->numActions = 1;
			printf("Starting Action phase..\n");
			G->phase = 0;
			while(G->numActions>0){
				printf("Player is thinking..\n");
				for(handpos = 0; handpos< G->handCount[a]-1; handpos++){
					useturn = rand()%3;
					if(useturn != 1){
						int result = playCard(handpos,(rand()%G->handCount[a]-1),allcards[rand()&17],(rand()%G->handCount[a]-1),G);
						if(result!=-1){
							break;
						}
						else continue;
					}
					else{
						G->numActions = 0;
						printf("Player does not play any card\n");
						break;
					}
				}
				switch(G->hand[a][handpos]) 
					{
					case adventurer:
					  printf("Adventurer is played\n");
					  break;
					case council_room:
					  printf("Council room is played\n");
					  break;
					case feast:
					  printf("Feast is played\n");
					  break;
					case gardens:
					   printf("Gardens is played\n");
					  break;
					case mine:
					   printf("Mine is played\n");
					  break;
					case remodel:
					  printf("Remodel is played\n");
					  break;
					case smithy:
					   printf("Smithy is played\n");
					  break;
					case village:
					   printf("Village is played\n");
					  break;
					case baron:
					  printf("Baron is played\n");
					  break;
					case great_hall:
					 printf("Great hall is played\n");
					  break;
					case minion:
					  printf("Minion is played\n");
					  break;
					case steward:
					  printf("Steward is played\n");
					  break;
					case tribute:
					  printf("Tribute is played\n");
					  break;
					case ambassador:
					  printf("Ambassador is played\n");
					  break;
					case cutpurse:
					  printf("Cutpurse is played\n");
					  break;
					case embargo: 
					  printf("Embargo is played\n");
					  break;
					case outpost:
					  printf("Outpost is played\n");
					  break;
					case salvager:
					  printf("Salvager is played\n");
					  break;
					case sea_hag:
					  printf("Sea hag is played\n");
					  break;
					case treasure_map:
					  printf("Treasure map is played\n");
					  break;
					}
				if(handpos>=G->handCount[a]-1){
					G->numActions = 0;
				}
			}
					
					
				
			
			printf("Player state after action phase: \n");
			printf("	Player %d hand count: %d\n", a, G->handCount[a]);
			printf("	Player %d discard count: %d\n",a, G->discardCount[a]);
			printf("	Player %d deck count: %d\n",a,G->deckCount[a]);
			printf("	Player %d bonus coin: %d\n",a, G->coins);
			printf("	Player %d number of buys: %d\n",a,G->numBuys);
 		
		updateCoins(G->whoseTurn,G,G->coins);
		printf("Starting buying phase\n");
		int want = rand()%(G->numBuys+1);
		for(int mon = 0; mon<want;mon++){
			if(rand()%2==0){
				printf("Player %d will not buy anything\n",a);
				break;
			}
			else{
				int cardbuy = allcards[rand()%17];
				if(buyCard(cardbuy,G)!=-1){
				switch(cardbuy) 
					{
					case adventurer:
					  printf("Adventurer is bought\n");
					  break;
					case council_room:
					  printf("Council room is bought\n");
					  break;
					case feast:
					  printf("Feast is bought\n");
					  break;
					case gardens:
					   printf("Gardens is bought\n");
					  break;
					case mine:
					   printf("Mine is bought\n");
					  break;
					case remodel:
					  printf("Remodel is bought\n");
					  break;
					case smithy:
					   printf("Smithy is bought\n");
					  break;
					case village:
					   printf("Village is bought\n");
					  break;
					case baron:
					  printf("Baron is bought\n");
					  break;
					case great_hall:
					 printf("Great hall is bought\n");
					  break;
					case minion:
					  printf("Minion is bought\n");
					  break;
					case steward:
					  printf("Steward is bought");
					  break;
					case tribute:
					  printf("Tribute is bought\n");
					  break;
					case ambassador:
					  printf("Ambassador is bought\n");
					  break;
					case cutpurse:
					  printf("Cutpurse is bought\n");
					  break;
					case embargo: 
					  printf("Embargo is bought\n");
					  break;
					case outpost:
					  printf("Outpost is bought\n");
					  break;
					case salvager:
					  printf("Salvager is bought\n");
					  break;
					case sea_hag:
					  printf("Sea hag is played\n");
					  break;
					case treasure_map:
					  printf("Treasure map is bought\n");
					  break;
					case copper:
					  printf("copper is bought\n");
					  break;
					case silver:
					  printf("silver is bought\n");
					  break;
					case gold:
					  printf("gold is bought\n");
					  break;
					case duchy:
					  printf("duchy is bought\n");
					  break;
					case estate:
					  printf("estate is bought\n");
					  break;
					case province:
					  printf("province is bought\n");
					  break;
					}
				}
				else continue;
			}
		}
		printf("Player state after buy phase: \n");
		printf("	Player %d hand count: %d\n", a, G->handCount[a]);
		printf("	Player %d discard count: %d\n",a, G->discardCount[a]);
		printf("	Player %d deck count: %d\n",a,G->deckCount[a]);
		printf("	Player %d score: %d\n",a, scoreFor(a,G));
		printf("Player %d turn ends\n", a);
		endTurn(G);
	}
	printf("Game ends\n");
	int player[MAX_PLAYERS];
	getWinners(player,G);
	for(int o=0;o<G->numPlayers;o++){
		if(player[o] == 1){
			printf("Player %d wins\n",o);
		}
	}
}