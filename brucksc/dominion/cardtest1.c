//#include "dominion.c"
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include "rngs.h"

//Tests smithy

int initializeGame(int, int*, int, struct gameState * ); 
struct gameState* newGame(); 
int cardEffect(int, int,  int, int, struct gameState *, int,  int *); 

int main (int argc, char *argv[]){
    int card = 13;
    enum CARD mycard = smithy;     
    int choice1 = 0;
    int choice2 = 0; 
    int choice3 = 0;
    struct gameState * GameState = newGame();
    int handPos = 0;
    int * bonus = 0;
    int initialcardnum = GameState->deckCount[0];
    int k[10] =  {adventurer, council_room, feast, gardens, mine,
            remodel, smithy, village, baron, great_hall};
    initializeGame(0, k, 14242, GameState); 
    cardEffect(mycard, choice1, choice2, choice3, GameState, handPos, bonus);
    assert(GameState->deckCount[0] == initialcardnum + 3);
       
        return 0;


}
