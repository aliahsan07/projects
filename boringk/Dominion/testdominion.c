#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
const char * getCardName(int cardNumber){
	if(cardNumber == curse)
		return "curse";
	else if(cardNumber == estate)
		return "estate";
	else if(cardNumber == duchy)
		return "duchy";
	else if(cardNumber == province)
		return "province";
	else if(cardNumber == copper)
		return "copper";
	else if(cardNumber == silver)
		return "silver";
	else if(cardNumber == gold)
		return "gold";
	else if(cardNumber == adventurer)
		return "adventurer";
	else if(cardNumber == council_room)
		return "council_room";
	else if(cardNumber == feast)
		return "feast";
	else if(cardNumber == gardens)
		return "gardens";
	else if(cardNumber == mine)
		return "mine";
	else if(cardNumber == remodel)
		return "remodel";
	else if(cardNumber == smithy)
		return "smithy";
	else if(cardNumber == village)
		return "village";
	else if(cardNumber == baron)
		return "baron";
	else if(cardNumber == great_hall)
		return "great_hall";
	else if(cardNumber == minion)
		return "minion";
	else if(cardNumber == steward)
		return "steward";
	else if(cardNumber == tribute)
		return "tribute";
	else if(cardNumber == ambassador)
		return "ambassador";
	else if(cardNumber == cutpurse)
		return "cutpurse";
	else if(cardNumber == embargo)
		return "embargo";
	else if(cardNumber == outpost)
		return "outpost";
	else if(cardNumber == salvager)
		return "salvager";
	else if(cardNumber == sea_hag)
		return "sea_hag";
	else if(cardNumber == treasure_map)
		return "treasure_map";
	
	printf("Card number not FOUND = %d ", cardNumber);
	return "N/A";
}


int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  //srand(time(NULL)); 
  srand(atoi(argv[1]));
  int i=0;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       remodel, feast, smithy};
  int money = 0;
  int kingdomCardPos = -1;
  int playableCards = 0;
  int copperPos = -1;
  int silverPos = -1;
  int goldPos = -1;
  int copperCnt = 0;
  int silverCnt = 0;
  int goldCnt = 0;
  int estatePos = -1;
  
/*   //Generates random kingdom cards to play with
  int k[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  int notDone = 1;
  int kCnt = 0;
  int i=0;
  while(notDone){
	  int genNumber = rand() % 26;
	  int match = 0;
	  if(genNumber > 6){
		  for(i =0; i< kCnt; i++){
			  if (k[i] == genNumber)
				  match = 1;
		  }
		  if(match == 0){
			  k[kCnt] = genNumber;
			  kCnt++;
		  }
		  if(kCnt == 10)
			  notDone = 0;
	  }
  }
  for(i =0; i< kCnt; i++){
		printf("k[%d] =%d == %s\n",i,k[i],getCardName(i));
  } */
		   

  //Random number of players game state is created		   
  int numberOfPlayers = rand() % 5;
  if (numberOfPlayers < 2){
	  numberOfPlayers = 2;
  }
  printf ("Starting game with %d players.\n",numberOfPlayers);
  initializeGame(numberOfPlayers, k, atoi(argv[1]), p);
  
  
