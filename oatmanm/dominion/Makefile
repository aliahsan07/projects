CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

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

testdominion:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c interface.c testdominion.c rngs.c -o randomtestdominion -lm -g

testdominion1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion1.c interface.c testdominion.c rngs.c -o randomtestdominion1 -lm -g

testdominion2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion2.c interface.c testdominion.c rngs.c -o randomtestdominion2 -lm -g

testInspection:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion2.c interface.c testdominion.c rngs.c -o randomtestdominion2 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion2.c unittest1.c rngs.c -o amidongunit1 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion2.c unittest2.c rngs.c -o amidongunit2 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion2.c unittest3.c rngs.c -o amidongunit3 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion2.c unittest4.c rngs.c -o amidongunit4 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion2.c cardtest1.c interface.c rngs.c -o amidongcard1 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion2.c cardtest2.c interface.c rngs.c -o amidongcard2 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion2.c cardtest3.c interface.c rngs.c -o amidongcard3 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion2.c cardtest4.c interface.c rngs.c -o amidongcard4 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion2.c randomtestadventurer.c rngs.c -o amidongrandomadventurer -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion2.c randomtestcard.c rngs.c -o amidongrandomcard -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 printSpace.c -o printSpace -lm -g

inspection:
	./randomtestdominion2 &> amidongResults.out
	./amidongunit1 &> amidong.out
	./printSpace >> amidong.out
	./amidongunit2 >> amidong.out
	./printSpace >> amidong.out
	./amidongunit3 >> amidong.out
	./printSpace >> amidong.out
	./amidongunit4 >> amidong.out
	./printSpace >> amidong.out
	./amidongcard1 >> amidong.out
	./printSpace >> amidong.out
	./amidongcard2 >> amidong.out
	./printSpace >> amidong.out
	./amidongcard3 >> amidong.out
	./printSpace >> amidong.out
	./amidongcard4 >> amidong.out
	./printSpace >> amidong.out
	./amidongrandomadventurer >> amidong.out
	./printSpace >> amidong.out
	./amidongrandomcard >> amidong.out

runDominion:
	./randomtestdominion &> gameResults.out
	gcov dominion.c &> testdominion.out
	cat dominion.c.gcov >> testdominion.out

runDominion1:
	./randomtestdominion1 &> gameResults1.out
	gcov dominion1.c &> testdominion1.out
	cat dominion1.c.gcov >> testdominion1.out

runDominion2:
	./randomtestdominion2 &> gameResults2.out
	gcov dominion2.c &> testdominion2.out
	cat dominion2.c.gcov >> testdominion2.out

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

unit1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest1.c rngs.c -o unittest1 -lm -g

unit2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest2.c rngs.c -o unittest2 -lm -g

unit3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest3.c rngs.c -o unittest3 -lm -g

unit4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest4.c rngs.c -o unittest4 -lm -g

card1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c interface.c rngs.c -o cardtest1 -lm -g

card2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c interface.c rngs.c -o cardtest2 -lm -g

card3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c interface.c rngs.c -o cardtest3 -lm -g

card4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c interface.c rngs.c -o cardtest4 -lm -g


myTest:
	./unittest1 &> unittestresult.out
	./unittest2 >> unittestresult.out
	./unittest3 >> unittestresult.out
	./unittest4 >> unittestresult.out
	./cardtest1 >> unittestresult.out
	./cardtest2 >> unittestresult.out
	./cardtest3 >> unittestresult.out
	./cardtest4 >> unittestresult.out
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

all: playdom player testDrawCard testBuyCard badTestDrawCard unit1 unit2 unit3 unit4 card1 card2 card3 card4 myTest randomcard adventurer runAdventurer runRandomCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
