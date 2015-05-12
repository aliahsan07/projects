#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 11

//This randomly tests Adventurer

int main() {

  int k[10] = {adventurer, gardens, embargo, copper, minion, mine, cutpurse,
               sea_hag, tribute, smithy};
  

	  int i;
          int numPlayers, currentPlayer;
	  int card = adventurer;
          int handCount, deckCount; //variables for players hand and deck count
          int randSeed;
          int choice1 = 0, choice2 = 0, choice3 = 0, handPos = 0;
          int *bonus;
          printf("\n***Start Testing***\n");

          struct gameState F;
          struct gameState G;
          struct gameState H;

          printf("\nRunning Random Card Test for Adventurer:\n");

          printf("\n***Start First Set of Tests on State F***\n");


	  for (i = 0; i < MAX_TESTS; i++) {
	    
	    numPlayers = rand() % 4;
	    
	    if (numPlayers == 0)
	      numPlayers = 2; //Need at least 1 player to sort of work
	    
	    randSeed = rand();
	    	    
	    initializeGame(numPlayers, k, randSeed, &F);
	    currentPlayer = rand() % numPlayers;
	    

	    //Code used from originally repoed randomtestadventuer.c
	    F.deckCount[currentPlayer] = rand() % MAX_DECK; 
	    F.discardCount[currentPlayer] = rand() % MAX_DECK;
	    F.handCount[currentPlayer] = rand() % MAX_HAND;
	    handCount = F.handCount[currentPlayer];
	    deckCount = F.deckCount[currentPlayer];

	    //Need to make sure treasure cards exist in deck:
	    for (i = 0; i < 10;++i){
	      gainCard(copper, &F, 2, currentPlayer);
	    }
	    
	    if (randSeed % 2 == 0){
	      F.deckCount[currentPlayer] = 0;
	    }
	    
	    cardEffect(card, choice1, choice2, choice3, &F, handPos, &bonus);
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


	    //Need to make sure treasure cards exist in deck:
	    for (i = 0; i < 10;++i){
	      gainCard(silver, &G, 2, currentPlayer);
	    }
	    
	    if (randSeed % 2 == 0) 
	      G.deckCount[currentPlayer] = 0;
	    
	    cardEffect(card, choice1, choice2, choice3, &G, handPos, &bonus);
	  }
	  printf("***Second Set of Tests Successful***\n");
	  
          printf("\n***Start Third Set of Tests on State H***\n");
	  
	   for (i = 0; i < MAX_TESTS; i++) {
	     
	     numPlayers = rand() % 4;
	     if (numPlayers == 0)
	       numPlayers = 1;
	     
	     randSeed = rand();
	     
	     initializeGame(numPlayers, k, randSeed, &H);
	     
	     H.deckCount[currentPlayer] = rand() % MAX_DECK;
	     H.discardCount[currentPlayer] = rand() % MAX_DECK;
	     H.handCount[currentPlayer] = rand() % MAX_HAND;
	     handCount = H.handCount[currentPlayer];
	     deckCount = H.deckCount[currentPlayer];
	     
	     for (i = 0; i < 10;++i){
	       gainCard(gold, &H, 2, currentPlayer);
	     }


	     //1 in 5 chance of making empty deck for coverage
	     if (randSeed % 5 == 0) 	       
	       H.deckCount[currentPlayer] = 0;
	     
	     cardEffect(card, choice1, choice2, choice3, &H, handPos, &bonus); 
	   }
	   printf("***Third Set of Tests Successful***\n");
	  
	   printf("Tests Complete\n");

	  return 0;
}
