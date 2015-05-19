#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1300

//This randomly tests remodel
int choice_randomizer(int player, struct gameState *state, int gold, int kingdom[10]);
int main() {

	  int kingdom[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       smithy, tribute, remodel};

	  int i, n, players, player, handCount, fullDeckCnt, testDeckTotal, seed, handPos, wantCard, disCard, gold;

	  struct gameState state;
	  
	  printf("Running Random Card Test for Remodel\n");
	srand (time(NULL));
	  for (i = 0; i < MAX_TESTS; i++) {

		 players = 2 + rand() % 3 ;//2-4 players always
		 player = rand() % players;
		 seed = rand();		
	
		initializeGame(players, kingdom, seed, &state);	//initialize Gamestate

		  //Initiate valid state variables
			state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
			if(seed%7777 == 6){
				state.deckCount[player] = 0;
			}
			state.discardCount[player] = rand() % MAX_DECK;
			if(seed%3333 == 12){
				state.discardCount[player] = 0;
			}
			state.handCount[player] = rand() % MAX_HAND;
			
		  //Copy state variables
		handCount = state.handCount[player];
			if(handCount == 0)
				handCount = 1;	//can't let handCount = 0 or cant mod it with rand
		fullDeckCnt = total_card(player, &state);
		handPos = rand() % handCount;
		disCard = state.hand[player][handPos];
			gold = getCost(disCard) + 2;
		wantCard = choice_randomizer(player, &state, gold, kingdom);
			
		n = cardEffect(remodel, disCard, wantCard, 1, &state, handPos);		

		if (n==-1){
			printf("\nRemodel failed, tried to discard %d to buy %d\n", disCard, wantCard);
			printf("\nPicked Card Cost: %d\n Available Gold: %d\n", getCost(wantCard), gold);
			printf("\n\t Test no. %d", i);
			assert(NULL);
		}
		if (handCount != state.handCount[player]){
			printf("\nHand count mismatch \n starting hand = %d \n ending hand = %d \n", handCount, state.handCount[player]);
			printf("\n\t Test no. %d", i);
			//assert(NULL);
		}
		testDeckTotal = total_card(player, &state);
		if (fullDeckCnt != testDeckTotal){
			printf("\nNumber of total cards in deck mismatch \n starting total of cards = %d \n ending total of cards = %d\n", fullDeckCnt, testDeckTotal);
			printf("\n\t Test no. %d", i);
			//assert(NULL);
		}	    
	  }
	   


	  printf("Remodel Tests Completed successfully\n");

	  return 0;
}


int choice_randomizer(int player, struct gameState *state, int gold, int kingdom[10]){
	int i, choice = 0, holder;
	
	while(!choice){
		i = rand() % 16; //for 10 kingdom cards, 3 victories and 3 treasure
		if(i < 10){
			holder = kingdom[i];
			if(getCost(holder) <= gold)
				choice = holder;
		}
		else{
			i = i-10;
			switch (i){
				case 0: 
					holder = estate;
					if(getCost(holder) <= gold)
						choice = holder;
					break;
				case 1: 
					holder = duchy;
					if(getCost(holder) <= gold)
						choice = holder;
					break;
				case 2: 
					holder = province;
					if(getCost(holder) <= gold)
						choice = holder;
					break;
				case 3: 
					holder = copper;
					if(getCost(holder) <= gold)
						choice = holder;
					break;
				case 4: 
					holder = silver;
					if(getCost(holder) <= gold)
						choice = holder;
					break;
				case 5: 
					holder = gold;
					if(getCost(holder) <= gold)
						choice = holder;
					break;
			}
		}
	}

	return choice;	
}





