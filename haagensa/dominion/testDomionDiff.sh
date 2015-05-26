cp myDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 4 4 > gameResults.out
cp gameResults.out gameResults.my.out
cp hansemikDominion.c dominion.c
make clean
make all
make testdominion
./testdominion 4 4 > gameResults.out
cp gameResults.out gameResults.other.out

