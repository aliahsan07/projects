/*
 * unittest1.c
 *
 *  Created on: Apr 22, 2015
 *      Author: jackknopp
 */
#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int main (int argc, char** argv) {

	int i = 1;
	int j =-1;

	const void* a = &i;
	const void* b = &j;

	int r1 = compare(a, b);
	assert(r1 == 1);

	i = -1;
	j = 1;

	int r2 = compare(a, b);
	assert(r2 == -1);

	i = 1;
	j = 1;

	int r3 = compare(a, b);
	assert(r3 == 0);

	printf("test passes\n");

	return 0;
}


