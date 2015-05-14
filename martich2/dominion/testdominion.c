/*
 * testdominion.c
 *
 * random game tester for dominion
 *
 *  Created on: May 13, 2015
 *      Author: martich2
 */

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "dominion.h"
#include "dominion_helpers.h"

int main(int argc, char** argv)
{
    srand(time(NULL));          // init libc random seed
    int players = (rand() % 3) + 2; // 2 to 4 players
	printf("Hello World: %d!\n", players);

	return 0;
}
