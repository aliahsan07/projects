#include "dominion.h"

#include <stdio.h>
#include <stdlib.h>

#define assertIntEqual(x, y) assertIntEqual_(x, y, __LINE__)


void assertIntEqual_(int x, int y, int line)
{
    if (x != y) {
        fprintf(
            stderr, "TEST FAILED on line %d: expected %d but got %d\n",
            line, x, y);
        exit(1);
    }
}


int main()
{
    struct gameState* g = newGame();
    int* ks = kingdomCards(
        gardens, gardens, gardens, gardens, gardens, gardens, gardens,
        gardens, gardens, gardens);
    assertIntEqual(-1, initializeGame(2, ks, 182, g));
    free(g);
    free(ks);

    puts("TEST PASSED");
    return 0;
}
