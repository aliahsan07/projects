#include "assert.h"
//#include "dominion_helpers.h"
#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "displayDom.h"

struct gameState *G;
int *tempKC;
void testNoDiscard()
{
	G = newGame();
	initializeGame(2, tempKC, 4, G);
	int turn1 = G->whoseTurn;
	int turn2 = turn1 + 1;

	//Assign first hand draw (deck must be identifiable)
	G->hand[turn1][0] = estate;
	G->hand[turn1][1] = baron;
	G->hand[turn1][2] = copper;
	G->hand[turn1][3] = copper;
	G->hand[turn1][4] = copper;

	//Each Deck position should be different (identification)
	G->deck[turn1][0] = estate;
	G->deck[turn1][1] = silver;
	G->deck[turn1][2] = gold;
	G->deck[turn1][3] = village;
	G->deck[turn1][4] = minion;

	//Set 2nd player to keep deck identifiable
	G->deck[turn2][0] = estate;
	G->deck[turn2][1] = estate;
	G->deck[turn2][2] = copper;
	G->deck[turn2][3] = copper;
	G->deck[turn2][4] = copper;
	G->deck[turn2][5] = tribute;
	G->deck[turn2][6] = salvager;
	G->deck[turn2][7] = adventurer;
	G->deck[turn2][8] = baron;
	G->deck[turn2][9] = remodel;

	printf("\n*********Before card effect (No Discard)***********\n");
	displayState(G);
	cardEffect(baron, 0, 0, 0, G, 0, 0);
	printf("\n*********After card effect(No Discard)***********\n");
	displayState(G);
	return;
}

void testDiscard()
{
	int turn1 = G->whoseTurn;
	int turn2 = turn1 + 1;

	//Assign first hand draw (deck must be identifiable)
	G->hand[turn1][0] = estate;
	G->hand[turn1][1] = baron;
	G->hand[turn1][2] = copper;
	G->hand[turn1][3] = estate;
	G->hand[turn1][4] = copper;

	//Each Deck position should be different (identification)
	G->deck[turn1][0] = estate;
	G->deck[turn1][1] = silver;
	G->deck[turn1][2] = gold;
	G->deck[turn1][3] = village;
	G->deck[turn1][4] = minion;

	//Set 2nd player to keep deck identifiable
	G->deck[turn2][0] = estate;
	G->deck[turn2][1] = estate;
	G->deck[turn2][2] = copper;
	G->deck[turn2][3] = copper;
	G->deck[turn2][4] = copper;
	G->deck[turn2][5] = tribute;
	G->deck[turn2][6] = salvager;
	G->deck[turn2][7] = adventurer;
	G->deck[turn2][8] = baron;
	G->deck[turn2][9] = remodel;

	printf("\n*********Before card effect (With Discard)***********\n");
	displayState(G);
	cardEffect(baron, 1, 0, 0, G, 0, 0);
	printf("\n*********After card effect(With Discard)***********\n");
	displayState(G);
	return;
}


void testDiscardFail()
{
	int turn1 = G->whoseTurn;
	int turn2 = turn1 + 1;

	//Assign first hand draw (deck must be identifiable)
	G->hand[turn1][0] = copper;
	G->hand[turn1][1] = baron;
	G->hand[turn1][2] = copper;
	G->hand[turn1][3] = copper;
	G->hand[turn1][4] = copper;

	//Each Deck position should be different (identification)
	G->deck[turn1][0] = estate;
	G->deck[turn1][1] = silver;
	G->deck[turn1][2] = gold;
	G->deck[turn1][3] = village;
	G->deck[turn1][4] = minion;

	//Set 2nd player to keep deck identifiable
	G->deck[turn2][0] = estate;
	G->deck[turn2][1] = estate;
	G->deck[turn2][2] = copper;
	G->deck[turn2][3] = copper;
	G->deck[turn2][4] = copper;
	G->deck[turn2][5] = tribute;
	G->deck[turn2][6] = salvager;
	G->deck[turn2][7] = adventurer;
	G->deck[turn2][8] = baron;
	G->deck[turn2][9] = remodel;

	printf("\n*********Before card effect (With Failed Discard)***********\n");
	displayState(G);
	cardEffect(baron, 1, 0, 0, G, 0, 0);
	printf("\n*********After card effect(With Failed Discard)***********\n");
	displayState(G);
	return;
}

int main(int argc, char** argv) {
	printf("\nStarting Card Test 3 (baron)\n");

	tempKC = kingdomCards(council_room, feast, mine, great_hall, cutpurse,
		treasure_map, outpost, smithy, gardens, embargo);
	G = newGame();
	initializeGame(2, tempKC, 4, G);

	testNoDiscard();

	free(G);
	G = newGame();
	initializeGame(2, tempKC, 4, G);

	testDiscard();

	free(G);
	G = newGame();
	initializeGame(2, tempKC, 4, G);

	testDiscardFail();

	printf("\n*********************************************************\n");
	printf("*********Successfully finished Card Test 3***********\n");
	printf("*********************************************************\n\n");
	return 0;
}