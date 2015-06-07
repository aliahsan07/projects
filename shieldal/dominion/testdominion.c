#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv) {
  struct gameState G;
  struct gameState *s = &G;
  int numPlayers;
  int seed;
  int k[10];
  int i;
  int j;
  int temp, check;
  int who;
  int r;

  if(argc != 2) {
    printf("Must give a random seed");
    return 0;
  } else {
    seed = atoi(argv[1]);
    printf("Seed is %d\n", seed);
  }

  srand(seed);
  numPlayers = rand() % 3 + 2;
  
  for(i = 0; i < 10;) {
    temp = rand() % (treasure_map - adventurer) + adventurer;
    check = 0;
    for(j = 0; j < i; j++) {
      if(temp == k[j]) {
	check = 1;
      }
    }
    if(check == 0) {
      printf("%d is in kingdom cards.\n", temp);
      k[i] = temp;
      i++;
    }
  }

  printf("Starting game with %d players.\n", numPlayers);

  initializeGame(numPlayers, k, seed, s);

  while(!isGameOver(s)) {
    who = s->whoseTurn;
    printf("Player %d turn:\n", who+1);

    //Action phase
    for(i = 0; i < numHandCards(s); i++) {
	if(handCard(i, s) <= gold) {
          continue;
	}
        if(s->numActions == 0) {
	  break;
	}
        if(handCard(i, s) == feast) {
          temp = 0;
	  if(k[temp] == adventurer) {
	    temp = 1;
	  }
	  playCard(i, temp, -1, -1, s);
	  printf("Played feast gaining %d\n", k[temp]);
	}
	else if(handCard(i, s) == mine) {
	  temp = -1;
          for(j = 0; j < numHandCards(s); j++) {
            if(handCard(j, s) == silver) { 
	      playCard(i, j, gold, -1, s);
	      printf("Played mine and upgraded to gold\n");
	      temp = 1;
	      break;
	    }
	  }
	  if(temp == 1) { break; }
          for(j = 0; j < numHandCards(s); j++) {
            if(handCard(j, s) == copper) {
	      playCard(i, j, silver, -1, s);
	      printf("Played mine and upgraded to silver\n");
	      break;
	    }
	  }
	}
	else if(handCard(i, s) == baron) {
          temp = 0;
	  for(j = 0; j < numHandCards(s); j++) {
	    if(handCard(j, s) == estate) {
              temp = 1;
	    } 
	  }
	  playCard(i, temp, -1, -1, s);
	  printf("Played baron\n");
	}
	else if(handCard(i, s) == minion) {
	  if(rand() % 2 == 0) {
	    playCard(i, 1, -1, -1, s);
	    printf("Played minion with choice 1\n");
	  } else {
	    playCard(i, 2, -1, -1, s);
	    printf("played minion with choice 2\n");
	  }
	}
	else if(handCard(i, s) == steward) {
          if(rand() % 2 == 0) {
	    playCard(i, 1, -1, -1, s);
	  } else {
	    playCard(i, 2, -1, -1, s);
	  }
	  printf("Played steward\n");
	}
	else if(handCard(i, s) == ambassador) {
	}
	else if(handCard(i, s) == embargo) {
          temp = rand() % 10;
	  playCard(i, temp, -1, -1, s);
	  printf("Played embargo on %d\n", temp);
	}
	else if(handCard(i, s) == salvager) {
	  temp = 0;
	  if(i == 0) {
	    temp = 1;
	  }
	  playCard(i, temp, -1, -1, s);
	  printf("Played salvager on %d\n", temp);
	}
	else {
	  printf("Played %d\n", i); 
	  playCard(i, -1, -1, -1, s);
	}
    }

    //Buy phase
    printf("money: %d\n", s->coins);
    if(s->coins >= 8) {
      buyCard(province, s);
      printf("Bought province\n");
    } else if(s->coins >= 6 && rand() % 2 == 0) {
      buyCard(gold, s);
      printf("Bought gold\n");
    } else if(s->coins >= 3 && rand() % 2 == 0) {
      buyCard(silver, s);
      printf("bought silver\n");
    }
    
    //give it the old college try
    
    for(i = 0; i < 15; i++) {
      temp = rand() % 10;
      r = buyCard(k[temp], s);
      if(r == 0) {
        printf("bought %d\n", k[temp]);
      }
    }
    //temp = rand() % 10;
    //buyCard(k[temp], s);
    //printf("Attempted to buy %d\n", temp);

    endTurn(s);
  }

  printf("FINAL SCORE:\n");
  for(i = 0; i < numPlayers; i++) {
    printf("Player %d: %d\n", i + 1, scoreFor(i, s));
  }
  return 0;
}
