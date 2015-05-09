#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 3000

int main() {
    int r;
    int players;
    struct gameState G;
    int currentPlayer;
    int choice1;
    int choice2;
    int i;
    int n;
    int seed;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int counter =0;
    int drawntreasure;
    int fails = 0;

    printf("Starting Random Test adventurer Card..\n");

    for (i = 0; i < MAX_TESTS; ++i) {
        players = rand() % (2) + 2;
        seed = rand();
        G.deckCount[players] = rand() % MAX_DECK;
        G.handCount[players] = rand() % MAX_HAND;
        G.discardCount[players] = rand() % MAX_DECK;

        r = initializeGame(players, k, 3, &G);
        if (r != 0) {
            printf("Initializing Game failed\n");
            printf("Values: players =%d seed =%d\nG.deckCount =%d G.handCount =%d\nG.discardCount =%d\n", players, seed, G.deckCount[players], G.handCount[players], G.discardCount[players]);
            ++fails;
        }

        currentPlayer = rand() % 4;
        choice1 = randomCardGenerator();
        choice2 = randomCardGenerator();

        printf(" ");
        r = cardEffect(adventurer, choice1, choice2, 1, &G);
        if (r !=0) {
            printf("\nSomething went wrong with adventurer.\nValues: players =%d seed =%d\nG.deckCount =%d G.handCount =%d\nG.discardCount =%d\n", players, seed, G.deckCount[players], G.handCount[players], G.discardCount[players]);
        }
        ++counter;
    }
        printf("\nNumber of failed initilizes = %d / 1300\n", fails);
        printf("End of remodel Random Test\nNumber of random tests excecuted = %d\n", counter);
return 0;
}


int randomCardGenerator()
{
    int card = rand () % 26;
    if (card == 0)
        return  curse;
    if (card == 1)
        return estate;
    if (card == 2)
        return duchy;
    if (card == 3)
        return province;
    if (card == 4)
        return copper;
    if (card == 5)
        return silver;
    if (card == 6)
        return gold;
    if (card == 7)
        return adventurer;
    if (card == 8)
        return council_room;
    if (card == 9)
        return feast;
    if (card == 10)
        return gardens;
    if (card == 11)
        return mine;
    if (card == 12)
        return remodel;
    if (card == 13)
        return smithy;
    if (card == 14)
        return village;
    if (card == 15)
        return baron;
    if (card == 16)
        return great_hall;
    if (card == 17)
        return minion;
    if (card == 18)
        return steward;
    if (card == 19)
        return tribute;
    if (card == 20)
        return ambassador;
    if (card == 21)
        return cutpurse;
    if (card == 22)
        return embargo;
    if (card == 23)
        return outpost;
    if (card == 24)
        return salvager;
    if (card == 25)
        return sea_hag;
    if (card == 26)
        return treasure_map;
}

