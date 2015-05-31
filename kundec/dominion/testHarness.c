#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "displayDom.h"
#include "playTest_out.c"

int main(int argc, char *argv[]){

	int i;

	if (argc > 1){
		if (sscanf(argv[1], "%i", &i) != 1){ i = MAX_CASES; }
		if (i < MAX_CASES){ TestCase(i); }
	}
	else{
		for (i = 0; i < MAX_CASES; ++i){
			TestCase(i);
		}
	}

	return 0;
}