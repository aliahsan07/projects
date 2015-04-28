/*
Name: unittest3.c

Purpose: test scoring system 
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
printf("Testing \n");
int check = 0;
struct gameState *game = newGame();
game->deck[0][0] = curse;
game->deck[0][1] = estate;

check = scoreFor(0, game);
if (check != 2){
	printf("You done goofed, it didn't add the scores for 3 minus 1 properly, instead you got %d", check);
}

printf(" Testing complete\n");
}
