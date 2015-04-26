#include <stdio.h>
#include <string.h>
#include <assert.h>

int compare(const void* a, const void* b);

int main() {
	int a = 10;
	int b = 4;

	char stringA[30];
	char stringB[30];

	int* adr_a = &a;
	int* adr_b = &b;

	//First test
	printf("Test 1: a=%d > b=%d\n", a,b);
	assert(compare(adr_a,adr_b) == 1);
	assert(compare(adr_b,adr_a) == -1);
	printf("Test passed\n");

	b = 15;

	printf("Test 2: a=%d < b=%d\n", a,b);
	assert(compare(adr_a,adr_b) == -1);
	assert(compare(adr_b,adr_a) == 1);
	printf("Test passed\n");

	a = b;

	printf("Test: a=%d = b=%d\n",a,b);
	assert(compare(adr_a,adr_b) == 0);
	printf("Test passed\n");


	strcpy(stringA, "OregonStateUniversity");
	strcpy(stringB, "UniversityOfOregon");

	assert(compare(stringB, stringA) == 1);
	assert(compare(stringA, stringB) == -1);
	strcpy(stringA, stringB);
	assert(compare(stringA,stringB) == 0);

	printf("All tests passed\n");
return 0;
}
