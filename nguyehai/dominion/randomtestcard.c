#include "assert.h"
#include "dominion_helpers.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


int testUseFeast(int player, int card, int choice, struct gameState *post) {
    int i, x;
    int result;
    //hand = 0;
    struct gameState pre;
    int temphand[MAX_HAND];
    memcpy(&pre, post, sizeof(struct gameState));

    printf("Choice: %d, Player: %d, Card: %d\n", choice, player, card);

    for (i = 0; i <= pre.handCount[player]; i++) {
        temphand[i] = pre.hand[player][i];
        pre.hand[player][i] = -1;
    }

    updateCoins(player, &pre, 5);
    x = 1;

    while(x == 1) {
        if(supplyCount(choice, &pre) <= 0) {
            if (DEBUG)
                printf("Error check 1\n");
            if (DEBUG)
                printf("Cards Left: %d\n", supplyCount(choice, &pre));
        }
        else if(pre.coins < getCost(choice)) {
            printf("Error check 2\n");
            if (DEBUG)
                printf("Coins: %d < %d\n", pre.coins, getCost(choice));
        }
        else{
            if (DEBUG)
                printf("Deck Count: %d\n", pre.handCount[player] + pre.deckCount[player] + pre.discardCount[player]);
        }

        gainCard(choice, &pre, 0, player);
        x = 0;

        if (DEBUG)
            printf("Deck Count: %d\n", pre.handCount[player] + pre.deckCount[player] + pre.discardCount[player]);
    }

    for(i = 0; i <= pre.handCount[player]; i++) {
        pre.hand[player][i] = temphand[i];
        temphand[i] = -1;
    }

    //result = useFeast(player, post, choice);
    result = cardEffect(feast, choice, 0, 0, post, 0, 0);

   // printf("One test completed\n");
    //assert(result == 0);

    //assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);

    return 0;
}

int main() {
    struct gameState G;

    printf("Starting Random Test for useFeast... \n");

    SelectStream(2);
    PutSeed(50);

    int i, n;
    int player, card, choice;

    for(n = 0; n < 2000; n++) {
        for(i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        player = floor(Random() * MAX_PLAYERS);
        card = floor(Random() * 26);
        choice = floor(Random() * 3);
        G.deckCount[player] = floor(Random() * MAX_DECK);
        G.discardCount[player] = floor(Random() * MAX_DECK);
        G.handCount[player] = floor(Random() * MAX_HAND);
        for (i = 0; i < G.handCount[player]; i++) {
            G.hand[player][i] = floor(Random() * MAX_DECK);
        }

        for (i = 0; i < G.discardCount[player]; i++) {
            G.discard[player][i] = floor(Random() * MAX_DECK);
        }

        for (i = 0; i < G.discardCount[player]; i++) {
            G.deck[player][i] = floor(Random() * MAX_DECK);
        }

        testUseFeast(player, card, choice, &G);
    }

    printf("Ending Test for useFeast...\n");
}
