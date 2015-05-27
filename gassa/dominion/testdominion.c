#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void getChoices(int card, int *choices, struct gameState *game){
	int badCard = 1;
	int maxValue = 0;
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
		case remodel:
			//first, check for a valid choice
			for(int i = 0;i<numHandCards(game);i++){
				maxValue = max(maxValue,getCost(handCard(i,game)));
			}
			for(int i = curse; i=<gold;i++){
				if(getCost(i) > (maxValue+2)) continue;
				else if(supplyCount(i) > 0) badCard = 0;
			}
			if(badCard) return;
			else{
				choices[0] = rand() % numHandCards(game);
				choices[1] = rand() % (treasure_map+1);
				while(!())
			}
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
					choices = getChoices(handCard(cardChoice,game),choices);
					printf("Associated choices, -1 means unused:\n");
					for(i=0,i<sizeof(choices)/sizeof(int),i++){
						printf("Choice %d: %d\n",i+1,choices[i],game);
					}
				}
				game->numActions--;
			}
			
		}
		
		free(game);
	}
}