//#include "dominion.c"
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include "rngs.h"

//Tests the intialize game funtion with correct input to see if supply is assigned correctly

int initializeGame(int, int*, int, struct gameState * ); 
struct gameState* newGame(); 
int cardEffect(int, int,  int, int, struct gameState *, int,  int *); 

int main (int argc, char *argv[]){
    enum CARD mycard = smithy;     
    int choice1 = 0;
    int choice2 = 0; 
    int choice3 = 0;
    struct gameState * GameState = newGame();
    int handPos = 0;
    int * bonus = 0;
    int i;
    int j;
    int numcardsT = 10;
    int k[10] =  {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    initializeGame(2, k, 14242, GameState); 
    int leftover = 26 - numcardsT; //total number of card - number of hards choosen per game
    //intializes supplies and sets all of the uninitilized to -1
    enum CARD notused = minion;
    enum CARD used = adventurer; 
    //checks that unused kingdom cards are uninitialized
    assert(GameState -> supplyCount[(int)minion]== -1);
    assert(GameState -> supplyCount[(int)steward]== -1);
    assert(GameState -> supplyCount[(int)tribute]== -1);
    assert(GameState -> supplyCount[(int)ambassador]== -1);
    assert(GameState -> supplyCount[(int)cutpurse]== -1);
    assert(GameState -> supplyCount[(int)embargo]== -1);
    assert(GameState -> supplyCount[(int)outpost]== -1);
    assert(GameState -> supplyCount[(int)salvager]== -1);
    assert(GameState -> supplyCount[(int)sea_hag]== -1);
    assert(GameState -> supplyCount[(int)treasure_map]== -1);
    
    //checks that kingdom cards are initiallized
    assert(GameState -> supplyCount[(int)adventurer] == 10);
    assert(GameState -> supplyCount[(int)council_room] == 10);
    assert(GameState -> supplyCount[(int)feast] == 10);
    assert(GameState -> supplyCount[(int)gardens] == 8);
    assert(GameState -> supplyCount[(int)mine] == 10);
    assert(GameState -> supplyCount[(int)remodel] == 10);
    assert(GameState -> supplyCount[(int)smithy] == 10);
    assert(GameState -> supplyCount[(int)village] == 10);
    assert(GameState -> supplyCount[(int)baron] == 10);
    assert(GameState -> supplyCount[(int)great_hall] == 10);
    printf("Assigns Supply correctly\n"); 

    //Check that cards not initialized should have supply set to -1

    
    
    
    return 0;


}
