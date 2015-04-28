/*** unit test for shuffle in dominion.c ***/


#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"


int main(){

    struct gameState G;
    int k[10] = {smithy, gardens, adventurer, minion, feast, village, sea_hag, treasure_map, baron, great_hall};
    int numPlayers = 2;
    int result;
    int oldDeck[numPlayers][MAX_DECK];
    int i, j;
    double same1 = 0, same2 = 0, count1 = 0, count2 = 0;


    result = initializeGame(numPlayers, k, 2, &G);
    assert(result == 0);

    for(i = 0; i < numPlayers; i++){
	for(j = 0; j < MAX_DECK; j++){
	    oldDeck[i][j] = G.deck[i][j];
	}
    }

    result = shuffle(1, &G);

    for(i = 0; i < numPlayers; i++){
	for(j = 0; j < MAX_DECK; j++){
	    if(i == 0){
		if(oldDeck[i][j] == G.deck[i][j]){
		    same1++;
		}
		count1++;
	    }
	    else{
		if(oldDeck[i][j] == G.deck[i][j] && i == 1){
		    same2++;
		}
		count2++;
	    }
	}
    }

    
    printf("\nBeginning shuffle() test ... \n");

    printf("Similarity between P1 cards: %f%%\n", (double)(same1/count1)*100); 
    printf("Similarity between P2 cards: %f%%\n", (double)(same2/count2)*100); 

    
    if(same1 >= count1){
        printf("TEST FAILED\n");
    }
    else{ printf("Player 1 test passed\n"); }

    if(same2 >= count2){
        printf("TEST FAILED\n");
    }
    else{ printf("Player 2 test passed\n"); }

    return 0;
}
