#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "assert.h"
#include "rngs.h"

int compare(const void* a, const void* b);

int main(int argc, char** argv) {
	int a, b;
	char stringA[10];
	char stringB[10];

	a = 11;
	b = 10;
	assert(compare(&a, &b) == 1);
	assert(compare(&b, &a) == -1);
	
	a = -6;
	b = -8;
	assert(compare(&a, &b) == 1);
	assert(compare(&b, &a) == -1);
	
	b = a;
	assert(compare(&a, &b) == 0);
	
	strcpy(stringA, "aardvark");
	strcpy(stringB, "bear");
		
	assert(compare(stringB, stringA) == 1);
	assert(compare(stringA, stringB) == -1);
	strcpy(stringA, stringB);
	assert(compare(stringA, stringB) == 0);
	
	printf("compare() passed all tests.\n");
	
	return 1;
}
