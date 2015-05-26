#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 2

//This randomly play dominion

//setupCard sets up the array to prepare for randomization 
//offset is the offset so that money cards and victory cards are not included
int  setupCards(int * setup, int length, int offset){
    int i;
    if (setup){
        for (i = 0; i < length; i++){
            setup[i] = i + offset; 
        } 
    }
    else{
        perror("setupCards recieved a NULL pointer\n"); 
        return -1;
    }  
    return 0;
} 
//This function uses the Fisher-Yates shuffle from this wikipedia article:
//http://en.wikipedia.org/wiki/Fisher-Yates_shuffle
//And this stackoverflow article: http://stackoverflow.com/questions/6127503/shuffle-array-in-c
int FYShuffle(int * randme, int length){
    int i;
    if (randme){
        for (i = 0; i < length; i++){
            int randnum, temp;
            randnum = i; 
            // while (randnum == 1){
            randnum = rand() % length;
            //   if (randnum != i){
            temp = randme[i];
            randme[i] = randme[randnum];
            randme[randnum] = temp;
            // }      
            // }
        } 
    }
    else{
        perror("FYShuffle recieved a NULL pointer\n"); 
        return -1;
    }  
    printf("The new Array is:\n"); 
    for (i = 0; i < length; i++){
        printf(" %d ", randme[i]); 
    }
    printf("\n");
    return 0;
}

