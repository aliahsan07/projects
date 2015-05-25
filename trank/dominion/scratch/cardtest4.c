/******************************************
 * Card Test 4: Steward *******************
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
    printf ("* Card Test 4: Steward START *************\n");
    printf ("******************************************\n\n");
    
    int players = 2;
    int randomSeed = 5;
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState Game;
    struct gameState *state = &Game;
    int player1 = whoseTurn(state);
    
    int r = initializeGame(players, cards, randomSeed, &Game);
    printf ("Initializing game...\n");
    printf ("(Expecting 0)\n");
    printf ("initializeGame(2, cards, 5, &Game) = %d\n\n", r);
    massert(r == 0, "Game didn't initialized");
    
    // Give player1 custom set of cards
    Game.hand[player1][0] = steward;
    Game.hand[player1][1] = copper;
    Game.hand[player1][2] = copper;
    Game.hand[player1][3] = copper;
    Game.hand[player1][4] = copper;

    Game.deck[player1][0] = silver;
    Game.deck[player1][1] = silver;
    Game.deck[player1][2] = silver;
    Game.deck[player1][3] = silver;
    Game.deck[player1][4] = silver;
    Game.coins = 0;
    printf ("Player1: 5 cards in hand, 5 cards in deck\n\n");
    
    int choice1 = 1;
    int choice2 = 1;
    int choice3 = 2;

    int prevHandCount1 = Game.handCount[player1];
    int prevDeckCount1 = Game.deckCount[player1];
    int prevCoins = state->coins;

    // Play Steward
    r = cardEffect(steward, choice1, choice2, choice3, &Game, 0, 0);
    printf ("Player1 plays Steward (+2 cards)...\n");
    massert (r == 0, "Failed to play card");
    
    printf ("Game.handCount[player1] = %d\n", Game.handCount[player1]);
    massert (Game.handCount[player1] == prevHandCount1 + 1, "Incorrect number of cards for player1's hand");
    printf ("(Expecting 6)\n");
    
    printf ("Game.deckCount[player1] = %d\n", Game.deckCount[player1]);
    massert (Game.deckCount[player1] == prevDeckCount1 - 2, "Incorrect number of cards for player1's deck");
    printf ("(Expecting 3)\n\n");

    Game.hand[player1][0] = steward;
    Game.hand[player1][1] = copper;
    Game.hand[player1][2] = copper;
    Game.hand[player1][3] = copper;
    Game.hand[player1][4] = copper;

    Game.deck[player1][0] = silver;
    Game.deck[player1][1] = silver;
    Game.deck[player1][2] = silver;
    Game.deck[player1][3] = silver;
    Game.deck[player1][4] = silver;
    
    // Play Steward
    choice1 = 2;
    r = cardEffect(steward, choice1, choice2, choice3, &Game, 0, 0);
    printf ("Player1 plays Steward (+2 coins)...\n");
    massert (r == 0, "Failed to play card");

    printf ("state->coins = %d\n", state->coins);
    massert (state->coins == prevCoins + 2, "Incorrect number of coins for player1");
    printf ("(Expecting 2)\n\n");

    Game.hand[player1][0] = steward;
    Game.hand[player1][1] = copper;
    Game.hand[player1][2] = copper;
    Game.hand[player1][3] = copper;
    Game.hand[player1][4] = copper;

    Game.deck[player1][0] = silver;
    Game.deck[player1][1] = silver;
    Game.deck[player1][2] = silver;
    Game.deck[player1][3] = silver;
    Game.deck[player1][4] = silver;
    
    // Play Steward
    choice1 = 0;
    r = cardEffect(steward, choice1, choice2, choice3, &Game, 0, 0);
    printf ("Player1 plays Steward (trash 2 cards in hand)...\n");
    massert (r == 0, "Failed to play card");
    printf ("Player1 discarded 2 cards...\n\n");
    
    printf ("******************************************\n");
    printf ("* Card Test 4: Steward FINISHED **********\n");
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
