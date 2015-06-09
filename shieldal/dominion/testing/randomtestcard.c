#include "dominion.h"
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_TESTS 150

int main(int argc, char* argv[])
{
  struct gameState* s = newGame();
  int who;
  int r;
  int i, j;
  int handSize, numBuys;
  int numPlayers;
  int success = 0;
  int failure = 0;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    		sea_hag, tribute, smithy};
  
  srand(time(NULL));

  for(i = 0; i < MAX_TESTS; i++) {
    s = newGame();
    

    numPlayers = rand() % 3 + 2; //2 - 4
    initializeGame(numPlayers, k, rand(), s);
    
    who = s->whoseTurn;

    s->deckCount[who] = rand() % MAX_DECK;
    s->discardCount[who] = (rand() %MAX_DECK - 4) + 4;
    s->handCount[who] = rand() % (MAX_HAND - 4);
    handSize = s->handCount[who];
    numBuys = s->numBuys;

    s->hand[who][0] = council_room;
    r = playCard(0, 0, 0, 0, s);
    //r = cardEffect(council_room, rand() % 2, rand() % 2, rand() % 2, s, 0, 0);

    if(r != 0) {
      failure++;
      continue;
    }

    if(handSize + 3 != s->handCount[who]) {
      failure++;
      printf("%d cards were added instead of 4\n", s->handCount[who] - handSize + 1);
      continue;
    }

    for(j = 0; j < numPlayers; j++) {
      if(j != who && s->handCount[j] != 1) {
        failure++;
	printf("Other players weren't given their card.\n");
	continue;
      }
    }

    if(numBuys + 1 == s->numBuys) {
      success++;
    }
    else {
      printf("1 buy wasn't added\n");
      failure++;
    }
  }
  printf("Council Room results:\n");
  printf("Successes: %d\n", success);
  printf("Failures: %d\n", failure);
  printf("Testing complete\n");
}
