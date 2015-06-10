CFLAGS = -Wall -fpic -coverage -lm
COVFLAGS = -fprofile-arcs -ftest-coverage -std=c99

foo: testdominion
	gcc -o foo foo.c testdominion.o rngs.o dominion.o $(CFLAGS)

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

adventurer:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestadventurer.c rngs.c -o randomtestadventurer -lm -g

runAdventurer: adventurer
	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomcard:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestcard.c rngs.c -o randomtestcard -lm -g

runRandomCard: randomcard
	./randomtestcard >> randomtestcard.out
	gcov dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out

testdominion: testdominion.c dominion.o
	gcc  -c testdominion.c -g $(COVFLAGS) $(CFLAGS)
	gcc -o testdominion testdominion.o rngs.o dominion.o $(CFLAGS)

# for the project and assign4, great_hall infinate loop, bug1
runTestDominion: testdominion
	gcc -o dominion_their.o -c ../../knoppjo/dominion/dominion.c -g $(COVFLAGS) $(CFLAGS)
	gcc -o testdominion_their testdominion.o rngs.o dominion_their.o $(CFLAGS)
	./seedTest.sh >> testdominion.out
	
# for the project test the smithy card, bug2
bug2:
	gcc -o dominion_their.o -c ../../knoppjo/dominion/dominion.c -g  $(CFLAGS)
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion_their.o cardtest1.c rngs.c -o card1_project -lm -g

# for the project, estate supply cards below 0, bug3 in knoppjo and my dominion
# The bug is now fixed  in code. uncomment the line in Baron cardEffect to see.
# project part1 and part2
bug3: testdominion
	gcc -o dominion_their.o -c ../../knoppjo/dominion/dominion.c -g  $(CFLAGS)
	gcc -o testdominion_their testdominion.o rngs.o dominion_their.o $(CFLAGS)
	./debugTest.sh
	 grep ":-1" gameResults_their_* >> debugTest.out
	 rm gameResults_their*.out

# project part three, just like bug3 from part1.
# looking in debugTest_kundec.out to see that estate goes to -1 for some random
# seeds.
part3_baron: testdominion
	gcc -o dominion_kundec.o -c ../../kundec/dominion/dominion.c -g  $(CFLAGS)
	gcc -o testdominion_kundec testdominion.o rngs.o dominion_kundec.o $(CFLAGS)
	./part3_baron.sh
	grep ":-1" gameResults_kundec_* >> debugTest_kundec.out
	rm gameResults_kundec*.out
	
part3_adventurer: part3_adventurer.c
	gcc dominion.c part3_adventurer.c rngs.c -o part3_adventurer -lm -g $(COVFLAGS) $(CFLAGS)


playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

playdom2: dominion.o playdom2.cS
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
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g

card2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g

card3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g

card4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g


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
	
unittestresult.out: unit1 unit2 unit3 unit4 card1 card2 card3 card4 myTest

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard unit1 unit2 unit3 unit4 card1 card2 card3 card4

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
	rm -f randomtestadventurer randomtestcard randomtestcard.out randomtestadventurer.out
	rm -f gameResults_mine*.out gameResults_their*.out testdominion.out testdominion testdominion_their
	rm -f diff_*
	
