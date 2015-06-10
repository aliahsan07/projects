CFLAGS = -Wall -fpic -coverage -lm -fprofile-arcs -ftest-coverage
TEST_DEPS = dominion.h dominion.c unittest1.c unittest2.c unittest3.c \
	unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c drawCardTest.c discardTest.c
TEST_DEPS2 = unit1 unit2 unit3 unit4 card1 card2 card3 card4
TEST_FLAGS = -Wall -fprofile-arcs -ftest-coverage -std=c99 -coverage


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
	cat dominion.c.gcov >> randomcard.out


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

unit1: unittest1.c dominion.c dominion.h
	gcc $(TEST_FLAGS) dominion.c unittest1.c rngs.c -o unittest1 -lm -g

unit2: unittest2.c dominion.c dominion.h
	gcc $(TEST_FLAGS) dominion.c unittest2.c rngs.c -o unittest2 -lm -g

unit3: unittest3.c dominion.c dominion.h
	gcc $(TEST_FLAGS) dominion.c unittest3.c rngs.c -o unittest3 -lm -g

unit4: unittest4.c dominion.c dominion.h
	gcc $(TEST_FLAGS) dominion.c unittest4.c rngs.c -o unittest4 -lm -g

card1: cardtest1.c dominion.c dominion.h
	gcc $(TEST_FLAGS) dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g

card2: cardtest1.c dominion.c dominion.h
	gcc $(TEST_FLAGS) dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g

card3: cardtest1.c dominion.c dominion.h
	gcc $(TEST_FLAGS) dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g

card4: cardtest1.c dominion.c dominion.h
	gcc $(TEST_FLAGS) dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g

drawCardTest: drawCardTest.c dominion.c dominion.h
	gcc $(TEST_FLAGS) dominion.c drawCardTest.c rngs.c -o drawCardTest -lm -g

discardTest: discardTest.c dominion.c dominion.h
	gcc $(TEST_FLAGS) dominion.c discardTest.c rngs.c -o discardTest -lm -g

randomtestcard:	randomtestcard.c dominion.c	
	gcc $(TEST_FLAGS) dominion.c randomtestcard.c rngs.c -o randomtestcard -lm -g

randomtestadventurer: randomtestadventurer.c dominion.c	
	gcc $(TEST_FLAGS) dominion.c randomtestadventurer.c  rngs.c -o randomtestadventurer -lm -g

testdominion: testdominion.c dominion.c dominion.o
	gcc $(TEST_FLAGS) dominion.c testdominion.c  rngs.c -o testdominion -lm -g
	

	
failing_test: failing_test.c dominion.c dominion.o
	gcc $(TEST_FLAGS) dominion.c failing_test.c  rngs.c -o failing_test -lm -g
	
passing_test: passing_test.c dominion.c dominion.o
	gcc $(TEST_FLAGS) dominion.c passing_test.c  rngs.c -o passing_test -lm -g
	
testCase: testCase.c dominion.c dominion.o
	gcc $(TEST_FLAGS) dominion.c testCase.c  rngs.c -o testCase -lm -g


	
	

#***************************************************************************************
#----------------- RUN ALL TESTS -------------------------------------------------------
#***************************************************************************************
	
randomtestcard.out: randomtestcard
	$(shell randomtestcard &> randomtestcard.out)
	$(shell gcov -b dominion.c >> randomtestcard.out)
	$(shell cat dominion.c.gcov >> randomtestcard.out)

randomtestadventurer.out: randomtestadventurer
	$(shell randomtestadventurer &> randomtestadventurer.out)
	$(shell gcov -b dominion.c >> randomtestadventurer.out)
	$(shell cat dominion.c.gcov >> randomtestadventurer.out)

testdominion.out: testdominion
	$(shell testdominion 22 &> gameResults.out)
	$(shell diff gameResults.out  gameResultsRef.out &> testdominion.out)
	
unittestresults.out: $(TEST_DEPS2)
	$(shell unittest1 &> unittestresults.out)
	$(shell unittest2 >> unittestresults.out)
	$(shell unittest3 >> unittestresults.out)
	$(shell unittest4 >> unittestresults.out)
	$(shell cardtest1 >> unittestresults.out)
	$(shell cardtest2 >> unittestresults.out)
	$(shell cardtest3 >> unittestresults.out)
	$(shell cardtest4 >> unittestresults.out)
	$(shell gcov -b dominion.c >> unittestresults.out)
	$(shell cat dominion.c.gcov >> unittestresults.out)

#***************************************************************************************
#---------------------------------------------------------------------------------------
#***************************************************************************************

	
	
	
	
	
interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard dominion.o

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 \
	unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe \
	testInit testInit.exe *.gcov *.gcda *.gcno *.so *.exe \
	randomtestcard randomtestadventurer passing_test failing_test \
	testdominion