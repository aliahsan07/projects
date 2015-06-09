#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <assert.h>

void printCard(int card, int r){
    if(card==adventurer){
        printf("adventurer %d\n",r);
    }
    else if(card==gardens){
        printf("gardens %d\n",r);
    }
    else if(card==mine){
        printf("mine %d\n",r);
    }
    else if(card==minion){
        printf("minion %d\n",r);
    }
    else if(card==smithy){
        printf("smithy %d\n",r);
    }
    else if(card==council_room){
        printf("council_room %d\n",r);
    }
    else if(card==embargo){
        printf("embargo %d\n",r);
    }
    else if(card==village){
        printf("village %d\n",r);
    }
    else if(card==cutpurse){
        printf("cutpurse %d\n",r);
    }
    else if(card==tribute){
        printf("tribute %d\n",r);
    }
    else if(card==sea_hag){
        printf("sea_hag %d\n",r);
    }
    else if(card==copper){
        printf("copper %d\n",r);
    }
    else if(card==silver){
        printf("silver %d\n",r);
    }
    else if(card==gold){
        printf("gold %d\n",r);
    }
    else if(card==estate){
        printf("estate %d\n",r);
    }
    else if(card==duchy){
        printf("duchy %d\n",r);
    }
    else if(card==province){
        printf("province %d\n",r);
    }
    else if(card==feast){
    	printf("feast: %d\n",r);
    }
    else if(card==ambassador){
    	printf("ambassador: %d\n",r);
    }
    else if(card==steward){
    	printf("steward: %d\n",r);
    }
    else if(card==great_hall){
    	printf("greathall: %d\n",r);
    }
    else if(card==baron){
    	printf("braon: %d\n",r);
    }
    else if(card==outpost){
    	printf("outpost: %d\n",r);
    }
    else if(card==salvager){
    	printf("salvager: %d\n",r);
    }
    else if(card==treasure_map){
    	printf("treasure map: %d\n",r);
    }
}

void chooseKingdomCards(int *k){
   int coinflip, i, j;
      int kc[18]={adventurer, gardens, embargo, village, minion, mine, cutpurse,
	 sea_hag, tribute, smithy, feast, ambassador, steward, great_hall, baron, outpost, salvager, treasure_map};
	    j=0;
	    for(i=0; i<18; i++){
	       coinflip=rand() % 4;
		  if(coinflip!=0){
		     k[j]=kc[i];
			j++;
		  }
	    }
   for(i=j; i<18; i++){
      k[j]=-1;
   }
}

int isPlayableCard(int *k, int card){
   int i;
      for(i=0; i<18; i++){
	 if(card==k[i]){
	    return 1;
	 }
	 else if(k[i]==-1){
	    return 0;
	 }
      }
   return 0;
}

int countMoney(struct gameState *G){
   int i, money;
      money=0;
      for (i = 0; i < numHandCards(G); i++) {
	 if (handCard(i, G) == copper)
	    money++;
	 else if (handCard(i, G) == silver)
	    money += 2;
	 else if (handCard(i, G) == gold)
	    money += 3;
      }
   return money;
}

int chooseHandCard(struct gameState* G, int *k, int* handpos){
   int i, j, rcard;
      j=0;
      int p[10];
      for(i=0; i<numHandCards(G); i++){
	 rcard=rand()%numHandCards(G);
	    if(isPlayableCard(k, handCard(rcard, G))==1){
	       p[j]=handCard(rcard,G);
		  j++;
	    }
      }
   if(j!=0){
      rcard=rand()%j;
	 *handpos=rcard;
	 return p[rcard];
   }
   return -1;
}

int randomBuyCard(struct gameState* G, int money, int* k){
   int p[24];
      int q[24];
      int size, i, rcard, j, coinflip;
      size=0;
      j=0;
      for(i=0; i<18; i++){
	 if(k[i]==-1){
	    break;
	 }
	 else{
	    p[size]=k[i];
	       size++;
	 }
      }
   p[size]=estate;
   p[size+1]=duchy;
   p[size+2]=province;
   p[size+3]=copper;
   p[size+4]=silver;
   p[size+5]=gold;
   size+=5;
   for(i=0; i<=size; i++){
	 if(getCost(p[i])<=money){
	    q[j]=p[i];
	       j++;
	 }
   }
   coinflip=rand()%200;
   rcard=rand()%j;
   if(coinflip<=8 && money>=getCost(province)){	//higher chance to buy province with higher money
        return province;
   }
   else if(coinflip<=8 && money>=getCost(gold)){	//used to speed up game, can be commented out and still work
        return gold;
   }
   else if(coinflip<=8 && money>=getCost(silver)){
   	return silver;
   }
   return q[rcard];
}


