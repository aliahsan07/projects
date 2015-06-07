//
//
//  testdominion.c
//  play a random game of dominion
//  each player with diff card 10k

#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv) {
    
    struct gameState G;
    struct gameState *s = &G;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    
    printf ("Initializing game...\n");
    srand(0);
    
    int people = rand() % 3 + 2;
    printf("Number of Players: %d\n", people); //Rand number of players
    
    int seed = rand() % 10000;
    initializeGame(people, k, seed, s);
    
    int i = 0;
    int money = 0;
    int numAdventurers = 0;
    int numSmithys = 0;
    int adventurerPos = -1;
    int cutpursePos = -1;
    int smithyPos = -1;
    
    while (!isGameOver(s)) {

        adventurerPos = -1;
        money = 0;
        smithyPos = -1;
        
        for (i = 0; i < numHandCards(s); i++) {
            if (handCard(i, s) == copper){
                money++;
            }
            else if (handCard(i, s) == silver) {
                money += 2;
            }
            else if (handCard(i, s) == gold) {
                money += 3;
            }
            else if (handCard(i, s) == smithy) {
                smithyPos = i;
            }
            else if (handCard(i, s) == adventurer) {
                adventurerPos = i;
            }
        }
        // zero's turn cases
        if (whoseTurn(s) == 0) {
            if (cutpursePos != -1) {
                printf("1: cutpurse played from position %d\n", cutpursePos);
                playCard(cutpursePos, -1, -1, -1, s);
                printf("cutpurse played.\n");
                i = 0;
                money = 0;

                while(i < numHandCards(s)){
                    if (handCard(i, s) == copper) {
                        playCard(i, -1, -1, -1, s);
                        money++;
                    }
                    else if (handCard(i, s) == silver) {
                        playCard(i, -1, -1, -1, s);
                        money += 2;
                    }
                    else if (handCard(i, s) == gold) {
                        playCard(i, -1, -1, -1, s);
                        money += 3;
                    }
                    i++;
                }
            }
            if (money >= 8) {
                printf("0: buys province\n");
                buyCard(province, s);
            }
            else if (money >= 6) {
                printf("0: buys gold\n");
                buyCard(gold, s);
            }
            else if ((money >= 4) && (numSmithys < 2)) {
                printf("0: buys smithy\n");
                buyCard(smithy, s);
                numSmithys++;
            }
            else if (money >= 3) {
                printf("0: bought silver\n");
                buyCard(silver, s);
            }
            
            printf("0: end of turn\n");
            endTurn(s);
        }
        // player 1's turn cases
        else if (whoseTurn(s) == 1) {
            if(adventurerPos != -1) {
                printf("2: adventurer played from position %d\n", adventurerPos);
                playCard(adventurerPos, -1, -1, -1, s);
                money = 0;
                i = 0;
                
                while(i < numHandCards(s)){
                    if (handCard(i, s) == copper){
                        playCard(i, -1, -1, -1, s);
                        money++;
                    }
                    else if (handCard(i, s) == silver){
                        playCard(i, -1, -1, -1, s);
                        money += 2;
                    }
                    else if (handCard(i, s) == gold){
                        playCard(i, -1, -1, -1, s);
                        money += 3;
                    }
                    i++;
                }
            }
            if (money >= 8) {
                printf("1: buys province\n");
                buyCard(province, s);
            }
            else if ((money >= 6) && (numAdventurers < 2)) {
                printf("1: buys adventurer\n");
                buyCard(adventurer, s);
                numAdventurers++;
            }
            else if (money >= 6) {
                printf("1: buys gold\n");
                buyCard(gold, s);
            }
            else if (money >= 3) {
                printf("1: buys silver\n");
                buyCard(silver, s);
            }
            printf("1: endTurn\n");
            endTurn(s);
        }
        //player 2's turn cases
        else if (whoseTurn(s) == 2) {
            if (smithyPos != -1) {
                printf("0: smithy played from position %d\n", smithyPos);
                playCard(smithyPos, -1, -1, -1, s);
                printf("smithy played.\n");
                i = 0;
                money = 0;
                
                while(i < numHandCards(s)){
                    if (handCard(i, s) == copper){
                        playCard(i, -1, -1, -1, s);
                        money++;
                    }
                    else if (handCard(i, s) == silver){
                        playCard(i, -1, -1, -1, s);
                        money += 2;
                    }
                    else if (handCard(i, s) == gold){
                        playCard(i, -1, -1, -1, s);
                        money += 3;
                    }
                    i++;
                }
            }
            if (money >= 8) {
                printf("2: buys province\n");
                buyCard(province, s);
            }
            else if ((money >= 6) && (numAdventurers < 2)) {
                printf("2: buys adventurer\n");
                buyCard(adventurer, s);
                numAdventurers++;
            }
            else if (money >= 6){
                printf("2: buys gold\n");
                buyCard(gold, s);
            }
            else if (money >= 3){
                printf("2: buys silver\n");
                buyCard(silver, s);
            }
            printf("2: endTurn\n");
            endTurn(s);
        }
        //player 3's turn cases
        else if (whoseTurn(s) == 3) {
            if (gardens != -1) {
                printf("3: buys gardens\n");
                buyCard(gardens, s);
            }
            if (money >= 8) {
                printf("3: buys province\n");
                buyCard(province, s);
            }
            else if ((money >= 6) && (numAdventurers < 2)) {
                printf("3: buys adventurer\n");
                buyCard(adventurer, s);
                numAdventurers++;
            }
            else if (money >= 6){
                printf("3: buys gold\n");
                buyCard(gold, s);
            }
            else if (money >= 3){
                printf("3: buys silver\n");
                buyCard(silver, s);
            }
            printf("3: endTurn\n");
            endTurn(s);
        }
        
        if (people == 2) {
            printf ("Player 0 score: %d ---\n", scoreFor(0, s));
            printf ("Player 1 score: %d ---\n", scoreFor(1, s));
        }
        else if (people == 3) {
            printf ("Player 0 score: %d ---\n", scoreFor(0, s));
            printf ("Player 1 score: %d ---\n", scoreFor(1, s));
            printf ("Player 2 score: %d ---\n", scoreFor(2, s));
        }
        else if (people == 4) {
            printf ("Player 0 score: %d ---\n", scoreFor(0, s));
            printf ("Player 1 score: %d ---\n", scoreFor(1, s));
            printf ("Player 2 score: %d ---\n", scoreFor(2, s));
            printf ("Player 3 score: %d ---\n", scoreFor(3, s));
        }
    }
    
    printf ("Game is finished...\n");
    if (people == 2) {
        printf ("Player 0 final score: %d ---\n", scoreFor(0, s));
        printf ("Player 1 final score: %d ---\n", scoreFor(1, s));
    }
    else if (people == 3) {
        printf ("Player 0 final score: %d ---\n", scoreFor(0, s));
        printf ("Player 1 final score: %d ---\n", scoreFor(1, s));
        printf ("Player 2 final score: %d ---\n", scoreFor(2, s));
    }
    else if (people == 4) {
        printf ("Player 0 final score: %d ---\n", scoreFor(0, s));
        printf ("Player 1 final score: %d ---\n", scoreFor(1, s));
        printf ("Player 2 final score: %d ---\n", scoreFor(2, s));
        printf ("Player 3 final score: %d ---\n", scoreFor(3, s));
    }
    return 0;
}