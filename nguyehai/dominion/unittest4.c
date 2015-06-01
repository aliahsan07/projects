#include "assert.h"
#include "dominion_helpers.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int testFullDeckCount(int player, int card, struct gameState *post) {
    int i;
    int result;
    int count = 0;
    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));

    for (i = 0; i < pre.deckCount[player]; i++) {
        if(pre.deck[player][i] == card) count++;
    }

    for (i = 0; i < pre.handCount[player]; i++)
    {
      if (pre.hand[player][i] == card) count++;
    }

    for (i = 0; i < pre.discardCount[player]; i++)
    {
      if (pre.discard[player][i] == card) count++;
    }

    result = fullDeckCount(player, card, post);
    assert(result == count);

    assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);

    return result;
}

int main() {
    struct gameState G;

    printf("\nStarting Test for fullDeckCount...\n");

    SelectStream(2);
    PutSeed(3);

    int i, n;
    int player;
    int card;

    for(n = 0; n < 2000; n++) {
        for(i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        player = floor(Random() * MAX_PLAYERS);
        card = floor(Random() * 26);
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

        testFullDeckCount(player, card, &G);
    }

    printf("\nAll Tests PASSED\n\n");
    printf("\n\nEnding Test for fullDeckCount...\n");
    return 0;
}
