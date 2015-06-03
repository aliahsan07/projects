#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>


int main (int argc, char** argv) {

	printf("***Testing kingdomCards***\n");
	printf("Entering random array...\n");
	int i;
	int r;
	int* initial_array = malloc(10 * sizeof(int));
	srand(time(NULL));


	for(i=0; i<10; i++){
		r = rand();
		initial_array[i] = r;
	}

	int* return_array = kingdomCards(initial_array[0], initial_array[1], initial_array[2],
			initial_array[3], initial_array[4], initial_array[5], initial_array[6], initial_array[7], initial_array[8], initial_array[9]);

	for(i=0; i<10; i++){
		assert(return_array[i] == initial_array[i]);
	}

	printf("All tests pass\n");

	return 0;

}