//loop over entire while loop per player, uses if else
  while (!isGameOver(p)) {
    money = 0;
	copperCnt = 0;
	silverCnt = 0;
	goldCnt = 0;	
    kingdomCardPos = -1;
	playableCards = 0;
	estatePos = -1;
	
	printf("%d: Starts Turn with  Hand drawn=(",whoseTurn(p)); 	
	//count current money of whose turn and set kingdom card to play
    for (i = 0; i < numHandCards(p); i++) {
		printf("%s,",getCardName(handCard(i,p))) ; 
		  if (handCard(i, p) == copper){
			money++;
			copperCnt ++;
			copperPos = i;
		  }
		  else if (handCard(i, p) == silver){
			money += 2;
			silverCnt ++;
			silverPos = i;
		  }
		  else if (handCard(i, p) == gold){
			money += 3;
			goldCnt ++;
			goldPos = i;
		  }
		  //checks if its a kingdom card
		  if (handCard(i, p) >= 7){ 
			kingdomCardPos = i;	
			playableCards++;
		  }
		  if(handCard(i,p) == estate){
			  estatePos = i;
		  }
    }
	printf(") coins=%d numBuys=%d numActions=%d PlayableCards=%d handCount=%d  discardCount=%d  playedCardCount=%d\n",
		p->coins,p->numBuys, p->numActions, playableCards,p->handCount[p->whoseTurn],p->discardCount[p->whoseTurn],p->playedCardCount);

	int invalidCard = 1; //boolean value, 1=invalid card , 0=valid card found	
	int buy_card = 0;
	
      if (kingdomCardPos != -1) {
			printf("%d: %s to be played from position %d\n",whoseTurn(p),getCardName(handCard(kingdomCardPos,p)), kingdomCardPos); 
			
			
			//feast
			if(handCard(kingdomCardPos,p) == feast){
				//chose a random card to buy for feast that cost less than 6 and is still available
				invalidCard = 1;
				while(invalidCard){
					buy_card = rand() %(treasure_map);
					if ((supplyCount(buy_card, p) > 0) && getCost(buy_card) <= 5){
						printf("%d: %s played and choose to replace it with %s.\n",whoseTurn(p),getCardName(handCard(kingdomCardPos,p)),getCardName(buy_card));
						playCard(kingdomCardPos, buy_card, -1, -1, p); 
						invalidCard = 0;
					}	
				}
				
			}
			//mine
			else if(handCard(kingdomCardPos,p) == mine){
				int done = 0;  //1= we traded in, 0= still need to trade in
				if(silverCnt >= 1){
					if(supplyCount(gold,p) > 0 ){
						playCard(kingdomCardPos, silverPos, gold, -1, p); 		
						done = 1;
						printf("%d: baron played upgraded silver to gold \n",whoseTurn(p));
					}
					else{
						printf("%d: could not upgrade silver to gold no supply left\n",whoseTurn(p));
					}
				}
				else if(copperCnt >=1 && done == 0){
					if(supplyCount(gold,p) > 0 ){
						playCard(kingdomCardPos, copperPos, silver, -1, p); 	
						done = 1;
						printf("%d: baron played upgraded copper to silver \n",whoseTurn(p));
					}
					else{
						printf("%d: could not upgrade copper to silver no supply left\n",whoseTurn(p));
					}
				
				}
				if(done == 0)
					printf("%d no money in had could be upgraded\n",whoseTurn(p));
			}
			//remodel
			else if(handCard(kingdomCardPos,p) == remodel){
				
				int trash_card = -1;
				for (i = 0; i < numHandCards(p); i++) {
					if(i != kingdomCardPos){
						trash_card = i;
					}
				}
				
				invalidCard = 1;
				int replace_value = getCost(handCard(trash_card,p));
				while(invalidCard){
					buy_card = rand() %(treasure_map);
					if ((supplyCount(buy_card, p) > 0) && getCost(buy_card) <= replace_value){
						printf("%d: %s played and choose to replace %s with %s.\n",whoseTurn(p),getCardName(handCard(kingdomCardPos,p)),getCardName(handCard(trash_card,p)),getCardName(buy_card));						
						playCard(kingdomCardPos, trash_card, buy_card, -1, p); 
						invalidCard = 0;
					}	
				}
				
			}
			//baron
			else if(handCard(kingdomCardPos,p) == baron){
				if(estatePos != -1){
					playCard(kingdomCardPos,1,-1,-1,p);
					printf("%d: baron played and choose to discard an estate card \n",whoseTurn(p));				
				}
				else{
					playCard(kingdomCardPos,0,-1,-1,p);
					printf("%d: baron played and to gain an estate card \n",whoseTurn(p));		
				}
			}
			//minion
			else if(handCard(kingdomCardPos,p) == minion){
				printf("%d: minion played and choose to get +2 coin \n",whoseTurn(p));
				playCard(kingdomCardPos,1,-1,-1,p);
							
			}
			//steward
			else if(handCard(kingdomCardPos,p) == steward){
				printf("%d: steward played and choose to get +2 coin \n",whoseTurn(p));
				playCard(kingdomCardPos,-1,1,-1,p);

			}
			//ambassador
			else if(handCard(kingdomCardPos,p) == ambassador){
				if(copperCnt > 2 ){
					printf("%d: returned 2 copper from your hand back to supply \n",whoseTurn(p)); 	
					playCard(kingdomCardPos,copperPos,2,-1,p);	
				
				}
				else
				{
					printf("%d: decided not play ambassador\n",whoseTurn(p)); 
				}
			}		
			//embargo
			else if(handCard(kingdomCardPos,p) == embargo){
				
				invalidCard = 1;
				while(invalidCard){
					buy_card = rand() %(treasure_map);
					if (supplyCount(buy_card, p) > 0) {
						printf("%d: %s played and choose to place embargo on %s.\n",whoseTurn(p),getCardName(handCard(kingdomCardPos,p)),getCardName(buy_card));
						playCard(kingdomCardPos, buy_card, -1, -1, p); 
						invalidCard = 0;					
					}	
				}
			}	
			//salvager
			else if(handCard(kingdomCardPos,p) == salvager){
				printf("%d: %s played and choose to trash %s.\n",whoseTurn(p),getCardName(handCard(kingdomCardPos,p)),getCardName(handCard(0,p)));				
				playCard(kingdomCardPos, 0, -1, -1, p); 
				
			}				
			//Not a special card to be played(does not have a choice we have to make)
			else{
				printf("%d: %s has been played.\n",whoseTurn(p),getCardName(handCard(kingdomCardPos,p)));
				playCard(kingdomCardPos, -1, -1, -1, p); 

			}
			
			printf("%d: After Turn with  Hand drawn=(",whoseTurn(p)); 
			for (i = 0; i < numHandCards(p); i++) {
				printf("%s,",getCardName(handCard(i,p))) ; 		
			}
			printf(") coins=%d numBuys=%d numActions=%d PlayableCards=%d handCount=%d  discardCount=%d  playedCardCount=%d\n",
			p->coins,p->numBuys, p->numActions, playableCards,p->handCount[p->whoseTurn],p->discardCount[p->whoseTurn],p->playedCardCount);
			money = 0;
			i=0;
      }
	  else{
		  printf("%d: Nothing to play this turn\n",whoseTurn(p)); 
	  }
		money = p->coins;
		
		
		//Buys a random card
		invalidCard = 1;
		while(invalidCard){
			buy_card = rand() %(treasure_map);
			if ((supplyCount(buy_card, p) > 0) && getCost(buy_card) <= money){
				buyCard(buy_card,p);
				invalidCard = 0;
			}
			//buyCard(feast,p);
		}
		
		
	/* 	
		if (money >= 8) {
		printf("%d: bought province\n",whoseTurn(p)); 
		buyCard(province, p);
		}
		else if (money >= 6) {
		printf("%d: bought gold\n",whoseTurn(p)); 
		buyCard(gold, p);
		}
		else if ((money >= 4) ) {

		if(whoseTurn(p) == 0){
			printf("%d: bought feast\n",whoseTurn(p)); 
			buyCard(feast, p);
		}
		else if(whoseTurn(p) == 1){
			printf("%d: bought adventurer\n",whoseTurn(p)); 
			buyCard(adventurer, p);		
		}
		}
		else if (money >= 3) {
		printf("%d: bought silver\n",whoseTurn(p)); 
		buyCard(silver, p);
		} */

		printf("%d: end turn\n",whoseTurn(p));
	  //Discards what left in hand, then inc whose turn(next player or loops) draws cards for the next player and updates coins
		endTurn(p);
		int z=0;
		for(z =0; z < numberOfPlayers; z++){
		  printf ("Player %d: %d\n", z, scoreFor(z, p));		
		}
		printf("\n\n");


	    
  } // end of While

  printf ("Finished game.\n");

  return 0;
}
