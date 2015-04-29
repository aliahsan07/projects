#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>


int main(int argc, char *argv[]) {

    printf("Unit Test 4\n");
    //Starts a game with 3 players, then ends the first players turn
    //Runs isGameOver
    struct gameState *game = newGame();
    int* kingdom_cards = kingdomCards(adventurer, council_room, feast, gardens, mine, smithy, remodel, village, baron, great_hall);
    initializeGame(3, kingdom_cards, 5, game);
    int r = isGameOver(game);

    printf("R: %d\n", r);

    //Asserts that game is not over
    assert(r == 0);
    printf("Unit Test 4 Success\n");
    return 0;
}
