#define MAX_CASES 2

void TestCase(int caseNum){
	struct gameState* gcpy = newGame(), *g = newGame();
	int result, *k;

	if(caseNum == 0){
	k = kingdomCards(24, 9, 7, 21, 11, 17, 16, 10, 15, 22);
	initializeGame(3, k, 758124073, g);

	printState(g, gcpy);

	result = playCard(0, 4, 22, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 4, 22, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 9, 2, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 9, 2, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 25, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 25, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 13, 15, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 13, 15, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 19, 2, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 19, 2, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 25, 19, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 25, 19, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 21, 9, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 21, 9, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 2, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 2, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 16, 7, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 16, 7, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 6, 14, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 6, 14, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 14, 2, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 14, 2, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 22, 17, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 22, 17, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 8, 15, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 8, 15, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 24, 22, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 24, 22, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 0, 11, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 0, 11, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 14, 2, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 14, 2, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 5, 26, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 5, 26, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 22, 20, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 22, 20, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 11, 25, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 11, 25, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 14, 22, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 14, 22, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 15, 12, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 15, 12, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 14, 3, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 14, 3, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 4, 0, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 4, 0, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 23, 3, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 23, 3, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 4, 4, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 4, 4, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 20, 19, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 20, 19, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 23, 11, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 23, 11, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 10, 0, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 10, 0, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 20, 15, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 20, 15, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 2, 4, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 2, 4, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 8, 15, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 8, 15, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 24, 9, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 24, 9, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 5, 18, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 5, 18, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 10, 4, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 10, 4, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 21, 17, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 21, 17, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 15, 14, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 15, 14, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 10, 14, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 10, 14, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 16, 23, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 16, 23, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 20, 17, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 20, 17, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 17, 9, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 17, 9, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 26, 24, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 26, 24, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 23, 5, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 23, 5, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 13, 15, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 13, 15, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 8, 0, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 8, 0, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 23, 6, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 23, 6, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 11, 10, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 11, 10, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 6, 15, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 6, 15, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 1, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 1, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 0, 13, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 0, 13, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 11, 17, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 11, 17, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 1, 0, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 1, 0, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 11, 21, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 11, 21, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 19, 20, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 19, 20, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 5, 17, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 5, 17, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 2, 24, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 2, 24, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 25, 2, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 25, 2, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 13, 12, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 13, 12, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 21, 21, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 21, 21, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 22, 4, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 22, 4, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 18, 22, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 18, 22, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 0, 8, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 0, 8, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 3, 0, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 3, 0, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 5, 17, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 5, 17, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 9, 4, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 9, 4, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 10, 1, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 10, 1, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 24, 4, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 24, 4, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 8, 26, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 8, 26, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 13, 5, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 13, 5, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 0, 7, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 0, 7, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 15, 19, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 15, 19, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 21, 20, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 21, 20, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 14, 0, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 14, 0, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 15, 13, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 15, 13, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 7, 12, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 7, 12, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 22, 17, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 22, 17, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 4, 26, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 4, 26, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 22, 12, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 22, 12, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 25, 15, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 25, 15, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 2, 2, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 2, 2, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 13, 11, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 13, 11, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 21, 26, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 21, 26, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 17, 7, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 17, 7, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 17, 11, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 17, 11, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 13, 4, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 13, 4, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 13, 26, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 13, 26, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 21, 5, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 21, 5, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 11, 15, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 11, 15, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 15, 26, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 15, 26, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 3, 5, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 3, 5, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 10, 18, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 10, 18, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 14, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 14, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 18, 5, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 18, 5, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 25, 25, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 25, 25, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 12, 24, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 12, 24, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 5, 9, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 5, 9, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 25, 21, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 25, 21, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 1, 12, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 1, 12, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 9, 13, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 9, 13, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 5, 19, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 5, 19, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 14, 20, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 14, 20, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 0, 3, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 0, 3, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 8, 19, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 8, 19, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 8, 23, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 8, 23, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 25, 0, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 25, 0, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 23, 19, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 23, 19, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 18, 2, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 18, 2, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 25, 7, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 25, 7, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 26, 23, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 26, 23, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 10, 14, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 10, 14, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 22, 13, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 22, 13, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 18, 1, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 18, 1, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 4, 25, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 4, 25, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 17, 11, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 17, 11, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 10, 7, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 10, 7, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 7, 0, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 7, 0, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 11, 22, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 11, 22, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 1, 7, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 1, 7, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 17, 13, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 17, 13, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 10, 1, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 10, 1, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 23, 4, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 23, 4, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 18, 1, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 18, 1, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 13, 6, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 13, 6, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 9, 2, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 9, 2, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 26, 10, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 26, 10, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 25, 6, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 25, 6, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 25, 5, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 25, 5, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 8, 5, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 8, 5, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 17, 10, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 17, 10, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 14, 24, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 14, 24, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 13, 0, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 13, 0, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 17, 23, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 17, 23, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 11, 21, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 11, 21, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 0, 26, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 0, 26, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 16, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 16, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 23, 14, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 23, 14, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 6, 3, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 6, 3, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 13, 3, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 13, 3, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 11, 3, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 11, 3, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 11, 11, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 11, 11, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 12, 9, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 12, 9, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 22, 23, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 22, 23, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 7, 14, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 7, 14, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 5, 21, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 5, 21, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 23, 15, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 23, 15, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 13, 12, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 13, 12, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 26, 1, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 26, 1, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 3, 10, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 3, 10, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 8, 20, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 8, 20, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 22, 5, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 22, 5, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 5, 6, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 5, 6, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 14, 26, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 14, 26, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 9, 5, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 9, 5, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 12, 20, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 12, 20, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 10, 11, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 10, 11, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 4, 7, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 4, 7, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 7, 15, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 7, 15, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 22, 21, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 22, 21, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 15, 3, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 15, 3, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 1, 1, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 1, 1, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 24, 26, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 24, 26, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 1, 25, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 1, 25, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 4, 21, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 4, 21, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 5, 18, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 5, 18, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 9, 14, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 9, 14, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 5, 16, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 5, 16, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 10, 6, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 10, 6, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 25, 26, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 25, 26, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 8, 9, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 8, 9, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 25, 17, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 25, 17, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 18, 10, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 18, 10, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 12, 4, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 12, 4, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 20, 7, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 20, 7, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 20, 12, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 20, 12, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 2, 7, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 2, 7, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 12, 26, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 12, 26, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 7, 20, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 7, 20, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 26, 1, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 26, 1, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 8, 19, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 8, 19, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 12, 13, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 12, 13, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 1, 18, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 1, 18, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 22, 3, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 22, 3, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 10, 1, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 10, 1, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 23, 0, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 23, 0, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 4, 18, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 4, 18, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 15, 1, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 15, 1, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 23, 10, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 23, 10, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 26, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 26, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 22, 3, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 22, 3, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 16, 14, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 16, 14, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 24, 26, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 24, 26, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 6, 5, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 6, 5, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 13, 6, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 13, 6, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 0, 8, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 0, 8, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 7, 22, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 7, 22, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 5, 22, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 5, 22, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 12, 26, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 12, 26, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 8, 14, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 8, 14, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 18, 3, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 18, 3, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 0, 25, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 0, 25, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 10, 18, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 10, 18, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 2, 9, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 2, 9, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 24, 24, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 24, 24, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 3, 18, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 3, 18, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 7, 6, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 7, 6, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 15, 10, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 15, 10, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 26, 5, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 26, 5, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 11, 15, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 11, 15, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 15, 1, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 15, 1, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 12, 17, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 12, 17, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 11, 9, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 11, 9, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 1, 7, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 1, 7, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 8, 10, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 8, 10, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 15, 3, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 15, 3, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 4, 10, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 4, 10, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 12, 13, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 12, 13, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 1, 8, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 1, 8, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 6, 9, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 6, 9, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 15, 9, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 15, 9, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 14, 4, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 14, 4, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 6, 22, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 6, 22, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 19, 9, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 19, 9, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 6, 4, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 6, 4, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 15, 1, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 15, 1, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 10, 20, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 10, 20, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 20, 8, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 20, 8, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 1, 25, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 1, 25, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 3, 11, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 3, 11, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 5, 9, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 5, 9, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 0, 10, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 0, 10, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 18, 11, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 18, 11, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 1, 1, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 1, 1, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 6, 13, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 6, 13, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 10, 25, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 10, 25, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 1, 5, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 1, 5, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 21, 15, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 21, 15, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 3, 13, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 3, 13, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 16, 16, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 16, 16, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 15, 10, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 15, 10, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 19, 23, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 19, 23, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 18, 16, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 18, 16, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 4, 24, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 4, 24, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 20, 5, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 20, 5, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 23, 0, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 23, 0, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 9, 9, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 9, 9, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 7, 26, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 7, 26, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 4, 20, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 4, 20, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 8, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 8, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 11, 22, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 11, 22, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 4, 3, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 4, 3, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 7, 17, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 7, 17, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 23, 2, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 23, 2, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 1, 22, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 1, 22, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 0, 16, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 0, 16, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 8, 23, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 8, 23, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 9, 17, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 9, 17, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 9, 25, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 9, 25, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 4, 12, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 4, 12, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 2, 2, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 2, 2, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 15, 6, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 15, 6, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 13, 25, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 13, 25, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 6, 2, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 6, 2, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 19, 26, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 19, 26, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 8, 12, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 8, 12, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 24, 17, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 24, 17, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 24, 3, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 24, 3, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 1, 17, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 1, 17, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 25, 9, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 25, 9, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 19, 14, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 19, 14, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 18, 23, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 18, 23, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 22, 21, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 22, 21, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 0, 21, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 0, 21, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 4, 1, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 4, 1, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 14, 14, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 14, 14, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 22, 24, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 22, 24, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 0, 4, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 0, 4, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 11, 19, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 11, 19, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 21, 8, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 21, 8, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 25, 3, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 25, 3, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 4, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 4, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 1, 13, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 1, 13, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 22, 2, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 22, 2, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 4, 10, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 4, 10, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 2, 24, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 2, 24, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 8, 3, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 8, 3, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 26, 6, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 26, 6, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 15, 7, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 15, 7, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 11, 14, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 11, 14, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 21, 8, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 21, 8, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 16, 17, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 16, 17, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 9, 6, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 9, 6, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 20, 19, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 20, 19, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 25, 10, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 25, 10, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 25, 15, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 25, 15, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 18, 13, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 18, 13, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 12, 22, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 12, 22, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 4, 9, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 4, 9, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 26, 9, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 26, 9, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 6, 9, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 6, 9, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 6, 22, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 6, 22, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 25, 7, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 25, 7, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 8, 6, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 8, 6, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 15, 7, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 15, 7, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 25, 25, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 25, 25, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 6, 23, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 6, 23, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 3, 22, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 3, 22, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 8, 25, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 8, 25, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 24, 1, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 24, 1, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 0, 1, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 0, 1, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 21, 22, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 21, 22, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 0, 11, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 0, 11, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 25, 4, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 25, 4, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 3, 23, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 3, 23, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 16, 2, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 16, 2, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 9, 11, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 9, 11, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 11, 23, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 11, 23, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 15, 6, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 15, 6, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 19, 25, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 19, 25, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 16, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 16, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 21, 21, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 21, 21, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 18, 15, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 18, 15, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 23, 21, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 23, 21, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 13, 11, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 13, 11, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 15, 20, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 15, 20, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 19, 3, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 19, 3, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 4, 18, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 4, 18, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 26, 6, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 26, 6, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 6, 25, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 6, 25, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 8, 19, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 8, 19, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 25, 23, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 25, 23, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 6, 1, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 6, 1, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 20, 24, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 20, 24, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 20, 13, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 20, 13, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 2, 7, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 2, 7, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 26, 10, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 26, 10, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 1, 21, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 1, 21, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 15, 24, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 15, 24, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 26, 16, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 26, 16, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 6, 12, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 6, 12, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 0, 20, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 0, 20, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 22, 22, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 22, 22, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 10, 0, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 10, 0, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 26, 21, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 26, 21, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 14, 26, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 14, 26, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 15, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 15, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 6, 1, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 6, 1, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 10, 0, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 10, 0, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 23, 15, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 23, 15, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 6, 9, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 6, 9, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 25, 8, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 25, 8, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 11, 9, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 11, 9, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 3, 14, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 3, 14, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 16, 15, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 16, 15, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 14, 0, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 14, 0, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 20, 3, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 20, 3, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 2, 0, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 2, 0, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 5, 1, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 5, 1, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 11, 20, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 11, 20, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 1, 18, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 1, 18, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 6, 25, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 6, 25, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 16, 6, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 16, 6, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 26, 5, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 26, 5, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 18, 15, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 18, 15, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 2, 17, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 2, 17, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 21, 7, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 21, 7, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 26, 2, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 26, 2, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 22, 11, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 22, 11, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 22, 4, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 22, 4, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 17, 12, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 17, 12, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 0, 24, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 0, 24, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 22, 17, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 22, 17, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 22, 1, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 22, 1, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 26, 4, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 26, 4, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 14, 14, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 14, 14, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 11, 15, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 11, 15, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 19, 9, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 19, 9, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 5, 0, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 5, 0, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 21, 17, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 21, 17, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 14, 18, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 14, 18, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 15, 24, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 15, 24, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 2, 5, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 2, 5, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 24, 4, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 24, 4, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 18, 16, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 18, 16, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 23, 16, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 23, 16, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 23, 7, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 23, 7, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 15, 6, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 15, 6, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 21, 19, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 21, 19, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 4, 6, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 4, 6, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 19, 14, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 19, 14, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 7, 17, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 7, 17, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 22, 15, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 22, 15, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 0, 19, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 0, 19, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 18, 5, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 18, 5, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 19, 11, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 19, 11, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 16, 18, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 16, 18, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 5, 0, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 5, 0, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 17, 14, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 17, 14, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 18, 4, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 18, 4, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 19, 9, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 19, 9, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 2, 20, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 2, 20, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 6, 17, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 6, 17, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 18, 16, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 18, 16, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 6, 4, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 6, 4, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 18, 21, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 18, 21, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 24, 3, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 24, 3, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 2, 12, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 2, 12, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 17, 22, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 17, 22, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 15, 4, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 15, 4, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 0, 10, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 0, 10, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 17, 26, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 17, 26, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 22, 12, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 22, 12, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 1, 16, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 1, 16, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 15, 17, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 15, 17, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 15, 24, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 15, 24, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 16, 0, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 16, 0, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 15, 9, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 15, 9, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 10, 8, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 10, 8, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 9, 23, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 9, 23, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 17, 7, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 17, 7, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 23, 7, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 23, 7, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 17, 10, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 17, 10, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 5, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 5, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 13, 20, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 13, 20, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 16, 2, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 16, 2, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 1, 25, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 1, 25, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 11, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 11, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 13, 4, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 13, 4, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 11, 18, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 11, 18, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 25, 14, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 25, 14, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 16, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 16, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 4, 5, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 4, 5, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 16, 7, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 16, 7, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 10, 10, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 10, 10, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 2, 10, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 2, 10, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 6, 18, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 6, 18, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 1, 20, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 1, 20, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 17, 4, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 17, 4, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 3, 2, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 3, 2, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 13, 22, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 13, 22, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 7, 19, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 7, 19, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 17, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 17, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 18, 22, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 18, 22, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 26, 4, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 26, 4, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 5, 15, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 5, 15, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 24, 24, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 24, 24, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 12, 19, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 12, 19, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 16, 10, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 16, 10, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 1, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 1, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 25, 6, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 25, 6, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 26, 19, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 26, 19, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 20, 6, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 20, 6, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 18, 21, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 18, 21, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 22, 19, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 22, 19, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 7, 20, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 7, 20, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 4, 17, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 4, 17, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 4, 10, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 4, 10, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 1, 23, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 1, 23, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 4, 9, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 4, 9, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 5, 16, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 5, 16, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 4, 0, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 4, 0, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 14, 1, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 14, 1, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 2, 16, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 2, 16, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 7, 14, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 7, 14, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 16, 8, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 16, 8, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 11, 6, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 11, 6, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 3, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 3, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 11, 19, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 11, 19, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 14, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 14, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 18, 23, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 18, 23, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 19, 0, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 19, 0, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 8, 2, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 8, 2, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 2, 8, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 2, 8, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 18, 14, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 18, 14, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 9, 5, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 9, 5, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 6, 4, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 6, 4, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 5, 18, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 5, 18, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 14, 3, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 14, 3, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 11, 4, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 11, 4, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 21, 26, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 21, 26, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 3, 3, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 3, 3, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 16, 18, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 16, 18, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 4, 6, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 4, 6, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 13, 19, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 13, 19, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 1, 2, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 1, 2, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 10, 5, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 10, 5, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 3, 3, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 3, 3, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 7, 14, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 7, 14, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 6, 1, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 6, 1, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 13, 20, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 13, 20, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 10, 7, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 10, 7, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 19, 16, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 19, 16, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 21, 11, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 21, 11, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 17, 13, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 17, 13, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 22, 2, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 22, 2, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 3, 13, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 3, 13, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 14, 23, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 14, 23, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 9, 15, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 9, 15, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 12, 11, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 12, 11, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 21, 13, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 21, 13, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 12, 10, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 12, 10, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 24, 6, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 24, 6, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 16, 0, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 16, 0, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 19, 3, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 19, 3, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 16, 25, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 16, 25, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 6, 14, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 6, 14, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 14, 6, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 14, 6, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 7, 10, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 7, 10, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 4, 14, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 4, 14, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 13, 13, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 13, 13, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 24, 1, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 24, 1, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 15, 7, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 15, 7, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 9, 25, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 9, 25, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 23, 4, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 23, 4, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 22, 20, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 22, 20, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 2, 6, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 2, 6, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 7, 6, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 7, 6, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 3, 24, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 3, 24, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 20, 12, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 20, 12, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 6, 13, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 6, 13, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 1, 10, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 1, 10, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 7, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 7, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 5, 20, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 5, 20, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 10, 0, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 10, 0, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 15, 0, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 15, 0, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 4, 7, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 4, 7, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 2, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 2, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 7, 1, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 7, 1, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 16, 9, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 16, 9, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 8, 6, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 8, 6, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 19, 18, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 19, 18, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 11, 15, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 11, 15, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 4, 19, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 4, 19, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 6, 16, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 6, 16, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 20, 3, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 20, 3, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 22, 25, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 22, 25, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 24, 18, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 24, 18, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 26, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 26, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 22, 0, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 22, 0, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 5, 11, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 5, 11, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 18, 16, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 18, 16, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 9, 11, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 9, 11, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 15, 6, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 15, 6, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 9, 23, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 9, 23, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 19, 24, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 19, 24, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 7, 24, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 7, 24, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 18, 5, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 18, 5, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	printf("Game Over\n");
	printScoreBoard(g);
}//End case 0

	if(caseNum == 1){
	k = kingdomCards(22, 17, 13, 16, 18, 25, 23, 11, 7, 12);
	initializeGame(4, k, 1862839871, g);

	printState(g, gcpy);

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 3, 10, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 3, 10, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 22, 13, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 22, 13, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 9, 7, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 9, 7, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 8, 13, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 8, 13, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 12, 6, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 12, 6, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 3, 15, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 3, 15, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 17, 20, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 17, 20, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 10, 5, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 10, 5, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 26, 3, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 26, 3, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 21, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 21, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 9, 5, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 9, 5, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 19, 20, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 19, 20, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 15, 4, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 15, 4, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 22, 23, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 22, 23, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 11, 20, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 11, 20, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 7, 4, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 7, 4, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 19, 6, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 19, 6, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 23, 14, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 23, 14, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 23, 21, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 23, 21, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 26, 7, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 26, 7, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 23, 21, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 23, 21, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 13, 1, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 13, 1, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 14, 23, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 14, 23, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 12, 10, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 12, 10, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 25, 1, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 25, 1, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 25, 20, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 25, 20, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 14, 4, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 14, 4, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 18, 9, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 18, 9, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 22, 1, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 22, 1, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 14, 15, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 14, 15, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 6, 21, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 6, 21, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 1, 17, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 1, 17, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 22, 22, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 22, 22, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 3, 25, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 3, 25, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 9, 6, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 9, 6, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 4, 2, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 4, 2, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 21, 24, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 21, 24, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 10, 15, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 10, 15, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 16, 12, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 16, 12, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 2, 4, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 2, 4, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 10, 4, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 10, 4, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 25, 7, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 25, 7, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 19, 0, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 19, 0, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 13, 18, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 13, 18, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 5, 22, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 5, 22, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 17, 4, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 17, 4, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 1, 26, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 1, 26, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 1, 23, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 1, 23, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 22, 8, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 22, 8, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 8, 18, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 8, 18, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 16, 13, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 16, 13, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 15, 15, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 15, 15, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 25, 6, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 25, 6, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 0, 3, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 0, 3, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 2, 16, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 2, 16, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 13, 6, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 13, 6, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 3, 0, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 3, 0, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 18, 13, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 18, 13, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 14, 8, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 14, 8, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 26, 4, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 26, 4, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 15, 4, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 15, 4, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 9, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 9, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 15, 16, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 15, 16, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 12, 13, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 12, 13, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 3, 6, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 3, 6, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 7, 23, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 7, 23, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 20, 10, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 20, 10, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 26, 1, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 26, 1, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 8, 17, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 8, 17, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 5, 20, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 5, 20, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 8, 23, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 8, 23, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 12, 13, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 12, 13, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 19, 19, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 19, 19, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 14, 2, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 14, 2, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 24, 11, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 24, 11, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 4, 8, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 4, 8, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 12, 17, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 12, 17, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 22, 1, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 22, 1, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 2, 22, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 2, 22, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 10, 21, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 10, 21, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 1, 6, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 1, 6, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 22, 24, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 22, 24, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 9, 26, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 9, 26, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 23, 9, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 23, 9, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 25, 20, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 25, 20, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 3, 3, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 3, 3, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 24, 17, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 24, 17, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 9, 25, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 9, 25, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 6, 8, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 6, 8, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 1, 4, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 1, 4, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 18, 19, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 18, 19, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 25, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 25, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 2, 4, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 2, 4, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 16, 20, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 16, 20, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 23, 15, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 23, 15, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 24, 16, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 24, 16, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 23, 8, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 23, 8, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 11, 13, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 11, 13, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 10, 22, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 10, 22, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 22, 0, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 22, 0, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 5, 5, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 5, 5, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 20, 5, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 20, 5, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 5, 23, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 5, 23, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 9, 2, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 9, 2, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 7, 21, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 7, 21, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 3, 18, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 3, 18, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 13, 4, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 13, 4, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 13, 15, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 13, 15, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 1, 13, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 1, 13, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 12, 25, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 12, 25, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 13, 24, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 13, 24, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 20, 13, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 20, 13, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 11, 15, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 11, 15, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 1, 2, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 1, 2, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 19, 19, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 19, 19, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 10, 19, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 10, 19, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 8, 14, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 8, 14, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 14, 8, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 14, 8, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 12, 11, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 12, 11, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 0, 15, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 0, 15, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 2, 26, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 2, 26, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 16, 4, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 16, 4, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 11, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 11, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 18, 16, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 18, 16, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 21, 0, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 21, 0, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 16, 8, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 16, 8, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 18, 6, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 18, 6, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 23, 5, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 23, 5, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 26, 1, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 26, 1, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 16, 1, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 16, 1, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 26, 11, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 26, 11, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 16, 5, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 16, 5, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 2, 16, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 2, 16, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 23, 17, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 23, 17, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 22, 19, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 22, 19, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 7, 15, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 7, 15, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 21, 8, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 21, 8, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 7, 3, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 7, 3, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 25, 13, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 25, 13, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 1, 6, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 1, 6, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 26, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 26, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 3, 12, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 3, 12, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 4, 0, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 4, 0, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 24, 22, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 24, 22, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 24, 25, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 24, 25, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 24, 23, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 24, 23, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 12, 24, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 12, 24, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 4, 15, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 4, 15, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 7, 0, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 7, 0, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 13, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 13, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 24, 15, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 24, 15, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 8, 16, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 8, 16, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 9, 1, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 9, 1, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 13, 16, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 13, 16, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 2, 12, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 2, 12, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 8, 2, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 8, 2, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 4, 26, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 4, 26, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 3, 11, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 3, 11, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 15, 12, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 15, 12, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 25, 1, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 25, 1, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 22, 15, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 22, 15, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 16, 26, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 16, 26, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 2, 21, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 2, 21, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 3, 3, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 3, 3, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 5, 6, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 5, 6, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 23, 18, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 23, 18, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 20, 7, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 20, 7, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 9, 18, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 9, 18, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 22, 26, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 22, 26, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 1, 18, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 1, 18, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 12, 9, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 12, 9, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 20, 26, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 20, 26, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 1, 12, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 1, 12, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 1, 10, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 1, 10, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 2, 5, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 2, 5, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 20, 18, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 20, 18, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 19, 1, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 19, 1, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 5, 11, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 5, 11, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 22, 24, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 22, 24, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 10, 14, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 10, 14, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 17, 18, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 17, 18, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 4, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 4, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 20, 1, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 20, 1, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 13, 4, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 13, 4, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 4, 9, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 4, 9, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 9, 18, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 9, 18, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 8, 20, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 8, 20, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 6, 11, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 6, 11, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 20, 9, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 20, 9, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 22, 3, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 22, 3, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 22, 24, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 22, 24, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 17, 18, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 17, 18, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 12, 13, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 12, 13, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 25, 10, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 25, 10, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 18, 3, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 18, 3, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 4, 2, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 4, 2, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 10, 1, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 10, 1, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 24, 7, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 24, 7, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 25, 6, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 25, 6, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 3, 25, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 3, 25, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 14, 23, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 14, 23, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 6, 12, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 6, 12, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 1, 24, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 1, 24, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 10, 8, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 10, 8, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 24, 3, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 24, 3, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 4, 0, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 4, 0, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 17, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 17, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 10, 23, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 10, 23, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 20, 4, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 20, 4, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 22, 24, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 22, 24, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 26, 8, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 26, 8, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 19, 23, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 19, 23, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 21, 9, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 21, 9, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 1, 23, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 1, 23, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 7, 5, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 7, 5, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 26, 11, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 26, 11, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 10, 25, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 10, 25, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 6, 15, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 6, 15, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 2, 20, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 2, 20, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 16, 22, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 16, 22, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 20, 10, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 20, 10, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 9, 20, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 9, 20, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 9, 14, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 9, 14, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 20, 15, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 20, 15, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 9, 0, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 9, 0, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 0, 8, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 0, 8, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 9, 23, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 9, 23, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 25, 12, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 25, 12, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 25, 23, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 25, 23, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 16, 2, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 16, 2, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 0, 11, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 0, 11, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 11, 12, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 11, 12, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 4, 6, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 4, 6, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 2, 6, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 2, 6, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 15, 18, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 15, 18, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 9, 21, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 9, 21, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 8, 21, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 8, 21, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 3, 5, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 3, 5, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 19, 20, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 19, 20, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 13, 2, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 13, 2, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 1, 2, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 1, 2, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 9, 25, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 9, 25, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 7, 13, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 7, 13, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 19, 2, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 19, 2, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 25, 13, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 25, 13, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 15, 24, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 15, 24, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 21, 19, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 21, 19, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 12, 7, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 12, 7, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 7, 12, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 7, 12, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 17, 22, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 17, 22, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 16, 20, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 16, 20, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 9, 15, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 9, 15, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 24, 18, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 24, 18, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 14, 11, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 14, 11, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 23, 4, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 23, 4, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 16, 21, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 16, 21, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 26, 21, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 26, 21, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 10, 20, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 10, 20, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 16, 2, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 16, 2, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 6, 0, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 6, 0, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 5, 5, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 5, 5, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 3, 24, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 3, 24, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 21, 10, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 21, 10, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 5, 21, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 5, 21, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 4, 0, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 4, 0, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 20, 2, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 20, 2, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 14, 15, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 14, 15, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 21, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 21, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 9, 22, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 9, 22, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 11, 9, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 11, 9, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 24, 18, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 24, 18, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 9, 1, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 9, 1, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 2, 26, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 2, 26, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 5, 11, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 5, 11, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 25, 0, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 25, 0, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 18, 13, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 18, 13, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 24, 0, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 24, 0, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 15, 8, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 15, 8, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 5, 19, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 5, 19, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 5, 2, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 5, 2, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 13, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 13, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 20, 20, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 20, 20, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 8, 0, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 8, 0, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 2, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 2, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 7, 15, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 7, 15, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 17, 17, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 17, 17, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 22, 7, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 22, 7, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 12, 15, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 12, 15, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 11, 23, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 11, 23, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 20, 10, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 20, 10, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 16, 22, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 16, 22, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 12, 16, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 12, 16, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 19, 7, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 19, 7, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 25, 21, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 25, 21, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 2, 9, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 2, 9, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 15, 9, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 15, 9, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 1, 9, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 1, 9, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 13, 8, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 13, 8, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 0, 23, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 0, 23, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 2, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 2, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 5, 0, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 5, 0, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 7, 21, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 7, 21, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 22, 5, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 22, 5, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 15, 21, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 15, 21, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 20, 14, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 20, 14, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 12, 13, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 12, 13, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 3, 21, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 3, 21, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 19, 1, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 19, 1, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 0, 15, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 0, 15, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 16, 19, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 16, 19, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 6, 3, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 6, 3, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 1, 9, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 1, 9, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 3, 11, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 3, 11, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 9, 8, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 9, 8, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 0, 7, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 0, 7, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 23, 16, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 23, 16, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 14, 24, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 14, 24, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 9, 18, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 9, 18, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 26, 1, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 26, 1, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 4, 1, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 4, 1, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 13, 14, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 13, 14, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 10, 0, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 10, 0, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 16, 18, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 16, 18, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 3, 13, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 3, 13, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 9, 3, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 9, 3, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 24, 9, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 24, 9, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 26, 8, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 26, 8, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 17, 22, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 17, 22, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 18, 5, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 18, 5, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 8, 20, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 8, 20, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 13, 3, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 13, 3, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 19, 25, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 19, 25, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 26, 23, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 26, 23, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 17, 24, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 17, 24, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 10, 14, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 10, 14, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 9, 21, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 9, 21, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 7, 14, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 7, 14, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 3, 0, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 3, 0, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 7, 9, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 7, 9, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 5, 12, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 5, 12, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 8, 12, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 8, 12, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 11, 21, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 11, 21, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 0, 22, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 0, 22, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 18, 3, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 18, 3, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 9, 23, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 9, 23, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 17, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 17, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 8, 23, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 8, 23, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 9, 6, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 9, 6, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 6, 3, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 6, 3, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 22, 1, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 22, 1, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 22, 18, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 22, 18, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 22, 12, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 22, 12, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 3, 21, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 3, 21, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 13, 6, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 13, 6, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 13, 14, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 13, 14, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 26, 8, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 26, 8, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 23, 19, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 23, 19, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 20, 18, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 20, 18, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 8, 11, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 8, 11, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 19, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 19, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 7, 24, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 7, 24, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 7, 20, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 7, 20, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 21, 0, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 21, 0, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 7, 3, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 7, 3, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 0, 22, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 0, 22, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 3, 12, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 3, 12, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 13, 17, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 13, 17, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 26, 2, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 26, 2, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 8, 19, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 8, 19, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 14, 13, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 14, 13, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 26, 9, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 26, 9, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 11, 21, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 11, 21, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 2, 25, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 2, 25, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 5, 18, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 5, 18, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 7, 6, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 7, 6, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 7, 13, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 7, 13, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 9, 8, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 9, 8, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 19, 8, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 19, 8, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 4, 17, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 4, 17, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 24, 17, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 24, 17, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 4, 20, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 4, 20, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 25, 0, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 25, 0, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 19, 3, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 19, 3, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 5, 12, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 5, 12, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 5, 1, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 5, 1, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 0, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 0, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 3, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 3, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 11, 14, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 11, 14, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 18, 20, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 18, 20, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 20, 15, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 20, 15, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 25, 14, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 25, 14, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 3, 20, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 3, 20, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 20, 23, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 20, 23, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 4, 14, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 4, 14, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 17, 8, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 17, 8, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 5, 5, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 5, 5, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 16, 9, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 16, 9, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 10, 20, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 10, 20, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 9, 25, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 9, 25, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 13, 25, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 13, 25, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 20, 2, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 20, 2, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 17, 11, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 17, 11, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 6, 15, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 6, 15, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 1, 7, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 1, 7, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 20, 14, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 20, 14, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 11, 23, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 11, 23, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 20, 13, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 20, 13, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 2, 1, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 2, 1, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 3, 5, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 3, 5, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 23, 5, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 23, 5, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 5, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 5, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 8, 13, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 8, 13, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 26, 10, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 26, 10, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 7, 15, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 7, 15, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 25, 18, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 25, 18, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 20, 20, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 20, 20, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 4, 11, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 4, 11, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 16, 2, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 16, 2, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 21, 19, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 21, 19, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 23, 14, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 23, 14, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 10, 6, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 10, 6, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 8, 23, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 8, 23, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 7, 9, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 7, 9, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 11, 7, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 11, 7, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 20, 6, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 20, 6, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 10, 13, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 10, 13, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 11, 3, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 11, 3, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 17, 26, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 17, 26, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 8, 23, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 8, 23, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 8, 18, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 8, 18, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 15, 2, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 15, 2, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 5, 7, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 5, 7, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 13, 0, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 13, 0, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 15, 3, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 15, 3, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 11, 8, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 11, 8, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 2, 10, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 2, 10, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 0, 7, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 0, 7, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 20, 14, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 20, 14, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 1, 7, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 1, 7, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 6, 23, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 6, 23, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 8, 14, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 8, 14, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 18, 12, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 18, 12, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 0, 3, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 0, 3, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 12, 26, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 12, 26, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 19, 7, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 19, 7, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 9, 13, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 9, 13, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 12, 6, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 12, 6, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 12, 18, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 12, 18, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 9, 15, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 9, 15, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 18, 17, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 18, 17, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 25, 16, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 25, 16, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 13, 16, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 13, 16, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 19, 16, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 19, 16, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 18, 0, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 18, 0, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 25, 0, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 25, 0, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 0, 11, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 0, 11, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 5, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 5, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 2, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 2, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 26, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 26, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 9, 1, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 9, 1, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 22, 1, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 22, 1, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 12, 13, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 12, 13, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 4, 8, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 4, 8, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 22, 23, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 22, 23, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 10, 19, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 10, 19, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 16, 25, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 16, 25, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 24, 6, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 24, 6, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 13, 0, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 13, 0, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 7, 5, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 7, 5, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 16, 20, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 16, 20, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 3, 8, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 3, 8, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 14, 5, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 14, 5, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 7, 2, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 7, 2, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 17, 10, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 17, 10, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 7, 18, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 7, 18, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 22, 13, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 22, 13, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 25, 12, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 25, 12, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 16, 7, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 16, 7, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 9, 24, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 9, 24, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 16, 10, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 16, 10, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 5, 23, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 5, 23, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 0, 20, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 0, 20, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 19, 4, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 19, 4, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 8, 21, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 8, 21, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 16, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 16, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 24, 8, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 24, 8, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 2, 15, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 2, 15, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 20, 23, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 20, 23, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 26, 16, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 26, 16, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 20, 2, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 20, 2, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 5, 20, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 5, 20, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 11, 2, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 11, 2, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 17, 4, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 17, 4, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 17, 26, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 17, 26, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 22, 10, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 22, 10, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 10, 22, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 10, 22, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 20, 1, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 20, 1, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 18, 3, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 18, 3, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 22, 24, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 22, 24, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 6, 23, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 6, 23, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 22, 18, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 22, 18, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 18, 26, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 18, 26, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 18, 8, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 18, 8, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 23, 8, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 23, 8, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 25, 13, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 25, 13, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 14, 19, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 14, 19, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 8, 11, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 8, 11, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 0, 1, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 0, 1, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 0, 11, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 0, 11, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 2, 10, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 2, 10, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 9, 22, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 9, 22, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 8, 19, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 8, 19, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 23, 26, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 23, 26, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 13, 7, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 13, 7, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 17, 6, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 17, 6, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 21, 16, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 21, 16, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 18, 5, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 18, 5, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 8, 17, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 8, 17, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 9, 0, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 9, 0, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 18, 26, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 18, 26, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 17, 22, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 17, 22, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(2, g);
	printf("#Card attempted to buy: ");
	printCardName(2);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 14, 6, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 14, 6, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 21, 23, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 21, 23, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 25, 13, 23, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 25, 13, 23, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 12, 0, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 12, 0, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 14, 13, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 14, 13, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 8, 13, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 8, 13, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 20, 0, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 20, 0, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 17, 19, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 17, 19, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 14, 25, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 14, 25, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 7, 19, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 7, 19, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 25, 1, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 25, 1, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 24, 2, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 24, 2, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 18, 20, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 18, 20, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 17, 10, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 17, 10, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 11, 24, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 11, 24, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 10, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 10, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 10, 4, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 10, 4, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 6, 6, 19, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 6, 6, 19, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 1, 2, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 1, 2, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 13, 25, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 13, 25, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 17, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 17, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 14, 15, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 14, 15, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 5, 25, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 5, 25, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(17, g);
	printf("#Card attempted to buy: ");
	printCardName(17);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 24, 2, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 24, 2, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 25, 25, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 25, 25, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 0, 6, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 0, 6, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 22, 6, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 22, 6, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 23, 12, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 23, 12, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 18, 10, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 18, 10, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 18, 24, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 18, 24, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 23, 18, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 23, 18, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 9, 7, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 9, 7, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 20, 14, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 20, 14, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 4, 24, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 4, 24, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 18, 13, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 18, 13, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 23, 2, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 23, 2, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 3, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 3, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(3, g);
	printf("#Card attempted to buy: ");
	printCardName(3);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 20, 8, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 20, 8, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 8, 13, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 8, 13, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 23, 15, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 23, 15, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 6, 5, 18, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 6, 5, 18, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 16, 6, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 16, 6, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 19, 17, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 19, 17, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 4, 5, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 4, 5, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 23, 8, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 23, 8, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 16, 6, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 16, 6, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 9, 5, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 9, 5, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 11, 15, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 11, 15, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 12, 26, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 12, 26, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 9, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 9, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 18, 26, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 18, 26, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 0, 6, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 0, 6, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 20, 23, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 20, 23, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 5, 9, 4, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 5, 9, 4, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 5, 7, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 5, 7, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 5, 25, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 5, 25, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 8, 15, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 8, 15, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 17, 23, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 17, 23, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 6, 17, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 6, 17, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 13, 21, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 13, 21, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 0, 17, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 0, 17, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 3, 19, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 3, 19, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 5, 10, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 5, 10, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 22, 0, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 22, 0, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 2, 24, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 2, 24, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 0, 4, 17, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 0, 4, 17, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 2, 20, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 2, 20, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 3, 4, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 3, 4, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 11, 18, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 11, 18, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 23, 16, 11, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 23, 16, 11, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 12, 18, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 12, 18, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 14, 24, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 14, 24, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 3, 3, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 3, 3, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 7, 16, 10, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 7, 16, 10, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 7, 23, 2, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 7, 23, 2, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 19, 12, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 19, 12, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 8, 7, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 8, 7, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 21, 9, 26, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 21, 9, 26, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 17, 25, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 17, 25, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 7, 11, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 7, 11, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(5, g);
	printf("#Card attempted to buy: ");
	printCardName(5);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 9, 16, 0, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 9, 16, 0, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 12, 12, 13, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 12, 12, 13, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(16, g);
	printf("#Card attempted to buy: ");
	printCardName(16);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(0, g);
	printf("#Card attempted to buy: ");
	printCardName(0);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 19, 24, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 19, 24, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(13, g);
	printf("#Card attempted to buy: ");
	printCardName(13);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 3, 20, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 3, 20, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 9, 13, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 9, 13, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(1, g);
	printf("#Card attempted to buy: ");
	printCardName(1);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 10, 18, 3, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 10, 18, 3, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(6, g);
	printf("#Card attempted to buy: ");
	printCardName(6);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 4, 14, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 4, 14, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 22, 18, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 22, 18, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 20, 5, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 20, 5, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(15, g);
	printf("#Card attempted to buy: ");
	printCardName(15);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 20, 23, 6, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 20, 23, 6, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(24, g);
	printf("#Card attempted to buy: ");
	printCardName(24);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 11, 9, 5, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 11, 9, 5, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(12, g);
	printf("#Card attempted to buy: ");
	printCardName(12);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 24, 12, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 24, 12, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 20, 15, 22, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 20, 15, 22, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(22, g);
	printf("#Card attempted to buy: ");
	printCardName(22);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 10, 2, 20, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 10, 2, 20, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(4, 9, 21, 15, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][4]);
	printResult(result);
	printf("playCard(4, 9, 21, 15, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(19, g);
	printf("#Card attempted to buy: ");
	printCardName(19);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(11, g);
	printf("#Card attempted to buy: ");
	printCardName(11);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(21, g);
	printf("#Card attempted to buy: ");
	printCardName(21);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(9, g);
	printf("#Card attempted to buy: ");
	printCardName(9);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(23, g);
	printf("#Card attempted to buy: ");
	printCardName(23);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 16, 10, 7, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 16, 10, 7, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(7, g);
	printf("#Card attempted to buy: ");
	printCardName(7);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 13, 9, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 13, 9, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(25, g);
	printf("#Card attempted to buy: ");
	printCardName(25);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 5, 6, 14, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 5, 6, 14, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 14, 26, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 14, 26, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(20, g);
	printf("#Card attempted to buy: ");
	printCardName(20);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(3, 1, 1, 21, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][3]);
	printResult(result);
	printf("playCard(3, 1, 1, 21, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 9, 7, 1, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 9, 7, 1, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 5, 7, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 5, 7, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(4, g);
	printf("#Card attempted to buy: ");
	printCardName(4);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(14, g);
	printf("#Card attempted to buy: ");
	printCardName(14);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = endTurn(g);
	printf("#Attempt EndTurn \n");
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 21, 24, 9, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 21, 24, 9, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 0, 1, 24, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 0, 1, 24, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(10, g);
	printf("#Card attempted to buy: ");
	printCardName(10);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(1, 2, 14, 8, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][1]);
	printResult(result);
	printf("playCard(1, 2, 14, 8, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(8, g);
	printf("#Card attempted to buy: ");
	printCardName(8);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 2, 2, 16, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 2, 2, 16, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 19, 8, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 19, 8, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(26, g);
	printf("#Card attempted to buy: ");
	printCardName(26);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(0, 3, 10, 12, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][0]);
	printResult(result);
	printf("playCard(0, 3, 10, 12, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = playCard(2, 0, 23, 25, g);
	printf("#Card attempted to play: ");
	printCardName(gcpy->hand[gcpy->whoseTurn][2]);
	printResult(result);
	printf("playCard(2, 0, 23, 25, g)\n");
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	result = buyCard(18, g);
	printf("#Card attempted to buy: ");
	printCardName(18);
	printResult(result);
	if (stateChanged(g, gcpy)){
		printState(g, gcpy);
	}

	printf("Game Over\n");
	printScoreBoard(g);
}//End case 1

}