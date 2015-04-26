#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>


int main(int argc, char *argv[]) {

    printf("Card Test 4\n");
    //Starts a game with 3 players, then ends the first players turn
    //Runs whoseTurn
    struct gameState *game = newGame();
    int* kingdom_cards = kingdomCards(adventurer, council_room, feast, gardens, mine, smithy, remodel, village, embargo, great_hall);
    initializeGame(3, kingdom_cards, 5, game);    
   
    int coins1 = game->coins;
    int embargoToken1 = game->embargoTokens[0];
    cardEffect(embargo, 0, 0, 0, game, 0, 0);
    int coins2 = game->coins;
    int embargoToken2 = game->embargoTokens[0];

    printf("Coins 1: %d\n", coins1);
    printf("Coins 2: %d\n", coins2);
    printf("Tokens 1: %d\n", embargoToken1);
    printf("Tokens 2: %d\n", embargoToken2);
    
    //Asserts that coins has increased by 2
    assert(coins1 == coins2 - 2);
    assert(embargoToken1 == embargoToken2 - 1);
    printf("Card Test 4 Success\n");
    return 0;
}
