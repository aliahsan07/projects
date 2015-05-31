#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "dominion.h"

#define FILENAME "./gameResults.out"

//DO NOT CHANGE -- This value comes from dominion.c
#define MAX_KINGDOM_CARDS 10

//change this as you see fit
#define RANDOM_SEED 324


//Random number of players between 2 and 4
int randomNumPlayers(){
    int numPlayers = (rand() % MAX_PLAYERS);
    if(numPlayers < 2){
	while(numPlayers < 2){
	    numPlayers++;
	}
    }
    return numPlayers;
}


int isInList(int k[MAX_KINGDOM_CARDS], int kSize, int card){

    int i;
    for(i = 0; i < kSize; i++){
	if(card == k[i]){
	    return 1;
	}
    }
    return 0;
}


int isMoney(int card){

    if(card == copper || card == silver || card == gold){
	return 1;
    }
    else{ return 0; }
}



//creates 10 random king cards
int* randomKingCards(){
    static int k[MAX_KINGDOM_CARDS];
    int i;

    for(i = 0; i < MAX_KINGDOM_CARDS; i++){
	k[i] = (rand() % treasure_map+1);
	while(isMoney(k[i]) || isInList(k, i, k[i])){
	    k[i] = (rand() % treasure_map+1);
	}
    }	
    return k;
}


//Initializes the game with 10 random king cards
void startGame(int numPlayers, int k[MAX_KINGDOM_CARDS], struct gameState *G){
    int i;    
    int randomSeed = rand();

    printf("Initializing Game\n\n");
    if(0 != (i = initializeGame(numPlayers, k, randomSeed, G))){
	printf("Error: %i initializing game with values:\n", i);
    }
    printf("*** Num Players: %i\n", numPlayers);
    printf("*** Kingdom Cards: ");
    for(i = 0; i < MAX_KINGDOM_CARDS; i++){
	printf("%i", k[i]);
	if(i != MAX_KINGDOM_CARDS-1){
	    printf(", ");
	}
	else{ printf("\n\n\n"); }
    }
}


//Prints game results
void printResults(int numPlayers, struct gameState *G){
    int i;
    int winners = 0; 
    int players[MAX_PLAYERS];
    getWinners(players, G);

    printf("\n\n*******Game over******\n\n");
    for(i = 0; i < numPlayers; i++){
	if(players[i] == 1){
	    winners++;
	}
    }
    if(winners == 1){
	printf("Winner(s):\n");
    }else{
	printf("Tie between:\n");
    }
    for(i = 0; i < winners; i++){
	printf("Player %i\n", i);
    }
    printf("\n******************\n\n");    
}

//returns a random card that costs <= numCoins
int randomBuy(int numCoins){

    int ret; 

    int two[2] = {embargo, copper};
    
    int three[6] = {embargo, copper, great_hall, steward, ambassador, silver};
    
    int four[16] = {embargo, copper, great_hall, steward, ambassador, silver, feast, gardens, 
	remodel, smithy, village, baron, cutpurse, salvager, sea_hag, treasure_map};
    
    int five[21] = {embargo, copper, great_hall, steward, ambassador, silver, feast, gardens, 
	remodel, smithy, village, baron, cutpurse, salvager, sea_hag, 
	treasure_map, council_room, mine, minion, tribute, outpost};
    
    int six[23] = {embargo, copper, great_hall, steward, ambassador, silver, feast, gardens, 
	remodel, smithy, village, baron, cutpurse, salvager, sea_hag, gold, 
	treasure_map, council_room, mine, minion, tribute, outpost, adventurer};    
    
    ret = copper;
    if(numCoins > 2){
        ret = two[0];
	if(numCoins > 3){
    	     ret = three[rand()%5];
            if(numCoins > 4){
	        ret = four[rand()%15];
	        if(numCoins > 5){
		    ret = five[rand()%20];
		    if(numCoins > 6){
		        ret = six[rand()%22];
		    }
		}
	    }
	}
    }

    //create 1% chance that no card is returned
    if((rand()%100) == 75) {
        ret = -1;
	printf("player does not buy a card\n");
    }
	
    return ret;
}



//*** This is the main function. ***//
int main(){
    int i, j; //just a loop variable 
    int r;
    int fd;
    int money, card;
    int *kingdomCards = randomKingCards();
    int numPlayers = randomNumPlayers();
    struct gameState *G = malloc(sizeof(struct gameState));

    srand(RANDOM_SEED);
/*
    fd = open(FILENAME, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    if(dup2(fd, 1) < 0){
        printf("error duping\n");
    }
    close(fd);
*/
    startGame(numPlayers, kingdomCards, G);

    while(!isGameOver(G)){
	for(i = 0; i < numPlayers; i++){
	    printf("\n\n-------------Player %i turn -----------------\n", i);
	    //count money in hand
	    money = 0;
	    for (j = 0; j < numHandCards(G); j++) {
		if (handCard(j, G) == copper){
		    money++;
		}
		else if (handCard(j, G) == silver){
		    money += 2;
		}
		else if (handCard(j, G) == gold){
		    money += 3;
		}
	    }

	    //play a card
	    if(G->numActions > 0){
		for(j = 0; j < G->handCount[i]; j++){
		    if(!(G->hand[i][j] < adventurer || G->hand[i][j] > treasure_map)){        
			card = rand()%5;
			r = playCard(card, -1, -1, -1, G);
			printf("Playcard returned: %i playing card: %i\n", r, G->hand[i][0]);
		    }	
		}

		card = randomBuy(money);
		if(G->numActions > 0 && card != -1){
		    r = buyCard(card, G);
		    printf("Player purchased card: %i, buyCard returned: %i\n", card, r);
		}
		
	    }

	    printf("\n");
	    endTurn(G);
	}
    }

    printResults(numPlayers, G);

    free(G);
    return 0;
}
