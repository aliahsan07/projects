#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

void displayGame(struct gameState* game) {
    int i, j;
    printf("Player %d turn", game->whoseTurn);
    printf("Coins: %d", game->coins);
    printf("Number of Buys: %d", game->numBuys);
}

char* getCard(int* card) {
    int cardNum = *card;
    switch(cardNum) {
    case curse:
      return "Curse";
    case estate:
      return "Estate";
    case duchy:
      return "Duchy";
    case province:
      return "Province";
    case copper:
      return "Copper";
    case silver:
      return "Silver";
    case gold:
      return "Gold";
    case adventurer:
      return "Adventurer";
    case council_room:
      return "CouncilRoom";
    case feast:
      return "Feast";
    case gardens:
      return "Gardens";
    case mine:
      return "Mine";
    case remodel:
      return "Remodel";
    case smithy:
      return "Smithy";
    case village:
      return "Village";
    case baron:
      return "Baron";
    case great_hall:
      return "GreatHall";
    case minion:
      return "Minion";
    case steward:
      return "Steward";
    case tribute:
      return "Tribute";
    case ambassador:
      return "Ambassador";
    case cutpurse:
      return "Cutpurse";
    case embargo:
      return "Embargo";
    case outpost:
      return "Outpost";
    case salvager:
      return "Salvager";
    case sea_hag:
      return "Sea Hag";
    case treasure_map:
      return "TreasureMap";
    default:
      return 0;
    }
}

