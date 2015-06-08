#include "dominion_helpers.h"
#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
  int r;
  printf("***Start Testing for  getCost ***\n");

  printf("Curse:\n");
  r = getCost(curse);
  assert(r == 0);

  printf("Estate:\n");
  r = getCost(estate);
  assert(r == 2);

  printf("Duchy:\n");
  r = getCost(duchy);
  assert(r == 5);

  printf("Provnce:\n");
  r = getCost(province);
  assert(r == 8);
  
  printf("Copper:\n");
  r = getCost(copper);
  assert(r == 0);
  
  printf("Silver:\n");
  r = getCost(silver);
  assert(r == 3);
  
  printf("Gold:\n");
  r = getCost(gold);
  assert(r == 6);

  printf("Adventurer\n");
  r = getCost(adventurer);
  assert(r == 6);

  printf("Council Room:\n");
  r = getCost(council_room);
  assert(r == 5);

  printf("Feast:\n");
  r = getCost(feast);
  assert(r == 4);

  printf("Gardens:\n");
  r = getCost(gardens);
  assert(r == 4);

  printf("Mine:\n");
  r = getCost(mine);
  assert(r == 5);
  
  printf("Remodel\n");
  r = getCost(remodel);
  assert(r == 4);

  printf("Smithy:\n");
  r = getCost(smithy);
  assert(r == 4);

  printf("Village:\n");
  r = getCost(village);
  assert(r == 3);

  printf("Baron\n");
  r = getCost(baron);
  assert(r == 4);

  printf("Great Hall:\n");
  r = getCost(great_hall);
  assert(r == 3);

  printf("Minion:\n");
  r = getCost(minion);
  assert(r == 5);

  printf("Steward\n");
  r = getCost(steward);
  assert(r == 3);

  printf("Tribute:\n");
  r = getCost(tribute);
  assert(r == 5);

  printf("Ambassador:\n");
  r = getCost(ambassador);
  assert(r == 3);

  printf("Cutpurse:\n");
  r = getCost(cutpurse);
  assert(r == 4);

  printf("Embargo:\n");
  r = getCost(embargo);
  assert(r == 2);

  printf("Outpost:\n");
  r = getCost(outpost);
  assert(r == 5);

  printf("Salvager:\n");
  r = getCost(salvager);
  assert(r == 4);

  printf("Sea Hag:\n");
  r = getCost(sea_hag);
  assert(r == 4);

  printf("Treasure Map\n");
  r = getCost(treasure_map);
  assert(r == 4);

  printf("Test for Invalid Input:\n");
  r = getCost(400);
  assert(r == -1);

  printf("Tests Are Successful\n"); 

  return 0;
}
