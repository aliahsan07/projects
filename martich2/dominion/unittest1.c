/*
 * unittest1.c
 *
 * test of compare compare(const void* a, const void* b)
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

	 /* a > b -> 1 */
	result = compare(ptr_a,ptr_b);
	assert(result == 1);
	printf("Test 1: A=%d is > B=%d passes\n", a, b);

	/* a < b -> -1 */
	b = 7;
	result = compare(ptr_a,ptr_b);
	assert(result == -1);
	printf("Test 2: A=%d is < B=%d passes\n", a, b);

	/* a = b -> 0 */
	a = 7;
	result = compare(ptr_a,ptr_b);
	assert(result == 0);
	printf("Test 3: A=%d is = B=%d passes\n", a, b);

	/* does it handles null data? */
	ptr_a = NULL;
	result = compare(ptr_a,ptr_b);
	// none shall pass, seg fault.
	printf("Test 4: A=NULL is = B=%d passes\n", b);

	return 0;
}
