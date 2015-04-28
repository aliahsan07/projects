#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"


# ifndef EQ
# define EQ(A, B) ((A) == (B))
# endif

//Test case for compare(void*, void*)


void assertTrue(int predicate, char* message) {

	printf("%s: ", message);

	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");

}

int main () {

	struct gameState* new_game = newGame();

	assert(new_game != NULL);

	new_game -> supplyCount[5] = 123;

	assertTrue(EQ(supplyCount(5, new_game), 123), "Value should be 123");


  return 0;
}
