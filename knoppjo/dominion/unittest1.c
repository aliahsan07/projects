#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {

	printf("***Testing compare***\n");
	int i = 1;
	int j =-1;
	printf("Compare %d and %d...\n", i, j);

	const void* a = &i;
	const void* b = &j;

	int r1 = compare(a, b);
	assert(r1 == 1);
	printf("Test passes\n");
	printf("Compare %d and %d...\n", i, j);
	i = -1;
	j = 1;

	int r2 = compare(a, b);
	assert(r2 == -1);
	printf("Test passes\n");

	i = 1;
	j = 1;

	printf("Compare %d and %d...\n", i, j);
	int r3 = compare(a, b);
	assert(r3 == 0);

	/*
	a = NULL;
	b = NULL;
	printf("Compare %d and %d...\n", i, j);
	int r4 = compare(a, b);
	assert(r4 == 0);
	*/

	printf("Test passes\n");

	return 0;
}


