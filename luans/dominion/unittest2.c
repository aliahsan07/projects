#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dominion.h"
#include "rngs.h"

int main(int argc, char *argv[])
{
	char *v1 = "adventurer";
	int v2 = adventurer;
	
	printf("Starting to compare two card assigned by string\n");
	
	int result = compare(v1, &v2);
	assert(result == 0);
	
	return EXIT_SUCCESS;
}