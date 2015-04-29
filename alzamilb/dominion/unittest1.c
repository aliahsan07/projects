/*  Basil Alzamil  
    CS 362 - Assignment #2
    April 21, 2015 
 */

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int main(int argc, char** argv) {
    int r;

    r = getCost(curse);
    assert(r == 0);

    r = getCost(estate);
    assert(r == 2);

    r = getCost(duchy);
    assert(r == 5);

    r = getCost(province);
    assert(r == 8);

    r = getCost(copper);
    assert(r == 0);

    r = getCost(silver);
    assert(r == 3);

    r = getCost(gold);
    assert(r == 6);

    r = getCost(adventurer);
    assert(r == 6);

    r = getCost(council_room);
    assert(r == 5);

    r = getCost(feast);
    assert(r == 4);

    r = getCost(gardens);
    assert(r == 4);

    r = getCost(mine);
    assert(r == 5);

    r = getCost(remodel);
    assert(r == 4);

    r = getCost(smithy);
    assert(r == 4);

    r = getCost(village);
    assert(r == 3);

    r = getCost(baron);
    assert(r == 4);

    r = getCost(great_hall);
    assert(r == 3);

    r = getCost(minion);
    assert(r == 5);

    r = getCost(steward);
    assert(r == 3);

    r = getCost(tribute);
    assert(r == 5);

    r = getCost(ambassador);
    assert(r == 3);

    r = getCost(cutpurse);
    assert(r == 4);

    r = getCost(embargo);
    assert(r == 2);

    r = getCost(outpost);
    assert(r == 5);

    r = getCost(salvager);
    assert(r == 4);

    r = getCost(sea_hag);
    assert(r == 4);

    r = getCost(treasure_map);
    assert(r == 4);

    printf("getCost passed the Test successfully!\n");

return 0;
}
