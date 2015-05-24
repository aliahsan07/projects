#define _POSIX_C_SOURCE 1

#include "dominion_helpers.h"
#include "more_dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


#define ONCE do
#define ENDONCE while (false);

#define assertIntEqual(x, y) assertIntEqual_(x, y, __LINE__)
#define lengthof(x) (sizeof(x) / sizeof((x)[0]))
#define print(x) fputs((x), stdout)


enum CARD buy_prefs[] = {
    province, gold, duchy, silver, village, mine, smithy
};


enum CARD trash_prefs[] = {
    copper, estate
};


enum CARD treasure_up_prefs[] = {
    copper, silver
};


static void handle_sigalrm(int signum)
{
    (void)signum;
    fputs("\nProgram ran for too long\n", stderr);
    exit(2);
}


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
        printf("  %s\n", cardNames[card]);
        assertIntEqual(0, playCard(idx, -1, -1, -1, g));
        return true;
    } else if (card == feast) {
        enum CARD new = 0;
        for (int i = 0; !new && i < (int)lengthof(buy_prefs); i++) {
            enum CARD c = buy_prefs[i];
            if (supplyCount(c, g) > 0 && getCost(c) <= 5)
                new = c;
        }

        for (enum CARD c = adventurer;
                !new && c <= treasure_map; c++)
            if (supplyCount(c, g) > 0 && getCost(c) <= 5)
                new = c;

        if (!new)
            return false;

        assertIntEqual(0, playCard(idx, new, -1, -1, g));
        printf("  %s (gain %s)\n", cardNames[card], cardNames[new]);
        return true;
    } else if (card == mine) {
        int hand_count = numHandCards(g);
        int trash_idx = -1;
        enum CARD trash = 0;
        for (int i = 0;
                trash_idx == -1 &&
                    i < (int)lengthof(treasure_up_prefs);
                i++) {
            for (int h = 0; trash_idx == -1 && h < hand_count; h++) {
                enum CARD c = handCard(h, g);
                if (c == treasure_up_prefs[i]) {
                    trash_idx = h;
                    trash = c;
                }
            }
        }

        if (trash_idx == -1 || supplyCount(trash, g) <= 0)
            return false;

        printf("  %s (trash %s, gain %s)\n", cardNames[card],
            cardNames[trash], cardNames[trash + 1]);
        assertIntEqual(0, playCard(idx, trash_idx, trash + 1, -1, g));
        return true;
    } else if (card == remodel) {
        int trash_idx;
        enum CARD new = 0;
        do {
            trash_idx = rand_int(0, numHandCards(g) - 1);
        } while (trash_idx == idx);

        int trash_cost = getCost(handCard(trash_idx, g));
        for (int i = 0; !new && i < (int)lengthof(buy_prefs); i++) {
            enum CARD c = buy_prefs[i];
            int cost = getCost(c);
            if (supplyCount(c, g) > 0 && trash_cost - 2 <= cost &&
                    cost <= trash_cost + 2)
                new = c;
        }

        if (!new)
            return false;

        printf("  %s (trash %s, gain %s)\n", cardNames[card],
            cardNames[handCard(trash_idx, g)], cardNames[new]);
        assertIntEqual(0, playCard(idx, trash_idx, new, -1, g));
        return true;
    } else if (card == baron) {
        int hand_count = numHandCards(g);
        bool discard = 0;
        int i;
        for (i = 0; !discard && i < hand_count; i++)
            if (handCard(i, g) == estate)
                discard = true;
        if (i == hand_count && g->coins < 4)
            return false;

        printf("  %s (%s %s)\n", cardNames[card], discard ? "discard" : "gain",
            cardNames[estate]);
        assertIntEqual(0, playCard(idx, (int)discard, -1, -1, g));
        return true;
    } else if (card == minion) {
        bool redraw = numHandCards(g) <= 3;
        printf("  %s (%s)\n", cardNames[card], redraw ? "redraw" : "+2 coins");
        assertIntEqual(0, playCard(idx, redraw ? 2 : 1, -1, -1, g));
        return true;
    } else if (card == steward) {
        int choice1, choice2 = -1, choice3 = -1;

        if (g->coins <= 4) {
            choice1 = 2; // +2 coins
            printf("  %s (+2 coins)\n", cardNames[card]);
        } else {
            int hand_count = numHandCards(g);

            // choice2 and choice3 are hand indices to discard
            for (int t = 0; choice3 == -1 && t < (int)lengthof(trash_prefs);
                    t++) {
                enum CARD c;
                for (int h = 0; choice3 == -1 && h < hand_count; h++) {
                    c = handCard(h, g);
                    if (trash_prefs[t] == c) {
                        if (choice2 == -1)
                            choice2 = c;
                        else
                            choice3 = c;
                    }
                }
            }

            if (choice3 >= 0) {
                choice1 = 3; // trash two cards
                printf("  %s (trash %s and %s)\n", cardNames[card],
                    cardNames[choice2], cardNames[choice3]);
            } else {
                choice1 = 1; // +2 cards
                choice2 = choice3 = -1;
                printf("  %s (+2 cards)\n", cardNames[card]);
            }
        }

        assertIntEqual(0, playCard(idx, choice1, choice2, choice3, g));
        return true;
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
    {
        struct sigaction sa = {
            .sa_handler = handle_sigalrm,
        };
        sigemptyset(&sa.sa_mask);

        if (sigaction(SIGALRM, &sa, NULL) < 0) {
            fputs("Can't set up SIGALRM handler\n", stderr);
            return 3;
        }

        struct itimerval t = {
            .it_interval = {0, 0},
            .it_value = {0, 20000},
        };

        if (setitimer(ITIMER_REAL, &t, NULL) < 0) {
            fputs("Can't set up timer\n", stderr);
            return 3;
        }
    }


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
                            !bought && i < lengthof(buy_prefs); i++)
                        bought = try_buy_card(g, buy_prefs[i]);
                }
            } else {
                print("  (Skipping preferred cards)\n");
            }

            if (g->numBuys > 0)
                print("  (Trying random kingdom cards)\n");
            int rand_tries = 10;
            while (g->numBuys > 0 && rand_tries > 0) {
                try_buy_card(g, ks[rand_int(0, 9)]);
                rand_tries--;
            }

            if (g->numBuys > 0)
                print("  (Trying Copper)\n");
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
