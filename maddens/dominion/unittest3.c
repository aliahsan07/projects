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



  int x = 5;
  int y = 8;

  int* smaller = &x;
  int* bigger = &y;

  assertTrue(EQ(compare(smaller, bigger), -1), "Right value is bigger: return -1");
  assertTrue(EQ(compare(bigger, smaller), 1), "Left value is bigger: return 1");
  assertTrue(EQ(compare(bigger, bigger), 0), "Values are the same: return 0");


  return 0;
}
