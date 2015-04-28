#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(){
	printf("--------------------TESTING kingdomCards-----------------\n");
	srand(time(NULL));
	int* test1 = malloc(10 * sizeof(int));
	int* test2 = malloc(10 * sizeof(int));

	int i;
	for(i = 0; i<10; i++){
		test1[i] = rand();
	}

	test2 = kingdomCards(test1[0],test1[1],test1[2],test1[3],test1[4],test1[5],test1[6],test1[7],test1[8],test1[9]);
	for(i = 0; i<10; i++){
                assert(test1[i]==test2[i]);
        }
	
	printf("--------------------TEST PASSED---------------\n");
	
	return 0;
}
