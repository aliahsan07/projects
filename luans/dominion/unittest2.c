#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"

int main(int argc, char *argv[])
{
	char *v1 = "adventurer";
	int v2 = adventurer;
	
	int result = compare(v1, &v2);
	
	printf("Starting to compare two cards......\n");
	
	assert(result == 0);
	printf("MORE COMPARE: %d\n", result);
	
	return EXIT_SUCCESS;
}