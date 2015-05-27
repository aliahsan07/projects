#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

int newassert(int x, int y){
	if(x==y){
		return 1;
	}
	return 0;
}

int main(){
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    int numtests, seed, i,j, numplayers, coinflip,handpos, player, numbuysbefore, s;
    numtests=100;
    printf("testing councilroom\n");
    for(i=0; i<numtests; i++){
       	    s=0;
            numplayers= rand() % 3+2;
            seed = rand();
            initializeGame(numplayers,k,seed,&G);
            int hc[numplayers];
	    int tc[numplayers];

            coinflip= rand() % 4;
            player=rand() % numplayers;
	    for(j=0; j<numplayers; j++){
            	G.handCount[j]= rand() % 10;
            	G.deckCount[j]= rand() % 50;
            	G.discardCount[j]= rand() % 50;
		tc[j]=G.deckCount[j]+G.discardCount[j];
	    }
            numbuysbefore=G.numBuys;

            G.whoseTurn=player;
            G.handCount[player]++;              //adds council room card to hand to be discarded later.
            G.hand[player][G.handCount[player]-1]=council_room;
	    handpos=G.handCount[player]-1;

            for(j=0; j<numplayers; j++){
                hc[j]=G.handCount[j];
            }

            cardEffect(council_room,1,2,3,&G,handpos,0);
            assert(numbuysbefore+1==G.numBuys);		//make sure the number of buys incrased
            for(j=0; j<numplayers; j++){			//checks to see if all other players have correct card counts
	        if(j==player){
		   if(tc[j]<4){					//case where number of cards in deck and discard is below 4
		      s=s+newassert(hc[j]+tc[j]-1, G.handCount[j]);
		   }
		   else{					//normal case where you can draw 4 cards
                      s=s+newassert(hc[j]+3,G.handCount[j]);
		   }
                }
		else{
		   if(tc[j]<1){					//case where other players have no cards in discard and deck
		      s=s+newassert(hc[j],G.handCount[j]);
		   }
		   else{					//normal case where other players can draw a card
                      s=s+newassert(hc[j]+1,G.handCount[j]);
		   }
		}
		printf("handcountbefore player %d: %d\n", j+1, hc[j]);
		printf("handcountafter player %d: %d\n", j+1, G.handCount[j]);
            }
	    if(newassert(G.hand[player][handpos],council_room)){
	       s=0;
	    };								//make sure that councilroom has been discarded
	    if(s==numplayers){
	    	printf("test %d passed\n", i);
	    }
	    else
	       printf("test %d failed\n", i);
    }
	    return 0;
}