int main() {
    int prek[20];
    int length = 20; 
    int offset = 7;
    setupCards(prek, length, offset);
    int * k; 
    // int k[10] = {adventurer, gardens, embargo, village, minion, steward, cutpurse, 
    //    sea_hag, tribute, smithy};

    int i, j, n, players, player, handCount, deckCount, coins, seed, address, choice, trashchoice1, trashchoice2;
    //struct gameState state;
    struct gameState mystate;
    struct gameState * state;
    state = &mystate;

    printf("Running Random Dominion Cards\n");

    //For greater than or equal to 8 coins always buy a province
    for (i = 0; i < MAX_TESTS; i++) {
        unsigned int zerocostcards[2] = {0};
        unsigned int twocostcards[2] = {0};
        unsigned int threecostcards[5] = {0};
        unsigned int fourcostcards[9] = {0};
        unsigned int fivecostcards[5] = {0};
        unsigned int sixcostcards[2] = {0}; 
        unsigned int numzeroKcards = 2;
        unsigned int numtwoKcards = 1; //Note this counts estate be sure to add 1  
        unsigned int numthreeKcards =  1; //Note this counts silver be sure to add 1
        unsigned int numfourKcards = 0; 
        unsigned int numfiveKcards = 1; //Note this count duchy be sure to add 1
        unsigned int numsixKcards = 1; //Note this  counts gold be sure to add 1; 
        //int j; 
        printf("\n\n Test # %d\n", i);
        players = (rand() % MAX_PLAYERS - 1) + 1 ;
        if (players == 0){
            player = rand() % 1;
        }
        else{
            player = rand() % players;
        }
        //seed = rand();		//pick random seed
        seed = 1;//set seed to i + 1
        FYShuffle(prek, length);
        k = prek;
        //setting up the zerocostKcards array 
        zerocostcards[0] = curse;
        zerocostcards[1] = copper;

        //seting up the twocostcard array
        twocostcards[0] = estate;
        threecostcards[0] = silver; 
        fivecostcards[0] = duchy;
        sixcostcards[0] = gold;
        //setting up the rest of the cards
        printf("The embarg num is %d\n ", embargo);
        for (j = 0; j < 10; j++){
            if (getCost(k[j]) == 2){
                twocostcards[numtwoKcards] = k[j];
                numtwoKcards++;
            }
            else if (getCost(k[j]) == 3){
                threecostcards[numthreeKcards] = k[j];
                numthreeKcards++;
            }
            else if (getCost(k[j]) == 4){
                fourcostcards[numfourKcards] = k[j];
                numfourKcards++;
            }
            else if (getCost(k[j]) == 5){
                fivecostcards[numfiveKcards] = k[j];
                numfiveKcards++;
            }
            else if (getCost(k[j]) == 6){
                sixcostcards[numsixKcards] = k[j];
                numsixKcards++;
            }
        }
        printf("Game has %u card(s) that cost two\n", numtwoKcards);        
        printf("Game has %u card(s) that cost three\n", numthreeKcards);   
        printf("Game has %u card(s) that cost four\n", numfourKcards);
        printf("Game has %u card(s) that cost five\n", numfiveKcards);
        printf("Game has %u card(s) that cost six\n", numsixKcards);   
        //setting up the threecostcard array
        printf("Starting Game #%d", i);
        initializeGame(2, k, seed, state);	//initialize Gamestate
        printf("I initialized my game #%i", i);
        printf("The number of provinces is %d", state->supplyCount[province]);
        while (!isGameOver(state)) {
            int money = 0;
            int finalactionposition = -1;

            if (whoseTurn(state) == 0) {
                /*   if (smithyPos != -1) {
                     printf("0: smithy played from position %d\n", smithyPos); 
                     playCard(smithyPos, -1, -1, -1, p); 
                     printf("smithy played.\n");*/
                money = 0;
                int m=0;
                while(m<numHandCards(state)){//This is the money playing phase
                    if (handCard(i, state) == copper){
                        playCard(i, -1, -1, -1, state);
                        money++;
                    }
                    else if (handCard(i, state) == silver){
                        playCard(i, -1, -1, -1, state);
                        money += 2;
                    }
                    else if (handCard(i, state) == gold){
                        playCard(i, -1, -1, -1, state);
                        money += 3;
                    }
                    m++;
                }
                //This is the buying phase
                //while (state -> numBuys > 0){
                    int which = rand()% 2;
                    if (which == 0){//buys money or provinces
                        if (money >= 8) {
                            printf("0: bought province\n"); 
                            buyCard(province, state);
                        }
                        else if (money >= 6) {
                            printf("0: bought gold\n"); 
                            buyCard(gold, state);
                        }
                        else if (money >= 3) {
                            printf("0: bought silver\n"); 
                            buyCard(silver, state);
                        }
                        else if (money >= 0) {
                            printf("0: bought copper\n"); 
                            buyCard(copper, state);
                        }


                    }
                    else{//buys victory cards
                        if (money >= 8) {
                            printf("0: bought province\n"); 
                            buyCard(province, state);
                        }
                        else if (money >= 5){
                            printf("0:bought a duchy\n");
                            buyCard(duchy,state);

                        }
                        else if(money >= 2){
                            printf("0: bought an estate\n");
                            buyCard(estate, state);
                        }
                        else{
                            printf("0: cursed itself\n");
                            buyCard(curse, state);

                        }

                    }


                //}

                printf("0: end turn\n");
                endTurn(state);

                //return 0;

            }
            if (whoseTurn(state) == 1) {
                /*   if (smithyPos != -1) {
                     printf("0: smithy played from position %d\n", smithyPos); 
                     playCard(smithyPos, -1, -1, -1, p); 
                     printf("smithy played.\n");*/
                money = 0;
                int m=0;
                while(m<numHandCards(state)){//This is the money playing phase
                    if (handCard(i, state) == copper){
                        playCard(i, -1, -1, -1, state);
                        money++;
                    }
                    else if (handCard(i, state) == silver){
                        playCard(i, -1, -1, -1, state);
                        money += 2;
                    }
                    else if (handCard(i, state) == gold){
                        playCard(i, -1, -1, -1, state);
                        money += 3;
                    }
                    m++;
                }
                //This is the buying phase
                //while (state -> numBuys > 0){
                    if (money >= 8) {
                        printf("1: bought province\n"); 
                        buyCard(province, state);
                    }
                    else if (money >= 6) {
                        int index = rand() % numsixKcards; 
                        printf("1: bought a card costing 6\n"); 
                        buyCard(sixcostcards[index], state);
                    }
                    else if (money == 5){
                        int index = rand() % numfiveKcards; 
                        printf("1: bought a card costing 5\n"); 
                        buyCard(fivecostcards[index], state);

                    }
                    else if (money == 4){
                        int index = rand() % numfourKcards; 
                        printf("1: bought a card costing 4\n"); 
                        buyCard(fourcostcards[index], state); 
                    }
                    else if (money >= 3) {
                        int index = rand() % numtwoKcards; 
                        printf("1: bought a card costing 3\n"); 
                        buyCard(threecostcards[index], state);
                    }
                    else if (money == 2){
                        int index = rand() % numtwoKcards; 
                        printf("1: bought a card costing 2\n"); 
                        buyCard(twocostcards[index], state);

                    }
                    else if (money >= 0) {
                        int index = rand() % numzeroKcards; 
                        printf("1: bought a card costing 0\n"); 
                        buyCard(zerocostcards[index], state);
                    }
                printf("1: end turn\n");
                endTurn(state);
            }//end of turn1
            printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, state), scoreFor(1, state));
	    
            //return 0;

            }
            printf ("Finished game #%d\n", i);
            printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, state), scoreFor(1, state));


            }


            printf("Tests Complete\n");

            return 0;


        }
