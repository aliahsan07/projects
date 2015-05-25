/*
 * testdominion.c
 *
 * random game tester for dominion
 *
 *  Created on: May 13, 2015
 *      Author: martich2
 */

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#include "testdominion.h"

int main(int argc, char** argv)
{
    //TODO: seed be constant.
	srand(time(NULL));          // init libc random seed
    int players = (rand() % 3) + 2; // 2 to 4 players
    int seed = rand() % 65536;
    int i;
    unsigned int round = 0;

    int kingdom_cards[10] = {0};
    genKcards(kingdom_cards);

    struct gameState *aGame = newGame();

	initializeGame(players,kingdom_cards, seed, aGame);

	printKCards(aGame);

	printf("This game has %d players\n", players);
	// game loop
	while(!isGameOver(aGame))
	{
        printf("Round: %d\n", round);
		for (i = 0; i < players; i++)
        {
			printf("Player %d turn\n", aGame->whoseTurn);
			//actionPhase(aGame);
			printHand(aGame);
			buyPhase(aGame, kingdom_cards);
			cleanupPhase(aGame);
        }
        round++;
	}

	//TODO: game over, who won?

	return 0;
}

void genKcards(int *kcards)
{
    int i = 0, j = 0;
    int card;
    int *card_checklist;

    card_checklist = (int*)calloc(NUM_K_CARDS, sizeof(int));
    if (card_checklist == NULL)
        // TODO: assert check not print
        printf("card_checklist is NULL");

    // random unique list of kingdom cards
    while(i < 10)
    {
        card = (rand() % 20); // 20 kingdom cards
        if (card_checklist[card] == 0)
        {
            // offset to cards 7 thru 26, only good if enum order doesnt change
            card_checklist[card] = (card + adventurer);
            i++;
        }
    }

    // go thru the check list and assign the selected card to the card list
    for (i = 0; i < 10; i++)
    {
        while (j <= 20)
        {
            if (card_checklist[j] != 0)
            {
                kcards[i] = card_checklist[j];
                j++;
                break;
            }
            j++;
        }
    }

    free(card_checklist);
}

//TODO: test this!!
void actionPhase(struct gameState *aGame)
{
    int card = 0;
    printf("Action phase\n");

    // while a player has actions
    while(aGame->numActions > 0)
    {
        // does the player have action cards?
        card = hasActionCards(aGame);
        if (card >= 0)
        {
            // all choices will be fixed to 0 for simplicity
            //TODO: randomize card choice, if more than one card pick one randomly
            assert(playCard(card, 0, 0, 0, aGame) == 0);
            // TODO: discard played card
        }
        else
        {
            printf("Player %d has no action cards in hand\n", aGame->whoseTurn);
            return;
        }
    }
}

void buyPhase(struct gameState *aGame, int *kcards)
{
    int card = -1;  // the card to buy. -1 no card picked, else card to buy
    int coins = 0;  // $ player has to buy
    int i;          // for loop
    int isCards = 0;// flag if there is a card in a price bracket to buy
    int buys = aGame->numBuys;
    printf("Buy Phase\n");
    updateCoins(aGame->whoseTurn, aGame, 0);


    while (buys > 0)
    {
        // reset vars for each buy loop
        coins = aGame->coins;
        card = -1;
        isCards = 0;

        // pick a card to buy, check cost, and is it in game/supply
        while (card == -1)
        {
            // cost 8: province
            if (coins >= 8)
            {
                if (isInGame(province, aGame))
                        card = province;
                // no provinces in the game, try buying lower cost cards
                else
                    coins = 6;
            }
            // cost 6: gold, adventurer
            else if (coins >= 6)
            {
                if (isInGame(gold, aGame))
                    card = gold;
                else if (isInGame(adventurer, aGame))
                        card = adventurer;
                // no gold or adventurer in game, try buying lower cost cards
                else
                    coins--;
            }
            // cost 5: duchy,council_room, mine, minion, tribute, outpost
            else if (coins == 5)
            {
                // are there any cards in the game that cost 5?
                for (i = 0; i < NUM_COST5; i++)
                {
                    if (isInGame(i,aGame))
                    {
                        isCards = 1;
                        break;
                    }
                }
                // there is a card in the game that costs 5
                if (isCards)
                {
                    do
                    {
                        card = rand() % NUM_COST5;
                    } while (!isInGame(card, aGame));
                }
                else
                    coins--;
            }
            // cost 4:
            else if (coins == 4)
            {

            }
            // cost 3:
            else if (coins == 3)
            {

            }
            // cost 2:
            else if (coins == 2)
            {

            }
            // cost 0: copper
            else if (isInGame(copper, aGame))
                card = copper;
            // no cards to buy exit function
            else
            {
                card = 0;

            }
        } // end card = -1 while

        if (card == 0)
        {
            printf("Player %d, cannot buy any cards!\n", aGame->whoseTurn);
            return;
        }
        // buy that card
    } // end buy while
}

