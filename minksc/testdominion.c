#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAXIMUM_TESTS 9001

// char getname(int p){
	
	

// 	return j[];
// }
int main () {
	
	int k[10];
	int p_cards[20] = {sea_hag,council_room, feast, gardens,smithy, mine, remodel, village, adventurer , baron, minion, ambassador, steward, salvager, tribute, cutpurse, embargo, outpost, treasure_map, great_hall};// temp
	int i, deck, p, n;
	int j[17];
	int m_cards[7] = {duchy, curse, copper, silver, gold, estate, province};
	int seeds = 2;
	int	players = rand()%3+1;
	int player; 
	int money;
	//struct gameState *G;
	struct gameState *g =malloc(sizeof(struct gameState));
    //g = &G;

 	printf(" %d players are playing this game \n", players);
 	printf("*** Kingdom Cards are: ****\n");

	for(i = 0; i<10;i++){

		deck = rand() %20; //random card

	 	if(p_cards[deck] != estate){ 

			k[i] = p_cards[deck];
			j[i] = k[i];
			p_cards[deck] = estate;
			p= j[i];
			// l = getname(j[i]);
			
			// 	printf(" %s was shuffeled into the deck \n", l);
			if(p == sea_hag){
				printf("Sea Hag was placed into the deck\n");
			}
			else if(p == council_room){
				printf("Council Room was placed into the deck\n");
			}
			else if(p == feast){
				printf("Feast was placed into the deck\n");
			}
			else if(p == gardens){
				printf("Gardens was placed into the deck\n");
			}
			else if(p == smithy){
				printf("Smithy was placed into the deck\n");
			}
			else if(p == mine){
				printf("Mine was placed into the deck\n");
			}
			else if(p == remodel){
				printf("Remodel was placed into the deck\n");
			}
			else if(p == village){
				printf("Village was placed into the deck\n");
			}
			else if(p == adventurer){
				printf("Adventurer was placed into the deck\n");
			}
			else if(p == baron){
				printf("Baron was placed into the deck\n");
			}
			else if(p == minion){
				printf("Minion was placed into the deck\n");
			}
			else if(p == ambassador){
				printf("Ambassador was placed into the deck\n");
			}
			else if(p == steward){
				printf("Steward was placed into the deck\n");
				}
			else if(p == salvager){
				printf("Salvager was placed into the deck\n");
			}
			else if(p == tribute){
				printf("Tribute was placed into the deck\n");
			}
				else if(p == cutpurse){
				printf("Cutpurse was placed into the deck\n");
			}
			else if(p == embargo){
				printf("Embargo was placed into the deck\n");
			}
			else if(p == outpost){
				printf("Outpost was placed into the deck\n");
			}	
			else if(p == treasure_map){
				printf("Treasure map was placed into the deck\n");
			}
			else if(p == great_hall){
				printf("Great hall was placed into the deck\n");
			}	
		}
	}
				
	for (i= 11; i<17; i++){
		j[i]= m_cards[i-11];
		// l = getname(j[i]);
		printf("%d was shuffeled into the deck \n", j[i]);
	}
	initializeGame(players, k, seeds, g);
	printf("test place");
	while (isGameOver(g)==1){
		player= whoseTurn(g);
		updateCoins(player, g, 0);
		money = g->coins;
		printf("It is player: %d's turn \n",player +1 );
		printf("Coins: %d \n", money);
		//big money strategy 
		if (money >= 8){
			printf("bought a Province\n");
			buyCard(province, g);
		}
		else if (money >= 6 && money < 8){
			printf("bought a Gold\n");
			buyCard(gold, g);
		}

		else if (money >= 3 && money < 6){
			printf("bought a Silver\n");
			buyCard(silver, g);
		}

		else if (money < 3){
			printf("bought a copper\n");
			buyCard(copper, g);
		}
		printf("player %d' score is %d \n", player, scoreFor(player, g));

		endTurn(g);
	}
	printf("game over\n");
	printf("End Scores:\n");

	for (n = 0; n < players; ++n){
		printf("palyer: %d has %d \n",n, scoreFor(n, g));
	}

return 0;
}