#pragma once


#include "dominion.h"


extern const char* cardNames[treasure_map + 1];
int discardMultipleCards(int handPos[], int count, int currentPlayer,
    struct gameState *state, int trashFlag);
