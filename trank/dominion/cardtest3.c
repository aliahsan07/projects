/******************************************
 * Card Test 3: Mine **********************
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
    printf ("* Card Test 3: Mine START ****************\n");
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
    Game.hand[player1][0] = mine;
    Game.hand[player1][1] = curse;
    Game.hand[player1][2] = copper;
    Game.hand[player1][3] = copper;
    Game.hand[player1][4] = silver;
    printf ("Player1: 5 cards in hand\n\n");
    
    int choice1 = 1;
    int choice2 = gold;
    int choice3 = 0;
    int cardPresent = 0;
    int i;
    
    // Play Mine
    r = cardEffect(mine, choice1, choice2, choice3, &Game, 0, 0);
    printf ("Player1 plays Mine (attempt to discard curse for gold)...\n");
    massert (r == 0, "Failed to play card");

    Game.hand[player1][0] = mine;
    Game.hand[player1][1] = curse;
    Game.hand[player1][2] = copper;
    Game.hand[player1][3] = copper;
    Game.hand[player1][4] = silver;
    
    // Play Mine
    choice1 = 3;
    r = cardEffect(mine, choice1, choice2, choice3, &Game, 0, 0);
    printf ("Player1 plays Mine (attempt to discard copper for gold)...\n");
    massert (r == 0, "Failed to play card");

    Game.hand[player1][0] = mine;
    Game.hand[player1][1] = curse;
    Game.hand[player1][2] = copper;
    Game.hand[player1][3] = copper;
    Game.hand[player1][4] = silver;
    
    // Play Mine
    choice1 = 4;
    r = cardEffect(mine, choice1, choice2, choice3, &Game, 0, 0);
    printf ("Player1 plays Mine (attempt to discard silver for gold)...\n");
    massert (r == 0, "Failed to play card");

    printf ("\nCheck to find if gold is in hand...\n");
	for (i = 0; i < Game.handCount[player1]; i++)
	{
		if (Game.hand[player1][i] == gold)
	    {
	    	cardPresent = 1;
	    }
	}
	massert(cardPresent == 1, "Card not present");
    printf ("Gold present!\n\n");
    
    printf ("******************************************\n");
    printf ("* Card Test 3: Mine FINISHED *************\n");
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
