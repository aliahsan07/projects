#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
int main (int argc, char** argv) {
   
   struct gameState G;
   struct gameState *p = &G;
   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy}; 
   srand(time(NULL)); // Seed rand() that follows
   int numplayers = rand() % 3 + 2;
   int initseed = rand() % 10000;
   
   printf("Starting game with %d players:\n", numplayers);
   printf("Player 1 always plays/draws a garden\n");
   printf("Player 2 always plays/draws a smithy\n");
   if (numplayers >= 3) {
	   printf("Player 3 always plays/draws a village");
   }
   if (numplayers == 4) {
	   printf("Player 4 always plays/draws a cutpurse");
   }
   initializeGame(numplayers, k, initseed, p);
   int money;
   int i;
   int gardenPos = -1;
   int smithyPos = -1;
   int villagePos = -1;
   int cutpursePos = -1;
   int numGardens = 0;
   int numSmithy = 0;
   int numVillage = 0;
   int numCutPurse = 0;

   while(!isGameOver(p)) {
      money = 0;
   
     for (i = 0; i < numHandCards(p); i++) {
         if (handCard(i, p) == copper){
	    money++;
	 }
	 else if (handCard(i, p) == silver) {
	    money = money + 2;
	 }
	 else if (handCard(i, p) == gold) {
	    money = money + 3;
	 }
         else if (handCard(i, p) == gardens) { 
		   
	    gardenPos = i;
	 }
	 else if (handCard(i, p) == smithy) { 
	    smithyPos = i;
	 }
	 else if (handCard(i, p) == village) { 
	    villagePos = i;
	 }
     else if (handCard(i, p) == cutpurse) { 
	    cutpursePos = i;
	 }
     if (whoseTurn(p) == 0) {
	 printf("Player 1's turn: \n");
     if (gardenPos != -1) {
	   printf("Player 1 plays garden. \n");
	   playCard(gardenPos, -1, -1, -1, p);
	 }
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
           }
           i++;
	}
        if (money >= 8) {
           printf("Player 1 buys province\n");
           buyCard(province, p);
        }
        else if (money >= 6) {
           printf("Player 1 buys gold\n");
           buyCard(gold, p);
        }
        else if ((money >= 4) && (numGardens < 2)) {
           printf("Player 1 buys Gardens\n");
           buyCard(gardens, p);
           numGardens++;
        }
        else if (money >= 3) {
           printf("Player 1 buys silver\n");
           buyCard(silver, p);
        }
        printf("End of player 1's turn");
		endTurn(p);
     }
     else if (whoseTurn(p) == 1) {
        printf("Player 2's Turn: \n"); 
        if (smithyPos != -1) {
	      printf("Player 2 plays smithy. \n");
	      playCard(smithyPos, -1, -1, -1, p);
	    }
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
           } 
           i++;
        }
        if (money >= 8) {
           printf("Player 2 buys province\n");
           buyCard(province, p);
        }
        else if (money >= 6) {
           printf("Player 2 buys gold\n");
           buyCard(gold, p);
        }
        else if ((money >= 4) && (numSmithy < 2)) {
           printf("Player 2 buys smithy\n");
           buyCard(smithy, p);
           numSmithy++;
        }
        else if (money >= 3) {
           printf("Player 2 buys silver\n");
           buyCard(silver, p);
        }
		printf("End of player 2's turn\n\n");
		endTurn(p);
      }
      else if (whoseTurn(p) == 2) {
	     printf("Player 3's turn: \n");
         if (villagePos != -1) {
	        printf("Player 3 plays village. \n");
	        playCard(villagePos, -1, -1, -1, p);
	     }
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
            }
          i++;
         }
         if (money >= 8) {
            printf("Player 3 buys province\n");
            buyCard(province, p);
         }
         else if (money >= 6) {
            printf("Player 3 buys gold\n");
            buyCard(gold, p);
         }
         else if ((money >= 3) && (numVillage < 2)) {
            printf("Player 3 buys village\n");
            buyCard(village, p);
            numVillage++;
         }
         else if (money >= 3) {
            printf("Player 3 buys silver\n");
            buyCard(silver, p);
         }
		 printf("End of player 3's turn\n\n");
		 endTurn(p);
      }
      else {
	     printf("Player 4's turn\n");
         if (cutpursePos != -1) {
	        printf("Player 4 plays cutpurse. \n");
	        playCard(cutpursePos, -1, -1, -1, p);
	     }
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
            }
            i++;
         }
         if (money >= 8) {
            printf("Player 4 buys province\n");
            buyCard(province, p);
         }
         else if (money >= 6) {
            printf("Player 4 buys gold\n");
            buyCard(gold, p);
	 } 
         else if ((money >= 4) && (numCutPurse < 2)) {
            printf("Player 4 buys cutpurse\n");
            buyCard(cutpurse, p);
            numCutPurse++;
         }
         else if (money >= 3) {
            printf("Player 4 buys silver\n");
            buyCard(silver, p);
         } 
		 printf("End of player 4's turn\n\n");
		 endTurn(p);
      }

      printf("Score for Player 1: %d\n Score for Player 2: %d\n", scoreFor(0, p), scoreFor(1, p));
      if (numplayers >= 3) {
         printf("Score for Player 3: %d\n", scoreFor(2, p));
      }  
      if (numplayers == 4) {
         printf("Score for Player 4: %d\n\n", scoreFor(3, p));
      }
   }
   }
   printf("Game over: \n\n");
   printf("Score for Player 1: %d\n Score for Player 2: %d\n", scoreFor(0, p), scoreFor(1, p));
   if (numplayers >= 3) {
      printf("Score for Player 3: %d\n", scoreFor(2, p));
   }
   if (numplayers == 4) {
      printf("Score for Player 4: %d\n", scoreFor(3, p));
   }
   return 0;
}
