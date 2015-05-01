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
    int leftover = 26 - numcardsT; //total number of card - number of hards choosen per game
    //intializes supplies and sets all of the uninitilized to -1
    enum CARD notused = minion;
    enum CARD used = adventurer; 
    int k[10] =  {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    printf("\n\nUnitTest1\n");
    initializeGame(2, k, 14242, GameState); 

    //checks that unused kingdom cards are uninitialized
    if (GameState -> supplyCount[(int)minion]!= -1){
        printf("FAILURE: did not set minion card to -1\n");
    }
    if (GameState -> supplyCount[(int)steward]!= -1){
        printf("FAILURE: did not set steward card to -1\n");
    }
    if (GameState -> supplyCount[(int)tribute]!= -1){
        printf("FAILURE: did not set tribute card to -1\n");
    }
    if (GameState -> supplyCount[(int)ambassador]!= -1){
        printf("FAILURE: did not set ambassador card to -1\n");
    }
    if (GameState -> supplyCount[(int)cutpurse]!= -1){
        printf("FAILURE: did not set cutpurse card to -1\n");
    }
    if (GameState -> supplyCount[(int)embargo]!= -1){
        printf("FAILURE: did not set embargo card to -1\n");
    }
    if (GameState -> supplyCount[(int)outpost]!= -1){
        printf("FAILURE: did not set outpost card to -1\n");
    }
    if (GameState -> supplyCount[(int)salvager]!= -1){
        printf("FAILURE: did not set salvager card to -1\n");
    }
    if (GameState -> supplyCount[(int)sea_hag]!= -1){
        printf("FAILURE: did not set sea_hag card to -1\n");
    }
    if (GameState -> supplyCount[(int)treasure_map]!= -1){
        printf("FAILURE: did not set treasure_map card to -1\n");
    }
    if(GameState -> supplyCount[(int)great_hall] != -1){
        printf("FAILURE: did not set the great_hall card to -1\n");
    }
    
    //checks that kingdom cards are initiallized
    if(GameState -> supplyCount[(int)adventurer] != 10){
        printf("FAILURE: did not set the adventurer card to 10\n");
    }
    if(GameState -> supplyCount[(int)council_room] != 10){
        printf("FAILURE: did not set the adventurer card to 10\n");
    }
    if(GameState -> supplyCount[(int)feast] != 10){
        printf("FAILURE: did not set the feast card to 10\n");
    }
    if(GameState -> supplyCount[(int)gardens] != 8){
        printf("FAILURE: did not set the gardens card to 8\n");
    }
    if(GameState -> supplyCount[(int)mine] != 10){
        printf("FAILURE: did not set the mine card to 10\n");
    }
    if(GameState -> supplyCount[(int)remodel] != 10){
        printf("FAILURE: did not set the remodel card to 10\n");
    }
    if(GameState -> supplyCount[(int)smithy] != 10){
        printf("FAILURE: did not set the smithy card to 10\n");
    }
    if(GameState -> supplyCount[(int)village] != 10){
        printf("FAILURE: did not set the village card to 10\n");
    }
    if(GameState -> supplyCount[(int)baron] != 10){
        printf("FAILURE: did not set the baron card to 10\n");
    }

    
    //printf("Assigns Supply correctly\n"); 
    return 0;


}
