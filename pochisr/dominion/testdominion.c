#include "dominion_helpers.h"
#include "more_dominion_helpers.h"
#include "rngs.h"

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define print(x) fputs((x), stdout)


long get_seed(int argc, char** argv)
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
int rand_int(int min, int max)
{
    return min + (int)((max - min + 1) * Random());
}


void print_hand(struct gameState* g)
{
    int hand_count = numHandCards(g);
    for (int i = 0; i < hand_count; i++) {
        printf("  %s\n", cardNames[handCard(i, g)]);
    }
}


bool play_card(struct gameState* g, int i, enum CARD card)
{
    return false;
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

        {
            bool played;
            do {
                played = false;
                int hand_count = numHandCards(g);
                for (int i = 0; i < hand_count; i++) {
                    enum CARD card = handCard(i, g);
                    if (card < adventurer)
                        continue;
                    played = play_card(g, i, card);
                    if (played)
                        break;
                }
            } while (played);
        }

        // Buy phase

        {
            int rand_tries = 10;
            do {
                enum CARD card = ks[rand_int(0, 9)];
                if (supplyCount(card, g) == 0 || getCost(card) > g->coins)
                    continue;

                buyCard(card, g);
                printf("Buy %s\n", cardNames[card]);
            } while (g->numBuys > 0 && --rand_tries > 0);
            bool bought;
            do {
                bought = false;
                for (enum CARD card = estate; card <= treasure_map; card++) {
                    if (supplyCount(card, g) == 0 || getCost(card) > g->coins)
                        continue;

                    buyCard(card, g);
                    printf("Buy %s\n", cardNames[card]);
                    bought = true;
                    break;
                }
            } while (g->numBuys > 0 && bought);
        }

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
