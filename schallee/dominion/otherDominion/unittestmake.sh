make clean
make dominion.o
make all
make card1
./cardtest1 >> unittestresult.out
gcov dominion
make card2
./cardtest2 >> unittestresult.out
gcov dominion
make card3
./cardtest3 >> unittestresult.out
gcov dominion
make card4
./cardtest4 >> unittestresult.out
gcov dominion
make unit1
./unittest1 >> unittestresult.out
gcov dominion
make unit2
./unittest2 >> unittestresult.out
gcov dominion
make unit3
./unittest3 >> unittestresult.out
gcov dominion 
make unit4
./unittest4 >> unittestresult.out
gcov dominion.c >> unittestresult.out
cat dominion.c.gcov >> unittestresult.out
