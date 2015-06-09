CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)
	
passdominion.o: dominion.h passdominion.c rngs.o
	gcc -c passdominion.c -g $(CFLAGS)
	
interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)
	
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

testdominion.out: testdominion.c dominion.o rngs.o
	gcc -o testdominion -g testdominion.c dominion.o rngs.o $(CFLAGS)
	./testdominion &> testdominion.out
	
testdominion: testdominion.c dominion.o rngs.o
	gcc -o testdominion -g testdominion.c dominion.o rngs.o $(CFLAGS)
	
passdominion: testdominion.c passdominion.o rngs.o
	gcc -o passdominion -g testdominion.c passdominion.o rngs.o $(CFLAGS)

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

all: dominion.o passdominion.o rngs.o interface.o minion baron adventurer randomcard unit card testdominion passdominion

clean:
	rm -f *.o testdominion passdominion minion baron unit card adventurer randomcard unit1 unit2 unit3 unit4 card1 card2 card3 card4 randomtestadventurer randomtestcard *.gcov *.gcda *.gcno *.so
