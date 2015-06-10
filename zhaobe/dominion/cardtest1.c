//
//  cardtest1.c
//  Adventurer test


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
    
    int handA;
    int handB;
    int k[10] = {adventurer, embargo, great_hall, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int i;
    int j;
    struct gameState g;
    
    printf("Testing Adventurer...\n");
    
    initializeGame(2, k, 5, &g);
    
    printf("Start Amount of Cards: %d\n", g.handCount[0]);
    handA = g.handCount[0];
    
    printf("Starting Cards: \n");
    for(i = 0; i < 5; i++) {
        printf("%s ", getCard(&k[i]));
    }
    
    cardEffect(adventurer, 0, 0, 0, &g, 0, 0);
    
    printf("\n\nEnd Amount of Cards: %d\n", g.handCount[0]);
    handB = g.handCount[0];
    
    printf("Ending Cards: \n");
    for(j = 0; j < 10; j++) {
        printf("%s ", getCard(&k[i]));
    }

    if(handB > 7){
        printf("\n TEST FAILED. The end amount is more than expected. \n");
    }
    else{
        printf("\n TEST Adventurer SUCCEED. \n");
    }
    printf("Test Ending...\n");
    
    return 0;
}
