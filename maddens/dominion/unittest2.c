#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"


# ifndef EQ
# define EQ(A, B) ((A) == (B))
# endif

//Test case for kingdomCards()


void assertTrue(int predicate, char* message) {

	printf("%s: ", message);

	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");

}

int main() {

	printf("\nTESTING kingdomCards() method.\n\n");

	srand(time(NULL));

	int number;

	int* original = malloc(sizeof(int) * 10);
	int* returned = malloc(sizeof(int) * 10);
	int* random = malloc(sizeof(int) * 10);

	for (int i = 0; i < 10; i++) {
		number = rand();
		original[i] = number;
		random[i] = number;
	}

	returned = kingdomCards(random[0], random[1], random[2], random[3], random[4], random[5], random[6], random[7], random[8], random[9]);

	
	for (int i = 0; i < 10; i++) {
		printf("Checking if content in array position %d is the same in both arrays", i);	
		assertTrue(EQ(original[i], returned[i]), "");
	}

	printf("\n");

	return 0;
}
