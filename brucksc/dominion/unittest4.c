//#include "dominion.c"
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include "rngs.h"

//Tests that intialize game function with incorrect number of players

int initializeGame(int, int*, int, struct gameState * ); 
struct gameState* newGame(); 
int cardEffect(int, int,  int, int, struct gameState *, int,  int *); 

int main (int argc, char *argv[]){
    enum CARD mycard = smithy;     
    int choice1 = 0;
    int choice2 = 0; 
    int choice3 = 0;
    struct gameState * GameState = newGame();
    struct gameState * GameState1 = newGame();
    struct gameState * GameState2 = newGame();
    int handPos = 0;
    int * bonus = 0;
    int initialcardnum = GameState1->deckCount[0];
    int i;
    int j;
    int numcardsT = 10;
    int k[10] =  {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    printf("\n\nUnitTest4\n");
    int test = initializeGame(-2, k, 14242, GameState); 
    if(test != -1){
    printf("FAILURE: will accept invalid player number\n");
    }
    return 0;
}
