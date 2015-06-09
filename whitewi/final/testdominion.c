//Author:  Wilkins White
//This is a modified copy of playdom.c

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define NUM_TESTS 1000

void printKindomCards(int *k);
void printNameOfCard(int card);

int main (int argc, char** argv) {
  struct gameState *p;
  int numberPlayers;
  int testCounter;
  int i;
  int j;
  int money;
  int players[MAX_PLAYERS];  //used for getWinners
  
  	if(argv[1] == NULL)
	{
		printf ("Enter a positive integer argument for the random number generator seed.\n");
		return 0;
	}
	
	for(testCounter=0; testCounter < NUM_TESTS; testCounter++)
	{
		srand(atoi(argv[1]) + testCounter);
		p = newGame();
		
		printf("\n******************************\n");
		printf("Test %d\n", testCounter);
		printf("******************************\n\n");
		
		//Random number of players
		numberPlayers = (rand() % 3) + 2; 
		printf("\n%d Players\n", numberPlayers);
		
		//Random Kingdom cards
		int k[10];
		
		for(i = 0; i < 10; i++)
		{
			while(1){
				k[i] = (rand() % 20) + 7;
				
				for(j = 0; j < i; j++)
				{
					if(k[i] == k[j])				//If card is already selected
					{
						k[i] = (rand() % 20) + 7;	//retry
						j = 0;
					}
				}
				break;
			}
		}
		
		kingdomCards(k[0],k[1],k[2],k[3],k[4],k[5],k[6],k[7],k[8],k[9]);
		
		printKindomCards(k);
		
		//Gameplay

	  printf ("Starting game.\n");
	  
	  initializeGame(numberPlayers, k, atoi(argv[1]), p);

	  while (!isGameOver(p)) {
		money = 0;
		i=0;
		printf("-------------------------------\n");
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
		  }/*else if(handCard(i, p) == feast)
		  {
			  //Feast doesn't work with random testing
			  //playCard(i, (rand() % 26), -1, -1, p);
			  printf("ERROR:  FEAST DOESN'T COOPERATE, DON'T FORGET TO TEST IT BY HAND\n");
			  
		  }*/else{
			  //Try to play the card
			playCard(i, (rand() % numHandCards(p)), (rand() % numHandCards(p)), (rand() % numHandCards(p)), p);
		  }
		  i++;
		}
		
		  if (money >= 6) {
			printf("%d: Trying to buy: gold\n", whoseTurn(p)); 
			buyCard(gold, p);
		  }
		  else if (money >= 3) {
			printf("%d: Trying to buy: silver\n", whoseTurn(p)); 
			buyCard(silver, p);
		  }
		  
		  	//Buy a random card
			int randomCard = rand()%10;
			printf("%d: Trying to buy: ", whoseTurn(p));
			printNameOfCard(k[randomCard]);
			printf("\n");
			buyCard(k[randomCard], p);
			
		 if (money >= 8) {
			printf("%d: Trying to buy: province\n", whoseTurn(p)); 
			buyCard(province, p);
		  }

		  printf("%d: end turn\n", whoseTurn(p));
		  printf("Player %d Score:  %d\n", whoseTurn(p), scoreFor(whoseTurn(p), p));
		  printf("-------------------------------\n\n");
		  endTurn(p);
			
	  } // end of While
	  
	  printf ("\nFinished game.\n");
	  for(i=0; i < numberPlayers; i++)
	  {
		  printf("Player %d Score: %d\n", i, scoreFor(i, p));
	  }
	  printf ("\n\n");
	  
	  	getWinners(players, p);
		for(i=0; i < MAX_PLAYERS; i++)
		{
			if(players[i]==1)
				printf("Player %d Won!", i);
		}
		printf ("\n\n");
	  
	}
  return 0;
}

void printKindomCards(int k[10]){
	int i;
	printf("-------------------------------\n");
	for(i = 0; i < 10; i++)
	{
		if(k[i] == 7)
			printf("Kingdom Card %d:  Adventurer\n", i);
		else if(k[i] == 8)
			printf("Kingdom Card %d:  Council Room\n", i);
		else if(k[i] == 9)
			printf("Kingdom Card %d:  Feast\n", i);
		else if(k[i] == 10)
			printf("Kingdom Card %d:  Gardens\n", i);
		else if(k[i] == 11)
			printf("Kingdom Card %d:  Mine\n", i);
		else if(k[i] == 12)
			printf("Kingdom Card %d:  Remodel\n", i);
		else if(k[i] == 13)
			printf("Kingdom Card %d:  Smithy\n", i);
		else if(k[i] == 14)
			printf("Kingdom Card %d:  Village\n", i);
		else if(k[i] == 15)
			printf("Kingdom Card %d:  Baron\n", i);
		else if(k[i] == 16)
			printf("Kingdom Card %d:  Great Hall\n", i);
		else if(k[i] == 17)
			printf("Kingdom Card %d:  Minion\n", i);
		else if(k[i] == 18)
			printf("Kingdom Card %d:  Steward\n", i);
		else if(k[i] == 19)
			printf("Kingdom Card %d:  Tribute\n", i);
		else if(k[i] == 20)
			printf("Kingdom Card %d:  Ambassador\n", i);
		else if(k[i] == 21)
			printf("Kingdom Card %d:  Cutpurse\n", i);
		else if(k[i] == 22)
			printf("Kingdom Card %d:  Embargo\n", i);
		else if(k[i] == 23)
			printf("Kingdom Card %d:  Outpost\n", i);
		else if(k[i] == 24)
			printf("Kingdom Card %d:  Salvager\n", i);
		else if(k[i] == 25)
			printf("Kingdom Card %d:  Sea Hag\n", i);	
	}
	printf("-------------------------------\n");
	return;
}

void printNameOfCard(int card)
{
	if(card == 0)
		printf("Curse");
	else if(card == 1)
		printf("Estate");
	else if(card == 2)
		printf("Duchy");
	else if(card == 3)
		printf("Province");
	else if(card == 4)
		printf("Copper");
	else if(card == 5)
		printf("Silver");
	else if(card == 6)
		printf("Gold");
	else if(card == 7)
		printf("Adventurer");
	else if(card == 8)
		printf("Council Room");
	else if(card == 9)
		printf("Feast");
	else if(card == 10)
		printf("Gardens");
	else if(card == 11)
		printf("Mine");
	else if(card == 12)
		printf("Remodel");
	else if(card == 13)
		printf("Smithy");
	else if(card == 14)
		printf("Village");
	else if(card == 15)
		printf("Baron");
	else if(card == 16)
		printf("Great Hall");
	else if(card == 17)
		printf("Minion");
	else if(card == 18)
		printf("Steward");
	else if(card == 19)
		printf("Tribute");
	else if(card == 20)
		printf("Ambassador");
	else if(card == 21)
		printf("Cutpurse");
	else if(card == 22)
		printf("Embargo");
	else if(card == 23)
		printf("Outpost");
	else if(card == 24)
		printf("Salvager");
	else if(card == 25)
		printf("Sea Hag");	
	else if(card == 26)
		printf("Treasure Map");
	
	return;
}
