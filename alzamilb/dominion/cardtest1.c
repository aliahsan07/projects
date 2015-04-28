/*  Basil Alzamil  
    CS 362 - Assignment #2
    April 21, 2015 
 */

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Testing remodelCard()
int main (int argc, char** argv) {
    int currentPlayer;
    struct gameState G; 
    int choice1;
    int choice2;
    int choice3;
    int handPos = 5;
    int r;
    int players = 2;
    int player1 = 0;
    int bonus = 0;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    r = initializeGame(players, k, 3, &G);
    currentPlayer = whoseTurn(&G);
    assert (r == 0);
   
//Test 1: The card_to_trash+2 < new_card: should return -1 (illegal move)   
    choice1 = copper;
    choice2 = province;
    G.hand[player1][choice1] = 1;
    r = cardEffect(remodel, choice1, choice2, choice3, &G, handPos, &bonus);
    assert(r == -1);
    printf("Passed Test#1 Succesfully!\n");

//Test 2: The card_to_trash+2 > new_card: legal move: should retun 0.
    choice1 = estate;
    choice2 = silver;
    G.hand[player1][choice1] = 1;
    r = cardEffect(remodel, choice1, choice2, 0, &G, handPos, &bonus);
    assert(r == 0);
    printf("Passed Test#2 Succesfully!\n");

return 0;
}

