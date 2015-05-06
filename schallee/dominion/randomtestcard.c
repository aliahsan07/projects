#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include "dominion.h"

#define NUM_TESTS 5

int main(){

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	sea_hag, tribute, smithy};
    int r; //return variable
    int i, p, n; //loop variables
    int numPlayers = 0;
    int player;
    int rSeed;
    int failureFlag = 0;
    int numFailures = 0;
    int handSize, deckCount, discardCount;
    int tempCard, deck;
    int card = council_room; 
    struct gameState* newG = malloc(sizeof(struct gameState));
    struct gameState* oldG = malloc(sizeof(struct gameState));

    srand(time(NULL));

    for(n = 0; n < NUM_TESTS; n++){
	memset((void*)newG, (size_t)0, sizeof(struct gameState));
	memset((void*)oldG, (size_t)0, sizeof(struct gameState));

	printf("\n\nBeginning Council Room test %i\n", n);

	numPlayers = (rand() % MAX_PLAYERS);   

	if(numPlayers < 2){
	    while(numPlayers < 2){
		numPlayers++;
	    }
	}

	rSeed = (rand());
	player = (rand() % numPlayers);

	printf("Players: %i\nSelected Player: %i\n", numPlayers, p);

	if(initializeGame(numPlayers, k, rSeed, newG) == -1){
	    printf("\n ERROR INITIALIZING GAME\n");
	}

	newG->whoseTurn = p;

	for(p = 0; p < numPlayers; p++){
	    //randomly assigns handsize, assigns cards to hand
	    handSize = (rand() % MAX_HAND/2);
	    newG->handCount[p] = handSize;
	    for(i = 0; i < handSize; i++){
		tempCard = (rand() % treasure_map+1);
		newG->hand[p][i] = tempCard;
	    }

	    //randomly assign cards to deck
	    deckCount = (rand() % MAX_DECK/2);
	    newG->deckCount[p] = deckCount;
	    for(i = 0; i < deckCount; i++){
		newG->deck[p][i] = (rand() % treasure_map+1);
	    }
	    
	    //randomly assign cards to discard
	    discardCount = (rand() % MAX_DECK/2);
	    newG->discardCount[p] = discardCount;
	    for(i = 0; i < discardCount; i++){
		newG->discard[p][i] = (rand() % treasure_map+1);
	    }
	}

	//copy struct to check values against
	memcpy((void*)oldG, (void*)newG, sizeof(struct gameState));

	//play card
	r = cardEffect(card, 0, 0, 0, newG, 0, 0);
	
	if(r != 0){
	    printf("\nTEST FAILED\nExpected value 0, found %i\n", r);
	    failureFlag = 1;
	}
	else if(oldG->handCount[player]+4 < MAX_HAND){ 
	    //if player new hand count < old hand count+4
	    if(newG->handCount[player] != oldG->handCount[player] + 4){
		printf("\nTEST FAILED\nHand Count increase failed.\n");
		printf("Expected handCount value: %i, found: %i\n",
			oldG->handCount[player]+4, newG->handCount[player]);
		failureFlag = 1; 
	    }
	    //check that player gets +1 buy
	    if(newG->numBuys != oldG->numBuys+1){
		printf("\nTEST FAILED\nNumber of buys did not increase.");
		printf("Expected value: %i, found: %i\n", 
			oldG->numBuys, newG->numBuys);
		failureFlag = 1;
	    }
	    //check that other players each drew a card
	    for(i = 0; i < numPlayers; i++){
		if(oldG->handCount[i]+1 != newG->handCount[i] && i != player){
		    printf("\nTEST FAILED\nOther player card count increase failed.\n");
		    printf("Expected value: %i, found:%i\n", 
			    oldG->handCount[i]+1, newG->handCount[i]);
		    failureFlag = 1;
		}
	    }
	}
	if(!failureFlag){
	    printf("\nTest passed successfully\n");
	}else{numFailures++;}
    }
    printf("\n***END TESTS***\nNumber of failures: %i\nPercentage failed: %f\n",
	    numFailures, (double)100*(double)numFailures/(double)NUM_TESTS);
    free(newG);
    free(oldG);
    return 0;

}
