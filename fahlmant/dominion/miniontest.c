#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>
#include <time.h>



int main(int argc, char *argv[]) {
    
    srand(time(NULL));
    struct gameState *game = newGame();
    int* kingdom_cards = kingdomCards(adventurer, council_room, feast, gardens, mine, smithy, remodel, village, minion, great_hall);
    initializeGame(3, kingdom_cards, 5, game);    

    int choices = rand() % 10;
    int choice1 = 0;
    int choice2 = 0;
    
    if(choices > 5)
    {
        choice1 = 1;
    }
    else
    {
        choice2 = 1;
    }

    int numbuys = game->numBuys;
    int coins = game->coins;
    cardEffect(baron, choice1, choice2, 0, game, 0, 0);
    int numbuys2 = game->numBuys;
    int coins2 = game->coins;
    int hand2 = game->handCount[0];

    if(numbuys != numbuys2 - 1)
    {
        printf("1");
        exit(EXIT_SUCCESS);
    }
    if(choice1 == 1)
    {
        if(coins != coins2 - 2)
        {
            printf("1");
            exit(EXIT_SUCCESS);
        }
    }
    if(choice2 == 1)
    {
        if(hand2 != 4)
        {
            printf("1");
            exit(EXIT_SUCCESS);
        }
    }

    return 0;
}
