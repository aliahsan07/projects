#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void getChoices(int card, int *choices, struct gameState *game, int cardChoice){
	int badCard = 1;
	int maxValue = 0;
	int notChosen = 1;
	for(int i = 0; i<sizeof(choices)/sizeof(int),i++){
		choices[i] = -1;
	}
	switch(card) {
		case feast:
			//first, check for a valid choice
			for(int i = curse; i=<gold;i++){
				if(getCost(i) > 5) continue;
				else if(supplyCount(i) > 0) badCard = 0;
			}
			if(badCard) return;
			else {
				choices[0] = rand() % (gold + 1);
				while(!((supplyCount(choices[0]) > 0) && (getCost(choices[0]) =< 5))){
					choices[0] = rand() % (gold + 1);
				}
			}
			break;
		case mine:
			//first, check for a coin
			for(int i = 0; i<numHandCards(game);i++){
				if(handCard(i,game) >= copper && handCard(i,game) <= gold) badCard = 0;
			}
			if(badCard) return;
			else{
				choices[0] = rand() % numHandCards(game);
				while(handCard(choices[0]) < copper || handCard(choices[0]) > gold){
					choices[0] = rand() % numHandCards(game);
				}
				if(handCard(choices[0]) == copper) choices[1] = rand() % 1 + copper;
				else choices[1] = rand % 2 + copper;
			}
			break;
		case remodel:
			//first, check for a valid choice
			for(int i = 0;i<numHandCards(game);i++){
				if(handCard(i,game) == remodel) continue;
				else maxValue = max(maxValue,getCost(handCard(i,game)));
			}
			for(int i = curse; i=<gold;i++){
				if(getCost(i) > (maxValue+2)) continue;
				else if(supplyCount(i) > 0) badCard = 0;
			}
			if(badCard) return;
			else{
				choices[0] = rand() % numHandCards(game);
				choices[1] = rand() % 17;
				while(notChosen){
					if(choices[1] < 7){
						if(getCost(handCard(choices[0],game)) >= getCost(choices[1])-2) notChosen = 0;
						else if(getCost(handCard(choices[0])) >= getCost(k[choices[1]-7])-2) notChosen = 0;
						else {
							choices[0] = rand() % numHandCards(game);
							choices[1] = rand() % 17;
						}
					}
					
				}
			}
			break;
		case baron:
			for(int i = 0; i<numHandCards(game);i++){
				if(handCard(i,game) >= estate && handCard(i,game) <= province) badCard=0;
			}
			if(badCard) choices[0] = 0;
			else choices[0] = 1;
			break;
		case minion:
			choices[0] = (rand() % 2) + 1;
			break;
		case steward:
			choices[0] = (rand() % 3) + 1;
			if(choices[0] == 3) {
				while(choices[1] == -1 || choices[1] == cardChoice) {
					choices[1] = rand() % numHandCard(game);
				}
				while(choices[2] == -1 || choices[2] == cardChoice || choices[2] == choices[1]){
					choices[2] = rand() % numHandCard(game);
				}
			}
			break;
		case ambassador:
			while(choices[0] == -1 || choices[0] == cardChoice) {
				choices[0] = rand() % numHandCard(game);
			}
			for(int i = 0; i<numHandCards(game);i++){
				if(handCard(i,game) == handCard(choices[0],game)) maxValue++;
			}
			choices[1] = (rand() % min(maxValue+1,3))
		case embargo:
			choices[0] = rand() % (gold+1);
			break;
		case salvager:
			while(choices[0] == -1 || choices[0] == cardChoice) {
				choices[0] = rand() % numHandCard(game);
			}
			break;
		default:
		break;
	}
}
//Max time in minutes
#define MAX_TIME 10
int main() {
	int time;
	int gamesPlayed = 0;
	int c, i, j, r;
	//these 2 are bools
	int cardPresent;
	int canPlayCard;
	
	int turns;
	int players;
	int cardChoice;
	int choices[3];
	int coins;
	const char *allCards[treasure_map+1] = {"curse","estate","duchy","province",
											"copper","silver","gold",
				"adventurer","council_room","feast","gardens","mine","remodel","smithy","village",
				"baron","great_hall","minion","steward","tribute",
	"ambassador","cutpurse","embargo","outpost","salvager","sea_hag","treasure_map"};
	int k[10] = {0};
	struct gameState *game;
	
	srand(time(NULL));
	
	time = clock();
	while(MAX_TIME*60>difftime(now,time)){
		game = newGame();
		turns = 0;
		players = (rand() % 3) + 2;
		seed = rand();
		//build a set of 10 cards for play
		i=0;
		while(i<10){
			c = (rand() % (treasure_map-adventurer)) + adventurer;
			cardPresent = 0;
			for(j = 0;j<i;j++){
				if(k[j]=c){
					cardPresent = 1;
				}
			}
			if(cardPresent == 1) continue;
			else{
				k[i] = c;
				i++
			}
		}
		r = initializeGame(players,k,seed,game));
		if(r == 0) {
			printf("Game started.\n");
			printf("Seed: %d\n",seed);
			printf("Players: %d\n", players);
			printf("Cardset:\n");
			for(i=0;i<10;i++){
				printf("%s\n",allCards[k[i]]);
			}
		}
		else{
			printf("Game failed to initialize!\n");
			free(game);
			continue;
		}
		while(!isGameOver(game)){
			printf("Turns taken: %d\n",turns);
			printf("gameState readout for this turn:\n");
			printf("whoseTurn: %d\n",game->whoseTurn);
			printf("phase: %d\n",game->phase);
			printf("numActions: %d\n",game->numActions);
			printf("coins: %d\n",game->coins);
			printf("numBuys: %d\n",game->numBuys);
			printf("phase: %d\n",game->phase);
			
			printf("Player specific:\n");
			printf("Hand Count: %d\n",numHandCards(game));
			printf("Player hand:\n");
			for(i=0;i<numHandCards(game);i++){
				printf("%s\n",allCards[handCard(i,game)]);
			}
			
			printf("Deck Count: %d\n",game->deckCount[whoseTurn(game)]);
			printf("Player deck:\n");
			for(i=0;i<game->deckCount[whoseTurn(game)]);i++){
				printf("%s\n",allCards[handCard(i,game)]);
			}
			
			printf("Discard Count: %d\n",game->discardCount[whoseTurn(game)]);
			printf("Player discard:\n");
			for(i=0;i<game->discardCount[whoseTurn(game)]);i++){
				printf("%s\n",allCards[game->discard[whoseTurn(game)][i]]);
			}
			
			while(game->numActions!=0){
				canPlayCard = 0;
				for(i=0;i<numHandCards(game);i++){
					if(handCard(i,game) >= 7) canPlayCard = 1;
				}
				if(canPlayCard) {
					cardChoice = rand() % numHandCards(game);
					while(handCard(cardChoice,game) < 7){
						cardChoice = rand() % numHandCards(game);
					}
					printf("Playing Card: %s",allCards[handCard(cardChoice,game)]);
					choices = getChoices(handCard(cardChoice,game),choices,cardChoice);
					printf("Associated choices, -1 means unused:\n");
					for(i=0,i<sizeof(choices)/sizeof(int),i++){
						printf("Choice %d: %d\n",i+1,choices[i],game);
					}
					r = playCard(cardChoice,choices[0],choices[1],choices[2],game);
					if(r == 0) printf("Card successfully played.\n");
					else printf("There was an error playing the card.\n");
				}
				else game->numActions--; //this will break the while loop if no cards can play
			}
			
			while(game->numBuys != 0){
				coins = 0;
				cardChoice = -1;
				for(i = 0;i<numHandCards(game);i++){
					if(handCard(i,game) == copper) coins = coins + 1;
					if(handCard(i,game) == silver) coins = coins + 2;
					if(handCard(i,game) == gold) coins = coins + 3;
				}
				//I know you CAN buy curses, but I'm going to pretend you can't.
				if(coins < 2) game->numBuys--; //this will break the loop for no buys 
				else {
					while(cardChoice == -1 || getCost(cardChoice) > coins){
						cardChoice = rand() % 17;
						if(cardChoice > gold) cardChoice = k[cardChoice-gold];
					}
					r = buyCard(cardChoice,game);
					if(r == 0) printf("Bought %s for %d.\n",allCards[cardChoice],getCost(cardChoice));
					else printf("Error buying %s.\n",allCards[cardChoice]);
				}
			}
			endTurn(game);
		}
		
		free(game);
	}
}