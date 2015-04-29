#include "assert.h"
#include "dominion_helpers.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int testScoreFor(int player, struct gameState *post) {
    int i;
    int result;
    int score = 0;
    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));

    //score from hand
    for (i = 0; i < pre.handCount[player]; i++) {
        if (pre.hand[player][i] == curse) { score = score - 1; };
        if (pre.hand[player][i] == estate) { score = score + 1; };
        if (pre.hand[player][i] == duchy) { score = score + 3; };
        if (pre.hand[player][i] == province) { score = score + 6; };
        if (pre.hand[player][i] == great_hall) { score = score + 1; };
        if (pre.hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, &pre) / 10 ); };
    }

    //score from discard
    for (i = 0; i < pre.discardCount[player]; i++) {
        if (pre.discard[player][i] == curse) { score = score - 1; };
        if (pre.discard[player][i] == estate) { score = score + 1; };
        if (pre.discard[player][i] == duchy) { score = score + 3; };
        if (pre.discard[player][i] == province) { score = score + 6; };
        if (pre.discard[player][i] == great_hall) { score = score + 1; };
        if (pre.discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, &pre) / 10 ); };
    }

    //score from deck
    for (i = 0; i < pre.discardCount[player]; i++) {
        if (pre.deck[player][i] == curse) { score = score - 1; };
        if (pre.deck[player][i] == estate) { score = score + 1; };
        if (pre.deck[player][i] == duchy) { score = score + 3; };
        if (pre.deck[player][i] == province) { score = score + 6; };
        if (pre.deck[player][i] == great_hall) { score = score + 1; };
        if (pre.deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, &pre) / 10 ); };
    }

    result = scoreFor(player, post);
    assert(result == score);

    assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);

    return result;
}

int main() {
    struct gameState G;

    printf("\nStarting Test for scoreFor...\n");

    SelectStream(2);
    PutSeed(3);

    int i, n;
    int player;

    for(n = 0; n < 2000; n++) {
        for(i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        player = floor(Random() * MAX_PLAYERS);
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

        testScoreFor(player, &G);
    }

    printf("\nAll Tests PASSED\n\n");
    printf("\n\nEnding Test for scoreFor...\n");
    return 0;
}
