#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1500

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i;
	  int numPlayers, currentPlayer;
	  int handCount, deckCount; //variables for players hand and deck count
	  int randSeed;
	  int choice1 = 0, choice2 = 0, choice3 = 0, handPos = 0;
	  int *bonus = 0;
	  printf("\n***Start Testing***\n");

	  struct gameState F;
	  struct gameState G;
	  struct gameState H;

	  printf("\nRunning Random Card Test for Cutpurse:\n");

	  printf("\n***Start First Set of Tests on State F***\n");
	  for (i = 0; i < MAX_TESTS; i++) {

		  
	     numPlayers = (int)rand() % 4;
	    
	    if (numPlayers == 0)
	      numPlayers = 1; //Need at least 1 player to sort of work
	    
	    randSeed = (int)rand();
	    
	    initializeGame(numPlayers, k, randSeed, &F); 
	    currentPlayer =  rand() % numPlayers;
	    
	   
	    //Code used from originally repoed randomtestcard.c
	    F.deckCount[currentPlayer] = (int)rand() % MAX_DECK; 
	    F.discardCount[currentPlayer] = (int)rand() % MAX_DECK;
	    F.handCount[currentPlayer] = (int)rand() % MAX_HAND;
	    
	    handCount = F.handCount[currentPlayer];
	    deckCount = F.deckCount[currentPlayer];
	    
	    //Lines added to improve coverage
	    if (rand() % 3 == 0) //1 in 3 chance to get a copper card	  
	      gainCard(copper, &F, 2, (rand() % numPlayers));
	    
	    cardEffect(cutpurse, choice1, choice2, choice3, &F, handPos, bonus);
	    
	  }
	  printf("***First Set of Tests Successful***\n");

	  printf("\n***Start Second Set of Tests on State G***\n");
	  for (i = 0; i < MAX_TESTS; i++) {
	    
	    numPlayers = rand() % 4;

	    if (numPlayers == 0)
	      numPlayers = 1;
	    randSeed = rand();

	    initializeGame(numPlayers, k, randSeed, &G);

	    currentPlayer = rand() % numPlayers;
	    
	    G.deckCount[currentPlayer] = rand() % MAX_DECK;
	    G.discardCount[currentPlayer] = rand() % MAX_DECK;
	    G.handCount[currentPlayer] = rand() % MAX_HAND;
	    
		  
	    handCount = G.handCount[currentPlayer];
	    deckCount = G.deckCount[currentPlayer];
	    
	    cardEffect(cutpurse, choice1, choice2, choice3, &G, handPos, bonus);
	  	    
	  }
	  printf("***Second Set of Tests Successful***\n");
	  
	  printf("\n***Start Third Set of Tests on State H***\n");

	  for (i = 0; i < MAX_TESTS; i++) {
	    
	    randSeed = rand();
	    numPlayers = rand() % 4;

	    if (numPlayers == 0)
	      numPlayers = 1;
	    
	    initializeGame(numPlayers, k, randSeed, &H);
	    currentPlayer = rand() % numPlayers;
	  

	    H.deckCount[currentPlayer] = rand() % MAX_DECK;
	    H.discardCount[currentPlayer] = rand() % MAX_DECK;
	    H.handCount[currentPlayer] = rand() % MAX_HAND;
	   	    
	    handCount = H.handCount[currentPlayer];
	    deckCount = H.deckCount[currentPlayer];
  
	    cardEffect(cutpurse, choice1, choice2, choice3, &H, handPos, bonus);

	  }
	  printf("***Third Set of Tests Successful***\n");

	  printf("Tests Complete\n");

	  printf("\n\n\n");
	  return 0;
}
