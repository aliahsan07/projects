CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)
############################################################### 
#FOR MINION TEST: make minion
minion: minion_test.c dominion.o rngs.o
	gcc -o minion minion_test.c -g dominion.o rngs.o $(CFLAGS)
#FOR BARON TEST: make baron
baron: baron_test.c dominion.o rngs.o
	gcc -o baron baron_test.c -g dominion.o rngs.o $(CFLAGS)
############################################################### 

adventurer:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestadventurer.c rngs.c -o randomtestadventurer -lm -g

runAdventurer: adventurer
	./randomtestadventurer &> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomcard:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestcard.c rngs.c -o randomtestcard -lm -g

runRandomCard: randomcard
	./randomtestcard &> randomtestcard.out
	gcov dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out

unit: 
	gcc -o unit1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unit2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unit3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unit4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

card:
	gcc -o card1 cardtest1.c -g dominion.o rngs.o $(CFLAGS) 
	gcc -o card2 cardtest2.c -g dominion.o rngs.o $(CFLAGS) 
	gcc -o card3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o card4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

playdom2: dominion.o playdom2.c
	gcc -o playdom2 playdom2.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

testdominion.out: testdominion.c dominion.o rngs.o
	gcc -o testdominion -g testdominion.c dominion.o rngs.o $(CFLAGS)
	./testdominion &> testdominion.out

myTest:
	./unit1 &> unittestresult.out
	./unit2 >> unittestresult.out
	./unit3 >> unittestresult.out
	./unit4 >> unittestresult.out
	./card1 >> unittestresult.out
	./card2 >> unittestresult.out
	./card3 >> unittestresult.out
	./card4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe testdominion.out minion baron test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
