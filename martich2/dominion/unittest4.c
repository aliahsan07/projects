/*
 * unittest3.c
 *
 * test of int getCost(int cardNumber)
 * in dominion.c
 *
 *  Created on: Apr 22, 2015
 *      Author: martich2
 */
#include <stdio.h>
#include <assert.h>
#include "dominion.h"

/* prototype here to allow compiling, no linker errors/warnings */
int getCost(int cardNumber);

/* helper function to test all the cases of getCost*/
void test_getCost(const char* card_name, const unsigned int card_cost,
        const unsigned int test_number, enum CARD card_enum);

int main(int argc, char** argv)
{
    test_getCost("curse", 0, 1, curse);
    test_getCost("estate", 2, 2, estate);
    test_getCost("duchy", 5, 3, duchy);
    test_getCost("province", 8, 4, province);
    test_getCost("copper", 0, 5, copper);
    test_getCost("silver", 3, 6, silver);
    test_getCost("gold", 6, 7, gold);
    test_getCost("adventurer", 6, 8, adventurer);
    test_getCost("council_room", 5, 2, council_room);
    test_getCost("feast", 4, 10, feast);
    test_getCost("gardens", 4, 11, gardens);
    test_getCost("mine", 5, 12, mine);
    test_getCost("remodel", 4, 13, remodel);
    test_getCost("smithy", 4, 14, smithy);
    test_getCost("village", 3, 15, village);
    test_getCost("baron", 4, 16, baron);
    test_getCost("great_hall", 3, 17, great_hall);
    test_getCost("minion", 5, 18, minion);
    test_getCost("steward", 3, 19, steward);
    test_getCost("tribute", 5, 20, tribute);
    test_getCost("ambassador", 3, 21, ambassador);
    test_getCost("cutpurse", 4, 22, cutpurse);
    test_getCost("embargo", 2, 23, embargo);
    test_getCost("outpost", 5, 24, outpost);
    test_getCost("salvager", 4, 25, salvager);
    test_getCost("sea_hag", 4, 26, sea_hag);
    test_getCost("treasure_map", 4, 27, treasure_map);
    test_getCost("undefined card", -1, 28, 42);

    return 0;
}

void test_getCost(const char* card_name, const unsigned int card_cost,
        const unsigned int test_number, enum CARD card_enum)
{
    int result;

    printf("Test %d: %s costs %d...",test_number, card_name, card_cost);
    result = getCost(card_enum);
    assert(result == card_cost);
    printf("passes\n");
}
