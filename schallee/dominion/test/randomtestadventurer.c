#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include "dominion.h"

#define NUM_TESTS 50


int main(){

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	sea_hag, tribute, smithy};
    int r; //return variable
    int i, p, n; //loop variables
    int numPlayers = 0;
    int rSeed;
    int failureFlag = 0;
    int numFailures = 0;
    int handSize, deckCount, discardCount;
    int handCountBefore;
    int temp;
    int treasure[MAX_PLAYERS];
    int newTreasure = 0;
    int tempCard;
    int card = adventurer; 
    int pDCount, pHCount, disCount; 
    struct gameState* G = malloc(sizeof(struct gameState));

    srand(time(NULL));

    for(n = 0; n < NUM_TESTS; n++){
	memset((void*)G, (size_t)0, sizeof(struct gameState));

	printf("\n\nBeginning adventurerCard test %i\n", n);

	numPlayers = (rand() % MAX_PLAYERS);   

	if(numPlayers < 2){
	    while(numPlayers < 2){
		numPlayers++;
	    }
	}

	rSeed = (rand());
	p = (rand() % numPlayers);



	printf("Players: %i\nSelected Player: %i\n", numPlayers, p);

	if(initializeGame(numPlayers, k, rSeed, G) == -1){
	    printf("\n ERROR INITIALIZING GAME\n");
	}

	G->whoseTurn = p;


	temp = 0;
	//randomly assigns handsize, assigns cards to hand
	handSize = (rand() % MAX_HAND/2);
	G->handCount[p] = handSize;

	for(i = 0; i < handSize; i++){
	    tempCard = (rand() % treasure_map+1);
	    G->hand[p][i] = tempCard;
	    if(tempCard == copper || tempCard == silver || tempCard == gold){
		temp++;
	    }
	}
	treasure[p] = temp;

	//randomly assign cards to deck
	deckCount = (rand() % MAX_DECK/2);
	for(i = 0; i < deckCount; i++){
	    G->deck[p][i] = (rand() % treasure_map+1);
	}

	G->deckCount[p] = deckCount;

	//randomly assign cards to discard
	discardCount = (rand() % MAX_DECK/2);
	for(i = 0; i < discardCount; i++){
	    G->discard[p][i] = (rand() % treasure_map+1);
	}
	G->discardCount[p] = discardCount;

	pHCount = G->handCount[p];
	pDCount = G->deckCount[p];
	disCount = G->discardCount[p];

	assert(pHCount >= 0);
	assert(pDCount >= 0);
	assert(disCount >= 0);
	assert(G->numPlayers == numPlayers);
	assert(G->whoseTurn == p);


	//player's handCount before calling card
	handCountBefore = G->handCount[p];

	assert(treasure[p] >= 0); //assert
	assert(G->whoseTurn == p);
	
	r = cardEffect(card, 0, 0, 0, G, 0, 0);

	for(i = 0; i < MAX_HAND/2; i++){
	    if(G->hand[p][i] == copper || G->hand[p][i] == silver
		    || G->hand[p][i] == gold){
		newTreasure++;
	    }
	}
	if(r != 0){
	    printf("\nTEST FAILED\nExpected value 0, found %i\n", r);
	    failureFlag = 1;
	}
	else if(handCountBefore+2 < MAX_HAND/2){ 
	    //if new handCount < oldHandCount+2
	    if(G->handCount[p] < handCountBefore + 2){
		printf("\nTEST FAILED\nHand Count increase failed.\n");
		printf("Expected handCount value >= %i, found: %i\n",
			handCountBefore+2, G->handCount[p]);
		failureFlag = 1; 
	    }
	    //if new treasure < oldTreasure+2
	    if(newTreasure < treasure[p]+2){
		printf("\nTEST FAILED\nTreasure count increase failed.\n");
		printf("Expected treasure value >= %i, found:%i\n", 
			treasure[p]+2, newTreasure);
		failureFlag = 1;
	    }
	}
	if(!failureFlag){
	    printf("\nTest passed successfully\n");
	}else{numFailures++;}
    }
    printf("\n***END TESTS***\nNumber of failures: %i\nPercentage failed: %f\n",
	    numFailures, (double)100*(double)numFailures/(double)NUM_TESTS);
    free(G);
    return 0;

}
