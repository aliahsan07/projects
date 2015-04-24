#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>


int main(int argc, char *argv[]) {

    printf("Unit Test 2\n");
    //Starts a game with 3 players, then ends the first players turn
    //Runs shuffle
    struct gameState *game = newGame();
    int* kingdom_cards = kingdomCards(adventurer, council_room, feast, gardens, mine, smithy, remodel, village, baron, great_hall); 
    initializeGame(3, kingdom_cards, 5, game);
    int r = shuffle(whoseTurn(game), game);

    printf("R: %d\n", r);

    //Asserts that shuffle worked
    assert(r != -1);
    return 0;
}
