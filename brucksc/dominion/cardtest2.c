//#include "dominion.c"
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include "rngs.h"

//Tests village

int initializeGame(int, int*, int, struct gameState * ); 
struct gameState* newGame(); 
int cardEffect(int, int,  int, int, struct gameState *, int,  int *); 

int main (int argc, char *argv[]){
    int card = 13;
    enum CARD mycard = village;     
    int choice1 = 0;
    int choice2 = 0; 
    int choice3 = 0;
    struct gameState * GameState = newGame();
    int handPos = 0;
    int * bonus = 0;
    int initialcardnum = GameState->deckCount[0];
    int initialactions = GameState-> numActions;
    int k[10] =  {adventurer, council_room, feast, gardens, mine,
            remodel, smithy, village, baron, great_hall};
    
    printf("\n\nCardTest2\n");
    initializeGame(2, k, 14242, GameState); 
    cardEffect(mycard, choice1, choice2, choice3, GameState, handPos, bonus);
    if (GameState-> deckCount[0] != initialcardnum + 1){
        printf("FAILURE: Deck count was not increased by 1\n");
    }
    if (GameState-> numActions  != initialactions + 2){
        printf("FAILURE: Number of Actions was not increased by 2\n");
    }
       
        return 0;


}
