#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "displayDom.h"

#define MAX_TESTS 5
#define ACTIONS 1

struct gameState* getGameState();

int main()
{
	srand(time(NULL));
	struct gameState* g;
	struct gameState* gcpy;
	int option, pos, c1, c2, c3, max, result, action;

	FILE *fp = fopen("testdominion.c", "w");

	fprintf(fp, "#define MAX_CASES %i\n\n", MAX_TESTS);
	fprintf(fp, "void TestCase(int caseNum){\n");
	fprintf(fp, "\tstruct gameState* gcpy = newGame(), *g = newGame();\n\tint result, *k;\n\n");
	int testCount;
	for (testCount = 0; testCount < MAX_TESTS; ++testCount){

		fprintf(fp, "\tif(caseNum == %i){\n", testCount);

		g = getGameState(fp);
		gcpy = newGame();

		fprintf(fp, "\tprintState(g, gcpy);\n\n");
		memcpy(gcpy, g, sizeof(struct gameState));

		action = 0;
		while (!isGameOver(g)){
			option = rand() % 3;
			switch (option){
			case 0:
				max = (g->handCount[g->whoseTurn] > treasure_map ? g->handCount[g->whoseTurn] : treasure_map + 1);
				pos = rand() % (g->handCount[g->whoseTurn]);
				c1 = rand() % max;
				c2 = rand() % max;
				c3 = rand() % max;
				result = playCard(pos, c1, c2, c3, g);
				fprintf(fp, "\tresult = playCard(%i, %i, %i, %i, g);\n", pos, c1, c2, c3);
				fprintf(fp, "\tprintf(\"#Card attempted to play: \");\n");
				fprintf(fp, "\tprintCardName(gcpy->hand[gcpy->whoseTurn][%i]);\n", pos);
				fprintf(fp, "\tprintResult(result);\n");
				fprintf(fp, "\tprintf(\"playCard(%i, %i, %i, %i, g)\\n\");\n", pos, c1, c2, c3);

				//printf("playCard(%i, %i, %i, %i, g);\n", pos, c1, c2, c3);
				//printf("#Card attempted to play: ");
				//printCardName(gcpy->hand[gcpy->whoseTurn][pos]);
				//printf("\nResult = %i\n", result);

				if (result == 0){ action++; }
				fprintf(fp, "\tif (stateChanged(g, gcpy)){\n\t\tprintState(g, gcpy);\n\t}\n\n");
				break;
			case 1:
				pos = rand() % (treasure_map + 1);
				result = buyCard(pos, g);

				fprintf(fp, "\tresult = buyCard(%i, g);\n", pos);
				fprintf(fp, "\tprintf(\"#Card attempted to buy: \");\n");
				fprintf(fp, "\tprintCardName(%i);\n", pos);
				fprintf(fp, "\tprintResult(result);\n");
				
				// printf("buyCard(%i, g);\n", pos);
				//printf("#Card attempted to buy: ");
				//printCardName(pos);
				//printf("\nResult = %i\n", result);

				if (result == 0){ action++; }
				fprintf(fp, "\tif (stateChanged(g, gcpy)){\n\t\tprintState(g, gcpy);\n\t}\n\n");
				break;
			case 2:
				if (action >= ACTIONS)
				{
					result = endTurn(g);
					
					fprintf(fp, "\tresult = endTurn(g);\n");
					fprintf(fp, "\tprintf(\"#Attempt EndTurn \\n\");\n");
					fprintf(fp, "\tprintResult(result);\n");
					action = 0;
					fprintf(fp, "\tif (stateChanged(g, gcpy)){\n\t\tprintState(g, gcpy);\n\t}\n\n");

					//printf("endTurn(g);\n");
					//printf("#Attempt EndTurn \n");
					//printf("Result = %i\n", result);
				}
				break;
			}

			if (stateChanged(g, gcpy)){
				memcpy(gcpy, g, sizeof(struct gameState));
				//printState(g, gcpy);
			}

		}

		fprintf(fp, "\tprintf(\"Game Over\\n\");\n");
		fprintf(fp, "\tprintScoreBoard(g);\n");
		fprintf(fp, "}//End case %i\n\n", testCount);
		printf("Test Case %i completed.\n", testCount);

		free(g);
		free(gcpy);
	}

	//printf("\n\n******************Testing Completed*********************\n\n");

	fprintf(fp, "}");
	return 0;
}

struct gameState* getGameState(FILE *fp) {
	int base = treasure_map - adventurer + 1;
	int *k;
	struct gameState* g;
	int result;
	int nP, r, i;
	g = newGame();
	do {
		k = kingdomCards(rand() % base + adventurer, rand() % base + adventurer,
			rand() % base + adventurer, rand() % base + adventurer,
			rand() % base + adventurer, rand() % base + adventurer,
			rand() % base + adventurer, rand() % base + adventurer,
			rand() % base + adventurer, rand() % base + adventurer);
		nP = rand() % 3 + 2;
		r = rand();
		result = initializeGame(nP, k, r, g);

		if (result == -1) { free(k); }
	} while (result == -1);

	fprintf(fp, "\tk = kingdomCards(");
	for (i = 0; i < 9; ++i){ fprintf(fp, "%i, ", k[i]); }
	fprintf(fp, "%i);\n", k[9]);

	fprintf(fp, "\tinitializeGame(%i, k, %d, g);\n\n", nP, r);
	return g;
}
