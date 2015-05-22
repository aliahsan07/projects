#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int isUsedCard(int* k, int num, int kingdomCardIdx){
    int i = 0;
    for(i; i < kingdomCardIdx; i++){
        if(k[i] == num)
            return 1;
        }
        return 0;
    }

int generateRandomPlayers(){
    return (rand() % 3) + 2;
}

int generateRandomKingdom(){
    return (rand() % 20) + 7;
}

// no pass by reference in C :(
int generateRandomHandPos(){
    return (rand() % 20) + 7;
}

int countHandMoney(struct gameState* state){
    int money = 0;
    struct gameState* p;
    p = state;
    int i =0;

    // count money in curPlayer's hand
    while(i<numHandCards(state)){
        if (handCard(i, p) == copper){
        money++;
        }
        else if (handCard(i, p) == silver){
            money += 2;
        }
        else if (handCard(i, p) == gold){
            money += 3;
        }
        i++;
    }

    return money;
}

// gets first action in hand, if exists
int firstActionPos(struct gameState *state){
    struct gameState* p;
    p = state;
    int firstActionPos = -1; // assume no actions
    int i;

    for (i = 0; i < numHandCards(&state); i++) {
        if (( gold < handCard(i, p) ) && (handCard(i,p) < cardTypeCount) ){
            printf("handCard(ip) == %d\r\n", handCard(i,p));
            firstActionPos = i;
            break;
        }
    }

    return firstActionPos;
}

int main(int argc, char*argv[]){
    ensureArg2(argc);
    struct gameState state;
    int k[10];
    int i = 0;

    // randomly generate 10 unique kingdom cards
    for(i; i < 10; i++){
        k[i] = (rand() % 20) + 7;
        while(isUsedCard(k, k[i],i)){
            k[i] = (rand() % 20) + 7;
        }
    }

//printf("kcards: [%d][%d][%d],[%d][%d][%d],[%d][%d][%d],[%d]", k[0], k[1], k[2], k[2], k[3], k[4], k[5], k[6], k[7], k[8], k[9]); 
    int r = initializeGame(generateRandomPlayers(), k, atoi(argv[1]), &state);
    assert (r == 0);
    //while(!(isGameOver(&state))){
    // For curPlayer
    // track money avail
    int money = 0;
    // count money
    // simulate action cards phase. Just play one action card
    int cardPlayed = 0;
    int firstActionIdx = firstActionPos(&state);
    printf("first action pos: %d\r\n", firstActionPos(&state));
    printf("first action card: %d\r\n", handCard(firstActionPos(&state), &state));
    // //playCard(firstActionPos(&state), -1,-1,-1, &state); 
    printf("Player %d played action card: %d", state.whoseTurn, cardPlayed);
    //simulate buy phase
    //while(state.numBuys[state.whoseTurn] != 0){
    //
    //assuming buy card will update coins?
    //
    //}
    //simulate clean up phase
    // how to keep track of discards
    endTurn(&state); // resets: numActions, coins, numBuys
    //}

return 0;

}
