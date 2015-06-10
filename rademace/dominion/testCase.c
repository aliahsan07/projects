#include "testFunctions.h" 
int main (int argc, char** argv) { 
	struct gameState G; 
	struct gameState *p = &G; 
	int money; 
	int player; 
	int numPlayers;

	int k[10] = {11, 20, 26, 10, 14, 15, 16, 12, 18, 9};
	numPlayers = 2;
	initializeGame(numPlayers, k, 16, p);
	money = countMoney(p);
	player = whoseTurn(p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(20, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(18, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(18, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(2, 1, 1, 1, p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(12, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(14, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(2, 1, 1, 1, p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(gold, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(14, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(0, 0, duchy, -1, p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(0, 1, 1, 1, p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(province, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(20, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(16, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(16, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(12, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(15, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(1, 1, 1, 1, p);
	buyCard(20, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(gold, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(3, 0, 1, 1, p);
	buyCard(20, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(1, 1, 1, 1, p);
	buyCard(12, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(4, 1, 1, 1, p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(10, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(0, 0, duchy, -1, p);
	buyCard(18, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(20, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(province, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(1, 0, duchy, -1, p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(duchy, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(3, 1, 1, 1, p);
	buyCard(16, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(1, 0, 1, 1, p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(gold, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(16, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(20, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(province, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(20, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(18, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(1, 0, 1, 1, p);
	buyCard(14, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(province, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(12, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(4, 1, 1, 1, p);
	buyCard(16, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(18, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(1, 1, 1, 1, p);
	buyCard(gold, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(12, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(1, 1, 1, 1, p);
	playCard(3, 1, 1, 1, p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(gold, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(14, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(province, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(0, 0, duchy, -1, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(province, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(20, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(11, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(0, 1, 1, 1, p);
	playCard(3, 1, 1, 1, p);
	buyCard(14, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(province, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	playCard(1, 0, 1, 1, p);
	buyCard(silver, p);
	endTurn(p);

	money = countMoney(p);
	player = whoseTurn(p);
	buyCard(province, p);
	endTurn(p);

	return 0;
}