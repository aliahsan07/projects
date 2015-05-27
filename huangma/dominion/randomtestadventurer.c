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

int numtreasuresdiscard(struct gameState* G, int cplayer){
	int j, k;
	k=0;
	for(j=0; j<G->discardCount[cplayer]; j++){
	   if(G->discard[cplayer][j]==copper||G->discard[cplayer][j]==silver||G->discard[cplayer][j]==gold){
            k++;
	   }
	}
	return k;
}

int numtreasuresdeck(struct gameState* G, int cplayer){
	int j, k;
	k=0;
	for(j=0; j<G->deckCount[cplayer]; j++){
	   if(G->deck[cplayer][j]==copper||G->deck[cplayer][j]==silver||G->deck[cplayer][j]==gold){
            k++;
	   }
	}
	return k;
}
int numtreasures(struct gameState* G, int cplayer){
	int j, k;
	k=0;
	for(j=0; j<G->handCount[cplayer]; j++){
	   if(G->hand[cplayer][j]==copper||G->hand[cplayer][j]==silver||G->hand[cplayer][j]==gold){
            k++;
	   }
	}
	return k;
}

int main(){
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    int numtests, seed, i,j, numplayers, coinflip,success, player, handcount, deckcount,discardcount, newhc, gc, totaltreasures;
    int *p=0;
    numtests=100;
    printf("testing adventurer\n");
    for(i=0; i<numtests; i++){
    	    success=0;
            numplayers= rand() % 3+2;
            seed = rand();
            initializeGame(numplayers,k,seed,&G);

            coinflip= rand() % 4;
            player=rand() % numplayers;
            G.handCount[player]= rand() % 10;
            G.deckCount[player]= rand() % 50;
            G.discardCount[player]= rand() % 50;

	    G.whoseTurn=player;

            handcount=G.handCount[player];
            deckcount=G.deckCount[player];
	    discardcount=G.discardCount[player];

            if(coinflip==1){
                for(j=0; j<G.deckCount[player]; j++){
		   	G.discardCount[player]++;
			G.discard[player][G.discardCount[player]-1]=G.deck[player][j];
		};
		G.deckCount[player]=0;
               deckcount=G.deckCount[player];
	       discardcount=G.discardCount[player];
            }
        gc=numtreasures(&G, player);				//counts how much treasure in player hand before effect
	totaltreasures=numtreasuresdeck(&G,player) + numtreasuresdiscard(&G,player); //counts how many treasures in discard and deck
            printf("handcountbefore: %d\n", handcount);
	    printf("deckcountbefore: %d\n", deckcount);
	    printf("discardcountbefore: %d\n", discardcount);
            cardEffect(adventurer, 1,1,1,&G,3, &p);   		//variables not used are simply constant
            printf("handcountafter: %d\n", G.handCount[player]);
	    printf("deckcountafter: %d\n", G.deckCount[player]);
	    printf("discardcountafter: %d\n", G.discardCount[player]);
	    newhc=G.handCount[player];
	    if((deckcount+discardcount)-(G.deckCount[player]+G.discardCount[player])==0 && totaltreasures==0){	//case where no treasure in deck/discard
	    	success=success+newassert(handcount,newhc);
	    	success=success+newassert(deckcount+discardcount,(G.deckCount[player]+G.discardCount[player])+0);
	    	success=success+newassert(gc,numtreasures(&G,player));
	    }
	    else if((deckcount+discardcount)-(G.deckCount[player]+G.discardCount[player])==1 && totaltreasures==1){	//case where 1 treasure in deck/discard
	    	success=success+newassert(handcount+1,newhc);							//handcount increased
	    	success=success+newassert(deckcount+discardcount,(G.deckCount[player]+G.discardCount[player])+1); //make sure no cards lost
	    	success=success+newassert(gc+1,numtreasures(&G,player));						//make sure card gained is a treasure
	    }
	    else{										//regular case
            	success=success+newassert(handcount+2,newhc);
	    	success=success+newassert(deckcount+discardcount,(G.deckCount[player]+G.discardCount[player])+2);
	    	success=success+newassert(gc+2,numtreasures(&G,player));
	    }
	    if(success==3){
               printf("test %d passed\n", i);
	    }
	    else
	       printf("test %d failed\n", i);
    }
    return 0;
}
