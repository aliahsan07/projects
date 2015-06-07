/******************************************
 * Unit Test 4: gainCard ******************
 ******************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main (int argc, char** argv) {

    printf ("******************************************\n");
    printf ("* Unit Test 4: gainCard START ************\n");
    printf ("******************************************\n\n");
    
    int players = 2;
    int randomSeed = 1;
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState Game;
    int currentPlayer = 0;
    
    int r = initializeGame(players, cards, randomSeed, &Game);
    printf ("Initializing game...\n");
    printf ("(Expecting 0)\n");
    printf ("initializeGame(2, cards, 1, &Game) = %d\n\n", r);
    assert(r == 0);

    // Add smithy to currentPlayer's hand
    printf ("*** TEST A ***\n");
    r = gainCard(smithy, &Game, 2, currentPlayer);
    printf ("Adding a smithy card to currentPlayer's hand...\n");
    printf ("(Expecting 0)\n");
    printf ("gainCard(smithy, &Game, 2, currentPlayer) = %d\n\n", r);
    assert(r == 0);

    r = supplyCount(smithy, &Game);
    printf ("Re-counting smithy cards in supply...\n");
    printf ("(Expecting 9)\n");
    printf ("supplyCount(smithy, &Game) = %d\n\n", r);
    assert(r == 9);

    r = fullDeckCount(currentPlayer, smithy, &Game);
    printf ("Re-counting smithy cards in currentPlayer's hand, deck, and discard pile...\n");
    printf ("(Expecting 1)\n");
    printf ("fullDeckCount(currentPlayer, smithy, &Game) = %d\n\n", r);
    assert(r == 1);

    // Add smithy to currentPlayer's deck
    printf ("*** TEST B ***\n");
    r = gainCard(smithy, &Game, 1, currentPlayer);
    printf ("Adding a smithy card to currentPlayer's deck...\n");
    printf ("(Expecting 0)\n");
    printf ("gainCard(smithy, &Game, 1, currentPlayer) = %d\n\n", r);
    assert(r == 0);

    r = supplyCount(smithy, &Game);
    printf ("Re-counting smithy cards in supply...\n");
    printf ("(Expecting 8)\n");
    printf ("supplyCount(smithy, &Game) = %d\n\n", r);
    assert(r == 8);

    r = fullDeckCount(currentPlayer, smithy, &Game);
    printf ("Re-counting smithy cards in currentPlayer's hand, deck, and discard pile...\n");
    printf ("(Expecting 2)\n");
    printf ("fullDeckCount(currentPlayer, smithy, &Game) = %d\n\n", r);
    assert(r == 2);

    // Discard a smithy card from supply
    printf ("*** TEST C ***\n");
    r = gainCard(smithy, &Game, 0, currentPlayer);
    printf ("Discarding a smithy card from supply...\n");
    printf ("(Expecting 0)\n");
    printf ("gainCard(smithy, &Game, 0, currentPlayer) = %d\n\n", r);
    assert(r == 0);

    r = supplyCount(smithy, &Game);
    printf ("Re-counting smithy cards in supply...\n");
    printf ("(Expecting 7)\n");
    printf ("supplyCount(smithy, &Game) = %d\n\n", r);
    assert(r == 7);

    r = fullDeckCount(currentPlayer, smithy, &Game);
    printf ("Re-counting smithy cards in currentPlayer's hand, deck, and discard pile...\n");
    printf ("(Expecting 3)\n");
    printf ("fullDeckCount(currentPlayer, smithy, &Game) = %d\n\n", r);
    assert(r == 3);

    printf ("******************************************\n");
    printf ("* Unit Test 4: gainCard PASSED ***********\n");
    printf ("******************************************\n\n");

    return 0;
}
