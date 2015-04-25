/*
 * unittest1.c
 *
 * test of int compare(const void* a, const void* b)
 *
 *  Created on: Apr 22, 2015
 *      Author: martich2
 */

#include <stdio.h>
#include <assert.h>

/* prototype here to allow compiling, no linker errors/warnings */
int compare(const void* a, const void* b);

int main(void)
{
	int a = 5;
	int b = 2;
	int result;

	int* ptr_a = &a;
	int* ptr_b = &b;

	// Test 1
	/* a > b -> 1 */
	printf("Test 1: A=%d > B=%d...", a, b);
	result = compare(ptr_a,ptr_b);
	assert(result == 1);
	printf("passes\n");

	// Test 2
	/* a < b -> -1 */
	b = 7;
	printf("Test 2: A=%d < B=%d...", a, b);
	result = compare(ptr_a,ptr_b);
	assert(result == -1);
	printf("passes\n");

	/* a = b -> 0 */
	a = 7;
    printf("Test 3: A=%d = B=%d...", a, b);
	result = compare(ptr_a,ptr_b);
	assert(result == 0);
	printf("passes\n");

	/* does it handles null data? */
	printf("Test 4: A=NULL = B=%d...\n", b);
	ptr_a = NULL;
	result = compare(ptr_a,ptr_b);
	// none shall pass, seg fault.
    printf("passes\n");


	return 0;
}
