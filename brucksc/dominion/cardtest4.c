//#include "dominion.c"
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include "rngs.h"

//Tests steward

int initializeGame(int, int*, int, struct gameState * ); 
struct gameState* newGame(); 
int cardEffect(int, int,  int, int, struct gameState *, int,  int *); 
int playCard(int, int, int, int, struct gameState *);

int main (int argc, char *argv[]){
    int card = 13;
    enum CARD mycard = outpost;     
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
    initializeGame(2, k, 14242, GameState);
    int myturn = whoseTurn(GameState);
    int mydeckcount = GameState -> deckCount[myturn];
    GameState->hand[myturn][0] = steward; 
    choice1 = 1;
    playCard(GameState->hand[myturn][0] , 1 , 0 , 0 , GameState);
    assert(mydeckcount + 2 == GameState -> deckCount[myturn]);
        return 0;
}
