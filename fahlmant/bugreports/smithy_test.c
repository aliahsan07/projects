#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>


int main(int argc, char *argv[]) {

    printf("Card Test 1\n");
    //Starts a game with 3 players, then ends the first players turn
    //Runs whoseTurn
    struct gameState *game = newGame();
    int* kingdom_cards = kingdomCards(adventurer, council_room, feast, gardens, mine, smithy, remodel, village, baron, great_hall);
    initializeGame(3, kingdom_cards, 5, game);    
   
    int r1 = game->handCount[0];
    cardEffect(smithy, 0, 0, 0, game, 0, 0);
    int r2 = game->handCount[0];

    printf("R1: %d\n", r1);
    printf("R2: %d\n", r2);
    if(r1 == r2 - 3)
    {
        printf("Card Test 1 Success\n");
    }
    else
    {
        printf("Card Test 1 Failure!\n");
    }
    return 0;
}
