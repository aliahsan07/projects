#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>


int main(int argc, char *argv[]) {

    printf("Card Test 3\n");
    //Starts a game with 3 players, then ends the first players turn
    //Runs whoseTurn
    struct gameState *game = newGame();
    int* kingdom_cards = kingdomCards(adventurer, council_room, steward, gardens, mine, smithy, remodel, village, baron, great_hall);
    initializeGame(3, kingdom_cards, 5, game);    
   
    int coin1 = game->coins;
    cardEffect(steward, 2, 0, 0, game, 0, 0);
    int coin2 = game->coins;

    printf("Coins1: %d\n", coin1);
    printf("Coins2: %d\n", coin2);
    //Asserts taht coins has increaded by 2
    assert(coin1 == coin2 - 2);
    return 0;
}
