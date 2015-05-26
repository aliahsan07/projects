#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define NUM_TESTS 1

char* returnCardName(int cardNum);

int main (int argc, char* argv[])
{
	FILE * fp;
	fp = fopen("gameResults.out", "w");

	srand(time(NULL));
	int seed = 0;

	if (argc > 1)
		seed = atoi(argv[1]);
	else
		seed = rand() % RAND_MAX + 1;

	srand(seed);

	for(int z = 0; z < NUM_TESTS; z++)
	{
		struct gameState G;
		struct gameState *p = &G;

		int k[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
		int k_plus_others[17];
		int num_kingdom_cards = 0;
		int card = 0;
		int true_false = 1;
		char blank = ' ';

		int action_pos[MAX_HAND];
		int num_action_pos = 0;
		int has_action_card = 0;
		int play_pos = -1;
		int print_play_pos = play_pos;
		int get_new_actions = 1;
		int action_counter = 0;
		int canPlay_ret_val = 0;
		int play_ret_val = 0;
		int play_card = 0;

		int buy_counter = 0;
		int buy_card = -1;
		int cost_buy_card = 0;
		int succeeded_buy_card = -1;
		int temp = -1;

		int turn_counter = 0;


		int all_kingdom_cards[20] = {adventurer, council_room, feast, gardens, mine, 
			remodel, smithy, village, baron, great_hall, minion, steward, 
			tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};

		printf("Kingdom cards chosen: ");
		fprintf(fp, "Kingdom cards chosen: %c", blank);
		while (num_kingdom_cards < 10)
		{
			card = rand() % 20;

			for (int i = 0; i < 10 ; i++)
			{
				if(k[i] == all_kingdom_cards[card])
				{
					true_false = 0;
				}
			}
			if (true_false == 1)
			{
				printf("%s ", returnCardName(all_kingdom_cards[card]));
				fprintf(fp,"%s ", returnCardName(all_kingdom_cards[card]));
				k[num_kingdom_cards] = all_kingdom_cards[card];
				num_kingdom_cards ++;
			}
			true_false = 1;
		}
		printf("\n\n");
		fprintf(fp, "\n\n%c",blank);

		//Populate first 7 spots with curse through gold
		for(int i = 0; i < 7; i++)
		{
			k_plus_others[i] = i;
		}
		//Populate last 10 spots with kingdom cards
		for (int i = 0; i < 10; i++)
		{
			k_plus_others[i + 7] = k[i];
		}

		int num_players = rand() % 3 + 2;// 2 to 4 players

		printf("****Starting game.****\n");
		initializeGame(num_players, k, seed, &G);

	 	while (!isGameOver(p))
	  	{

	  		printf("Player %i's Turn\n", G.whoseTurn);
	  		fprintf(fp, "Player %i's Turn\n", G.whoseTurn);

	  		printf("Beginning action phase.\n");
	  		fprintf(fp, "Beginning action phase.\n%c", blank);
	  		//Play cards until actions are depleted
	  		while(G.numActions > 0)
	  		{
	  			printf("Number of actions = %d.\n", G.numActions);
	  			fprintf(fp, "Number of actions = %d.\n", G.numActions);
	  			action_counter ++;
	  			if(action_counter < 10)
	  			{
					//Reset action_pos
					if(get_new_actions == 1)
					{
						for(int i = 0; i < MAX_HAND; i++)
						{
							action_pos[i] = -1;
						}
						num_action_pos = 0;


						//This relies on the card getting discarded from the hand after being played or
						//else the same card can be played twice if there are enough numActions
						for(int i = 0; i < G.handCount[G.whoseTurn]; i++)
						{
							if(G.hand[G.whoseTurn][i] >= adventurer &&  G.hand[G.whoseTurn][i] <= treasure_map)
							{
								has_action_card = 1;
								action_pos[num_action_pos] = i;
								num_action_pos ++;
							}
						}
					}

		  			//If num_action_pos is 0 then we have tried to run all the action cards
		  			if(has_action_card && (num_action_pos > 0))
		  			{
		  				temp = rand() % num_action_pos;
		  				play_pos = action_pos[temp];
		  				play_card = G.hand[G.whoseTurn][play_pos];
						canPlay_ret_val = can_playCard(play_pos, p);
						if (canPlay_ret_val != 0)
						{
							get_new_actions = 0;
							//Cannot play card, get rid of action card from playable list and get new one
							action_pos[temp] = action_pos[num_action_pos - 1]; //Place last action card in
							action_pos[num_action_pos - 1] = -1;			   //place of card card that could
							num_action_pos--;								   //not be played. Decrement num_action_pos
						}
						else
						{
							get_new_actions = 1;
							//Since the card was played, remove from the list of playable cards
							action_pos[temp] = action_pos[num_action_pos - 1];
							action_pos[num_action_pos - 1] = -1;
							num_action_pos--;
							printf("Played %s.\n", returnCardName(play_card));
							fprintf(fp, "Played %s.\n", returnCardName(play_card));
							//G.numActions--; //Played card so decrement numActions //This is done in playCard
						}
		  			}

					else
					{
						break; //Break out of playing more action cards
					}
				}
	  		}
	  		get_new_actions = 1;
	  		action_counter = 0;


	  		//Play/add coins
	 		for (int i = 0; i < G.handCount[G.whoseTurn]; i++)
	 		{
	    	    if (G.hand[G.whoseTurn][i] == copper)
			    {
			       G.coins += 1;
			    }
	 		  		else if (G.hand[G.whoseTurn][i] == silver)
			    {
			      G.coins += 2;
			    }
	  		   	else if (G.hand[G.whoseTurn][i] == gold)
			    {
	  		   	 G.coins += 3;
				}
	 		}
	 		printf("Beginning buy phase.\n");
	 		printf("Number of coins = %d. Number of buys = %d.\n",G.coins , G.numBuys);

	 		fprintf(fp, "Beginning buy phase.\n%c", blank);
	 		fprintf(fp, "Number of coins = %d. Number of buys = %d.\n", G.coins, G.numBuys);

	 		//Buy card
	 		while(G.numBuys > 0 && buy_counter < 10)
	 		{
	 			buy_counter++;

	 			if(G.coins < 2)
	 				break;

	 			temp = rand() % 17;
	 			buy_card = k_plus_others[temp];

	 			//Buy a random card
	 			while(buy_card == -1 || buy_card == 0 || buy_card == 4 )//dont buy copper or curse
	 			{
	 				temp = rand() % 17;
	 				buy_card = k_plus_others[temp];
	 			}

	 			if(G.coins >= 3 && (rand() % 4) == 0)
	 				buy_card = silver;
	 			 if(G.coins >= 6 && (rand() % 2) == 0)
	 				buy_card = gold;

	 			cost_buy_card = getCost(buy_card);

	 			if (cost_buy_card <= G.coins)
	 			{
	 				succeeded_buy_card = gainCard(buy_card, p, 0, G.whoseTurn);
	 				if (succeeded_buy_card == 0)
	 				{
						printf("Bought %s.\n", returnCardName(buy_card));
						fprintf(fp, "Bought %s.\n", returnCardName(buy_card));
	 					G.coins -= cost_buy_card;
	 					succeeded_buy_card = -1;
	 					G.numBuys --;
	 				}
	 			}
	 		}
	 		buy_counter = 0;
	 		buy_card = -1;

	 		printMyState(fp,p);

	 		printf("Turn Complete.\n\n");
	 		fprintf(fp, "Turn Complete\n\n%c", blank);

	 		endTurn(p);
	 		turn_counter ++;
  		}

  		printf("Number of turns in game = %d\n", turn_counter);
  		fprintf(fp, "Number of turns in game = %d\n", turn_counter);
  		printScores(p);
  	}
}

void printMyState(FILE *fp, struct gameState *state)
{
	for(int i = 0; i < state->numPlayers; i++)
	{
		fprintf(fp, "\tPlayer %d:\n", i);

		fprintf(fp, "\t\thandCount = %d\n\t\t\t", state->handCount[i]);

		for (int j = 0; j < state->handCount[i]; j++)
		{
			fprintf(fp, "%s ,", returnCardName(state->hand[i][j]));
		}
		fprintf(fp, "\n\n");

		fprintf(fp, "\t\tdeckCount = %d\n\t\t\t", state->deckCount[i]);

		for (int j = 0; j < state->deckCount[i]; j++)
		{
			fprintf(fp, "%s ,", returnCardName(state->deck[i][j]));
		}
		fprintf(fp, "\n\n");

		fprintf(fp, "\t\tdiscardCount = %d\n\t\t\t", state->discardCount[i]);

		for (int j = 0; j < state->discardCount[i]; j++)
		{
			fprintf(fp, "%s ,", returnCardName(state->discard[i][j]));
		}
		fprintf(fp, "\n\n%c",' ');

	}
}


char* returnCardName(int cardNum)
{
	char *cardName;

	if(cardNum == -1)
		return "-1";

	char *cards[27] = {"curse", "estate", "duchy", "province", "copper", "silver",
		"gold" , "adventurer", "council_room", "feast", "gardens", "mine",
		"remodel", "smithy", "village", "baron", "great_hall", "minion",
		"steward", "tribute", "ambassador", "cutpurse", "embargo", "outpost",
		"salvager", "sea_hag", "treasure_map"};
	cardName = cards[cardNum];
	return cardName;
}

//This function returns 1 if the card cannot be played and 0 is the card was played
int can_playCard(int handPos, struct gameState *state)
{
	int card = handCard(handPos, state);

	switch (card)
	{
		case adventurer:
			return play_card_noChoices(handPos, state);

		case council_room:
			return play_card_noChoices(handPos, state);

		case feast:
			return play_card_Feast(handPos, state);

		case gardens:
			return 1;

		case mine:
			return play_card_Mine(handPos, state);

		case remodel:
			return play_card_Remodel(handPos, state);

		case smithy:
			return play_card_noChoices(handPos, state);

		case village:
			return play_card_noChoices(handPos, state);

		case baron:
			return play_card_Baron(handPos, state);

		case great_hall:
			return play_card_noChoices(handPos, state);

		case minion:
			return play_card_Minion(handPos, state);

		case steward:
			return play_card_Steward(handPos, state);

		case tribute:
			return play_card_noChoices(handPos, state);

		case ambassador:
			return play_card_Ambassador(handPos, state);

		case cutpurse:
			return play_card_noChoices(handPos, state);

		case embargo:
			return play_card_Embargo(handPos, state);

		case outpost:
			return play_card_noChoices(handPos, state);

		case salvager:
			return play_card_Salvager(handPos, state);

		case sea_hag:
			return play_card_noChoices(handPos, state);

		case treasure_map:
			//return 1;
			return play_card_treasureMap(handPos, state);

		default:
			printf("DEFAULT CASE. EXIT.\n");
			exit(1);
	}
}

int play_card_noChoices(int handPos, struct gameState *state)
{
	int card_played = -1;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;

	while (card_played == -1)
	{
		card_played = playCard(handPos, choice1, choice2, choice3, state);//If cannot play, retry with random choices
	}
	return 0;
}


int play_card_Feast(int handPos, struct gameState *state)
{
	int card_played = -1;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;

	while (card_played == -1)
	{
		choice1 = rand() % (treasure_map + 1); //Any random card
		card_played = playCard(handPos, choice1, choice2, choice3, state);//If cannot play, retry with random choices
	}
	return 0;
}

int play_card_Mine(int handPos, struct gameState *state)
{
	int card_in_hand = 0;
	int hand_card_array[state->handCount[state->whoseTurn]];
	int num_hand_card = 0;

	int card_played = -1;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;

	//check if coin in hand
	for (int i = 0; i < state->handCount[state->whoseTurn]; i++)
	{
		if (state->hand[state->whoseTurn][i] >= copper && state->hand[state->whoseTurn][i] <= gold)
		{
			card_in_hand = 1;
			hand_card_array[num_hand_card] = i; //Pos in hand
			num_hand_card++;
		}
	}

	while (card_played == -1)
	{
		if (card_in_hand == 1)
		{
			choice1 = rand() % state->handCount[state->whoseTurn];//Random card in hand
			choice2 = rand() % 3 + 4; //Random between copper,silver,gold

			card_played = playCard(handPos, choice1, choice2, choice3, state);//If cannot play, retry with random choices
		}
		else
		{
			return 1;//Cannot play card
		}
	}
	return 0;//Card has been played
}

int play_card_Remodel(int handPos, struct gameState *state)
{
	int card_played = -1;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;

	while (card_played == -1)
	{
		choice1 = rand() % state->handCount[state->whoseTurn];//Random card in hand
		choice2 = rand() % (treasure_map + 1); //Any random card
		card_played = playCard(handPos, choice1, choice2, choice3, state);//If cannot play, retry with random choices
	}
	return 0;
}

int play_card_Baron(int handPos, struct gameState *state)
{
	int card_played = -1;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;

	while (card_played == -1)
	{
		choice1 = rand() % 2;
		card_played = playCard(handPos, choice1, choice2, choice3, state);//If cannot play, retry with random choices
	}
	return 0;
}

int play_card_Minion(int handPos, struct gameState *state)
{
	int card_played = -1;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;

	while (card_played == -1)
	{
		choice1 = rand() % 2 +1;
		card_played = playCard(handPos, choice1, choice2, choice3, state);//If cannot play, retry with random choices
	}
	return 0;
}

int play_card_Steward(int handPos, struct gameState *state)
{
	int card_played = -1;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;

	if (state->handCount[state->whoseTurn] < 2)
	{
		return 1;//Too few cards
	}

	while (card_played == -1)
	{
		choice1 = rand() % 3 + 1;
		while(choice2 == choice3)
		{
			choice2 = rand() % state->handCount[state->whoseTurn];
			choice3 = rand() % state->handCount[state->whoseTurn];
		}
		card_played = playCard(handPos, choice1, choice2, choice3, state);//If cannot play, retry with random choices
	}
	return 0;
}

int play_card_Ambassador(int handPos, struct gameState *state)
{
	int card_played = -1;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;
	int counter = 0;

	for(int i = 0; i < state->handCount[state->whoseTurn]; i++)
	{
		if(state->hand[state->whoseTurn][i] != ambassador)
			counter ++;
	}

	if (counter < 1)
	{
		return 1;
	}

	while (card_played == -1)
	{
		choice1 = rand() % state->handCount[state->whoseTurn];
		choice2 = rand() % 2 + 1;
		card_played = playCard(handPos, choice1, choice2, choice3, state);//If cannot play, retry with random choices
	}
	return 0;
}

int play_card_Embargo(int handPos, struct gameState *state)
{
	int card_played = -1;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;

	while (card_played == -1)
	{
		choice1 = rand() % treasure_map + 1;
		card_played = playCard(handPos, choice1, choice2, choice3, state);//If cannot play, retry with random choices
	}
	return 0;
}

int play_card_Salvager(int handPos, struct gameState *state)
{
	int card_played = -1;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;

	while (card_played == -1)
	{
		choice1 = rand() % state->handCount[state->whoseTurn];
		card_played = playCard(handPos, choice1, choice2, choice3, state);//If cannot play, retry with random choices
	}
	return 0;
}


int play_card_treasureMap(int handPos, struct gameState *state)
{
	int card_played = -1;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;

    int can_play = 0;

    for (int i = 0; i < state->handCount[state->whoseTurn]; i++)
	{
	  	if (state->hand[state->whoseTurn][i] == treasure_map && i != handPos)
	    {
	      can_play = 1;
	    }
	}

    if (can_play == 0)
	{
		return 1; // not enough trasure maps
	}
	else
	{
		while (card_played == -1)
		{
			card_played = playCard(handPos, choice1, choice2, choice3, state);//If cannot play, retry with random choices
		}
	}
	return 0;
}