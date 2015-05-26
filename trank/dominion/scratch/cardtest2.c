/******************************************
 * Card Test 2: Council Room **************
 ******************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

#define DIE_ON_ASSERT 0

void massert(int b, char* s);

int main () {
    printf ("******************************************\n");
    printf ("* Card Test 2: Council Room START ********\n");
    printf ("******************************************\n\n");
    
    int players = 2;
    int randomSeed = 3;
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState Game;
    struct gameState *state = &Game;
    int player1 = whoseTurn(state);
    int player2 = player1 + 1;
    
    int r = initializeGame(players, cards, randomSeed, &Game);
    printf ("Initializing game...\n");
    printf ("(Expecting 0)\n");
    printf ("initializeGame(2, cards, 3, &Game) = %d\n\n", r);
    massert(r == 0, "Game didn't initialized");

    // Give player1 custom set of cards
    Game.hand[player1][0] = council_room;
    Game.hand[player1][1] = copper;
    Game.hand[player1][2] = copper;
    Game.hand[player1][3] = copper;
    Game.hand[player1][4] = copper;

    Game.deck[player1][0] = silver;
    Game.deck[player1][1] = silver;
    Game.deck[player1][2] = silver;
    Game.deck[player1][3] = silver;
    Game.deck[player1][4] = silver;
    printf ("Player1: 5 cards in hand, 5 cards in deck\n");

    // Give player2 custom set of cards
    Game.deck[player2][0] = council_room;
    Game.deck[player2][1] = copper;
    Game.deck[player2][2] = copper;
    Game.deck[player2][3] = copper;
    Game.deck[player2][4] = copper;
    Game.deck[player2][5] = silver;
    Game.deck[player2][6] = silver;
    Game.deck[player2][7] = silver;
    Game.deck[player2][8] = silver;
    Game.deck[player2][9] = silver;
    printf ("Player2: 10 cards in deck\n");
    
    int prevHandCount1 = Game.handCount[player1];
    int prevDeckCount1 = Game.deckCount[player1];
    int prevHandCount2 = Game.handCount[player2];
    int prevDeckCount2 = Game.deckCount[player2];
    int prevNumBuys = state->numBuys;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;

    // Play Council Room
    cardEffect(council_room, choice1, choice2, choice3, &Game, 0, 0);
    printf ("Player1 plays Council Room (player1: +4 cards, +1 buy | others: +1 card)...\n\n");
    
    printf ("Game.handCount[player1] = %d\n", Game.handCount[player1]);
    massert (Game.handCount[player1] == prevHandCount1 + 3, "Incorrect number of cards for player1's hand");
    printf ("(Expecting 8)\n\n");
    
    printf ("Game.deckCount[player1] = %d\n", Game.deckCount[player1]);
    massert (Game.deckCount[player1] == prevDeckCount1 - 4, "Incorrect number of cards for player1's deck");
    printf ("(Expecting 1)\n\n");

    printf ("state->numBuys = %d\n", state->numBuys);
    massert (state->numBuys == prevNumBuys + 1, "Incorrect number of cards for player1's deck");
    printf ("(Expecting 2)\n\n");
    
    printf ("Game.handCount[player2] = %d\n", Game.handCount[player2]);
    massert (Game.handCount[player2] == prevHandCount2 + 1, "Incorrect number of cards for player2's hand");
    printf ("(Expecting 1)\n\n");

    printf ("Game.deckCount[player2] = %d\n", Game.deckCount[player2]);
    massert (Game.deckCount[player2] == prevDeckCount2 - 1, "Incorrect number of cards for player2's deck");
    printf ("(Expecting 9)\n\n");
    
    printf ("******************************************\n");
    printf ("* Card Test 2: Council Room FINISHED *****\n");
    printf ("******************************************\n\n");
}

void massert(int b, char* s) {
    if (!b) {
        printf ("ASSERTION FAILURE: %s\n", s);
        if (DIE_ON_ASSERT) {
            exit(1);
        }
    }
}
