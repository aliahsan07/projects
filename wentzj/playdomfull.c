#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "time.h"
#include "math.h"

int main(int argc, char** argv){
    struct gameState G;
    struct gameState *p = &G;
    int k[10] = {0};
    int cards[19] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
    int card;
    int card_chosen = 0;
    srand(time(NULL));

    int players = (rand() % 3) + 2;
    int i;
    int j;
    int counter = 0;

    //Randomly choose a card out of 19 
    while(k[10] == 0){
        card = (rand() % 19);
        for(j = 0; j<10; j++){
            if(k[j] == card){
                card_chosen+=1;
            }
        }    
        if(card_chosen == 0){
            k[counter] = card;
            counter+=1;
        }
        card_chosen = 0;
    }

    printf("Kingdom Cards\n");
    for(j=0; j<10; j++){
            printf("k[%d]: %d\n", j, k[j]);
    }

   return 0;
}
