CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

dominion_kaiserh.o: dominion.h dominion_kaiserh.c rngs.o
	gcc -c dominion_kaiserh.c -g  $(CFLAGS)

dominion_gassa.o: dominion.h dominion_gassa.c rngs.o
	gcc -c dominion_gassa.c -g  $(CFLAGS)

adventurer:
	gcc -fprofile-arcs -ftest-coverage -Wall dominion.c randomtestadventurer.c rngs.c -o randomtestadventurer -lm -g
	
runAdventurer: adventurer
	./randomtestadventurer &> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomcard:
	gcc -fprofile-arcs -ftest-coverage -Wall  dominion.c randomtestcard.c rngs.c -o randomtestcard -lm -g

runRandomCard: randomcard
	./randomtestcard &> randomtestcard.out
	gcov dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomtestcard.out


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

unit1: playdom 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest1.c rngs.c -o unittest1 -lm -g

unit1kaiserh: dominion_kaiserh.o  
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion_kaiserh.c unittest1.c rngs.c -o unittest1 -lm -g


unit1gassa: dominion_gassa.o 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion_gassa.c unittest1.c rngs.c -o unittest1 -lm -g

unit2kaiserh: dominion_kaiserh.o  
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion_kaiser.c unittest2.c rngs.c -o unittest2 -lm -g

unit2gassa: dominion_kaiserh.o  
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion_gassa.c unittest2.c rngs.c -o unittest2 -lm -g
unit3:playdom
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest3.c rngs.c -o unittest3 -lm -g

unit4:playdom
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest4.c rngs.c -o unittest4 -lm -g

card1:playdom
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g

card2:playdom
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g

card3:playdom
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g

card4:playdom
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g


card4gassa:dominion_gassa.o 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion_gassa.c cardtest4.c rngs.c -o cardtest4 -lm -g

myTest:unit1 unit2 unit3 unit4 card1 card2 card3 card4
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest1.c rngs.c -o unittest1 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest2.c rngs.c -o unittest2 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest3.c rngs.c -o unittest3 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest4.c rngs.c -o unittest4 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g
	./unittest1 200 >> unittestresult.out
	./unittest2 200 >> unittestresult.out
	./unittest3 200 >> unittestresult.out
	./unittest4 200 >> unittestresult.out
	./cardtest1 200 >> unittestresult.out
	./cardtest2 200 >> unittestresult.out
	./cardtest3 200 >> unittestresult.out
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

testdominion:  testdominion.c dominion.o
	gcc -o testdominion testdominion.c -g dominion.o rngs.o $(CFLAGS)
	
testdominion2: rngs.o dominion2.o testdominion.c
	gcc -o testdominion2 testdominion.c -g dominion2.o rngs.o $(CFLAGS)

testdominionkaiserh:rngs.o testdominion.c dominion_kaiserh.o dominion.o	
	gcc -ftest-coverage -lm -g -o testdominion_kaiserh testdominion.c -g dominion_kaiserh.o rngs.o $(CFLAGS)
	

testdominiongassa:rngs.o testdominion.c dominion_gassa.o	
	gcc -ftest-coverage -lm -g -o  testdominion_gassa testdominion.c -g dominion_gassa.o rngs.o $(CFLAGS)

runtestdominionkaiserh: testdominionkaiserh testdominion
	-./testdominion 12 >testdominion4.out
	-./testdominion_kaiserh 12 >testdominion3.out
	-gcov dominion_kaiserh.c >> testdominion3cov.out	
	-gcov dominion.c >> testdominion4cov.out	
	-diff testdominion4.out testdominion3.out > diffresults2.out


runtestdominiongassa: testdominiongassa testdominion
	-./testdominion 12 >testdominion.out
	-./testdominion_gassa 12 >testdominion2.out
	-gcov dominion_gassa.c >> testdominion2cov.out
	-gcov dominion.c >> testdominioncov.out
	-diff testdominion.out testdominion2.out > diffresults.out

runtestdominion: testdominion testdominion2
	-./testdominion 15 > testdominion1.out
	-./testdominion2 15 > testdominion2.out
	-diff testdominion1.out testdominion2.out > diff1results.out
	-./testdominion 215 > testdominion3.out
	-./testdominion2 215 > testdominion4.out
	-diff testdominion3.out testdominion4.out > diff2results.out
	-./testdominion 89 > testdominion5.out
	-./testdominion2 89 > testdominion6.out
	-diff testdominion5.out testdominion6.out > diff3results.out
	-./testdominion 78 > testdominion7.out
	-./testdominion2 78 > testdominion8.out
	-diff testdominion7.out testdominion8.out > diff4results.out
	
cleanuptestdominion:
	rm -rf testdominion1.out testdominion2.out testdominion3.out testdominion4.out testdominion5.out testdominion6.out testdominion7.out \
	testdominion8.out
	rm -rf diff1results.out diff2results.out diff3results.out diff4results.out
	rm -rf testdominion testdominion2			 	

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
