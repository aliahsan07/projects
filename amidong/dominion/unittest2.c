#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Testing compare(...);


int main (int argc, char** argv) {
	int* a; 
	int* b;
	int c = 1; 
	int d = -1; 
	a = &c;
	b = &d; 
	int result = compare(a,b);
	assert(result == 1);
	
	return 0; 
}