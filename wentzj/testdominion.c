#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "time.h"
#include "math.h"

/*int isUsedCard(int* k, int num, int kingdomCardIdx){
    int i = 0;

    for(i; i < kingdomCardIdx; i++){
        if(k[i] == num){
            return 1;
        }
    }

    return 0;
}*/

int main(){
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    srand(time(NULL));
    int players = (rand() % 3) + 2;
    int isend = 0;
    int i, n, player, handCount, deckCount, address, choice1, choice2, choice3;
    int fail = 0;
    int pass = 0;
    int action_status = -1;
    int card_choice = 0;
    int action_choice = 0;
    int l = 0;

    printf("++++++++++++\nGame Started\n++++++++++++\n");
    printf("Players: %d\n", players);
    printf("++++++++++++\n\n");
    
    int seed = (rand()+1);
    player = rand() % players;
    initializeGame(players, k, seed, &G);
    G.discardCount[player] = rand() % MAX_DECK;
    G.handCount[player] = rand() % MAX_HAND;
    handCount = G.handCount[player];
    deckCount = G.deckCount[player];

    //Random set of kingom cards
    /*for(i=0; i < 10; i++){
        k[i] = (rand() % 20) + 7;
        while(isUsedCard(k, k[i],i)){
            k[i] = (rand() % 20) + 7;
        }
    }*/
    
    initializeGame(players, k, seed, &G);

    while(isend != 1){
        printf("\n++++++++++++\nBefore\n++++++++++++\n");
        printf("whoseTurn: %d. \nphase: %d. \nnumActions: %d. \nnumBuys: %d. \ncoins: %d. \nplayedCardCount: %d. \nhandCount: %d. \ndeckCount: %d. \ndiscardCount: %d.\n", G.whoseTurn, G.phase, G.numActions, G.numBuys, G.coins, G.playedCardCount, G.handCount[G.whoseTurn], G.deckCount[G.whoseTurn], G.discardCount[G.whoseTurn]);

        action_choice = rand() % 4;
        card_choice = rand() % 10;
        choice1 = rand() % 2;
        choice2 = rand() % 2;
        choice3 = rand() % 2;
        action_status = playCard(action_choice, choice1, choice2, choice3, &G);
        printf("Action Card Choice: %d\n", action_choice);
        for(i = 0; i < G.numBuys; i++){
            l = buyCard(k[card_choice], &G);
            if (l == -1){
                card_choice = rand() % 10;
            }
        }

        printf("Buy Card Choice: %d\n", card_choice);
        printf("++++++++++++\nAfter Turn\n++++++++++++\n");
        printf("whoseTurn: %d. \nphase: %d. \nnumActions: %d. \nnumBuys: %d. \ncoins: %d. \nplayedCardCount: %d. \nhandCount: %d. \ndeckCount: %d. \ndiscardCount: %d.\n", G.whoseTurn, G.phase, G.numActions, G.numBuys, G.coins, G.playedCardCount, G.handCount[G.whoseTurn], G.deckCount[G.whoseTurn], G.discardCount[G.whoseTurn]);

        endTurn(&G);
        isend = isGameOver(&G);
    }

    printf("\n++++++++++++\nGame Over\n++++++++++++\n");

   return 0;
}