//void buyPhase(struct gameState *aGame, int *kcards)
//{
//    int choice = 0;
//    int card = -1;
//    printf("Buy Phase\n");
//    updateCoins(aGame->whoseTurn, aGame, 0);
//
//    while (aGame->numBuys > 0)
//    {
//        // figure out what card to buy
//        choice = rand() % SIZE_BUY_OPTS;
//        switch(choice)
//        {
//            case NO_BUY:
//                printf("player %d choose not buy anything\n", aGame->whoseTurn);
//                return;
//                break;
//            case TREASURE:
//                if (aGame->coins >= getCost(gold))
//                    card = gold;
//                else if (aGame->coins >= getCost(silver))
//                    card = silver;
//                else if (aGame->coins >= getCost(copper))
//                    card = copper;
//                else
//                    card = -1;
//                break;
//            case VICTORY:
//                if (aGame->coins >= getCost(province))
//                    card = province;
//                else if (aGame->coins >= getCost(duchy))
//                    card = duchy;
//                else if (aGame->coins >= getCost(estate))
//                    card = estate;
//                else
//                    card = -1;
//                break;
//            case KINGDOM:
//                choice = rand() % 10;
//                if (aGame->coins >= getCost(kcards[choice]))
//                    card = kcards[choice];
//                else
//                    card = -1;
//                break;
//            default:
//                card = -1;
//                break;
//        } // end switch
//
//        if (card == -1)
//        {
//            printf("Player %d not enough money to buy picked card!\n",
//                    aGame->whoseTurn);
//            printf("Player %d will try buying again\n", aGame->whoseTurn);
//        }
//        // if a valid card was picked...
//        else
//        //if (card > -1)
//        {
//            //...and there are card left in its supply pile...
//            if (aGame->supplyCount[card] > 0)
//            {
//                //...buy the card!
//                assert(buyCard(card, aGame) == 0);
//                printf("player %d bought a %s card\n", aGame->whoseTurn,
//                        getCardName(card));
//            }
//            else
//            {
//                printf("Player %d, picked %s card, but there are none left\n",
//                        aGame->whoseTurn, getCardName(card));
//                printf("Player %d will try buying again\n", aGame->whoseTurn);
//            }
//        }
//    } // end while
//} // end function

void cleanupPhase(struct gameState *aGame)
{
    printf("Clean Up Phase\n");
    endTurn(aGame);
}

int hasActionCards(struct gameState *aGame)
{
    int i;
    int result = -1;

    // look for an action card in hand
    for(i = 0; i < aGame->handCount[aGame->whoseTurn]; i++)
    {
        // play that found action card
        if(isActionCard(aGame->hand[aGame->whoseTurn][i]))
        {
            result = i;
            break;
        }
    }

    return result;
}

int isActionCard(int card)
{
    int result = 0;
    if ((card >= adventurer) && (card <= treasure_map))
        result = 1;
    return result;
}

int isInGame(int card, struct gameState *aGame)
{
    int result = 0;
    if (aGame->supplyCount[card] > 0)
        result = 1;
    return result;
}

char *getCardName(int cardNumb)
{
	char *result = "BAD CARD";

	char* cardName[NUMBER_OF_CARDS] = {"curse", "estate", "duchy", "provice", "copper", "silver",
	        "gold", "adventurer", "council_room", "feast", "gardens", "mine",
	        "remodel", "smithy", "village", "baron", "great_hall", "minion",
	        "steward", "tribute", "ambassador", "cutpurse", "embargo", "outpost",
	        "salvager", "sea_hag", "treasure_map"};

	if ((cardNumb >= curse) && (cardNumb <= NUMBER_OF_CARDS -1))
		result = cardName[cardNumb];

	return result;
}

void printHand(struct gameState *aGame)
{
    int card;
    int player = whoseTurn(aGame);
    printf("Player %d hand: ", player);
    for (card = 0; card < aGame->handCount[player]; card++)
    {
        printf("%s ", getCardName(aGame->hand[player][card]));
    }
    printf("\n");
}

void printKCards(struct gameState *aGame)
{
    int card;
    printf("Kingdom Cards in this game: ");
    for (card = adventurer; card <= treasure_map; card++)
    {
        if (aGame->supplyCount[card] > -1)
            printf("%s ", getCardName(card));
    }
    printf("\n");
}


int pickACard(int *coins, struct gameState *aGame)
{
return 0;
}
