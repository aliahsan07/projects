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
  int i;
  int card1, card2;
  int handSize;
  int success = 0;
  int failure = 0;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    		sea_hag, tribute, smithy};
  
  srand(time(NULL));

  for(i = 0; i < MAX_TESTS; i++) {
    s = newGame();

    initializeGame(2, k, rand(), s);
    
    who = s->whoseTurn;

    s->deckCount[who] = rand() % MAX_DECK;
    s->discardCount[who] = rand() %MAX_DECK;
    s->handCount[who] = rand() % MAX_HAND;
    handSize = s->handCount[who];

    r = cardEffect(adventurer, rand() % 2, rand() % 2, rand() % 2, s, 0, 0);

    if(r != 0) {
      failure++;
      continue;
    }

    if(handSize + 2 != s->handCount[who]) {
      failure++;
      printf("Less than two cards were added\n");
      continue;
    }

    card1 = s->hand[who][s->handCount[who] - 1];
    card2 = s->hand[who][s->handCount[who] - 2];

    if((card1 == copper || card1 == silver || card1 == gold) &&
	(card2 == copper || card2 == silver || card2 == gold)) {
      success++;
    }
    else {
      printf("The two cards added weren't money\n");
      failure++;
    }
  }
  printf("Adventurer results:\n");
  printf("Successes: %d\n", success);
  printf("Failures: %d\n", failure);
  printf("Testing complete\n");
}
