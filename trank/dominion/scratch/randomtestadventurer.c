/******************************************
 * Random Card Test: Adventurer ***********
 ******************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

#define DIE_ON_ASSERT 0
#define MAX_TESTS 10
//#define RAND_MAX 1000

void massert(int b, char* s);

int main() {

    printf ("******************************************\n");
    printf ("* Random Card Test: Adventurer START *****\n");
    printf ("******************************************\n\n");
    
    int players, player, randomSeed, totalCards, i, r;
    
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState Game1;
    struct gameState Game2;

    // Start random test 1 out of 2
    for (i = 0; i < MAX_TESTS; i++){

        printf("Game1 Test %d:\n", i+1);

        players = rand()%3 + 2;   // create random numbers of players (2-4)
        randomSeed = rand();    // create a random seed

        // Initialize game
        r = initializeGame(players, cards, randomSeed, &Game1);
        printf ("Initializing game...\n");
        massert(r == 0, "Game didn't initialized!");

        // Set deckCount, discardCount, and handCount for player
        Game1.deckCount[player] = rand() % MAX_DECK;
        Game1.discardCount[player] = rand() % MAX_DECK;
        Game1.handCount[player] = rand() % MAX_HAND;

        // Show total cards
        totalCards = Game1.handCount[player] + Game1.deckCount[player] + Game1.discardCount[player];
        printf ("Hand count before playing card: %d\n", Game1.handCount[player]);
        printf ("Deck count before playing card: %d\n", Game1.deckCount[player]);
        printf ("Dicard pile count before playing card: %d\n", Game1.discardCount[player]);
        printf ("Total cards before playing card: %d\n", totalCards);

        // Play adventurer card
        r = cardEffect(adventurer, 1, 1, 1, &Game1, 0, 0);
        printf ("Playing adventurer card...\n");
        massert(r == 0, "Failed to play!");

        // Show total cards
        totalCards = Game1.handCount[player] + Game1.deckCount[player] + Game1.discardCount[player];
        printf ("Hand count after playing card: %d\n", Game1.handCount[player]);
        printf ("Deck count after playing card: %d\n", Game1.deckCount[player]);
        printf ("Dicard pile count after playing card: %d\n", Game1.discardCount[player]);
        printf ("Total cards after playing card: %d\n\n", totalCards);
        
    }

    printf ("******************************************\n\n");

    // Start random test 2 out of 2
    for (i = 0; i < MAX_TESTS; i++){

        printf("Game2 Test %d:\n", i+1);

        players = rand()%3 + 2;   // create random numbers of players (2-4)
        randomSeed = rand();    // create a random seed

        // Initialize game
        r = initializeGame(players, cards, randomSeed, &Game2);
        printf ("Initializing game...\n");
        massert(r == 0, "Game didn't initialized!");

        // Set deckCount, discardCount, and handCount for player
        Game2.deckCount[player] = rand() % MAX_DECK;
        Game2.discardCount[player] = rand() % MAX_DECK;
        Game2.handCount[player] = rand() % MAX_HAND;

        // Show total cards
        totalCards = Game2.handCount[player] + Game2.deckCount[player] + Game2.discardCount[player];
        printf ("Hand count before playing card: %d\n", Game2.handCount[player]);
        printf ("Deck count before playing card: %d\n", Game2.deckCount[player]);
        printf ("Dicard pile count before playing card: %d\n", Game2.discardCount[player]);
        printf ("Total cards before playing card: %d\n", totalCards);

        // Play adventurer card
        r = cardEffect(adventurer, 1, 1, 1, &Game2, 0, 0);
        printf ("Playing adventurer card...\n");
        massert(r == 0, "Failed to play!");

        // Show total cards
        totalCards = Game2.handCount[player] + Game2.deckCount[player] + Game2.discardCount[player];
        printf ("Hand count after playing card: %d\n", Game2.handCount[player]);
        printf ("Deck count after playing card: %d\n", Game2.deckCount[player]);
        printf ("Dicard pile count after playing card: %d\n", Game2.discardCount[player]);
        printf ("Total cards after playing card: %d\n\n", totalCards);
        
    }
    
    printf ("******************************************\n");
    printf ("* Random Card Test: Adventurer FINISHED **\n");
    printf ("******************************************\n\n");

    return 0;
}


void massert(int b, char* s) {
    if (!b) {
        printf ("ASSERTION FAILURE: %s\n", s);
        if (DIE_ON_ASSERT) {
            exit(1);
        }
    }
}
