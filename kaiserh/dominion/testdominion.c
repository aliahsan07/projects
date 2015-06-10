#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
//GLOBALS
int k[10];
//DEFINES
#define TEST_COUNT 50
//PROTOTYPES
void turn_logic(struct gameState*, int, FILE*);
void run_game_test(struct gameState*, int, FILE*);
void seeder_loop(struct gameState*, FILE*);

void print_state(struct gameState* ts, FILE* fp){
	fprintf(fp, "Current Player: %d\n", whoseTurn(ts));
	fprintf(fp, "Handcount: %d\n", ts->handCount[whoseTurn(ts)]);
	fprintf(fp, "Coins: %d\n", ts->coins);
	fprintf(fp, "DeckCount: %d\n", ts->deckCount[whoseTurn(ts)]);
	fprintf(fp, "DiscardCount: %d\n", ts->discardCount[whoseTurn(ts)]);
	fprintf(fp, "numActions: %d\n", ts->numActions);
	fprintf(fp, "playedCardCount: %d\n", ts->playedCardCount);
}
//MAIN

int main (int argc, char *argv[]){
	struct gameState testState;
	struct gameState *ts = &testState;
	FILE *fp;
	srand(0);
	fp = fopen(argv[1], "w");
	if (fp == NULL){
		perror("FILE OPEN FAILED\n");
		return 0;
	}	
	seeder_loop(ts, fp);
	fclose(fp);
	return 0;
}
void seeder_loop(struct gameState* ts, FILE* fp){
	int seed, count;
	fprintf(fp, "Begin Test Run...\n");	
	for(count = 0; count < TEST_COUNT; count++){	
		seed = (((count + 1) * 2) * (count + 1) * (count + 1));
		fprintf(fp, "*****START Game %d*****\n", count+1);		
		run_game_test(ts, seed, fp);
		fprintf(fp, "*****END GAME %d*****\n", count+1);		
	}
	fprintf(fp, "End Test Run.\n");
}

void run_game_test(struct gameState* ts, int seed, FILE* gr){
	//int k[10];
	int ref[20] = {0};
	int check, i, score[MAX_PLAYERS];
	memset(ts, 0, sizeof(struct gameState));
	int players = ((rand() % 3) + 2);
	//DEBUG
	//DISABLING TRIBUTE
	ref[12] = 1;
	//DISABLING STEWARD
	ref[18] = 1;
	for(i = 0; i < 10; i++){
		while(1){
			k[i] = ((rand() % 20) + 7);
			if(ref[k[i]-7] != 1){
				ref[k[i]-7] = 1;
				break;
			}
		}
	}
	memset(ref, 0, sizeof(ref));
	check = initializeGame(players, k, seed, ts);
	if (check == -1)
		fprintf(gr, "INIT_FAIL\n");
	else{
		fprintf(gr, "Seed: %d\nPlayers: %d\n", seed, players);
		fprintf(gr, "Kingdom Cards: ");
		for (i = 0; i < 10; i++){
			fprintf(gr, "%d ", k[i]);
		}
		fprintf(gr, "\n");
	}
	int x = 0;
	while(!isGameOver(ts) || x == 100){
		for(i = 0; i < players; i++){
			turn_logic(ts, i, gr);
		}
		x++;
	}
	getWinners(score, ts);
	for(i = 0; i < players; i++)
		fprintf(gr, "Player %d: %d ", i+1, score[i]);
	fprintf(gr, "\n");
}

void turn_logic(struct gameState* ts, int p, FILE* gr){
	int i, check, bonus = 0;
	int flip = rand() % 3;
	int k_flip = rand() % 10;
	int c1 = MAX_DECK + 1;
	int c2 = MAX_DECK + 1;
	int c3 = MAX_DECK + 1;
	fprintf(gr, "ACTION\n");
	print_state(ts, gr);	
	while(ts->numActions > 0){
		for(i = 0; i < ts->handCount[p]; i++){
			
			if ((ts->hand[p][i] - 7) > 0){
				fprintf(gr, "Played Card: %d\n", ts->hand[p][i]);			
				do{
					c1 = rand() % ts->handCount[p];
				}while(c1 == i);
				do{
					c2 = rand() % ts->handCount[p];
				}while(c2 == i);
				do{
					c3 = rand() % ts->handCount[p];
				}while(c3 == i);

				check = playCard(i, c1, c2, c3, ts);
				if (check == -1){
					discardCard(i, p, ts, 0);
				}
				break;
			}
		}
		if(i >= ts->handCount[p])
			break;
	}
	fprintf(gr, "BUY\n");
	print_state(ts, gr);
	if (ts->coins == 0)
		updateCoins(p, ts, bonus);
	if(ts->coins > 3 && flip == 1){
		check = buyCard(gold, ts);
		check = buyCard(silver, ts);
	}
	else if (ts->coins > 3 && flip == 0){
		for(i = 0; i < 10; i++){
			if((k_flip + i) > 9)
				k_flip = (i-(2*i));
			if (getCost(k[k_flip + i]) < ts->coins){
				check = buyCard((k[k_flip+i]), ts);
			}
		}
	}
	else if (ts->coins > 3 && flip == 2){
		buyCard(province, ts);
		buyCard(duchy, ts);
		buyCard(estate, ts);
	}
	fprintf(gr, "END\n");
	print_state(ts, gr);	
	endTurn(ts);
}
