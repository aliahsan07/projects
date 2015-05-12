//#include "dominion.c"
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include "rngs.h"

//Tests baron

int initializeGame(int, int*, int, struct gameState * ); 
struct gameState* newGame(); 
int cardEffect(int, int,  int, int, struct gameState *, int,  int *); 

int main (int argc, char *argv[]){
    int card = 13;
    enum CARD mycard = baron;
    enum CARD estatecard = estate;
    int discard = 1;
    int keep = 0;    
    int hasestate = 0;
    int choice1 = 0;
    int choice2 = 0; 
    int choice3 = 0;
    struct gameState * GameState = newGame();
    int handPos = 0;
    int * bonus = 0;
    int initialcardnum = GameState->deckCount[0];
    int initialactions = GameState-> numActions;
    int initialbuys = GameState -> numBuys;
    int initialcoins = GameState -> coins;
    int k[10] =  {adventurer, council_room, feast, gardens, mine,
            remodel, smithy, village, baron, great_hall}; 
    int i;
    int newbuys;
    int newcoins;
    int totalestate = fullDeckCount(0,estatecard,GameState); 
    printf("\n\nCardTest3\n");
    initializeGame(2, k, 14242, GameState);  
    printf("The total number of estates is: %d\n", totalestate);
    for (i = 0; i < numHandCards(GameState); i++){
        if (handCard(estatecard, GameState)){
            hasestate = 1;
        }
    }

    //testing discarding the estate
    if (hasestate == 1){
    choice1 = discard;
    cardEffect(mycard, choice1, choice2, choice3, GameState, handPos, bonus);
    if(GameState-> numBuys  != initialbuys + 1){
        printf("FAILURE: Using the Baron and discarding an estate did not  increase buys by 1\n");
    }
    if(GameState -> coins != initialcoins + 4){
        printf("FAILURE: Using a Baron and discarding an estate did not increase coins by 4\n");
    }
    if (fullDeckCount(0 , estate, GameState) != (totalestate -1)){
        printf("FAILURE: Using a Baron did not actually discard the estate\n");
    }
    newbuys = GameState -> numBuys;
    newcoins = GameState -> coins;
    totalestate = fullDeckCount(0,estatecard,GameState); 
    printf("After discarding, the total number of estate is: %d\n", totalestate);
    //testing playing the card without discarding estate
    choice1 = keep;
    cardEffect(mycard, choice1, choice2, choice3, GameState, handPos, bonus);
    if (GameState-> numBuys != newbuys + 1){
        printf("FAILURE: Using a Baron without discarding an estate, did not increase the number of buys\n");
    }
    if (GameState -> coins != newcoins){
        printf("FAILURE: Using a Baron without discarding an estate, changed number of coins\n");
    }
    if (fullDeckCount(0 , estate, GameState) != (totalestate + 1)){
        printf("FAILURE: Using a Baron without discarding an estate did not increase number of estate\n");
    }
    printf("After keeping, the total number of estates is: %d\n", totalestate);
    
    }
    else{
    choice1 = keep;
    cardEffect(mycard, choice1, choice2, choice3, GameState, handPos, bonus);
    if (GameState-> numBuys != newbuys + 1){
        printf("FAILURE: Using a Baron without discarding an estate, did not increase the number of buys\n");
    }
    if (GameState -> coins != newcoins){
        printf("FAILURE: Using a Baron without discarding an estate, changed number of coins\n");
    }
    if (fullDeckCount(0 , estate, GameState) != (totalestate + 1)){
        printf("FAILURE: Using a Baron without discarding an estate did not increase number of estate\n");
    }
    printf("After keeping, the total number of estates is: %d\n", totalestate);
    }

    return 0;


}
