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
    int card;
    srand(time(NULL));

    int players = (rand() % 3) + 2;
    int *cardset = calloc(19, sizeof(int));
    if(cardset != NULL){
        printf("Cardset not NULL\n");
    }

    //initializeGame(players, k, rand(), &p);

    for(int i = 0; i<10; i++){
        card = (rand() % 19);
        if(cardset[card] == 0){
            cardset[card] = (card + 7);
        }
    }

    for (int i = 0; i<10; i++){
        for (int j = 0; j<19; j++){
            if (cardset[j] != 0){
                k[i] = cardset[j];
                break;
            }
        }
    }
   
   return 0;
}
