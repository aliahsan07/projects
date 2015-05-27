#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "dominion.h"
#include "interface.h"

#define MAX_TESTS 20


int pick_card(int* list, int* size, int random) {

  int i;
  int return_card;


  return_card = list[random];

  for (i = random - 1; i < *size - 1; i++)
    list[i] = list[i+1];

  (*size)--;

  return return_card;

}

int main() {

  FILE *fp = fopen("results.txt", "w");


  int init, i, random, players, player, seed;
  struct gameState gs;
  struct gameState *state = &gs;

  int* k = malloc(sizeof(int)*10);
  int all_cards[21] = {duchy, adventurer, tribute, steward, minion, great_hall, baron, village, smithy, remodel, mine, gardens, feast, council_room, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
  int size = 21;
  int* amount = &size;

  char string[20];

  random = rand() % 21;

  printf("Setting up kingdom cards.\n\n");

  for (i = 0; i < 10; i++) {
    k[i] = pick_card(all_cards, amount, random);
  }

  for (i = 0; i < 10; i++) {
    cardNumToName(k[i], string);
    printf("card at position %d is %s\n", i, string);
  }


  printf("STARTING RANDOM TESTS\n");

  for (i = 0; i < MAX_TESTS; i++) {
    players = rand() % 4;

    if (players < 2)
      players += 2;

    player = rand() % players;

    seed = rand();

    printf("Initalizing Game\n");

    init = initializeGame(players, k, seed, state);

    assert(init == 0);

    printf("Game is initialized.\n");


    int money = 0;
    int purchased = -1;
    int lowest_cost_in_kingdom = 9999;
    int h = 0;
    int j = 0;
    int l = 0;
    int m = 0;
    int n = 0;

    for (n = 0; n < 10; n++) {
      //printf("k[n] is %d\n", getCost(k[n]));
      if (lowest_cost_in_kingdom > getCost(k[n]))
        lowest_cost_in_kingdom = getCost(k[n]);
    }

    while (!isGameOver(state)) {


      printf("*******Starting turn***********\n");
      printf("\n");

      //Play card if it's not copper/silver/gold or estate.
      for (m = 0; m < numHandCards(state); m++) {
        if ((handCard(m, state) != copper) && (handCard(m, state) != silver) && (handCard(m, state) != gold) && (handCard(m, state) != estate) && (handCard(m, state) != province)) {
          playCard(m, -1, -1, -1, state);
          cardNumToName(handCard(m, state), string);
          printf("Played this card: %s\n", string);
          break;
        }
      }

        money = 0;
        h = 0;

        //Cash in that money.
      	while (h < numHandCards(state)) {
      	  if (handCard(h, state) == copper){
      	    playCard(h, -1, -1, -1, state);
      	    money++;
      	  }
      	  else if (handCard(h, state) == silver){
      	    playCard(h, -1, -1, -1, state);
      	    money += 2;
      	  }
      	  else if (handCard(h, state) == gold){
      	    playCard(h, -1, -1, -1, state);
      	    money += 3;
      	  }
      	  h++;
      	}

        printf("We have %d money to spend.\n", money);

        purchased = -1;

        //Buy things.
        if (money >= 8) {
          printf("Buying province.\n\n");
          buyCard(province, state);
        }
        else if (money >= 6) {
          printf("Buying gold.\n\n");
          buyCard(gold, state);
        }

        else if (money >= 3 && (rand()%2 == 0)) {
          printf("Buying silver.\n\n");
          buyCard(silver, state);
        }


        //printf("lowest cost is %d\n", lowest_cost_in_kingdom);
        else if (money < lowest_cost_in_kingdom) {
          printf("Not enough money to buy anything. Ending turn. \n");
          printf("\n");
          //break;
        }

        //Buy a random card.
        else {
          while(purchased == -1) {
            for (l = 0; l < 10; l++) {
              purchased = buyCard(k[l], state);
              if (purchased != -1) {
                //printf("Bought a card.\n");
                break;
              }
            }
            break;
          }
        }

        printf("*******Ending turn***********\n");
        //printf("********Player %d ends his turn*******\n", whoseTurn(state));
        endTurn(state);




   }

    printf ("Finished game.\n");
    printf("Game number %d\nPlayer 0: %d\nPlayer 1: %d\n\n", i, scoreFor(0, state), scoreFor(1, state));
    fprintf (fp, "Game number %d\nPlayer 0: %d\nPlayer 1: %d\n\n", i, scoreFor(0, state), scoreFor(1, state));
    printf("\n --------------------------------------------------------------------\n");

  }


  fclose(fp);
  return 0;
}
