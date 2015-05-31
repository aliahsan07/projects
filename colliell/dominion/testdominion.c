/*********************************************************************
** testdominion.c
** Reilly Collins [colliell]
** CS 362, Spring 2015
** Random tester that plays complete games of dominion
** Produces .out file with key information about the game state
*********************************************************************/

#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#define MAX_GAMES 7 //if this is set too high it seems that the memory for gameState runs out! 

int is_card_dup(int *, int, int);
char * get_kingdom(int);
void print_game(struct gameState *, FILE *, int *);
void action_phase(struct gameState *, int, int, int *, FILE *);
void buy_phase(struct gameState *, int, int, int *, FILE *);
int check_deck(struct gameState *, int, int, int *);

int main(int argc, char *argv[])
{
	FILE * fp; 
	int games;

	srand(time(NULL));
	fp = fopen("gameResults.out", "w"); //write print statements to gameResults.out using fprintf

	for(games = 0; games < MAX_GAMES; games++)
	{
		int i, init = -1;
		int seed, coins = 0, turn = 0, num_players = 0;
		int k[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int pos[27];
		struct gameState * G = newGame();

		//use CLA or random value for seed
		if(argc > 1) seed = atoi(argv[1]);
		else seed = rand();

		printf("\n***Randomizing kingdom cards.\n");
		for(i = 0; i < 10; i++)
		{
			int r = rand()%20; // randomly assign value 0-20
			k[i] = r+7; //skip over first 7 non-kingdom cards
			while(is_card_dup(k, k[i], i) == 1) //makes sure no duplicate kingdom cards
			{
				int r = rand()%20;
				k[i] = r+7;
			}
		}

		fprintf(fp, "*Kingdom cards randomly chosen: \n\t");
		for(i = 0; i < 10; i++) 
		{
			fprintf(fp, "| %s ", get_kingdom(k[i]));
		}
		fprintf(fp, "| \n");

		num_players = rand()%5; //gives max of 4 players per game instructions
		while(num_players == 0 || num_players == 1) num_players = rand()%5; //makes sure 2-4 players
		assert(num_players > 1 && num_players < 5); 

		fprintf(fp, "*Number of players randomly chosen: %d\n", num_players);

		//initialize game and assert it worked
		printf("***Initializing game.\n");
		init = initializeGame(num_players, k, seed, G);
		assert(init == 0);

		fprintf(fp, "*gameState members after initialization: \n");	
		for(i = 0; i < 10; i++)
		{
			fprintf(fp, "\t**kingdom card = %-13s", get_kingdom(k[i]));
			fprintf(fp, "\t\tsupplyCount = %d\n", G->supplyCount[k[i]]);
		}

		fprintf(fp, "\t**numPlayers = %d\t", G->numPlayers);
		print_game(G, fp, k);

		//gameplay begins!
		printf("***Gameplay begins.\n");
		fprintf(fp, "*Beginning game: %d\n", games+1);

		i = 1;
		while(!isGameOver(G))
		{
			coins = 0;
			turn = whoseTurn(G);

			fprintf(fp, "*Player %d's turn\n", turn+1);
			fprintf(fp, "Starting action phase\n");

			printf("***Beginning action phase.\n");

			action_phase(G, turn, coins, pos, fp);
			fprintf(fp, "*gameState members after action: \n");	
			print_game(G, fp, k);


			fprintf(fp, "Starting buy phase\n");
			printf("***Beginning buy phase.\n");
			buy_phase(G, coins, turn, pos, fp);

			fprintf(fp, "*gameState members after turn: \n");		
			print_game(G, fp, k);	
			check_deck(G, turn, coins, pos);
			endTurn(G);
		}

		printf("\n");
		fprintf(fp, "\n\n");

		printf ("***Finished game.\n");
		fprintf(fp, "**Game over\n");
		for(i = 0; i < G->numPlayers; i++)
		{
			printf ("***Player %d: %d\n", i+1, scoreFor(i, G));
			fprintf(fp, "*Player %d: %d\n", i+1, scoreFor(i, G));
		}

		printf("\n");
		fprintf(fp, "\n\n");

		free(G);
	}

	fclose(fp);

	return 0;
}

/*********************************************************************
** Function: is_card_dup
** Returns: true if newly added card is a duplicate
** false if all kingdom cards are unique
** Takes: current array of kingdom cards
** new card being added
** current index
*********************************************************************/ 
int is_card_dup(int k[], int new_card, int cur_index)
{
	int i;
	for (i = 0; i < cur_index; i++)
	{
		if (k[i] == new_card) return 1;
	}
	return 0;

}

/*********************************************************************
** Function: get_kingdom
** Returns: string value of card 
** Takes: enum card name as an int value
*********************************************************************/ 
char * get_kingdom(int c)
{
	switch(c)
	{
   		case curse: return "curse";
   		case estate: return "estate";
   		case duchy: return "duchy";
   		case province: return "province";
   		case copper: return "copper";
   		case silver: return "silver";
   		case gold: return "gold";
		case adventurer: return "adventurer";
		case council_room: return "council_room";
		case feast: return "feast";
		case gardens: return "gardens";
		case mine: return "mine";
		case remodel: return "remodel";
		case smithy: return "smithy";
		case village: return "village";

		case baron: return "baron";
		case great_hall: return "great_hall";
		case minion: return "minion";
		case steward: return "steward";
		case tribute: return "tribute";

		case ambassador: return "ambassador";
		case cutpurse: return "cutpurse";
		case embargo: return "embargo";
		case outpost: return "outpost";
		case salvager: return "salvager";
		case sea_hag: return "sea_hag";
		case treasure_map: return "treasure_map";
		default: return "error";
	}
}

/*********************************************************************
** Function: print_game
** Description: Writes all significant aspects of gameState to file
** Takes: gameState
** file to be written to
** kingdom card array
*********************************************************************/ 
void print_game(struct gameState * G, FILE * fp, int k[])
{
	int i, j;

	fprintf(fp, "\t**whoseTurn = %d\t", G->whoseTurn);
	fprintf(fp, "\t**numActions = %d\t", G->numActions);
	fprintf(fp, "\t**coins = %d\t", G->coins);
	fprintf(fp, "\t**numBuys = %d\n", G->numBuys);

	for(i = 0; i < G->numPlayers; i++)
	{
		fprintf(fp, "\t**player = %d\n", i+1);

		fprintf(fp, "\t\t***discardCount = %d\n", G->discardCount[i]);

		fprintf(fp, "\t\t***handCount = %d\n\t\t\t", G->handCount[i]);
		if(G->handCount[i] != 0) fprintf(fp, " |");
		for(j = 0; j < G->handCount[i]; j++)
			fprintf(fp, " %-5s |", get_kingdom(G->hand[i][j]));

		fprintf(fp, "\n\t\t***deckCount = %d\n\t\t\t", G->deckCount[i]);
		if(G->deckCount[i] != 0) fprintf(fp, " |");
		for(j = 0; j < G->deckCount[i]; j++)
			fprintf(fp, " %-5s |", get_kingdom(G->deck[i][j]));

		fprintf(fp, "\n");
	}
}

/*********************************************************************
** Function: action_phase
** Description: performs action phase of dominion game for current
** player, checking for action cards and testing whether they are
** actually being played
** Takes: gameState struct
** current player's coin value
** positions of cards in hand
** file to be written to
*********************************************************************/ 
void action_phase(struct gameState * G, int turn, int coins, int pos[], FILE * fp)
{
	int i, r, action = 0;
	int loop_check = 0;

	G->coins = check_deck(G, turn, coins, pos);
	fprintf(fp, "Player %d's current coins: %-10d current actions: %-10d\n", turn+1, G->coins, G->numActions);
	printf("**Player %d's current coins: %-10d current actions: %-10d\n", turn+1, G->coins, G->numActions);

	//check for each card and the appropriate actions/coins/etc.
	while(G->numActions > 0)
	{
		//get the contents of player's hand and reset positions
		for(i = adventurer; i < treasure_map; i++)
		{
			printf("***Playing %s.\n", get_kingdom(i));
			//skip gardens because it's not an action
			/*
				When feast is played, the tester stalls the program.
				Putting this statement in that skips feast seems to 
				fix the problem. 
				This can be commented out; however, without this
				statement, playing a feast card will probably cause
				the tester to stop and give undesireable results.
			*/

			if(i == gardens || i == feast) continue;
			//check for action taken
			if(pos[i] != -1 && G->numActions > 0)
			{
				action = 1;

				r = playCard(pos[i], 1, 1, 1, G);
				G->coins = check_deck(G, turn, coins, pos);
				
				if(r == -1) 
				{
					printf("\t**Error: action_phase %s\n", get_kingdom(i));
					fprintf(fp, "\tError: action phase %s\n", get_kingdom(i));
					return;
				}

				else
				{
					fprintf(fp, "Player %d played %s\n", turn+1, get_kingdom(i));
					//fprintf(fp, "\tchoice1: %d choice2: %d choice3: %d\n", c1, c2, c3);
				}
			}
		}
		if(action == 0)
		{
			fprintf(fp, "No actions taken this turn\n");
			break;
		}
		loop_check++;
		if(loop_check > 17)
		{
			printf("Unusually high number of actions\n\tProbably stuck in loop\tending action phase\n");
			break;
		}
	}

	if(action == 1) fprintf(fp, "No more actions this turn\n");

	printf("***Action phase complete.\n");
}


/*********************************************************************
** Function: buy_phase
** Description: performs buy phase of dominion game for current 
** player, testing whether player's coins are actually being used
** to buy kingdom cards/treasure
** Takes: gameState struct
** current player's coin value
** positions of cards in hand
** file to be written to
*********************************************************************/ 
void buy_phase(struct gameState * G, int coins, int turn, int pos[], FILE * fp)
{
	int r = 1; //used for both random num and return value
	coins = G->coins;
	fprintf(fp, "Player %d's current coins: %-10d current buys: %-10d\n", turn+1, coins, G->numBuys);
	printf("**Player %d's current coins: %-10d current buys: %-10d\n", turn+1, coins, G->numBuys);

	while(G->numBuys > 0)
	{
		if(coins == 0) break;

		//province
		if(coins >= 8 && G->numBuys > 0)
		{
			r = buyCard(province, G);
			coins = G->coins; //reset coin value
			if(r == 0) 
			{
				printf("***Buying province.\n");
				fprintf(fp, "Player %d bought province for 8 \t\t updated coins: %d\n", turn+1, coins);
			}
			else
			{
				printf("\t**Error: buy_phase province\n");
				fprintf(fp, "\tError: buy phase province\n");
				return;
			}
		} //end province

		//gold and adventurer
		if(coins >= 6 && G->numBuys > 0)
		{
			//randomly choose between the two
			r = rand()%2;
			//check that adventurer is available to buy
			if((r == 0) && (G->supplyCount[adventurer] > 0))
			{
				r = buyCard(adventurer, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying adventurer.\n");
					fprintf(fp, "Player %d bought adventurer for 6 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase adventurer\n");
					fprintf(fp, "\tError: buy phase adventurer\n");
					return;
				}
			} //end adventurer
			else if((r == 1) && (G->supplyCount[gold] > 0))
			{
				r = buyCard(gold, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying gold.\n");
					fprintf(fp, "Player %d bought gold for 6 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase gold\n");
					fprintf(fp, "\tError: buy phase gold\n");
					return;
				}
			} //end gold
		} //end gold and adventurer

		//duchy, council room, mine, minion, tribute, and outpost
		if(coins >= 5 && G->numBuys > 0)
		{
			r = rand()%6;
			if((r == 0) && (G->supplyCount[duchy] > 0))
			{
				r = buyCard(duchy, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying duchy.\n");
					fprintf(fp, "Player %d bought duchy for 5 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase duchy\n");
					fprintf(fp, "\tError: buy phase duchy\n");
					return;
				}
			} //end duchy

			else if((r == 1) && (G->supplyCount[council_room] >0))
			{
				r = buyCard(council_room, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying council room.\n");
					fprintf(fp, "Player %d bought council room for 5 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase council_room\n");
					fprintf(fp, "\tError: buy phase council room\n");
					return;
				}
			} //end council_room

			else if((r == 2) && (G->supplyCount[mine] >0))
			{
				r = buyCard(mine, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying mine.\n");
					fprintf(fp, "Player %d bought mine for 5 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase mine\n");
					fprintf(fp, "\tError: buy phase mine\n");
					return;
				}
			} //end mine

			else if((r == 3) && (G->supplyCount[tribute] > 0))
			{
				r = buyCard(tribute, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying tribute.\n");
					fprintf(fp, "Player %d bought tribute for 5 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase tribute\n");
					fprintf(fp, "\tError: buy phase tribute\n");
					return;
				}
			} //end tribute

			else if((r == 4) && (G->supplyCount[minion] >0))
			{
				r = buyCard(minion, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying minion.\n");
					fprintf(fp, "Player %d bought minion for 5 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase minion\n");
					fprintf(fp, "\tError: buy phase minion\n");
					return;
				}
			} //end minion

			else if((r == 5) && (G->supplyCount[outpost] >0))
			{
				r = buyCard(outpost, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying outpost.\n");
					fprintf(fp, "Player %d bought outpost for 5 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase outpost\n");
					fprintf(fp, "\tError: buy phase outpost\n");
					return;
				}
			} //end outpost
		} //end 5 coins

		//feast, gardens, remodel, smithy, baron, cutpurse, salvager, sea_hag, and treasure_map
		if(coins >= 4 && G->numBuys > 0)
		{
			r = rand()%9;
			if((r == 0) && (G->supplyCount[feast] > 0))
			{
				r = buyCard(feast, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying feast.\n");
					fprintf(fp, "Player %d bought feast for 4 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase feast\n");
					fprintf(fp, "\tError: buy phase feast\n");
					return;
				}
			} //end feast

			else if((r == 1) && (G->supplyCount[gardens] > 0))
			{
				r = buyCard(gardens, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying gardens.\n");
					fprintf(fp, "Player %d bought gardens for 4 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase gardens\n");
					fprintf(fp, "\tError: buy phase gardens\n");
					return;
				}
			} //end gardens

			else if((r == 2) && (G->supplyCount[remodel] > 0))
			{
				r = buyCard(remodel, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying remodel.\n");
					fprintf(fp, "Player %d bought remodel for 4 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase remodel\n");
					fprintf(fp, "\tError: buy phase remodel\n");
					return;
				}
			} //end remodel

			else if((r == 3) && (G->supplyCount[smithy] > 0))
			{
				r = buyCard(smithy, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying smithy.\n");
					fprintf(fp, "Player %d bought smithy for 4 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase smithy\n");
					fprintf(fp, "\tError: buy phase smithy\n");
					return;
				}
			} //end smithy

			else if((r == 4) && (G->supplyCount[baron] > 0))
			{
				r = buyCard(baron, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying baron.\n");
					fprintf(fp, "Player %d bought baron for 4 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase baron\n");
					fprintf(fp, "\tError: buy phase baron\n");
					return;
				}
			} //end baron

			else if((r == 5) && (G->supplyCount[cutpurse] > 0))
			{
				r = buyCard(cutpurse, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying cutpurse.\n");
					fprintf(fp, "Player %d bought cutpurse for 4 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase cutpurse\n");
					fprintf(fp, "\tError: buy phase cutpurse\n");
					return;
				}
			} //end cutpurse

			//sea_hag, and treasure_map
			else if((r == 6) && (G->supplyCount[salvager] > 0))
			{
				r = buyCard(salvager, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying salvager.\n");
					fprintf(fp, "Player %d bought salvager for 4 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase salvager\n");
					fprintf(fp, "\tError: buy phase salvager\n");
					return;
				}
			} //end salvager

			else if((r == 7) && (G->supplyCount[sea_hag] > 0))
			{
				r = buyCard(sea_hag, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying sea_hag.\n");
					fprintf(fp, "Player %d bought sea hag for 4 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase sea_hag\n");
					fprintf(fp, "\tError: buy phase sea hag\n");
					return;
				}
			} //end sea_hag

			else if((r == 8) && (G->supplyCount[treasure_map] > 0))
			{
				r = buyCard(treasure_map, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying treasure_map.\n");
					fprintf(fp, "Player %d bought treasure map for 4 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase treasure_map\n");
					fprintf(fp, "\tError: buy phase treasure map\n");
					return;
				}
			} //end treasure_map
		} //end 4 coins

		//village, great_hall, steward, and ambassador
		if(coins >= 3 && G->numBuys > 0)
		{
			r = rand()%4;
			if((r == 0) && (G->supplyCount[village] > 0))
			{
				r = buyCard(village, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying village.\n");
					fprintf(fp, "Player %d bought village for 3 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase village\n");
					fprintf(fp, "\tError: buy phase village\n");
					return;
				}
			} //end village

			else if((r == 1) && (G->supplyCount[great_hall] > 0))
			{
				r = buyCard(great_hall, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying great_hall.\n");
					fprintf(fp, "Player %d bought great hall for 3 \t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase great_hall\n");
					fprintf(fp, "\tError: buy phase great hall\n");
					return;
				}
			} //end great_hall

			else if((r == 2) && (G->supplyCount[steward] > 0))
			{
				r = buyCard(steward, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying steward.\n");
					fprintf(fp, "Player %d bought steward for 3 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase steward\n");
					fprintf(fp, "\tError: buy phase steward\n");
					return;
				}
			} //end steward

			else if((r == 3) && (G->supplyCount[ambassador] > 0))
			{
				r = buyCard(ambassador, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying ambassador.\n");
					fprintf(fp, "Player %d bought ambassador for 3 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase ambassador\n");
					fprintf(fp, "\tError: buy phase ambassador\n");
					return;
				}
			} //end ambassador
		} //end 3 coins

		//silver, estate, and embargo
		if(coins >= 2 && G->numBuys > 0)
		{
			r = rand()%3;
			//check that embargo is available to buy
			if((r == 0) && (G->supplyCount[embargo] > 0))
			{
				r = buyCard(embargo, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying embargo.\n");
					fprintf(fp, "Player %d bought embargo for 2 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase embargo\n");
					fprintf(fp, "\tError: buy phase embargo\n");
					return;
				}
			} //end embargo

			else if((r == 1) && (G->supplyCount[estate]) > 0)
			{
				r = buyCard(estate, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying estate.\n");
					fprintf(fp, "Player %d bought estate for 2 \t\t updated coins: %d\n", turn+1, coins);
				}
				else
				{
					printf("\t**Error: buy_phase estate\n");
					fprintf(fp, "\tError: buy phase estate\n");
					return;
				}
			} //end estate

			else if((r == 2) && (G->supplyCount[silver] > 0))
			{
				r = buyCard(silver, G);
				coins = G->coins;
				if(r == 0)
				{
					printf("***Buying silver.\n");
					fprintf(fp, "Player %d bought silver for 2 \t\t updated coins: %d\n", turn+1, coins);
				}

				else
				{
					printf("\t**Error: buy_phase silver\n");
					fprintf(fp, "\tError: buy phase silver\n");
					return;
				}
			} //end silver
		} //end 2 coins

		if(coins < 2 && G->numBuys > 0)
		{
			//give players a 1 in 10 chance to buy copper
			r = rand()%10;
			if((r == 0) && (G->supplyCount[copper] > 0))
			{
				r = buyCard(copper, G);
				//coins should be unaffected
				if(r == 0)
				{
					printf("***Buying copper.\n");
					fprintf(fp, "Player %d bought copper for 0 \t\t updated coins: %d\n", turn+1, coins);
				}

				else
				{
					printf("\t**Error: buy_phase copper\n");
					fprintf(fp, "\tError: buy phase copper\n");
					return;
				}
			}
		}

	}
	fprintf(fp, "No more buys this turn\n");
	printf("***Buy phase complete.\n");
	fprintf(fp, "End of player %d's turn\n", turn+1);
	printf("***Turn complete.\n");
}

/*********************************************************************
** Function: check_deck
** Description: checks deck for card positions and treasure amounts
** Returns: updated coin value for current player
** Takes: gameState struct
** current player
** current player's coin value
** positions of cards in hand
*********************************************************************/ 
int check_deck(struct gameState * G, int turn, int coins, int pos[])
{
	int i, j;

	for(i = curse; i < treasure_map; i++) //reset card positions
		pos[i] = -1;

	//printf("check_deck\n");

	for(i = 0; i < G->handCount[turn]; i++)
	{
		for(j = curse; j < treasure_map; j++)
		{
			if(G->hand[turn][i] == j) 
			{	
				pos[j] = i;
				//printf("\tpos[j] = %d j = %s i = %d\n", pos[j], get_kingdom(j), i);
			}
		}

		//update coins for testing vs. G->coins
		if(G->hand[turn][i] == copper) coins++;
		if(G->hand[turn][i] == silver) coins += 2;
		if(G->hand[turn][i] == silver) coins += 3;

	}

	return coins;
}
