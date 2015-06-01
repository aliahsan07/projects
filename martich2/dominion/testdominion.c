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
    int scores[MAX_PLAYERS] = {0};
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
            printHand(aGame);
			actionPhase(aGame);
			buyPhase(aGame, kingdom_cards);
			cleanupPhase(aGame);
        }
        round++;
        printSupplyCards(aGame);
	}

	getWinners(scores, aGame);
	for (i = 0; i < MAX_PLAYERS; i++)
	{
	   if (scores[i] == 1)
	   {
	       printf("Player %d won!\n", i);
	       break;
	   }
	}


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
        card = (rand() % NUM_K_CARDS); // kingdom cards
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
        while (j <= NUM_K_CARDS)
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
    int card = -1;
    int cardPos = 0;
    int player = aGame->whoseTurn;

    printf("Action phase\n");

    // while a player has actions
    while(aGame->numActions > 0)
    {
        // does the player have action cards?
        cardPos = hasActionCards(aGame);
        if (cardPos >= 0)
        {
            card = aGame->hand[player][cardPos];
            switch(card)
            {
            	case gardens: // gardens is not an action card, cant be played
            		printf("Player %d chose gardens but that can't be played\n");
                        return;
            		break;

            	// these cards require extra work to test so they are ignored for simplicity.
            	case tribute:
                case feast:
                case gardens:
                case mine:
                case remodel:
                case ambassador:
                case treasure_map:
                    printf("skipping %s card\n", getCardName(card));
                    return;
                    break;

            }

            // all choices will be fixed to 0 for simplicity
            //TODO: randomize card choice, if more than one card pick one randomly
            printf("Player %d played %s\n", player, getCardName(aGame->hand[player][cardPos]));
            aGame->phase = 0; // buy phase (enum...)
            assert(playCard(cardPos, 0, 0, 0, aGame) == 0);
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

    printf("Buy Phase\n");
    updateCoins(aGame->whoseTurn, aGame, 0);

    while (aGame->numBuys > 0)
    {
        // reset vars for each buy loop
        coins = aGame->coins;
        card = -1;
        printf("Player %d has %d coins and %d buys\n", aGame->whoseTurn, coins, aGame->numBuys);

        // pick a card to buy, check cost, and is it in game/supply
        while (card == -1)
        {
            card = pickACard(&coins, aGame);
        }

        if (card == 0)
        {
            printf("Player %d, cannot buy any cards!\n", aGame->whoseTurn);
            return;
        }
        else
        {
            assert(buyCard(card, aGame) == 0);
            printf("player %d bought a %s \n", aGame->whoseTurn, getCardName(card));
        }
    }
}

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

int pickACard(int *coins, struct gameState *aGame)
{
    // the card to buy. -1 no card picked, 0 no cards to buy, else card to buy
    int card = -1;
    int i;
    int isCards = 0;// flag if there is a card in a price bracket to buy

    // cost 8: province
    if (*coins >= 8)
    {
        if (isInGame(province, aGame))
            card = province;
        // no provinces in the game, try buying lower cost cards
        else
            *coins = 6;
    }
    // cost 6: gold, adventurer
    else if (*coins >= 6)
    {
        if (isInGame(gold, aGame))
            card = gold;
        else if (isInGame(adventurer, aGame))
            card = adventurer;
        // no gold or adventurer in game, try buying lower cost cards
        else
            (*coins)--;
    }
    // cost 5: duchy,council_room, mine, minion, tribute, outpost
    else if (*coins == 5)
    {
        // are there any cards in the game that cost 5?
        for (i = 0; i < NUM_COST5; i++)
        {
            if (isInGame(cost5cards[i],aGame))
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
                card = cost5cards[rand() % NUM_COST5];
            } while (!isInGame(card, aGame));
        }
        // no cost 5 cards in game, try lower cost cards
        else
            (*coins)--;
    }
    // cost 4: feast, gardens, remodel, smithy, baron, cutpurse, salvager
    //         , sea_hag, treasure_map
    else if (*coins == 4)
    {
        // are there any cards in the game that cost 4?
        for (i = 0; i < NUM_COST4; i++)
        {
            if (isInGame(cost4cards[i],aGame))
            {
                isCards = 1;
                break;
            }
        }
        // there is a card in the game that costs 4
        if (isCards)
        {
            do
            {
                card = cost4cards[rand() % NUM_COST4];
            } while (!isInGame(card, aGame));
        }
        else
            (*coins)--;
    }
    // cost 3: silver, village, great_hall, steward, ambassador
    else if (*coins == 3)
    {
        // are there any cards in the game that cost 4?
        for (i = 0; i < NUM_COST3; i++)
        {
            if (isInGame(cost3cards[i],aGame))
            {
                isCards = 1;
                break;
            }
        }
        // there is a card in the game that costs 3
        if (isCards)
        {
            do
            {
                card = cost3cards[rand() % NUM_COST3];
            } while (!isInGame(card, aGame));
        }
        else
            (*coins)--;
    }
    // cost 2: estate, embargo
    else if (*coins == 2)
    {
        if (isInGame(embargo, aGame))
            card = embargo;
        else if (isInGame(estate, aGame))
            card = estate;
        else
            (*coins)--;
    }
    // cost 0: copper
    else if (isInGame(copper, aGame))
        card = copper;
    // no cards to buy
    else
        card = 0;

    return card;
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

void printSupplyCards(struct gameState *aGame)
{
    int x, y;
    int card = adventurer;
    int cards[4][5]; //array to hold the cards to be printed (x,y)

    // load array with victory cards
    for (y = 0; y < 3; y++)
    {
        cards[0][y] = y + estate;
    }

    // load array with Treasure cards
    for (y = 0; y < 3; y++)
    {
        cards[1][y] = y + copper;
    }

    // load array with Kingdom cards
    for (y = 0; y < 5; y++)
    {
        for (x = 2; x < 4; x++)
        {
            while (card <= treasure_map)
            {
                // the card was in the game, could be empty now.
                if (aGame->supplyCount[card] > -1)
                {
                    cards[x][y] = card;
                    card++;
                    break;
                }
                card++;
            }
        }
    }
    // spots (0,3) (1,3) (0,4) (1,4) not used.

    printf("Victory \tTreasure\t\tKingdom\n");

    for (y = 0; y < 3; y++)
    {
        for (x = 0; x < 4; x++)
        {
            printf("%s:%d\t", getCardName(cards[x][y]), aGame->supplyCount[cards[x][y]]);
            // "gold" too short, print a tab
            if ((x == 1) && (y == 2))
                    printf("\t");
            // "duchy:9: too short, print a tab
            if ((x == 0) && (y ==1) && (aGame->supplyCount[duchy] < 10))
                printf("\t");
        }
        printf("\n");
    }

    // print the rest of the kingdom cards
    for (y = 3; y < 5; y++)
    {
        printf("\t\t\t");
        for (x = 2; x < 4; x++)
        {
            printf("\t%s:%d", getCardName(cards[x][y]), aGame->supplyCount[cards[x][y]]);
        }
        printf("\n");
    }
}
