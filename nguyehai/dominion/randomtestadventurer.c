#include "assert.h"
#include "dominion_helpers.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


int testUseAdventurer(int player, struct gameState *post) {
    int drawntreasure = 0;
    int cardDrawn;
    int temphand[MAX_HAND];
    int result;
    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));

    int z = 0;

    printf("Player: %d", player);
    while (drawntreasure < 2) {
        if (pre.deckCount[player] < 1) {
            shuffle(player, &pre);
        }
    }
    drawCard(player, &pre);
    cardDrawn = pre.hand[player][pre.handCount[player] - 1];
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
        drawntreasure++;
    else {
        temphand[z] = cardDrawn;
        pre.handCount[player]--;
        z++;
    }

    while(z-1 >= 0) {
        pre.discard[player][pre.discardCount[player]++] = temphand[z-1];
        z = z - 1;
    }

    result = useAdventurer(player, post);
    assert(result == 0);

    assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);

    return result;
}

int main() {
    struct gameState G;

    printf("Starting Random Test for useAdventurer... \n");

    SelectStream(2);
    PutSeed(3);

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

        testUseAdventurer(player, &G);
    }

    printf("Ending Test for useAdventurer...\n");
}
