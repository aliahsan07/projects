CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

adventurer: dominion.o rngs.o
        gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestadventurer.c rngs.o -o randomtestadventurer -lm -g $(CFLAGS)

runAdventurer: adventurer
        ./randomtestadventurer > randomtestadventurer.out
        gcov dominion.c >> randomtestadventurer.out
        cat dominion.c.gcov >> randomtestadventurer.out
randomcard: dominion.o rngs.o
        gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestcard.c rngs.o -o randomtestcard -lm -g $(CFLAGS)


runRandomCard: randomcard
        ./randomtestcard > randomtestcard.out
        gcov dominion.c >> randomtestcard.out
        cat dominion.c.gcov >> randomtestcard.out


playdom: dominion.o playdom.c
        gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

playdom2: dominion.o playdom2.c
        gcc -o playdom2 playdom2.c -g dominion.o rngs.o $(CFLAGS)

testdom: dominion.o testdominion.c
        gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o testdominion.c rngs.o -o testdominion -lm -g $(CFLAGS)
        ./testdominion 11 >> output.out
        ./testdominion 15 >> output.out
        ./testdominion 20 >> output.out
        ./testdominion 25 >> output.out
        gcov dominion.c >> testdominion.out
        cat dominion.c.gcov >> testdominion.out
#commented out for final projet
#       ./testdominion 1 &> gameResults.out
#       ./testdominion 2 &> gameResults.out
#       ./testdominion 3 &> gameResults.out
#       ./testdominion 10 &> gameResults.out
#       ./testdominion 15 &> gameResults.out
#       cat gameResults.out >> testdominion.out

testDrawCard: testDrawCard.c dominion.o rngs.o
        gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
        gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
        gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

unit1:  dominion.o rngs.o
        gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest1.c rngs.o -o unittest1 -lm -g

unit2: dominion.o rngs.o
        gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest2.c rngs.o -o unittest2 -lm -g

unit3: dominion.o rngs.o
        gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest3.c rngs.o -o unittest3 -lm -g

unit4: dominion.o rngs.o
        gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest4.c rngs.o -o unittest4 -lm -g

card1: dominion.o rngs.o
        gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest1.c rngs.o -o cardtest1 -lm -g

card2: dominion.o rngs.o
        gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest2.c rngs.o -o cardtest2 -lm -g

card3: dominion.o rngs.o
        gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest3.c rngs.o -o cardtest3 -lm -g

card4: dominion.o rngs.o
        gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest4.c rngs.o -o cardtest4 -lm -g


fail:
	./cardtest1 >> mybugs.out
	./cardtest4 >> mybugs.out
	gcov dominion.c >> mybugs.out
	cat dominion.c.gcov >> mybugs.out
myTest:
        ./unittest1 > unittestresult.out
        ./unittest2 >> unittestresult.out
        ./unittest3 >> unittestresult.out
        ./unittest4 >> unittestresult.out
        ./cardtest1 >> unittestresult.out
        ./cardtest2 >> unittestresult.out
        ./cardtest3 >> unittestresult.out
        ./cardtest4 >> unittestresult.out
        ./randomtestcard >> unittestresult.out
        ./randomtestadventurer >> unittestresult.out
        ./testdominion 4 >> unittestresult.out
        gcov dominion.c >> unittestresult.out
        cat dominion.c.gcov >> unittestresult.out
reliable:
        ./unittest1 > reliability.out
        ./unittest2 >> reliability.out
        ./unittest3 >> reliability.out
        ./unittest4 >> reliability.out
        ./cardtest1 >> reliability.out
        ./cardtest2 >> reliability.out
        ./cardtest3 >> reliability.out
        ./cardtest4 >> reliability.out
        ./randomtestcard >> reliability.out
        ./randomtestadventurer >> reliability.out
        gcov dominion.c >> reliability.out
        cat dominion.c.gcov >> reliability.out

card1test:
	./cardtest1 > bugreport1.out
	gcov dominion.c >> bugreport1.out
	cat dominion.c.gcov >> bugreport1.out
card2test:
	./cardtest2 > bugreport2.out
	gcov dominion.c >> bugreport2.out
	cat dominion.c.gcov >> bugreport2.out
card3test:
	./cardtest3 > bugreport3.out
	gcov dominion.c >> bugreport3.out
	cat dominion.c.gcov >> bugreport3.out

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard testdom randomcard adventurer unit1 unit2 unit3 unit4 card1 card2 card3 card4

final: unit1 unit2 unit3 unit4 card1 card2 card3 card4 randomcard adventurer testdom reliable

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 testdominion player.exe testInit testInit.exe randomtestadventurer testDrawCard randomtestcard badTestDrawCard *.gcov *.gcda *.gcno *.so
