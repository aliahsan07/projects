//
//  cardtest3.c
//  Smithy test


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


char* getCard(int* card) {
    int cardNum = *card;
    switch(cardNum) {
        case curse:
            return "Curse";
        case estate:
            return "Estate";
        case duchy:
            return "Duchy";
        case province:
            return "Province";
        case copper:
            return "Copper";
        case silver:
            return "Silver";
        case gold:
            return "Gold";
        case adventurer:
            return "Adventurer";
        case council_room:
            return "CouncilRoom";
        case feast:
            return "Feast";
        case gardens:
            return "Gardens";
        case mine:
            return "Mine";
        case remodel:
            return "Remodel";
        case smithy:
            return "Smithy";
        case village:
            return "Village";
        case baron:
            return "Baron";
        case great_hall:
            return "GreatHall";
        case minion:
            return "Minion";
        case steward:
            return "Steward";
        case tribute:
            return "Tribute";
        case ambassador:
            return "Ambassador";
        case cutpurse:
            return "Cutpurse";
        case embargo:
            return "Embargo";
        case outpost:
            return "Outpost";
        case salvager:
            return "Salvager";
        case sea_hag:
            return "SeaHag";
        case treasure_map:
            return "TreasureMap";
        default:
            return 0;
    }
}

int main(){

    int i;
    int j;
    int k[10] = {adventurer, embargo, great_hall, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    struct gameState g;
    
    printf("Testing Smithy...\n");
    
    initializeGame(2, k, 5, &g);
    
    printf("Start Hand has: %d cards \n", g.handCount[0]);
    assert(g.handCount[0] == 5);
    
    printf("Starting Cards: \n");
    for(i = 0; i < 5; i++) {
        printf("%s ", getCard(&k[i]));
    }
    
    cardEffect(smithy, 0, 0, 0, &g, 0, 0);
    
    printf("\n\nEnd Hand has: %d cards \n", g.handCount[0]);
    
    printf("Ending Cards: \n");
    for(j = 0; j < 8; j++) {
        printf("%s ", getCard(&k[i]));
    }
    
    if(g.handCount[0] == 8){
        printf("\n TEST Smithy SUCCEED. Ending hand has: %d cards \n", g.handCount[0]);
    }
    else{
        printf("\n TEST Smithy FAILED. Ending hand has: %d cards \n", g.handCount[0]);
    }

    return 0;
}
