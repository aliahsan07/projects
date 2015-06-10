#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

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
}

void chooseKingdomCards(int *k){
   int coinflip, i, j;
      int kc[10]={adventurer, gardens, embargo, village, minion, mine, cutpurse,
	 sea_hag, tribute, smithy};
	    j=0;
	    for(i=0; i<10; i++){
	       coinflip=rand() % 4;
		  if(coinflip!=0){
		     k[j]=kc[i];
			j++;
		  }
	    }
   for(i=j; i<10; i++){
      k[j]=-1;
   }
}

int isPlayableCard(int *k, int card){
   int i;
      for(i=0; i<10; i++){
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
   int p[16];
      int q[16];
      int size, i, rcard, j, coinflip;
      size=0;
      j=0;
      for(i=0; i<10; i++){
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
   coinflip=rand()%16;
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
   struct gameState *G;
      int numplayers, money, handpos, rseed, rcard, choice1, choice2, choice3, coinflip, i, numtests,r;
      int *k;
      int players[4];
      numtests=1;
      for(i=0; i<numtests; i++){
	 G=newGame();
	    rseed=atoi(argv[1]);
	    k = malloc(sizeof(int)*10);
	    numplayers=rand()%3+2;
	    chooseKingdomCards(k);
	    initializeGame(numplayers, k, rseed, G);

	    printf("FOR SEED %d\n", rseed);
	    if(isGameOver(G)){
	       printf("game creation error\n");
	       printf("test %d failed\n",i);
	    }
	    else{
	       while(!isGameOver(G)){
                printf("player %d turn start\n", whoseTurn(G));
		  handpos=-1;
		     coinflip=rand()%10;
		  rcard=chooseHandCard(G, k, &handpos);
		     choice1=rand()%2;
		     choice2=0;
		     if(choice1==0){
			choice2=1;
		     }
		  choice3=rand()%2;
		     if(rcard!=-1 || rcard==curse){
			r=playCard(handpos, choice1,choice2,choice3,G);
			printf("player %d played ", whoseTurn(G));
			printCard(rcard, r);
		     }
		  money=countMoney(G);
		     printf("money: %d\n", money);
		     rcard=randomBuyCard(G, money, k);
		     if(coinflip!=9){				//small chance to not buy anything
			r=buyCard(rcard, G);
			printf("player %d bought ", whoseTurn(G));
			printCard(rcard, r);
		     }
		     printf("player %d hand\n", whoseTurn(G));
		     printhand(G);
		     printf("player %d score: %d\n", whoseTurn(G), scoreFor(whoseTurn(G),G));
		     printf("player %d turn ending\n", whoseTurn(G));
		     endTurn(G);
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
