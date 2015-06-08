#pragma once


#include "dominion.h"


int play_adventurer(struct gameState *state, int currentPlayer, int handPos);
int play_council_room(struct gameState *state, int currentPlayer, int handPos);
int play_feast(struct gameState *state, int currentPlayer, int choice1,
        int handPos);
int play_mine(struct gameState *state, int currentPlayer, int choice1,
        int choice2, int handPos);
int play_remodel(struct gameState *state, int currentPlayer, int choice1,
        int choice2, int handPos);
