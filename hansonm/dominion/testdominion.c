#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>
/*
string print_function(){
	 printf(") coins=%d numBuys=%d numActions=%d PlayableCards=%d handCount=%d  discardCount=%d  playedCardCount=%d\n",
p->coins,p->numBuys, p->numActions, playableCards,p->handCount[p->whoseTurn],p->discardCount[p->whoseTurn],p->playedCardCount);

}*/

int main (int argc, char* argv[]) 
{
	//srand(time(0));
	 
	
	
	struct gameState G;
	struct gameState *p = &G;
	int i, k, players, seed, temp, money, choice1, choice2, buy_num, action;
	int check_num = 1;
	int check_cost = 0;
	int check_buy = 0;
	int embargo_count = 0;
	int cards[12];
	printf("Cards will be: ");
	for(i = 0; i < 9; i++){
		temp = rand() % 19 + 7;
		for(k = 0; k < 9; k++){
			if(cards[k] == temp){
				check_num = 0; 
			}
		}
		if(check_num){
			cards[i] = temp;
		}
		else{
			--i;
		}
		check_num = 1;
	}
	for(i=0; i < 9; i++){ //print out cards chosen
		printf("%i ",cards[i]);
		if(i == 8){
			printf("\n");
		}
	}
	
	
	players = rand() % MAX_PLAYERS + 1;
	if(players == 1){
		players++;
	}
	seed = rand();
	printf("seed number: %i\n",seed);
	printf("Player number: %i\n",players);
		
	initializeGame(players, cards, seed, &G);

	
	while (!isGameOver(p)) {
		check_cost = 0;
		check_buy = -1;
		money = 0;
		i = 0;
		action = 1;
		choice1 = 0;
		choice2 = 0;
		
		printf(" coins=%d numBuys=%d numActions=%d PlayableCards=%d handCount=%d  discardCount=%d  playedCardCount=%d\n",
p->coins,p->numBuys, p->numActions, numHandCards(p),p->handCount[p->whoseTurn],p->discardCount[p->whoseTurn],p->playedCardCount);
		
		while(i<numHandCards(p)){
			if (handCard(i, p) == copper){
				playCard(i, -1, -1, -1, p);
				printf("Player %i played a copper\n", whoseTurn(p));
				money++;
			}
			else if (handCard(i, p) == silver){
				playCard(i, -1, -1, -1, p);
				printf("Player %i played a silver\n", whoseTurn(p));
				money += 2;
			}
			else if (handCard(i, p) == gold){
				playCard(i, -1, -1, -1, p);
				printf("Player %i played a gold\n", whoseTurn(p));
				money += 3;
			}
			else if(handCard(i, p) == remodel){
				if(action > 0){
					choice1 = rand() % numHandCards(p);
					if(choice1 == i) i++; //this is to just make sure that we are not trashing the remodel
					while(check_cost){
						choice2 = rand() % 10;
						if(getCost(cards[choice2] >= getCost(handCard(i,p) + 2))){
							if(supplyCount(cards[choice2], p))
								check_cost = 1;
						}
					}
					
					playCard(i, choice1, choice2, -1, p);
					printf("Player %i is playing, remodel, trashing card: %i and gaining card: %i\n",whoseTurn(p), handCard(choice1, p), cards[choice2]);
					action--;
				}
			}
			else if(handCard(i, p) == mine){
				if(action > 0){
					int check_choice1 = 0;
					choice1 = 1;
					while(check_choice1){
						if(handCard(choice1,p) <= 4 && handCard(choice1,p) >=6){
							check_choice1 = 1;
						}
						else if(choice1 > numHandCards(p)){
							check_choice1 =1;
							choice1 = 0;
						}
						else{
							choice1++;
						}
					}
					while(check_cost){
						choice2 = rand() % 10;
						if(getCost(cards[choice2] >= getCost(handCard(i,p) + 3))){
							if(supplyCount(cards[choice2], p))
								check_cost = 1;
						}
					}
					if(choice1 == 0){
						printf("Player %i couldn't play mine because there are no treasures in hand\n", whoseTurn(p));
					}
					else{
						playCard(i, choice1, choice2, -1, p);
						printf("Player %i is playing, remodel, trashing card: %i and gaining card: %i\n",whoseTurn(p), handCard(choice1, p), cards[choice2]);
					}
					action--;
				}
			}
			else if(handCard(i, p) == minion){
				choice1 = rand() % 1;
				if(!choice1){
					choice2 = 1;
					choice1 = -1;
				}
				else{
					choice2 = -1;
				}
				playCard(i, choice1, choice2, -1, p);
			}
			else if(handCard(i,p) == steward){
				playCard(i, 1, -1, -1, p);
			}
			else if(handCard(i, p) == ambassador){
				choice1 = rand() % 5;
				playCard(i, choice1, 1, -1, p);
			}
			else if(handCard(i,p) == embargo){
				embargo_count++;
				playCard(i, embargo_count, -1, -1, p);
			}
			else if(handCard(i,p) == salvager){
				choice1 = rand() % 5;
				playCard(i, choice1, -1, -1, p);
			}
			else if (handCard(i, p) == feast){
				if(action > 0){
					while(check_cost){
						choice1 = rand() % 10;
						if(getCost(cards[choice1] >= 5)){
							if(supplyCount(cards[choice1], p))
								check_cost = 1;
						}
					}
					printf("Player %i is playing feast card, grabbing kingdom card number: %i\n", whoseTurn(p), cards[choice1]);
					//playCard(i, cards[choice1], -1, -1, p);
					printf("check;\n");
					action--;
					check_cost = 0;
				}
			}
			else{
				if(action > 0){
					playCard(i,-1, -1, -1, p);
					printf("Player %i is playing card: %i\n",whoseTurn(p), handCard(i,p));
					action--;
				}
				
			}
			
			i++;
		}
		while (!check_buy == 0){
			buy_num = rand() % 27;
			check_buy = buyCard(buy_num, p);
			if(buy_num == 0){
				check_buy = 0;
			}
		}
		printf("Player %i bought card number %i \n", whoseTurn(p), buy_num);
	 printf(" coins=%d numBuys=%d numActions=%d PlayableCards=%d handCount=%d  discardCount=%d  playedCardCount=%d\n",
p->coins,p->numBuys, p->numActions, numHandCards(p),p->handCount[p->whoseTurn],p->discardCount[p->whoseTurn],p->playedCardCount);
	  printf("%i: end turn\n",whoseTurn(p));
	  endTurn(p);
		
		
	}
			
	printf ("Finished game.\n");
	printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));
	
		

}