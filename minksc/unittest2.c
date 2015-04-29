#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>

int main(){
	int p = 0;
  struct gameState *game = malloc(sizeof(struct gameState));
  printf("**Testing getCost **\n");

  printf("Curse: ");
  int r = getCost(curse);
  if (r == 0){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }

  printf("Estate: ");
  r = getCost(estate);
  if (r == 2){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }

  printf("Duchy: ");
  r = getCost(duchy);
  if (r == 5){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }

  printf("Provinve: ");
  r = getCost(province);
  if (r == 8){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }

  printf("Copper:");
  r = getCost(copper);
  if(r == 0){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }

  printf("Silver:");
  r = getCost(silver);
  if (r == 3){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }

  
  printf("Gold:");
  r = getCost(gold);
  if(r == 6){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Adventurer: ");
  r = getCost(adventurer);
  if(r == 6){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Council Room: ");
  r = getCost(council_room);
  if(r == 5){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Feast: ");
  r = getCost(feast);
  if(r == 4){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Gardens: ");
  r = getCost(gardens);
  if(r == 4){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Mine: ");
  r = getCost(mine);
  if(r == 5){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }

  
  printf("Remodel: ");
  r = getCost(remodel);
  if(r == 4){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Smithy: ");
  r = getCost(smithy);
  if(r == 4){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Village: ");
  r = getCost(village);
  if(r == 3){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Baron: ");
  r = getCost(baron);
  if(r == 4){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Great Hall: ");
  r = getCost(great_hall);
  if(r == 3){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Minion: ");
  r = getCost(minion);
  if(r == 5){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Steward: ");
  r = getCost(steward);
  if(r == 3){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Tribute: ");
  r = getCost(tribute);
  if(r == 5){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Ambassador: ");
  r = getCost(ambassador);
  if(r == 3){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Cutpurse: ");
  r = getCost(cutpurse);
  if(r == 4){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Embargo: ");
  r = getCost(embargo);
  if(r == 2){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Outpost: ");
  r = getCost(outpost);
  if(r == 5){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Salvager: ");
  r = getCost(salvager);
  if(r == 4){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Sea Hag: ");
  r = getCost(sea_hag);
  if(r == 4){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Treasure Map: ");
  r = getCost(treasure_map);
  if(r == 4){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }


  printf("Test for Invalid Input: ");
  r = getCost(400);
  if(r == -1){
  	printf("Passes\n");
  }
  else {
  	printf("Failed\n");
  	p++;
  }

  
  if(p == 0){
  	printf("**** All Test Pass ******\n");
  }
  else{
  	printf("**** %d Tests Fail ******\n",p);
  }


	return 0;
}