int main (int argc, char** argv) {
    struct gameState G;
    struct gameState *p = &G;
    int i, n;
    int player, card, choice;
    int money;
    int playerTurn;

    int cardstack[26] = {curse, estate, duchy, province, copper, silver, gold,
                        adventurer, council_room, feast, gardens, mine, remodel, smithy, village,
                        baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo,
                        outpost, salvager, sea_hag, treasure_map};

//    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
//	      sea_hag, tribute, smithy};

    int k[10];

    SelectStream(2);
    PutSeed(3);
    int turns = 0;

    player = floor(Random() * 3 + 2);
    int seed = floor(Random() * 100);

    for(i = 0; i < 10; i++) {
        int j = i + floor(Random() * 26);

        int temp = cardstack[i];
        cardstack[i] = cardstack[j];
        cardstack[j] = temp;

        k[i] = cardstack[i];
    }


    printf("Starting Cards: \n");
    for(i = 0; i < 10; i++) {
        printf("%s ", getCard(&k[i]));
    }

    printf("\nPlayers: %d ", player);

    printf("\nStarting game with %d players\n", player);
    initializeGame(player, k, seed, p);

    int numEstate = 0;
    int numDuchy = 0;
    int numProvince = 0;
    int numAdventurer = 0;
    int numCouncil_room = 0;
    int numFeast = 0;
    int numGardens = 0;
    int numMine = 0;
    int numRemodel = 0;
    int numSmithy = 0;
    int numVillage = 0;
    int numBaron = 0;
    int numGreat_hall = 0;
    int numMinion = 0;
    int numSteward = 0;
    int numTribute = 0;
    int numAmbassador = 0;
    int numCutpurse = 0;
    int numEmbargo = 0;
    int numOutpost = 0;
    int numSalvager = 0;
    int numSea_hag = 0;
    int numTreasure_map = 0;

    while(!isGameOver(p)) {
        int choice = floor(Random() * 3);
        printf("\nPlayer %d's turn\n", whoseTurn(p) + 1);
        int cursePos = -1;
        int estatePos = -1;
        int duchyPos = -1;
        int provincePos = -1;
        int adventurerPos = -1;
        int council_roomPos = -1;
        int feastPos = -1;
        int gardensPos = -1;
        int minePos = -1;
        int remodelPos = -1;
        int smithyPos = -1;
        int villagePos = -1;
        int baronPos = -1;
        int great_hallPos = -1;
        int minionPos = -1;
        int stewardPos = -1;
        int tributePos = -1;
        int ambassadorPos = -1;
        int cutpursePos = -1;
        int embargoPos = -1;
        int outpostPos = -1;
        int salvagerPos = -1;
        int sea_hagPos = -1;
        int treasure_mapPos = -1;
        money = 0;

        //draw 5 cards
        while(numHandCards(p) < 5)
            drawCard(whoseTurn(p), p);

        for(i = 0; i < numHandCards(p); i++) {
            if(handCard(i, p) == copper)
                money++;
            else if(handCard(i, p) == silver)
                money += 2;
            else if(handCard(i, p) == gold)
                money += 3;
            else if(handCard(i, p) == adventurer)
                adventurerPos = i;
            else if(handCard(i, p) == smithy)
                smithyPos = i;
            else if(handCard(i, p) == curse)
                cursePos = i;
            else if(handCard(i, p) == estate)
                estatePos = i;
            else if(handCard(i, p) == duchy)
                duchyPos = i;
            else if(handCard(i, p) == province)
                provincePos = i;
            else if(handCard(i, p) == council_room)
                council_roomPos = i;
            else if(handCard(i, p) == feast)
                feastPos = i;
            else if(handCard(i, p) == gardens)
                gardensPos = i;
            else if(handCard(i, p) == mine)
                minePos = i;
            else if(handCard(i, p) == remodel)
                remodelPos = i;
            else if(handCard(i, p) == village)
                villagePos = i;
            else if(handCard(i, p) == baron)
                baronPos = i;
            else if(handCard(i, p) == great_hall)
                great_hallPos = i;
            else if(handCard(i, p) == minion)
                minionPos = i;
            else if(handCard(i, p) == steward)
                stewardPos = i;
            else if(handCard(i, p) == tribute)
                tributePos = i;
            else if(handCard(i, p) == ambassador)
                ambassadorPos = i;
            else if(handCard(i, p) == cutpurse)
                cutpursePos = i;
            else if(handCard(i, p) == embargo)
                embargoPos = i;
            else if(handCard(i, p) == outpost)
                outpostPos = i;
            else if(handCard(i, p) == salvager)
                salvagerPos = i;
            else if(handCard(i, p) == sea_hag)
                sea_hagPos = i;
            else if(handCard(i, p) == treasure_map)
                treasure_mapPos = i;
        }
        if(adventurerPos != -1) {
            playCard(adventurerPos, -1, -1, -1, p);
            printf("Adventurer Played.\n");
        }
        else if(smithyPos != -1) {
            playCard(smithyPos, -1, -1, -1, p);
            printf("Smithy Played.\n");
        }
        else if(estatePos != -1) {
            playCard(estatePos, -1, -1, -1, p);
            printf("Estate Played.\n");
        }
        else if(duchyPos != -1) {
            playCard(duchyPos, -1, -1, -1, p);
            printf("Duchy Played.\n");
        }
        else if(provincePos != -1) {
            playCard(provincePos, -1, -1, -1, p);
            printf("Province Played.\n");
        }
        else if(council_roomPos != -1) {
            playCard(council_roomPos, -1, -1, -1, p);
            printf("Council Room Played.\n");
        }
        else if(feastPos != -1) {
            playCard(feastPos, -1, -1, -1, p);
            printf(" Played.\n");
        }
        else if(gardensPos != -1) {
            playCard(gardensPos, -1, -1, -1, p);
            printf("Garden Played.\n");
        }
        else if(minePos != -1) {
            playCard(minePos, -1, -1, -1, p);
            printf("Mine Played.\n");
        }
        else if(remodelPos != -1) {
            playCard(remodelPos, -1, -1, -1, p);
            printf("Remodel Played.\n");
        }
        else if(villagePos != -1) {
            playCard(villagePos, -1, -1, -1, p);
            printf("Village Played.\n");
        }
        else if(baronPos != -1) {
            playCard(baronPos, -1, -1, -1, p);
            printf("Baron Played.\n");
        }
        else if(great_hallPos != -1) {
            playCard(great_hallPos, -1, -1, -1, p);
            printf("Great Hall Played.\n");
        }
        else if(minionPos != -1) {
            playCard(minionPos, -1, -1, -1, p);
            printf("Minion Played.\n");
        }
        else if(stewardPos != -1) {
            playCard(stewardPos, -1, -1, -1, p);
            printf("Steward Played.\n");
        }
        else if(tributePos != -1) {
            playCard(tributePos, -1, -1, -1, p);
            printf("Tribute Played.\n");
        }
        else if(ambassadorPos != -1) {
            playCard(ambassadorPos, -1, -1, -1, p);
            printf("Ambassador Played.\n");
        }
        else if(cutpursePos != -1) {
            playCard(cutpursePos, -1, -1, -1, p);
            printf("Cutpurse Played.\n");
        }
        else if(embargoPos != -1) {
            playCard(embargoPos, -1, -1, -1, p);
            printf("Embargo Played.\n");
        }
        else if(outpostPos != -1) {
            playCard(outpostPos, -1, -1, -1, p);
            printf("Outpost Played.\n");
        }
        else if(salvagerPos != -1) {
            playCard(salvagerPos, -1, -1, -1, p);
            printf("Salvager Played.\n");
        }
        else if(sea_hagPos != -1) {
            playCard(sea_hagPos, -1, -1, -1, p);
            printf("Sea Hag Played.\n");
        }
        else if(treasure_mapPos != -1) {
            playCard(treasure_mapPos, -1, -1, -1, p);
            printf("Treasure Map Played.\n");
            money = 0;
            i = 0;
        }

        while(i < numHandCards(p)) {
            if(handCard(i, p) == copper) {
                playCard(i, -1, -1, -1, p);
                money++;
            }
            else if(handCard(i, p) == silver) {
                playCard(i, -1, -1, -1, p);
                money += 2;
            }
            else if (handCard(i, p) == gold) {
                playCard(i, -1, -1, -1, p);
                money += 3;
            }
        }

        if(money >= 8) {
            printf("Player %d bought province\n", whoseTurn(p) + 1);
            buyCard(province, p);
        }
        else if(money >= 6) {
            if(choice >= 1) {
                printf("Player %d bought gold\n", whoseTurn(p) + 1);
                buyCard(gold, p);
            }
            else {
                printf("Player %d bought adventurer", whoseTurn(p) + 1);
                buyCard(adventurer, p);
                //numAdventurer++;
            }
        }
        else if(money >= 5) {
            if(choice == 2) {
                printf("Player %d bought duchy", whoseTurn(p) + 1);
                buyCard(duchy, p);
            }
            else if(choice == 1) {
                printf("Player %d bought Council Room", whoseTurn(p) + 1);
                buyCard(council_room, p);
                //numCouncil_room++;
            }
            else {
                printf("Player %d bought Outpost", whoseTurn(p) + 1);
                buyCard(outpost, p);
                //numOutpost++;
            }
        }
        else if(money >= 4) {
            printf("Player %d bought Smithy\n", whoseTurn(p) + 1);
            buyCard(smithy, p);
            //numSmithy++;
        }

        else if(money >= 3) {
            printf("Player %d bought silver\n", whoseTurn(p) + 1);
            buyCard(silver, p);
        }

        else if(money >= 2) {
            printf("Player %d bought estate\n", whoseTurn(p) + 1);
            buyCard(estate, p);
        }

        printf("\n\n----Player %d ends turn.----\n", whoseTurn(p) + 1);
        endTurn(p);
        turns++;
        printf("Turns %d\n", turns);
        printf("\n Player 1: %d\n Player 2: %d\n", scoreFor(0, p), scoreFor(1, p));

    }

    printf("Finished game.\n");
    printf("\n Player 1: %d\n Player 2: %d\n", scoreFor(0, p), scoreFor(1, p));

    printf("\n\n\nStarting Cards: \n\n\n");
    for(i = 0; i < 10; i++) {
        printf("%s ", getCard(&k[i]));
    }
    printf("\n");

  return 0;
}
