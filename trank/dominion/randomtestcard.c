/******************************************
 * Random Card Test: Steward **************
 ******************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

#define DIE_ON_ASSERT 0
#define MAX_TESTS 10     // 5-ok, 6-seg falt, 7-failed initialize
#define MAX_COINS 20
//#define RAND_MAX 1000

void massert(int b, char* s);

int main() {

    printf ("******************************************\n");
    printf ("* Random Card Test: Steward START ********\n");
    printf ("******************************************\n\n");
    
    int players, player, randomSeed, totalCards, choice, i, r;
    
    int cards[10] = {adventurer, steward, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState Game1;
    struct gameState Game2;
    struct gameState Game3;

    // Start random test 1 out of 3
    for (i = 0; i < MAX_TESTS; i++){

        printf("Game1 Test %d:\n", i+1);

        players = rand()%3 + 2;   // create random numbers of players (2-4)
        randomSeed = rand();    // create a random seed
        choice = rand() % 3;

        // Initialize game
        r = initializeGame(players, cards, randomSeed, &Game1);
        printf ("Initializing game...\n");
        massert(r == 0, "Game didn't initialized!");

        // Set deckCount, discardCount, handCount, and coins for player
        Game1.deckCount[player] = rand() % MAX_DECK;
        Game1.discardCount[player] = rand() % MAX_DECK;
        Game1.handCount[player] = rand() % MAX_HAND;
        Game1.coins = rand() % MAX_COINS;

        // Show total cards & coins
        totalCards = Game1.handCount[player] + Game1.deckCount[player];
        printf ("Hand count before playing card: %d\n", Game1.handCount[player]);
        printf ("Deck count before playing card: %d\n", Game1.deckCount[player]);
        printf ("Total cards before playing card: %d\n", totalCards);
        printf ("Total coins before playing card: %d\n", Game1.coins);

        // Play steward card
        r = cardEffect(steward, choice, 3, 4, &Game1, 0, 0);
        printf ("Playing steward card...\n");
        massert(r == 0, "Failed to play!");
        printf("Choice %d:\n", choice);

        // Show total cards & coins
        totalCards = Game1.handCount[player] + Game1.deckCount[player];
        printf ("Hand count after playing card: %d\n", Game1.handCount[player]);
        printf ("Deck count after playing card: %d\n", Game1.deckCount[player]);
        printf ("Total cards after playing card: %d\n", totalCards);
        printf ("Total coins after playing card: %d\n\n", Game1.coins);
        
    }

    printf ("******************************************\n\n");

    // Start random test 2 out of 3
    for (i = 0; i < MAX_TESTS; i++){

        printf("Game2 Test %d:\n", i+1);

        players = rand()%3 + 2;   // create random numbers of players (2-4)
        randomSeed = rand();    // create a random seed
        choice = rand() % 3;

        // Initialize game
        r = initializeGame(players, cards, randomSeed, &Game2);
        printf ("Initializing game...\n");
        massert(r == 0, "Game didn't initialized!");

        // Set deckCount, discardCount, handCount, and coins for player
        Game2.deckCount[player] = rand() % MAX_DECK;
        Game2.discardCount[player] = rand() % MAX_DECK;
        Game2.handCount[player] = rand() % MAX_HAND;
        Game2.coins = rand() % MAX_COINS;

        // Show total cards & coins
        totalCards = Game2.handCount[player] + Game2.deckCount[player];
        printf ("Hand count before playing card: %d\n", Game2.handCount[player]);
        printf ("Deck count before playing card: %d\n", Game2.deckCount[player]);
        printf ("Total cards before playing card: %d\n", totalCards);
        printf ("Total coins before playing card: %d\n", Game2.coins);

        // Play steward card
        r = cardEffect(steward, choice, 3, 4, &Game2, 0, 0);
        printf ("Playing steward card...\n");
        massert(r == 0, "Failed to play!");
        printf("Choice %d:\n", choice);

        // Show total cards & coins
        totalCards = Game2.handCount[player] + Game2.deckCount[player];
        printf ("Hand count after playing card: %d\n", Game2.handCount[player]);
        printf ("Deck count after playing card: %d\n", Game2.deckCount[player]);
        printf ("Total cards after playing card: %d\n", totalCards);
        printf ("Total coins after playing card: %d\n\n", Game2.coins);
        
    }

    printf ("******************************************\n\n");

    // Start random test 2 out of 3
    for (i = 0; i < MAX_TESTS; i++){

        printf("Game3 Test %d:\n", i+1);

        players = rand()%3 + 2;   // create random numbers of players (2-4)
        randomSeed = rand();    // create a random seed
        choice = rand() % 3;

        // Initialize game
        r = initializeGame(players, cards, randomSeed, &Game3);
        printf ("Initializing game...\n");
        massert(r == 0, "Game didn't initialized!");

        // Set deckCount, discardCount, handCount, and coins for player
        Game3.deckCount[player] = rand() % MAX_DECK;
        Game3.discardCount[player] = rand() % MAX_DECK;
        Game3.handCount[player] = rand() % MAX_HAND;
        Game3.coins = rand() % MAX_COINS;

        // Show total cards & coins
        totalCards = Game3.handCount[player] + Game3.deckCount[player];
        printf ("Hand count before playing card: %d\n", Game3.handCount[player]);
        printf ("Deck count before playing card: %d\n", Game3.deckCount[player]);
        printf ("Total cards before playing card: %d\n", totalCards);
        printf ("Total coins before playing card: %d\n", Game3.coins);

        // Play steward card
        r = cardEffect(steward, choice, 3, 4, &Game3, 0, 0);
        printf ("Playing steward card...\n");
        massert(r == 0, "Failed to play!");
        printf("Choice %d:\n", choice);

        // Show total cards & coins
        totalCards = Game3.handCount[player] + Game3.deckCount[player];
        printf ("Hand count after playing card: %d\n", Game3.handCount[player]);
        printf ("Deck count after playing card: %d\n", Game3.deckCount[player]);
        printf ("Total cards after playing card: %d\n", totalCards);
        printf ("Total coins after playing card: %d\n\n", Game3.coins);
        
    }
    
    printf ("******************************************\n");
    printf ("* Random Card Test: Steward FINISHED *****\n");
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
