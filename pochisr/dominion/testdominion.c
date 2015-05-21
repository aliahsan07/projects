#include "dominion_helpers.h"
#include "more_dominion_helpers.h"
#include "rngs.h"

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define assertIntEqual(x, y) assertIntEqual_(x, y, __LINE__)
#define lengthof(x) (sizeof(x) / sizeof((x)[0]))
#define print(x) fputs((x), stdout)


enum CARD buy_pref_order[] = {
    province, gold, duchy, silver, estate
};


static void assertIntEqual_(int x, int y, int line)
{
    if (x != y) {
        fprintf(
            stderr, "TEST FAILED on line %d: expected %d but got %d\n",
            line, x, y);
        exit(1);
    }
}


static long get_seed(int argc, char** argv)
{
    if (argc < 2) {
        print("Usage: testdominion SEED\n");
        print("  If SEED is 0, the current epoch time is used instead\n");
        exit(1);
    }

    errno = 0;
    long seed = strtol(argv[1], NULL, 10);
    if (errno || seed <= 0) {
        return -1;
    }

    return seed;
}


/* Note: The probability of returning max + 1 is very small but nonzero.
 *       If double were infinitely precise, it would be zero, but it's not. */
static int rand_int(int min, int max)
{
    return min + (int)((max - min + 1) * Random());
}


static void print_hand(struct gameState* g)
{
    int hand_count = numHandCards(g);
    for (int i = 0; i < hand_count; i++) {
        printf("  %s\n", cardNames[handCard(i, g)]);
    }
}


static bool try_play_card(struct gameState* g, int idx, enum CARD card)
{
    // cards with no choices
    if (card == adventurer || card == council_room || card == smithy ||
            card == village || card == great_hall || card == tribute ||
            card == cutpurse || card == outpost || card == sea_hag) {
        assertIntEqual(0, playCard(idx, -1, -1, -1, g));
        return true;
    } else if (card == feast) {
        enum CARD new_card = 0;
        for (unsigned int i = 0; !new_card && i < lengthof(buy_pref_order);
                i++) {
            enum CARD card = buy_pref_order[i];
            if (supplyCount(card, g) > 0 && getCost(card) <= 5)
                new_card = card;
        }

        for (enum CARD card = adventurer;
                !new_card && card <= treasure_map; card++)
            if (supplyCount(card, g) > 0 && getCost(card) <= 5)
                new_card = card;

        if (!new_card)
            return false;

        assertIntEqual(0, playCard(idx, new_card, -1, -1, g));
        return true;
    } else if (card == mine) {
            return false;
    } else if (card == remodel) {
            return false;
    } else if (card == baron) {
            return false;
    } else if (card == minion) {
            return false;
    } else if (card == steward) {
            return false;
    } else if (card == ambassador) {
            return false;
    } else if (card == embargo) {
            return false;
    } else if (card == salvager) {
            return false;
    } else if (card == treasure_map) {
            return false;
    } else {
        return false;
    }
}


static bool try_buy_card(struct gameState* g, enum CARD card)
{
    if (supplyCount(card, g) <= 0 || getCost(card) > g->coins)
        return false;

    assertIntEqual(0, buyCard(card, g));
    printf("  %s\n", cardNames[card]);
    return true;
}


int main(int argc, char** argv)
{
    long seed = get_seed(argc, argv);
    PlantSeeds(seed);
    GetSeed(&seed);
    printf("Random seed is %ld\n", seed);
    for (int i = 0; i < 1189; i++)
        (void)Random();

    struct gameState* g = newGame();
    int ks[10];

    print("Kingdom cards:\n");
    for (int i = 0; i < 10; i++) {
        while (1) {
            int r = rand_int(adventurer, treasure_map);
            int j;
            for (j = 0; j < i; j++)
                if (r == ks[j])
                    break;
            if (j == i) {  // the for loop was exited normally
                ks[i] = r;
                printf("  %s\n", cardNames[r]);
                break;
            }
        }
    }
    putchar('\n');

    int player_count = rand_int(2, 4);

    initializeGame(player_count, ks, seed, g);
    for (int i = 0; i < 2701; i++)
        (void)Random();

    while (!isGameOver(g)) {
        int player = whoseTurn(g);

        print("---------------\n");
        printf("Player %d's turn\n", player);
        print("---------------\n\n");
        print("Hand:\n");
        print_hand(g);
        putchar('\n');

        // Action phase

        print("Action:\n");
        {
            bool played = true;
            while (g->numActions > 0 && played) {
                int hand_count = numHandCards(g);
                played = false;
                for (int i = 0; !played && i < hand_count; i++) {
                    enum CARD card = handCard(i, g);
                    if (card < adventurer)
                        continue;
                    played = try_play_card(g, i, card);
                }
            }
        }
        putchar('\n');

        // Buy phase

        print("Buy:\n");
        {
            bool bought;

            if (rand_int(0, 1) == 0) {
                print("  (Trying preferred cards)\n");
                bought = true;
                while (g->numBuys > 0 && bought) {
                    bought = false;
                    for (unsigned int i = 0;
                            !bought && i < lengthof(buy_pref_order); i++)
                        bought = try_buy_card(g, buy_pref_order[i]);
                }
            } else {
                print("  (Skipping preferred cards)\n");
            }

            print("  (Trying random kingdom cards)\n");
            int rand_tries = 10;
            while (g->numBuys > 0 && rand_tries > 0) {
                try_buy_card(g, ks[rand_int(0, 9)]);
                rand_tries--;
            }

            print("  (Trying kingdom cards in order)\n");
            bought = true;
            while (g->numBuys > 0 && bought) {
                bought = false;
                for (enum CARD card = adventurer;
                        !bought && card <= treasure_map; card++)
                    bought = try_buy_card(g, card);
            }

            print("  (Trying coppers)\n");
            bought = true;
            while (g->numBuys > 0 && bought)
                bought = try_buy_card(g, copper);
        }
        putchar('\n');

        // Cleanup phase

        endTurn(g);

        print("\n\n");
    }

    print("##################\n");
    print("#   Game over!   #\n");
    print("#                #\n");
    int winners[MAX_PLAYERS];
    getWinners(winners, g);
    for (int i = 0; i < g->numPlayers; i++) {
        if (winners[i])
            printf("#  Player %d won  #\n", i);
    }
    print("##################\n");

    free(g);

    return 0;
}