void printhand(struct gameState *G){
      int i;
      for(i=0; i<numHandCards(G); i++){
        printCard(handCard(i,G),0);
      }
}

int main(int argc, char** argv){
   printf("int main(){ struct gameState *G;\n");
      struct gameState *G;
      int numplayers, money, handpos, rseed, rcard, choice1, choice2, choice3, coinflip, i, numtests,r;
      printf("int numplayers, money, handpos, rseed, rcard, choice1, choice2, choice3, coinflip, i, numtests,r;\n");
      int *k;
      printf("int k[18]={adventurer, gardens, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, feast, ambassador, steward, great_hall, baron, outpost, salvager, treasure_map};\n");
      int players[4];
      printf("int players[4];\n");
      numtests=1;
      for(i=0; i<numtests; i++){
	 G=newGame();
	    printf("G=newGame();\n");
	    rseed=atoi(argv[1]);
	    printf("rseed=%d;\n",rseed);
	    k = malloc(sizeof(int)*18);
	    numplayers=rand()%3+2;
	    printf("numplayers=%d;\n", numplayers);
	    chooseKingdomCards(k);
	    initializeGame(numplayers, k, rseed, G);
	    printf("initializeGame(numplayers,k,rseed,G);\n");
	   // printf("FOR SEED %d\n", rseed);
	    if(isGameOver(G)){
	       printf("game creation error\n");
	       printf("test %d failed\n",i);
	    }
	    else{
	       printf("isGameOver(G);\n");
	       while(!isGameOver(G)){
                //printf("player %d turn start\n", whoseTurn(G));
		  handpos=-1;
		     printf("handpos=-1;\n");
		     coinflip=rand()%10;
		     printf("coinflip=rand()%10;\n");
		     rcard=chooseHandCard(G, k, &handpos);
		     printf("rcard=%d;\n",rcard);
		     printf("handpos=%d;\n",handpos);
		     choice1=rand()%2;
		     printf("choice1=%d;", choice1);
		     choice2=0;
		     printf("choice2=0;\n");
		     if(choice1==0){
			choice2=1;
		     }
		  
		     choice3=rand()%2;
		     printf("choice3=%d;\n",choice3);
		     if(rcard!=-1 && rcard!=curse){
			//printf("player %d playing ", whoseTurn(G));
			//printCard(rcard, r);
			//printf("printCard(rcard, r)\n");
			r=playCard(handpos, 3, choice2, choice3,G);
			printf("cardEffect(rcard, 3, choice2,choice3,G,0);\n");
			//printf("player %d played ", whoseTurn(G));
			//printCard(rcard, r);
			//printf("printCard(rcard, r)\n");
		     }
		  money=countMoney(G);
		     printf("money=%d;\n",money);
		     //printf("money: %d\n", money);
		     rcard=randomBuyCard(G, money, k);
		     //rcard=feast;
		     printf("rcard=feast;\n");
		     if(coinflip!=9){			//small chance to not buy anything
			r=buyCard(rcard, G);
			printf("r=buyCard(rcard,G);\n");
			//printf("player %d bought ", whoseTurn(G));
			//printCard(rcard, r);
			//printf("printCard(rcard, r)\n");
		     }
		     //printf("player %d hand\n", whoseTurn(G));
		     //printhand(G);
		     //printf("printhand(G)\n");
		     //printf("player %d score: %d\n", whoseTurn(G), scoreFor(whoseTurn(G),G));
		     //printf("player %d turn ending\n", whoseTurn(G));
		     endTurn(G);
		     printf("endTurn(G);\n");
		     printf("isGameOver(G);\n");
		     if(isGameOver(G)){
			printf("game over player %d won\n", getWinners(players, G));
		     }
	       }
	       free(k);
	       free(G);
	       printf("test %d passed\n", i);
	    }
      }
      return 0;
}
